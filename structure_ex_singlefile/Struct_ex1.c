#include <stdio.h>
#include <string.h>



struct ExStruct_ {    
    float Ex1;
    float Ex2[6];
} ExStruct;     

struct ExStruct_ ExStruct = 
{ 
    .Ex1 = 0.1 ,
    .Ex2 = {0.2,0.3,0.4,0.5,0.6,0.7}

};

//===================================
//           Declaration
//===================================

void ExFunc(struct ExStruct_ *ExStruct);

//===================================
//             Main
//===================================
void main(void)
{
    ExFunc(&ExStruct);
}


//===================================
//           Definition
//===================================

void ExFunc(struct ExStruct_ *ExStruct){

    printf("===> ExStruct.Ex1 Value :   %.4f  \n", ExStruct->Ex1);
    
}
