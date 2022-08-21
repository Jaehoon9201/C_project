

typedef struct ExStruct_ {    
    float Ex1;
    float Ex2[6];
} ExStruct;     
extern ExStruct ExStruct1;

// struct ExStruct_ ExStruct1 = 
// { 
//     .Ex1 = 0.1 ,
//     .Ex2 = {0.2,0.3,0.4,0.5,0.6,0.7}

// };


//===================================
//           Declaration
//===================================
void ExFunc(struct ExStruct_ *ExStruct);


