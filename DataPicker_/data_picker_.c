#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


#define PntNum 7200
#define PI2 6.283184
#define PI 3.141592
#define deg2rad 0.017453288
float elecangle[PntNum];
float elecangle_noise[PntNum];



/*-----------------------------------------------------------------------*/
/*                     Variables related to sampler                      */
/*-----------------------------------------------------------------------*/
/**
 * @brief structure def
 */
struct sampler{
    float interval ;
    float temp_elecangle ;
    float databuf[6];
    int anglestate_est;
    int anglestate_est_old;
    int filtnum;
    int sample_trig;
    int anglestate_estimator_run;
} SP;
//struct sampler SP; // both experssions are fine.


int anglestate_estimator(struct sampler *SP, int i);
int data_sampler(struct sampler *SP, float tempdata);

void initsampler(struct sampler *SP){
    SP->interval = 60 *  3.141592/180;
    SP->temp_elecangle = 0;
    SP->anglestate_est = 0;
    SP->anglestate_est_old = 0;
    SP->filtnum = 5;
    SP->sample_trig = 0;
    SP->anglestate_estimator_run = 1;

    for(int i = 0; i < 6; i++) {
        SP->databuf[i] = 0.;
    }
}
/*-----------------------------------------------------------------------*/



void main(void){

    initsampler(&SP);

    for (int i = 0; i < 7200; i++) {
        /*-----------------------------------------------------------------------*/
        /**
        * @brief Parts for generating signals. If u have targets, u don;t need this part.
        */
        elecangle[i]       = (float) ((360- (float)i/10) * deg2rad) ;  /* driection 1*/ 
        //elecangle[i]       = (float) ((float)i/10 * deg2rad) ;    /* driection 2*/ 
        elecangle_noise[i] = (float) ((float)rand()-16500) / 10000000 ;  /* noise */
        elecangle[i]       = elecangle[i] + 1.*elecangle_noise[i];
        
        /**
         * @brief outputs limitation
         */
        int q = 0;
        q = elecangle[i] / PI2;
        if(elecangle[i]>(PI2*(float)q)) {elecangle[i] = elecangle[i]-(PI2*(float)q);}
        if(elecangle[i]>PI )   {elecangle[i] = elecangle[i]-PI2;}
        //printf("here 3 %.7f    %d \n", elecangle[i]* 1/deg2rad, (int)(elecangle[i])   );    
        /*-----------------------------------------------------------------------*/



        /*-----------------------------------------------------------------------*/
        /*                          Main algorithm                               */
        /*-----------------------------------------------------------------------*/
        /*
        * Data picking trigger signal
        */
        float tempdata;
        tempdata = elecangle[i];
        if(anglestate_estimator(&SP, i)){
            data_sampler(&SP, tempdata);
        }
        
        /*
        * Data picking when state is changed
        */
    }

}


int estimate_when = 9999;
int estimator_cnt = 0;
int anglestate_estimator(struct sampler *SP, int i){
    estimator_cnt++;
    SP->temp_elecangle = elecangle[i];

    SP->anglestate_est_old = SP->anglestate_est;
    SP->anglestate_est = (floor)((SP->temp_elecangle)/SP->interval) ; // quotient

    // [필터 방법 1]
    // 필터 넣고 싶으면 anglestate_est 좌우 +- 0.05 deg에서 state est해보고,
    // 모두 같을 경우만 est 업데이트.

    // [필터 방법 2]
    // 한번 트리거 되고 해당 state 무시. 이거 적용.

    if ((SP->anglestate_est != SP->anglestate_est_old) &&  abs(estimator_cnt - estimate_when ) > SP->filtnum ){
        printf("anglestate_est %d  \n", SP->anglestate_est);
        printf("anglestate_est_old %d  \n", SP->anglestate_est_old);

        estimate_when = estimator_cnt;
        SP->sample_trig = 1;
    }
    else {
        SP->sample_trig = 0;
    }

    return SP->sample_trig;
}

int bufcnt = 0;
int data_sampler(struct sampler *SP, float tempdata){
    bufcnt ++;
    
    SP->databuf[bufcnt] = tempdata;
    if (bufcnt > 6-1){ bufcnt = 0; }
    printf("here 2 %.4f \n", SP->databuf[bufcnt]);    

    return 0;
}
