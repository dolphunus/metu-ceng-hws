/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/* 
 * Please fill in the following student struct 
 */
team_t team = {
    "2099380",                       /* Student ID */
    "Onur Can TIRTIR",               /* full name */
    "onur.tirtir@ceng.metu.edu.tr",  /* email address */
    "",                              /* leave blank */
    ""                               /* leave blank */
};


/*******************
 * CONVOLUTION KERNEL
 *******************/

/***************************************************************
 * Your different versions of the convolution functions  go here
 ***************************************************************/

/* 
 * naive_conv - The naive baseline version of convolution 
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim,int *src, int *ker,int *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
    for(j = 0; j < dim-8+1; j++) {
        dst[j*dim+i] = 0;
        for(k = 0; k < 8; k++)
        for(l = 0; l < 8; l++) {
            dst[j*dim+i] = dst[j*dim+i] +src[(j+l)*dim+(i+k)]*ker[l*dim+k];
        }
    }
}
/*
char conv_descr[] = "conv";
void conv(int dim,int *src, int *ker,int *dst) {
    int i, j, rdim = dim-7;

    for(j = 0; j < rdim; j++) {
        int *srcj = src+j*dim;
        for(i = 0; i < rdim; i++) {
            int acc = 0;

            int *kert = ker;
            int *srcji = srcj+i;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[6]*kert[6];
            acc  += srcji[5]*kert[5];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            
            dst[j*dim+i] = acc;
        }
    }
}
*/
/*
char conv1_descr[] = "conv1";
void conv1(int dim,int *src, int *ker,int *dst) {
    int i, j, rdim = dim-7;

    int *srcj = src;
    int *dstj = dst;
    for(j = 0; j < rdim; j++) {
        for(i = 0; i < rdim; i++) {
            int acc = 0;

            int *kert = ker;
            int *srcji = srcj+i;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            srcji += dim;
            kert  += dim;
            acc  += srcji[0]*kert[0];
            acc  += srcji[1]*kert[1];
            acc  += srcji[2]*kert[2];
            acc  += srcji[3]*kert[3];
            acc  += srcji[4]*kert[4];
            acc  += srcji[5]*kert[5];
            acc  += srcji[6]*kert[6];
            acc  += srcji[7]*kert[7];
            
            dstj[i] = acc;
        }
        dstj += dim;
        srcj += dim;
    }
}
*/
/*
char conv2_descr[] = "conv2";
void conv2(int dim, int *src, int *ker,int *dst) {
    int i, j, rdim = dim-7;
    
    int ker0  = ker[0];
    int ker1  = ker[1];
    int ker2  = ker[2];
    int ker3  = ker[3];
    int ker4  = ker[4];
    int ker5  = ker[5];
    int ker6  = ker[6];
    int ker7  = ker[7];

    ker += dim;
    int ker8  = ker[0];
    int ker9  = ker[1];
    int ker10 = ker[2];
    int ker11 = ker[3];
    int ker12 = ker[4];
    int ker13 = ker[5];
    int ker14 = ker[6];
    int ker15 = ker[7];
    
    ker += dim;
    int ker16 = ker[0];
    int ker17 = ker[1];
    int ker18 = ker[2];
    int ker19 = ker[3];
    int ker20 = ker[4];
    int ker21 = ker[5];
    int ker22 = ker[6];
    int ker23 = ker[7];
    
    ker += dim;
    int ker24 = ker[0];
    int ker25 = ker[1];
    int ker26 = ker[2];
    int ker27 = ker[3];
    int ker28 = ker[4];
    int ker29 = ker[5];
    int ker30 = ker[6];
    int ker31 = ker[7];
    
    ker += dim;
    int ker32 = ker[0];
    int ker33 = ker[1];
    int ker34 = ker[2];
    int ker35 = ker[3];
    int ker36 = ker[4];
    int ker37 = ker[5];
    int ker38 = ker[6];
    int ker39 = ker[7];
    
    ker += dim;
    int ker40 = ker[0];
    int ker41 = ker[1];
    int ker42 = ker[2];
    int ker43 = ker[3];
    int ker44 = ker[4];
    int ker45 = ker[5];
    int ker46 = ker[6];
    int ker47 = ker[7];
    
    ker += dim;
    int ker48 = ker[0];
    int ker49 = ker[1];
    int ker50 = ker[2];
    int ker51 = ker[3];
    int ker52 = ker[4];
    int ker53 = ker[5];
    int ker54 = ker[6];
    int ker55 = ker[7];
    
    ker += dim;
    int ker56 = ker[0];
    int ker57 = ker[1];
    int ker58 = ker[2];
    int ker59 = ker[3];
    int ker60 = ker[4];
    int ker61 = ker[5];
    int ker62 = ker[6];
    int ker63 = ker[7];

    int *srcj = src;
    int *dstj = dst;
    for(j = 0; j < rdim; j++) {
        for(i = 0; i < rdim; i++) {
            int *srcji = srcj+i;
            
            int acc = srcji[0]*ker0 ;
            acc  += srcji[1]*ker1 ;
            acc  += srcji[2]*ker2 ;
            acc  += srcji[3]*ker3 ;
            acc  += srcji[4]*ker4 ;
            acc  += srcji[5]*ker5 ;
            acc  += srcji[6]*ker6 ;
            acc  += srcji[7]*ker7 ;
            srcji += dim;
            acc  += srcji[0]*ker8 ;
            acc  += srcji[1]*ker9 ;
            acc  += srcji[2]*ker10;
            acc  += srcji[3]*ker11;
            acc  += srcji[4]*ker12;
            acc  += srcji[5]*ker13;
            acc  += srcji[6]*ker14;
            acc  += srcji[7]*ker15;
            srcji += dim;
            acc  += srcji[0]*ker16;
            acc  += srcji[1]*ker17;
            acc  += srcji[2]*ker18;
            acc  += srcji[3]*ker19;
            acc  += srcji[4]*ker20;
            acc  += srcji[5]*ker21;
            acc  += srcji[6]*ker22;
            acc  += srcji[7]*ker23;
            srcji += dim;
            acc  += srcji[0]*ker24;
            acc  += srcji[1]*ker25;
            acc  += srcji[2]*ker26;
            acc  += srcji[3]*ker27;
            acc  += srcji[4]*ker28;
            acc  += srcji[5]*ker29;
            acc  += srcji[6]*ker30;
            acc  += srcji[7]*ker31;
            srcji += dim;
            acc  += srcji[0]*ker32;
            acc  += srcji[1]*ker33;
            acc  += srcji[2]*ker34;
            acc  += srcji[3]*ker35;
            acc  += srcji[4]*ker36;
            acc  += srcji[5]*ker37;
            acc  += srcji[6]*ker38;
            acc  += srcji[7]*ker39;
            srcji += dim;
            acc  += srcji[0]*ker40;
            acc  += srcji[1]*ker41;
            acc  += srcji[2]*ker42;
            acc  += srcji[3]*ker43;
            acc  += srcji[4]*ker44;
            acc  += srcji[5]*ker45;
            acc  += srcji[6]*ker46;
            acc  += srcji[7]*ker47;
            srcji += dim;
            acc  += srcji[0]*ker48;
            acc  += srcji[1]*ker49;
            acc  += srcji[2]*ker50;
            acc  += srcji[3]*ker51;
            acc  += srcji[4]*ker52;
            acc  += srcji[5]*ker53;
            acc  += srcji[6]*ker54;
            acc  += srcji[7]*ker55;
            srcji += dim;
            acc  += srcji[0]*ker56;
            acc  += srcji[1]*ker57;
            acc  += srcji[2]*ker58;
            acc  += srcji[3]*ker59;
            acc  += srcji[4]*ker60;
            acc  += srcji[5]*ker61;
            acc  += srcji[6]*ker62;
            acc  += srcji[7]*ker63;
            
            dstj[i] = acc;
        }
        dstj += dim;
        srcj += dim;
    }
}

char conv3_descr[] = "conv3";
void conv3(int dim, int *src, int *ker,int *dst) {
    int i, j, rdim = dim-7;
    
    int ker0  = ker[0];
    int ker1  = ker[1];
    int ker2  = ker[2];
    int ker3  = ker[3];
    int ker4  = ker[4];
    int ker5  = ker[5];
    int ker6  = ker[6];
    int ker7  = ker[7];

    ker += dim;
    int ker8  = ker[0];
    int ker9  = ker[1];
    int ker10 = ker[2];
    int ker11 = ker[3];
    int ker12 = ker[4];
    int ker13 = ker[5];
    int ker14 = ker[6];
    int ker15 = ker[7];
    
    ker += dim;
    int ker16 = ker[0];
    int ker17 = ker[1];
    int ker18 = ker[2];
    int ker19 = ker[3];
    int ker20 = ker[4];
    int ker21 = ker[5];
    int ker22 = ker[6];
    int ker23 = ker[7];
    
    ker += dim;
    int ker24 = ker[0];
    int ker25 = ker[1];
    int ker26 = ker[2];
    int ker27 = ker[3];
    int ker28 = ker[4];
    int ker29 = ker[5];
    int ker30 = ker[6];
    int ker31 = ker[7];
    
    ker += dim;
    int ker32 = ker[0];
    int ker33 = ker[1];
    int ker34 = ker[2];
    int ker35 = ker[3];
    int ker36 = ker[4];
    int ker37 = ker[5];
    int ker38 = ker[6];
    int ker39 = ker[7];
    
    ker += dim;
    int ker40 = ker[0];
    int ker41 = ker[1];
    int ker42 = ker[2];
    int ker43 = ker[3];
    int ker44 = ker[4];
    int ker45 = ker[5];
    int ker46 = ker[6];
    int ker47 = ker[7];
    
    ker += dim;
    int ker48 = ker[0];
    int ker49 = ker[1];
    int ker50 = ker[2];
    int ker51 = ker[3];
    int ker52 = ker[4];
    int ker53 = ker[5];
    int ker54 = ker[6];
    int ker55 = ker[7];
    
    ker += dim;
    int ker56 = ker[0];
    int ker57 = ker[1];
    int ker58 = ker[2];
    int ker59 = ker[3];
    int ker60 = ker[4];
    int ker61 = ker[5];
    int ker62 = ker[6];
    int ker63 = ker[7];

    int *srcj = src;
    int *dstj = dst;
    for(j = 0; j < rdim; j++) {
        for(i = 0; i < rdim; i++) {
            int *srcji = srcj+i;
            
            int acc0 = srcji[0]*ker0 ;
            int acc1 = srcji[1]*ker1 ;
            acc0  += srcji[2]*ker2 ;
            acc1  += srcji[3]*ker3 ;
            acc0  += srcji[4]*ker4 ;
            acc1  += srcji[5]*ker5 ;
            acc0  += srcji[6]*ker6 ;
            acc1  += srcji[7]*ker7 ;
            srcji += dim;
            acc0  += srcji[0]*ker8 ;
            acc1  += srcji[1]*ker9 ;
            acc0  += srcji[2]*ker10;
            acc1  += srcji[3]*ker11;
            acc0  += srcji[4]*ker12;
            acc1  += srcji[5]*ker13;
            acc0  += srcji[6]*ker14;
            acc1  += srcji[7]*ker15;
            srcji += dim;
            acc0  += srcji[0]*ker16;
            acc1  += srcji[1]*ker17;
            acc0  += srcji[2]*ker18;
            acc1  += srcji[3]*ker19;
            acc0  += srcji[4]*ker20;
            acc1  += srcji[5]*ker21;
            acc0  += srcji[6]*ker22;
            acc1  += srcji[7]*ker23;
            srcji += dim;
            acc0  += srcji[0]*ker24;
            acc1  += srcji[1]*ker25;
            acc0  += srcji[2]*ker26;
            acc1  += srcji[3]*ker27;
            acc0  += srcji[4]*ker28;
            acc1  += srcji[5]*ker29;
            acc0  += srcji[6]*ker30;
            acc1  += srcji[7]*ker31;
            srcji += dim;
            acc0  += srcji[0]*ker32;
            acc1  += srcji[1]*ker33;
            acc0  += srcji[2]*ker34;
            acc1  += srcji[3]*ker35;
            acc0  += srcji[4]*ker36;
            acc1  += srcji[5]*ker37;
            acc0  += srcji[6]*ker38;
            acc1  += srcji[7]*ker39;
            srcji += dim;
            acc0  += srcji[0]*ker40;
            acc1  += srcji[1]*ker41;
            acc0  += srcji[2]*ker42;
            acc1  += srcji[3]*ker43;
            acc0  += srcji[4]*ker44;
            acc1  += srcji[5]*ker45;
            acc0  += srcji[6]*ker46;
            acc1  += srcji[7]*ker47;
            srcji += dim;
            acc0  += srcji[0]*ker48;
            acc1  += srcji[1]*ker49;
            acc0  += srcji[2]*ker50;
            acc1  += srcji[3]*ker51;
            acc0  += srcji[4]*ker52;
            acc1  += srcji[5]*ker53;
            acc0  += srcji[6]*ker54;
            acc1  += srcji[7]*ker55;
            srcji += dim;
            acc0  += srcji[0]*ker56;
            acc1  += srcji[1]*ker57;
            acc0  += srcji[2]*ker58;
            acc1  += srcji[3]*ker59;
            acc0  += srcji[4]*ker60;
            acc1  += srcji[5]*ker61;
            acc0  += srcji[6]*ker62;
            acc1  += srcji[7]*ker63;
            
            dstj[i] = (acc0 + acc1);
        }
        dstj += dim;
        srcj += dim;
    }
}
*/

