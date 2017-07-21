#include <stdio.h>
#include "judge.h"
#define POINT_F(x) (*((float*)(x)))
extern void zipfloat2array3(char *p,char id,float pos0,float pos1,float pos2);

void zipfloat2array3(char *p,char id,float pos0,float pos1,float pos2){
    for(int i = 0;i<32;i++){
        p[i] = 0;        
    }
    p[0] = 0xA1;
    p[1] = id;
    POINT_F(p+2) = pos0;
    POINT_F(p+6) = pos1;
    POINT_F(p+10) = pos2;
    fast_GET_CRC8((unsigned char * )p);
    return;
}
