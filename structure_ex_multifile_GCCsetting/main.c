#include <stdio.h>
#include <string.h>
#include "struct_ex.h"

//===================================
//             Main
//===================================
// ExStruct ExStruct1;

struct ExStruct_ ExStruct1 = 
{ 
    .Ex1 = 0.1 ,
    .Ex2 = {0.2,0.3,0.4,0.5,0.6,0.7}

};


void main(void)
{
    ExFunc(&ExStruct1);
}

 