char conv4_descr[] = "conv4";
void conv4(int dim, int *src, int *ker,int *dst) {
    int ker0  = ker[0];
    int ker1  = ker[1];
    int ker2  = ker[2];
    int ker3  = ker[3];
    int ker4  = ker[4];
    int ker5  = ker[5];
    int ker6  = ker[6];
    int ker7  = ker[7];

    ker += dim;
    int ker8  = ker[0];
    int ker9  = ker[1];
    int ker10 = ker[2];
    int ker11 = ker[3];
    int ker12 = ker[4];
    int ker13 = ker[5];
    int ker14 = ker[6];
    int ker15 = ker[7];
    
    ker += dim;
    int ker16 = ker[0];
    int ker17 = ker[1];
    int ker18 = ker[2];
    int ker19 = ker[3];
    int ker20 = ker[4];
    int ker21 = ker[5];
    int ker22 = ker[6];
    int ker23 = ker[7];
    
    ker += dim;
    int ker24 = ker[0];
    int ker25 = ker[1];
    int ker26 = ker[2];
    int ker27 = ker[3];
    int ker28 = ker[4];
    int ker29 = ker[5];
    int ker30 = ker[6];
    int ker31 = ker[7];
    
    ker += dim;
    int ker32 = ker[0];
    int ker33 = ker[1];
    int ker34 = ker[2];
    int ker35 = ker[3];
    int ker36 = ker[4];
    int ker37 = ker[5];
    int ker38 = ker[6];
    int ker39 = ker[7];
    
    ker += dim;
    int ker40 = ker[0];
    int ker41 = ker[1];
    int ker42 = ker[2];
    int ker43 = ker[3];
    int ker44 = ker[4];
    int ker45 = ker[5];
    int ker46 = ker[6];
    int ker47 = ker[7];
    
    ker += dim;
    int ker48 = ker[0];
    int ker49 = ker[1];
    int ker50 = ker[2];
    int ker51 = ker[3];
    int ker52 = ker[4];
    int ker53 = ker[5];
    int ker54 = ker[6];
    int ker55 = ker[7];
    
    ker += dim;
    int ker56 = ker[0];
    int ker57 = ker[1];
    int ker58 = ker[2];
    int ker59 = ker[3];
    int ker60 = ker[4];
    int ker61 = ker[5];
    int ker62 = ker[6];
    int ker63 = ker[7];

    int rdim = dim-7;
    for(int j = 0; j < rdim; ++j, dst += dim, src += dim) {
        int acc0, acc1;
        for(int i = 0; i < rdim; dst[i] = (acc0 + acc1), ++i) {
            int *srcji = src+i;
            
            acc0   = srcji[0]*ker0 ;
            acc1   = srcji[1]*ker1 ;
            acc0  += srcji[2]*ker2 ;
            acc1  += srcji[3]*ker3 ;
            acc0  += srcji[4]*ker4 ;
            acc1  += srcji[5]*ker5 ;
            acc0  += srcji[6]*ker6 ;
            acc1  += srcji[7]*ker7 ;
            srcji += dim;
            acc0  += srcji[0]*ker8 ;
            acc1  += srcji[1]*ker9 ;
            acc0  += srcji[2]*ker10;
            acc1  += srcji[3]*ker11;
            acc0  += srcji[4]*ker12;
            acc1  += srcji[5]*ker13;
            acc0  += srcji[6]*ker14;
            acc1  += srcji[7]*ker15;
            srcji += dim;
            acc0  += srcji[0]*ker16;
            acc1  += srcji[1]*ker17;
            acc0  += srcji[2]*ker18;
            acc1  += srcji[3]*ker19;
            acc0  += srcji[4]*ker20;
            acc1  += srcji[5]*ker21;
            acc0  += srcji[6]*ker22;
            acc1  += srcji[7]*ker23;
            srcji += dim;
            acc0  += srcji[0]*ker24;
            acc1  += srcji[1]*ker25;
            acc0  += srcji[2]*ker26;
            acc1  += srcji[3]*ker27;
            acc0  += srcji[4]*ker28;
            acc1  += srcji[5]*ker29;
            acc0  += srcji[6]*ker30;
            acc1  += srcji[7]*ker31;
            srcji += dim;
            acc0  += srcji[0]*ker32;
            acc1  += srcji[1]*ker33;
            acc0  += srcji[2]*ker34;
            acc1  += srcji[3]*ker35;
            acc0  += srcji[4]*ker36;
            acc1  += srcji[5]*ker37;
            acc0  += srcji[6]*ker38;
            acc1  += srcji[7]*ker39;
            srcji += dim;
            acc0  += srcji[0]*ker40;
            acc1  += srcji[1]*ker41;
            acc0  += srcji[2]*ker42;
            acc1  += srcji[3]*ker43;
            acc0  += srcji[4]*ker44;
            acc1  += srcji[5]*ker45;
            acc0  += srcji[6]*ker46;
            acc1  += srcji[7]*ker47;
            srcji += dim;
            acc0  += srcji[0]*ker48;
            acc1  += srcji[1]*ker49;
            acc0  += srcji[2]*ker50;
            acc1  += srcji[3]*ker51;
            acc0  += srcji[4]*ker52;
            acc1  += srcji[5]*ker53;
            acc0  += srcji[6]*ker54;
            acc1  += srcji[7]*ker55;
            srcji += dim;
            acc0  += srcji[0]*ker56;
            acc1  += srcji[1]*ker57;
            acc0  += srcji[2]*ker58;
            acc1  += srcji[3]*ker59;
            acc0  += srcji[4]*ker60;
            acc1  += srcji[5]*ker61;
            acc0  += srcji[6]*ker62;
            acc1  += srcji[7]*ker63;
        }
    }
}
/*
char conv5_descr[] = "conv5";
void conv5(int dim, int *src, int *ker,int *dst) {
    int ker0  = ker[0];
    int ker1  = ker[1];
    int ker2  = ker[2];
    int ker3  = ker[3];
    int ker4  = ker[4];
    int ker5  = ker[5];
    int ker6  = ker[6];
    int ker7  = ker[7];

    ker += dim;
    int ker8  = ker[0];
    int ker9  = ker[1];
    int ker10 = ker[2];
    int ker11 = ker[3];
    int ker12 = ker[4];
    int ker13 = ker[5];
    int ker14 = ker[6];
    int ker15 = ker[7];
    
    ker += dim;
    int ker16 = ker[0];
    int ker17 = ker[1];
    int ker18 = ker[2];
    int ker19 = ker[3];
    int ker20 = ker[4];
    int ker21 = ker[5];
    int ker22 = ker[6];
    int ker23 = ker[7];
    
    ker += dim;
    int ker24 = ker[0];
    int ker25 = ker[1];
    int ker26 = ker[2];
    int ker27 = ker[3];
    int ker28 = ker[4];
    int ker29 = ker[5];
    int ker30 = ker[6];
    int ker31 = ker[7];
    
    ker += dim;
    int ker32 = ker[0];
    int ker33 = ker[1];
    int ker34 = ker[2];
    int ker35 = ker[3];
    int ker36 = ker[4];
    int ker37 = ker[5];
    int ker38 = ker[6];
    int ker39 = ker[7];
    
    ker += dim;
    int ker40 = ker[0];
    int ker41 = ker[1];
    int ker42 = ker[2];
    int ker43 = ker[3];
    int ker44 = ker[4];
    int ker45 = ker[5];
    int ker46 = ker[6];
    int ker47 = ker[7];
    
    ker += dim;
    int ker48 = ker[0];
    int ker49 = ker[1];
    int ker50 = ker[2];
    int ker51 = ker[3];
    int ker52 = ker[4];
    int ker53 = ker[5];
    int ker54 = ker[6];
    int ker55 = ker[7];
    
    ker += dim;
    int ker56 = ker[0];
    int ker57 = ker[1];
    int ker58 = ker[2];
    int ker59 = ker[3];
    int ker60 = ker[4];
    int ker61 = ker[5];
    int ker62 = ker[6];
    int ker63 = ker[7];

    int rdim = dim-7;
    int dim8 = dim-8;
    for(int j = 0; j < rdim; ++j, dst += dim, src += dim) {
        int acc0, acc1;
        for(int i = 0; i < dim8; i+=2) {
            int *srcji = src+i;
            
            acc0   = srcji[0]*ker0 ;
            acc1   = srcji[1]*ker1 ;
            acc0  += srcji[2]*ker2 ;
            acc1  += srcji[3]*ker3 ;
            acc0  += srcji[4]*ker4 ;
            acc1  += srcji[5]*ker5 ;
            acc0  += srcji[6]*ker6 ;
            acc1  += srcji[7]*ker7 ;
            srcji += dim;
            acc0  += srcji[0]*ker8 ;
            acc1  += srcji[1]*ker9 ;
            acc0  += srcji[2]*ker10;
            acc1  += srcji[3]*ker11;
            acc0  += srcji[4]*ker12;
            acc1  += srcji[5]*ker13;
            acc0  += srcji[6]*ker14;
            acc1  += srcji[7]*ker15;
            srcji += dim;
            acc0  += srcji[0]*ker16;
            acc1  += srcji[1]*ker17;
            acc0  += srcji[2]*ker18;
            acc1  += srcji[3]*ker19;
            acc0  += srcji[4]*ker20;
            acc1  += srcji[5]*ker21;
            acc0  += srcji[6]*ker22;
            acc1  += srcji[7]*ker23;
            srcji += dim;
            acc0  += srcji[0]*ker24;
            acc1  += srcji[1]*ker25;
            acc0  += srcji[2]*ker26;
            acc1  += srcji[3]*ker27;
            acc0  += srcji[4]*ker28;
            acc1  += srcji[5]*ker29;
            acc0  += srcji[6]*ker30;
            acc1  += srcji[7]*ker31;
            srcji += dim;
            acc0  += srcji[0]*ker32;
            acc1  += srcji[1]*ker33;
            acc0  += srcji[2]*ker34;
            acc1  += srcji[3]*ker35;
            acc0  += srcji[4]*ker36;
            acc1  += srcji[5]*ker37;
            acc0  += srcji[6]*ker38;
            acc1  += srcji[7]*ker39;
            srcji += dim;
            acc0  += srcji[0]*ker40;
            acc1  += srcji[1]*ker41;
            acc0  += srcji[2]*ker42;
            acc1  += srcji[3]*ker43;
            acc0  += srcji[4]*ker44;
            acc1  += srcji[5]*ker45;
            acc0  += srcji[6]*ker46;
            acc1  += srcji[7]*ker47;
            srcji += dim;
            acc0  += srcji[0]*ker48;
            acc1  += srcji[1]*ker49;
            acc0  += srcji[2]*ker50;
            acc1  += srcji[3]*ker51;
            acc0  += srcji[4]*ker52;
            acc1  += srcji[5]*ker53;
            acc0  += srcji[6]*ker54;
            acc1  += srcji[7]*ker55;
            srcji += dim;
            acc0  += srcji[0]*ker56;
            acc1  += srcji[1]*ker57;
            acc0  += srcji[2]*ker58;
            acc1  += srcji[3]*ker59;
            acc0  += srcji[4]*ker60;
            acc1  += srcji[5]*ker61;
            acc0  += srcji[6]*ker62;
            acc1  += srcji[7]*ker63;

            dst[i] = (acc0 + acc1);

////////////////////////////////////////////


            srcji = src+i+1;
            
            acc0   = srcji[0]*ker0 ;
            acc1   = srcji[1]*ker1 ;
            acc0  += srcji[2]*ker2 ;
            acc1  += srcji[3]*ker3 ;
            acc0  += srcji[4]*ker4 ;
            acc1  += srcji[5]*ker5 ;
            acc0  += srcji[6]*ker6 ;
            acc1  += srcji[7]*ker7 ;
            srcji += dim;
            acc0  += srcji[0]*ker8 ;
            acc1  += srcji[1]*ker9 ;
            acc0  += srcji[2]*ker10;
            acc1  += srcji[3]*ker11;
            acc0  += srcji[4]*ker12;
            acc1  += srcji[5]*ker13;
            acc0  += srcji[6]*ker14;
            acc1  += srcji[7]*ker15;
            srcji += dim;
            acc0  += srcji[0]*ker16;
            acc1  += srcji[1]*ker17;
            acc0  += srcji[2]*ker18;
            acc1  += srcji[3]*ker19;
            acc0  += srcji[4]*ker20;
            acc1  += srcji[5]*ker21;
            acc0  += srcji[6]*ker22;
            acc1  += srcji[7]*ker23;
            srcji += dim;
            acc0  += srcji[0]*ker24;
            acc1  += srcji[1]*ker25;
            acc0  += srcji[2]*ker26;
            acc1  += srcji[3]*ker27;
            acc0  += srcji[4]*ker28;
            acc1  += srcji[5]*ker29;
            acc0  += srcji[6]*ker30;
            acc1  += srcji[7]*ker31;
            srcji += dim;
            acc0  += srcji[0]*ker32;
            acc1  += srcji[1]*ker33;
            acc0  += srcji[2]*ker34;
            acc1  += srcji[3]*ker35;
            acc0  += srcji[4]*ker36;
            acc1  += srcji[5]*ker37;
            acc0  += srcji[6]*ker38;
            acc1  += srcji[7]*ker39;
            srcji += dim;
            acc0  += srcji[0]*ker40;
            acc1  += srcji[1]*ker41;
            acc0  += srcji[2]*ker42;
            acc1  += srcji[3]*ker43;
            acc0  += srcji[4]*ker44;
            acc1  += srcji[5]*ker45;
            acc0  += srcji[6]*ker46;
            acc1  += srcji[7]*ker47;
            srcji += dim;
            acc0  += srcji[0]*ker48;
            acc1  += srcji[1]*ker49;
            acc0  += srcji[2]*ker50;
            acc1  += srcji[3]*ker51;
            acc0  += srcji[4]*ker52;
            acc1  += srcji[5]*ker53;
            acc0  += srcji[6]*ker54;
            acc1  += srcji[7]*ker55;
            srcji += dim;
            acc0  += srcji[0]*ker56;
            acc1  += srcji[1]*ker57;
            acc0  += srcji[2]*ker58;
            acc1  += srcji[3]*ker59;
            acc0  += srcji[4]*ker60;
            acc1  += srcji[5]*ker61;
            acc0  += srcji[6]*ker62;
            acc1  += srcji[7]*ker63;

            dst[i+1] = (acc0 + acc1);
        }
            int *srcji = src+dim8;
            
            acc0   = srcji[0]*ker0 ;
            acc1   = srcji[1]*ker1 ;
            acc0  += srcji[2]*ker2 ;
            acc1  += srcji[3]*ker3 ;
            acc0  += srcji[4]*ker4 ;
            acc1  += srcji[5]*ker5 ;
            acc0  += srcji[6]*ker6 ;
            acc1  += srcji[7]*ker7 ;
            srcji += dim;
            acc0  += srcji[0]*ker8 ;
            acc1  += srcji[1]*ker9 ;
            acc0  += srcji[2]*ker10;
            acc1  += srcji[3]*ker11;
            acc0  += srcji[4]*ker12;
            acc1  += srcji[5]*ker13;
            acc0  += srcji[6]*ker14;
            acc1  += srcji[7]*ker15;
            srcji += dim;
            acc0  += srcji[0]*ker16;
            acc1  += srcji[1]*ker17;
            acc0  += srcji[2]*ker18;
            acc1  += srcji[3]*ker19;
            acc0  += srcji[4]*ker20;
            acc1  += srcji[5]*ker21;
            acc0  += srcji[6]*ker22;
            acc1  += srcji[7]*ker23;
            srcji += dim;
            acc0  += srcji[0]*ker24;
            acc1  += srcji[1]*ker25;
            acc0  += srcji[2]*ker26;
            acc1  += srcji[3]*ker27;
            acc0  += srcji[4]*ker28;
            acc1  += srcji[5]*ker29;
            acc0  += srcji[6]*ker30;
            acc1  += srcji[7]*ker31;
            srcji += dim;
            acc0  += srcji[0]*ker32;
            acc1  += srcji[1]*ker33;
            acc0  += srcji[2]*ker34;
            acc1  += srcji[3]*ker35;
            acc0  += srcji[4]*ker36;
            acc1  += srcji[5]*ker37;
            acc0  += srcji[6]*ker38;
            acc1  += srcji[7]*ker39;
            srcji += dim;
            acc0  += srcji[0]*ker40;
            acc1  += srcji[1]*ker41;
            acc0  += srcji[2]*ker42;
            acc1  += srcji[3]*ker43;
            acc0  += srcji[4]*ker44;
            acc1  += srcji[5]*ker45;
            acc0  += srcji[6]*ker46;
            acc1  += srcji[7]*ker47;
            srcji += dim;
            acc0  += srcji[0]*ker48;
            acc1  += srcji[1]*ker49;
            acc0  += srcji[2]*ker50;
            acc1  += srcji[3]*ker51;
            acc0  += srcji[4]*ker52;
            acc1  += srcji[5]*ker53;
            acc0  += srcji[6]*ker54;
            acc1  += srcji[7]*ker55;
            srcji += dim;
            acc0  += srcji[0]*ker56;
            acc1  += srcji[1]*ker57;
            acc0  += srcji[2]*ker58;
            acc1  += srcji[3]*ker59;
            acc0  += srcji[4]*ker60;
            acc1  += srcji[5]*ker61;
            acc0  += srcji[6]*ker62;
            acc1  += srcji[7]*ker63;

            dst[dim8] = (acc0 + acc1);


    }
}
*/

