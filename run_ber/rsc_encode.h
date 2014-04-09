/*
function x = rsc_encode(G,m,termination)
% Copyright 1998, Yufei Wu, MPRG lab, Virginia Tech. for academic use
% encodes a binary data block m (0/1) with a RSC (recursive systematic
% convolutional) code defined by generator matrix G, returns the output
% in x (0/1), terminates the trellis with all-0 state if termination>0
if nargin<3, termination = 0; end
[N,L] = size(G); % Number of output bits, Constraint length
M = L-1; % Dimension of the state
lu = length(m)+(termination>0)*M; % Length of the input
lm = lu-M; % Length of the message
state = zeros(1,M); % initialize the state vector
% To generate the codeword
x = [];
for i = 1:lu
   if termination<=0 || (termination>0 && i<=lm)
     d_k = m(i);
   elseif termination>0 && i>lm
     d_k = rem(G(1,2:L)*state.',2);
   end
   a_k = rem(G(1,:)*[d_k state].',2);
   xp = rem(G(2,:)*[a_k state].',2); % 2nd output (parity) bits
   state = [a_k state(1:M-1)]; % Next sttate
   %disp(state)
   x = [x [d_k; xp]]; % since systematic, first output is input bit
end
*/
#ifndef __RSC_ENCODE_H
#define __RSC_ENCODE_H
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


// depriciated: @Penlin: 2013/08/04  use block by copy is too slow
void rsc_encode(int ** G, const int &L, const int *block, int * map, const int &lm, const int &termination, int* output){

    int M, lu, i, j;
    int *state;
    int d_k = 0, a_k = 0, xp=0;

    M = L-1;
    lu = (lm + ((termination>0)?M:0));

    state = (int*)malloc(sizeof(int)*M);
    for(i=0;i<M;++i)
        state[i] = 0;

    for(i=0;i<lu;++i){
        if(termination <= 0 || ( termination > 0 && i < lm ))
            d_k = block[map[i]];
        else if(termination > 0 && i >= lm)
            d_k = ((int)InnerProduct(G[0], state, 1 ,L-1,0, M-1))%2;

        a_k = ((int)(G[0][0]*d_k+InnerProduct(G[0],state,1,L-1,0,M-1)))%2;
        xp = ((int) (G[1][0]*a_k+InnerProduct(G[1],state,1,L-1,0,M-1)))%2;

        for(j=M-1;j>0;--j)
           state[j] = state[j-1];

        state[0] = a_k;

        output[2*i] = d_k;
        output[1+2*i] = xp;

    }

    free(state);
}

void generate_Ly(int* x, const int &lu , const double &EbN0dB, double* Ly) {
    //parameters
    const int puncture = 0;                     // puncture or not
    double rate = 1/(double)(2-puncture);       // code rate
    const double a = 1;                         // Fading amplitude. a=1 -> AWGN channel
    const double EbN0 = pow(10,EbN0dB/10);      // convert Eb/N0[dB] to normal number
    const double L_c = 4*a*EbN0*rate;           // reliability value of the channel
    const double sigma = a*sqrt(2*rate*EbN0);   // standard deviation of AWGN noise

    for(int i = 0 ; i < 2*lu ; ++i)
        Ly[i] = 0.5*L_c*(2*x[i] - 1)+ sigma*gaussian_noise();  // add noise   + sigma*gaussian_noise()

}

#endif // __RSC_ENCODE_H
