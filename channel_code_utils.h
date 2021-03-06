#ifndef __CHANNEL_CODE_H
#define __CHANNEL_CODE_H

#if __BCJR__==__MAP__
#include "map_util.h"
#else
#include "logmap_util.h"
#endif

#include "math.h"
#include "build_value.h"

#define G_N 2
#define G_L 3
#define G_M (G_L-1)

const static int G[G_N][G_L] = {{1,1,1},{1,0,1}};      // code generator

int ** getGenerator(){
    int ** G_ptr ;
    G_ptr = new2d<int>(G_N,G_L);
    for(int i = 0 ; i < G_N ; ++i){
        for(int j = 0 ; j < G_L ; ++j){
            G_ptr[i][j] = G[i][j];
        }
    }
    return G_ptr;
}

/**
* Copyright 1998, Yufei Wu, MPRG lab, Virginia Tech. for academic use
* Log_MAP algorithm using straightforward method to compute branch cost
* Input: Ly     = scaled received bits Ly=0.5*L_c*y=(2*a*rate*Eb/N0)*y
*        G      = code generator for the RSC code a in binary matrix
*        Lu     = extrinsic information from the previous decoder.
*        ind_dec= index of decoder=1/2 (assumed to be terminated/open)
* Output: L_A   = ln (P(x=1|y)/P(x=-1|y)), i.e., Log-Likelihood Ratio
*              (soft-value) of estimated message input bit at each level
*tic
*
*   @Penlin: modified to C++ version
*
*   @param Ly
*   @param G
*   @param Lu
*   @param ind_dec
*   @param lu, L
*
*/
/** depreciated @Penlin: 2013/07/30  dont malloc/free too frequently
void logmap(double* Ly, int** G, const double* Lu, const int &ind_dec, const int &lu ,int ** ps, int** pout, double* LA){

    const int Ns = pow(2,G_L-1);
    double* Le1 = (double*)malloc(sizeof(double)*lu);
    double* Le2 = (double*)malloc(sizeof(double)*lu);

    printf("computeLe ...\n");
    computeLe(Lu,Le1,Le2,lu);
//    printf("done!\n");
    // L_A = logmap_mex(Ns,Infty,EPS,lu,Ly,logical(ind_dec),Le1,Le2,ps,pout);
//    LA = logmap(Ns, lu, ind_dec, Ly, Le1, Le2, ps, pout);
    printf("logmap ...\n");
    logmap(Ns, lu, ind_dec, Ly, Le1, Le2, ps, pout,LA);
    printf("done\n");

    free(Le1);
    free(Le2);

//    return LA;
}
**/

void BCJR_decoding(const int &Ns, const int &lu, const int &ind_dec, double* Ly, double* Le1, double* Le2, int** ps, int** pout, double* LA){

#if __BCJR__==__MAP__
    BCJR_map(Ns, lu, ind_dec, Ly,  Le1, Le2,  ps, pout, LA);
#else
    BCJR_logmap(Ns, lu, ind_dec, Ly,  Le1, Le2,  ps, pout, LA);
#endif

}


/**
*   @Penlin: modified to C version
*   @param G        [N*L]
*   @param Ns       2^(L-1)
*   @param pout     [Ns*4]
*   @param pstate   [Ns*2]
**/

void trellis(int** G, const int &N, const int &L, const int &Ns, int ** pout, int** pstate ){

    const int M = L-1;
    int* state_b;
    int d_k, a_k, bN, b1;
    int** out = new2d<int>(2,2);
    int** state = new2d<int>(2,M);
    int** nstate = new2d<int>(Ns,2);
    int** nout = new2d<int>(Ns,4);

    // Set up next_out and next_state matrices for RSC code generator G
    for(int state_i = 0 ; state_i < Ns ; ++state_i){
        state_b = deci2binl(state_i,M);
        for(int i = 1 ; i < M ; ++i ){
            state[0][i] =  state_b[i-1];
            state[1][i] =  state_b[i-1];
        }

        for(int input_bit = 0 ; input_bit <= 1; ++input_bit){
            d_k = input_bit;
            a_k = (G[0][0]*d_k + InnerProduct(G[0],state_b,1,M,0,M-1))%2;
            out[d_k][0] = d_k;
            out[d_k][1] = (G[1][0]*a_k + InnerProduct(G[1],state_b,1,M,0,M-1))%2;

            state[d_k][0] = a_k;
        }

        for(int i = 0 ; i < 4; ++i)
            nout[state_i][i] = 2*out[i/2][i%2] -1;

        for(int i = 0 ; i < 2 ; ++i){
            nstate[state_i][i] =  bin2deci(state[i],M);
        }

        free(state_b);
    }

    // Possible previous states having reached the present state
    // with input_bit=0/1
    for(int input_bit = 0 ; input_bit < 2; ++input_bit){
        bN = input_bit*N;
        b1 = input_bit;
        for(int state_i = 0 ; state_i < Ns ; ++state_i){
            pstate[nstate[state_i][b1]][b1] = state_i;
            for(int i = bN ; i < (N+bN) ; ++i)
                pout[nstate[state_i][b1]][i] = nout[state_i][i];
        }
    }

    delete2d<int>(out);
    delete2d<int>(state);
    delete2d<int>(nstate);
    delete2d<int>(nout);
}


/**
*   @Penlin: 2D
*/

void deinterleave(double** Lu, int** map, const int &lm){
#if __INTERLEAVE__
    double* tmp = (double*) malloc(sizeof(double)*lm);

    for(int t_lvl = 0 ; t_lvl < PXL; ++t_lvl){
        for(int i = 0 ; i < lm ; ++i)
            tmp[i] = Lu[t_lvl][i];

        for(int i = 0 ; i < lm ; ++i)
            Lu[t_lvl][map[t_lvl][i]] = tmp[i];
    }

    free(tmp);
#endif
}

/** @depriciated 2013/07/23
*   @Penlin: 1D test version
*/

void deinterleave(int* Lu, int* map, const int &lm){
#if __INTERLEAVE__
    int* tmp = (int*) malloc(sizeof(double)*lm);

    for(int i = 0 ; i < lm ; ++i)
        tmp[i] = Lu[i];

    for(int i = 0 ; i < lm ; ++i)
        Lu[map[i]] = tmp[i];

    free(tmp);
#endif
}


/**
*   @Penlin: 2D interleave
*
*/

void interleave(double** Lu, int** map, const int &lm ){
#if __INTERLEAVE__
    double* tmp = (double*) malloc(sizeof(double)*lm);

    for(int t_lvl = 0 ; t_lvl < PXL; ++t_lvl){
        for(int i = 0 ; i < lm ; ++i)
            tmp[i] = Lu[t_lvl][map[t_lvl][i]];

        for(int i = 0 ; i < lm ; ++i)
            Lu[t_lvl][i] = tmp[i];
    }

    free(tmp);
#endif
}


void dpcm(int*** Y, int*** dpcm_Y, const int &height, const int & width, const int &frame){

    int i,j,k;

    for(i=0;i<height;++i)
        for(j=0;j<width;++j)
            dpcm_Y[0][i][j] = Y[0][i][j];

    for(k=1;k<frame;++k){
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                dpcm_Y[k][i][j] = (Y[k][i][j]-Y[k-1][i][j]);
                if(dpcm_Y[k][i][j]>0)
                    dpcm_Y[k][i][j]+=256;
            }
        }
    }

}

#endif // __CHANNEL_CODE_H
