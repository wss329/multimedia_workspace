#ifndef __ALGS_DIRECT_H
#define __ALGS_DIRECT_H
#include <stdio.h>
#include <stdlib.h>
#include "frame.h"


/**
*   @Penlin: algorithm for direct decode
*
*   @param: str     clip short name for record                          [char*]
*
*   @param: PSNR    computed PSNR between decoded frame and original frame [n_frame]
*   @param: imgr_out decoded clip                                       [n_frame*imgh*imgw]
*
*   @param: imgh, imgw, n_frame, lu, G
*
**/

void direct_system(const char* str, FILE* fptr, const int &imgh, const int &imgw, const int &n_frame,int** G, int** pout, int** pstate,const double &snr, double* weights,double* PSNR , int*** img_out = NULL){


    Frame* frame = new Frame(imgh,imgw,0,0);
    frame->encode_info(snr,G);

    // param initial
    const int Ns = pow(2,G_L-1);
    const int lm = imgh*imgw;
    const int lu = lm + 2;
    double* Lu = (double*) malloc(sizeof(double)*lu);

    for(int i=0; i<lu ;++i)
        Lu[i] = 0;

    double* Le1 = (double*)malloc(sizeof(double)*lu);
    double* Le2 = (double*)malloc(sizeof(double)*lu);

    computeLe(Lu,Le1,Le2,lu);

    // frame buffer
    int** imgO;
    int** imgr = new2d<int>(imgh,imgw);
    int*** imgr_bp = new3d<int>(PXL,imgh,imgw);
    double** Ly = new2d<double>(PXL,2*lu,0);    //channel value
    int** map = new2d<int>(PXL,lm);      //interleaver map

    double** Lu_c = new2d<double>(PXL,lu,0);  //channel decoder output


    // decoding
    for(int f = 0 ; f < n_frame ; ++f){
        printf("Encoding frame#%d\n",f+1);

        frame->next(fptr,Ly,map,weights);

        printf("Decoding frame#%d\n",f+1);


        // initialize channel value
       // Ly = Ly_in[f];
       //map = map_in[f];

        // BCJR decoding
#if __STATUS__
        printf("BCJR decoding ...%lf\n",getCurrentTime());
#endif
        for(int t_lvl = 0 ; t_lvl < PXL ; ++t_lvl)
            BCJR_decoding(Ns, lu, 1, Ly[t_lvl], Le1, Le2, pstate, pout, Lu_c[t_lvl]);

        // deinterleave
#if __STATUS__
        printf("deinterleave ...%lf\n",getCurrentTime());
#endif
        deinterleave(Lu_c,map,lm);

        // recover to image
        for(int i = 0 ; i <imgh ; ++i){
            for(int j = 0 ; j < imgw ; ++j){
                for(int t_lvl=0 ; t_lvl < PXL ; ++t_lvl)
                    imgr_bp[t_lvl][i][j] = ((Lu_c[t_lvl][j+i*imgw]>=0)?1:0);
            }
        }

        // construct image
        bin2dec_img(imgr_bp,imgh,imgw,imgr);

        // compute PSNR
        PSNR[f] = frame->psnr(imgr);
#if __PSNR__
        printf("%s frame#%d PSNR = %lf\n",str,f+1,PSNR[f]);
#endif

        // imgr output
        if(img_out!=NULL)
            for(int i = 0, j = 0; i <imgh ; ++i)
                for(j=0 ; j < imgw ; ++j)
                    img_out[f][i][j] = imgr[i][j];

    }

    delete3d<int>(imgr_bp);
    delete2d<double>(Lu_c);
    delete2d<int>(imgr);
    free(Lu);
    free(Le1);
    free(Le2);

    delete frame;
}


#endif // __ALGS_DIRECT_H
