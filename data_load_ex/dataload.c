#include <stdio.h>
#include <math.h>
#include <string.h>

#define DataNum 24

int data_cnt; 

typedef struct {
    float D1[DataNum];
    float D2[DataNum];
    float D3[DataNum];
    float D4[DataNum];
    float D5[DataNum];
    float D6[DataNum];
    float D7[DataNum];
} csvdata_;    

int read_data(csvdata_ *csvdata) {
    const int DataRows = DataNum, DataColumns = 7;
    int DataRowsIdx = 0;
    char DataReceiveChar[2048];
    float DataReceive[2048] = {0.1f,};
    int dataidx;
    float sum;
    char *DataSplited;
    FILE *DataFile = NULL;

    DataFile = fopen("data.csv", "r" );

    if( DataFile != NULL ){   
        while( !feof( DataFile ) ){
            fgets( DataReceiveChar, 2048, DataFile );          
            
            dataidx=0;
            DataSplited = strtok(DataReceiveChar, ",");
            while(DataSplited != NULL){
                DataReceive[dataidx]=atof(DataSplited);  //atof , atoi
                dataidx++;
                DataSplited=strtok(NULL, ",");
            }


            if (DataRowsIdx < DataNum){  //하번 더 출력돼서 이렇게 해줘야 갯수에 맞게 출력됨.
                csvdata->D1[DataRowsIdx]     = DataReceive[0];
                csvdata->D2[DataRowsIdx]     = DataReceive[1];
                csvdata->D3[DataRowsIdx]     = DataReceive[2];
                csvdata->D4[DataRowsIdx]     = DataReceive[3];
                csvdata->D5[DataRowsIdx]     = DataReceive[4];
                csvdata->D6[DataRowsIdx]     = DataReceive[5];
                csvdata->D7[DataRowsIdx]     = DataReceive[6];
        
                DataRowsIdx +=1;
            }
        }     
    }
    fclose( DataFile );
    printf("Data is loaded ! \n\n");
}


void main(void)
{
    
    //================================================================
    //                         Data process 
    //================================================================
    // References
    //https://steemit.com/kr-dev/@codingman/c-csv-strtok--1553126583583
    //https://stackoverflow.com/questions/41125193/using-fscanf-to-read-from-a-csv-file-in-c
    //https://modoocode.com/123
    csvdata_ csvdata1;
    read_data(&csvdata1);
    //================================================================


    for(int i = 0 ; i < DataNum ; i++){
        float D1_       =  csvdata1.D1[i];
        float D2_       =  csvdata1.D2[i];
        float D3_       =  csvdata1.D3[i];
        float D4_       =  csvdata1.D4[i];
        float D5_       =  csvdata1.D5[i];
        float D6_       =  csvdata1.D6[i];
        float D7_       =  csvdata1.D7[i];

        printf("D1_  :  %.4f |  D7_  :  %.4f \n", D1_, D7_);
    }
   
}