char conv6_descr[] = "conv6";
void conv6(int dim, int *src, int *ker,int *dst) {
    int ker0  = ker[0];
    int ker1  = ker[1];
    int ker2  = ker[2];
    int ker3  = ker[3];
    int ker4  = ker[4];
    int ker5  = ker[5];
    int ker6  = ker[6];
    int ker7  = ker[7];

    ker += dim;
    int ker8  = ker[0];
    int ker9  = ker[1];
    int ker10 = ker[2];
    int ker11 = ker[3];
    int ker12 = ker[4];
    int ker13 = ker[5];
    int ker14 = ker[6];
    int ker15 = ker[7];
    
    ker += dim;
    int ker16 = ker[0];
    int ker17 = ker[1];
    int ker18 = ker[2];
    int ker19 = ker[3];
    int ker20 = ker[4];
    int ker21 = ker[5];
    int ker22 = ker[6];
    int ker23 = ker[7];
    
    ker += dim;
    int ker24 = ker[0];
    int ker25 = ker[1];
    int ker26 = ker[2];
    int ker27 = ker[3];
    int ker28 = ker[4];
    int ker29 = ker[5];
    int ker30 = ker[6];
    int ker31 = ker[7];
    
    ker += dim;
    int ker32 = ker[0];
    int ker33 = ker[1];
    int ker34 = ker[2];
    int ker35 = ker[3];
    int ker36 = ker[4];
    int ker37 = ker[5];
    int ker38 = ker[6];
    int ker39 = ker[7];
    
    ker += dim;
    int ker40 = ker[0];
    int ker41 = ker[1];
    int ker42 = ker[2];
    int ker43 = ker[3];
    int ker44 = ker[4];
    int ker45 = ker[5];
    int ker46 = ker[6];
    int ker47 = ker[7];
    
    ker += dim;
    int ker48 = ker[0];
    int ker49 = ker[1];
    int ker50 = ker[2];
    int ker51 = ker[3];
    int ker52 = ker[4];
    int ker53 = ker[5];
    int ker54 = ker[6];
    int ker55 = ker[7];
    
    ker += dim;
    int ker56 = ker[0];
    int ker57 = ker[1];
    int ker58 = ker[2];
    int ker59 = ker[3];
    int ker60 = ker[4];
    int ker61 = ker[5];
    int ker62 = ker[6];
    int ker63 = ker[7];

    int rdim = dim-7;
    int dim8 = dim-8;
    for(int j = 0; j < rdim; ++j, dst += dim, src += dim) {
        int acc0, acc1, acc2, acc3, f0, f1;
        for(int i = 0; i < dim8; i+=2) {
            int *srcji = src+i;
            
            f0 = srcji[0];
            f1 = srcji[1];
            acc0   = f0*ker0 ;
            acc1   = f1*ker1 ;
            acc3   = f1*ker0 ;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker2 ;
            acc1  += f1*ker3 ;
            acc2   = f0*ker1 ;
            acc3  += f1*ker2 ;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker4 ;
            acc1  += f1*ker5 ;
            acc2  += f0*ker3 ;
            acc3  += f1*ker4 ;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker6 ;
            acc1  += f1*ker7 ;
            acc2  += f0*ker5 ;
            acc3  += f1*ker6 ;
            
            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker8 ;
            acc1  += f1*ker9 ;
            acc2  += f0*ker7 ;
            acc3  += f1*ker8 ;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker10;
            acc1  += f1*ker11;
            acc2  += f0*ker9 ;
            acc3  += f1*ker10;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker12;
            acc1  += f1*ker13;
            acc2  += f0*ker11;
            acc3  += f1*ker12;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker14;
            acc1  += f1*ker15;
            acc2  += f0*ker13;
            acc3  += f1*ker14;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker16;
            acc1  += f1*ker17;
            acc2  += f0*ker15;
            acc3  += f1*ker16;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker18;
            acc1  += f1*ker19;
            acc2  += f0*ker17;
            acc3  += f1*ker18;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker20;
            acc1  += f1*ker21;
            acc2  += f0*ker19;
            acc3  += f1*ker20;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker22;
            acc1  += f1*ker23;
            acc2  += f0*ker21;
            acc3  += f1*ker22;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker24;
            acc1  += f1*ker25;
            acc2  += f0*ker23;
            acc3  += f1*ker24;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker26;
            acc1  += f1*ker27;
            acc2  += f0*ker25;
            acc3  += f1*ker26;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker28;
            acc1  += f1*ker29;
            acc2  += f0*ker27;
            acc3  += f1*ker28;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker30;
            acc1  += f1*ker31;
            acc2  += f0*ker29;
            acc3  += f1*ker30;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker32;
            acc1  += f1*ker33;
            acc2  += f0*ker31;
            acc3  += f1*ker32;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker34;
            acc1  += f1*ker35;
            acc2  += f0*ker33;
            acc3  += f1*ker34;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker36;
            acc1  += f1*ker37;
            acc2  += f0*ker35;
            acc3  += f1*ker36;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker38;
            acc1  += f1*ker39;
            acc2  += f0*ker37;
            acc3  += f1*ker38;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker40;
            acc1  += f1*ker41;
            acc2  += f0*ker39;
            acc3  += f1*ker40;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker42;
            acc1  += f1*ker43;
            acc2  += f0*ker41;
            acc3  += f1*ker42;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker44;
            acc1  += f1*ker45;
            acc2  += f0*ker43;
            acc3  += f1*ker44;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker46;
            acc1  += f1*ker47;
            acc2  += f0*ker45;
            acc3  += f1*ker46;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker48;
            acc1  += f1*ker49;
            acc2  += f0*ker47;
            acc3  += f1*ker48;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker50;
            acc1  += f1*ker51;
            acc2  += f0*ker49;
            acc3  += f1*ker50;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker52;
            acc1  += f1*ker53;
            acc2  += f0*ker51;
            acc3  += f1*ker52;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker54;
            acc1  += f1*ker55;
            acc2  += f0*ker53;
            acc3  += f1*ker54;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker56;
            acc1  += f1*ker57;
            acc2  += f0*ker55;
            acc3  += f1*ker56;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker58;
            acc1  += f1*ker59;
            acc2  += f0*ker57;
            acc3  += f1*ker58;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker60;
            acc1  += f1*ker61;
            acc2  += f0*ker59;
            acc3  += f1*ker60;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker62;
            acc1  += f1*ker63;
            acc2  += f0*ker61;
            acc3  += f1*ker62;

            acc2  += srcji[8]*ker63;

            dst[i]   = (acc0 + acc1);
            dst[i+1] = (acc2 + acc3);
        }
            int *srcji = src+dim8;
            
            f0 = srcji[0];
            f1 = srcji[1];
            acc0   = f0*ker0 ;
            acc1   = f1*ker1 ;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker2 ;
            acc1  += f1*ker3 ;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker4 ;
            acc1  += f1*ker5 ;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker6 ;
            acc1  += f1*ker7 ;
            
            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker8 ;
            acc1  += f1*ker9 ;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker10;
            acc1  += f1*ker11;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker12;
            acc1  += f1*ker13;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker14;
            acc1  += f1*ker15;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker16;
            acc1  += f1*ker17;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker18;
            acc1  += f1*ker19;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker20;
            acc1  += f1*ker21;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker22;
            acc1  += f1*ker23;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker24;
            acc1  += f1*ker25;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker26;
            acc1  += f1*ker27;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker28;
            acc1  += f1*ker29;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker30;
            acc1  += f1*ker31;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker32;
            acc1  += f1*ker33;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker34;
            acc1  += f1*ker35;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker36;
            acc1  += f1*ker37;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker38;
            acc1  += f1*ker39;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker40;
            acc1  += f1*ker41;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker42;
            acc1  += f1*ker43;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker44;
            acc1  += f1*ker45;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker46;
            acc1  += f1*ker47;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker48;
            acc1  += f1*ker49;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker50;
            acc1  += f1*ker51;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker52;
            acc1  += f1*ker53;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker54;
            acc1  += f1*ker55;

            srcji += dim;
            f0 = srcji[0];
            f1 = srcji[1];
            acc0  += f0*ker56;
            acc1  += f1*ker57;
            f0 = srcji[2];
            f1 = srcji[3];
            acc0  += f0*ker58;
            acc1  += f1*ker59;
            f0 = srcji[4];
            f1 = srcji[5];
            acc0  += f0*ker60;
            acc1  += f1*ker61;
            f0 = srcji[6];
            f1 = srcji[7];
            acc0  += f0*ker62;
            acc1  += f1*ker63;

            dst[dim8] = (acc0+acc1);
    }
}

/* 
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Dot product: Current working version";
void convolution(int dim,int *src, int *ker,int *dst) 
{
    conv6(dim, src, ker, dst);
}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);   
    add_conv_function(&convolution, convolution_descr);   
    /* ... Register additional test functions here */
    add_conv_function(&conv6, conv6_descr);
//    add_conv_function(&conv5, conv5_descr);
    add_conv_function(&conv4, conv4_descr);
/*    add_conv_function(&conv3, conv3_descr);
    add_conv_function(&conv2, conv2_descr);*/
}

/*********************
 * MATRIX MULTIP KERNEL
 *********************/

/******************************************************
 * Your different versions of the matrix multiplications  go here
 ******************************************************/

/* 
 * naive_matrix_multiplication - The naive baseline version of matrix multiplication 
 */

char naive_matrix_multiplication_descr[] =
    "Naive_matrix_multiplication: Naive baseline implementation";
void naive_matrix_multiplication(int dim,int *src, int *src2,int *dst) {
    int i,j,k;

    for(i = 0; i < dim; i++)
        for(j = 0; j < dim; j++) {
            dst[j*dim+i]=0;
            for(k = 0; k < dim; k++) 
            dst[j*dim+i] = dst[j*dim+i] + src[j*dim+k]*src2[i+k*dim];
        }    
}

char matmul_optimized_descr[] = "matmul_optimized";
void matmul_optimized(int n, int *src, int *src2, int *dst) {
    int i, j, k, r, nd = n >> 5, in = 0, kn = n;
    int *dstij, *src2ij, *src2i = src2;
    
    for (i = 0; i < n; i++) {
        r  = src[in];
        dstij  = dst+in;
        src2ij = src2i;
        for (j = 0; j < nd; j++) {
            dstij[0 ] = r * src2ij[0 ];
            dstij[1 ] = r * src2ij[1 ];
            dstij[2 ] = r * src2ij[2 ];
            dstij[3 ] = r * src2ij[3 ];
            dstij[4 ] = r * src2ij[4 ];
            dstij[5 ] = r * src2ij[5 ];
            dstij[6 ] = r * src2ij[6 ];
            dstij[7 ] = r * src2ij[7 ];
            dstij[8 ] = r * src2ij[8 ];
            dstij[9 ] = r * src2ij[9 ];
            dstij[10] = r * src2ij[10];
            dstij[11] = r * src2ij[11];
            dstij[12] = r * src2ij[12];
            dstij[13] = r * src2ij[13];
            dstij[14] = r * src2ij[14];
            dstij[15] = r * src2ij[15];
            dstij[16] = r * src2ij[16];
            dstij[17] = r * src2ij[17];
            dstij[18] = r * src2ij[18];
            dstij[19] = r * src2ij[19];
            dstij[20] = r * src2ij[20];
            dstij[21] = r * src2ij[21];
            dstij[22] = r * src2ij[22];
            dstij[23] = r * src2ij[23];
            dstij[24] = r * src2ij[24];
            dstij[25] = r * src2ij[25];
            dstij[26] = r * src2ij[26];
            dstij[27] = r * src2ij[27];
            dstij[28] = r * src2ij[28];
            dstij[29] = r * src2ij[29];
            dstij[30] = r * src2ij[30];
            dstij[31] = r * src2ij[31];

            dstij  += 32;
            src2ij += 32;
        }
        in += n;
    }

    for (k = 1; k < n; k++) {
        in = 0;
        src2i = src2 + kn;
        for (i = 0; i < n; i++) {
            r  = src[in+k];
            dstij  = dst+in;
            src2ij = src2i;
            for (j = 0; j < nd; j++) {
                dstij[0 ] += r * src2ij[0 ];
                dstij[1 ] += r * src2ij[1 ];
                dstij[2 ] += r * src2ij[2 ];
                dstij[3 ] += r * src2ij[3 ];
                dstij[4 ] += r * src2ij[4 ];
                dstij[5 ] += r * src2ij[5 ];
                dstij[6 ] += r * src2ij[6 ];
                dstij[7 ] += r * src2ij[7 ];
                dstij[8 ] += r * src2ij[8 ];
                dstij[9 ] += r * src2ij[9 ];
                dstij[10] += r * src2ij[10];
                dstij[11] += r * src2ij[11];
                dstij[12] += r * src2ij[12];
                dstij[13] += r * src2ij[13];
                dstij[14] += r * src2ij[14];
                dstij[15] += r * src2ij[15];
                dstij[16] += r * src2ij[16];
                dstij[17] += r * src2ij[17];
                dstij[18] += r * src2ij[18];
                dstij[19] += r * src2ij[19];
                dstij[20] += r * src2ij[20];
                dstij[21] += r * src2ij[21];
                dstij[22] += r * src2ij[22];
                dstij[23] += r * src2ij[23];
                dstij[24] += r * src2ij[24];
                dstij[25] += r * src2ij[25];
                dstij[26] += r * src2ij[26];
                dstij[27] += r * src2ij[27];
                dstij[28] += r * src2ij[28];
                dstij[29] += r * src2ij[29];
                dstij[30] += r * src2ij[30];
                dstij[31] += r * src2ij[31];

                dstij  += 32;
                src2ij += 32;
            }
            in += n;
        }
        kn += n;
    }
}

/* 
 * matrix_multiplication - Your current working version of matrix_multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char matrix_multiplication_descr[] = "Matrix multiplications: Current working version";
void matrix_multiplication(int dim,int *src, int *src2,int *dst) 
{
    matmul_optimized(dim,src,src2,dst);
}

/*********************************************************************
 * register_matrix_multiplication_functions - Register all of your different versions
 *     of the matrix multiplication  with the driver by calling the
 *     add_matrix_multiplication_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_matrix_multiplication_functions() {
    add_matrix_multiplication_function(&naive_matrix_multiplication,
        naive_matrix_multiplication_descr);   
    add_matrix_multiplication_function(&matrix_multiplication,
        matrix_multiplication_descr);   
    /* ... Register additional test functions here */
    add_matrix_multiplication_function(&matmul_optimized, matmul_optimized_descr);   

}

