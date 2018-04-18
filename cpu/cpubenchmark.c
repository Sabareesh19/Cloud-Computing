#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <immintrin.h>


//strcmp(number_of_arguments[1] - To indicate the Type of precision
//atoi(number_of_arguments[2] - To indicate the number of threads


//FILL ME IN

char **number_of_arguments;
//char SELECT = 'Q';
int NUMBER_OF_THREADS = 1;
long TRILLION_DATA = 1000000000;

//Calculation of Quarter Precision
void* Quarter_precision(void* arg)
{
   if(strcmp(number_of_arguments[1],"QP") == 0) 
   {
   
   for(int i = 0;i <= TRILLION_DATA/atoi(number_of_arguments[2]);i++)
     {
       char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
     }
   }
}


//Calculation of Half Precision
void* Half_precision(void* arg)
{  
   if(strcmp(number_of_arguments[1],"HP") == 0) 
   {
   for(int i = 0;i <= TRILLION_DATA/atoi(number_of_arguments[2]);i++)
     {
       short a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
    
      }
    }
}

//Calculation of Single Precision
void* single_precision(void* arg)
{  
   if(strcmp(number_of_arguments[1],"SP") == 0)  
   {  
   for(int i = 0;i <= TRILLION_DATA/atoi(number_of_arguments[2]);i++)
     {
       int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
      }
    }
}

//Calculation of Double Precision
void* double_precision(void* arg)
{  
   if(strcmp(number_of_arguments[1],"DP") == 0)  
   {    
   for(int i = 0;i <= TRILLION_DATA/atoi(number_of_arguments[2]);i++)
      {
       double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
       a11 = (a1+a2+a3-a4+a5+a6+a7+a8+a9+a10)*a1;
     
      }
    }  
}

//pthread Implementation for the clock execution

void clock_operations_per_sec()
{

//Calculating time using clock() functions
    double start_time, end_time;
    double flops_ops;
    start_time = clock();  
    pthread_t pthread_id[atoi(number_of_arguments[2])];
    int thread[atoi(number_of_arguments[2])];
       
     if(strcmp(number_of_arguments[1],"QP") == 0) 
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,Quarter_precision,NULL);
            
        }
    } 

     if(strcmp(number_of_arguments[1],"HP") == 0) 
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,Half_precision,NULL);
        }
    } 

    if(strcmp(number_of_arguments[1],"SP") == 0) 
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,single_precision,NULL);
        }
    } 

      if(strcmp(number_of_arguments[1],"DP") == 0)  
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,double_precision,NULL);
        }
    } 

    for (int i=0;i<atoi(number_of_arguments[2]);i++) 
    {
            pthread_join(pthread_id[i], NULL);
      
    }

    end_time = clock();
    double total_time = (end_time-start_time)/CLOCKS_PER_SEC; 	
    
    flops_ops = (TRILLION_DATA*250*atoi(number_of_arguments[2]))/(total_time); //atoi(number_of_arguments[2] - indicates the number of threads
    flops_ops = flops_ops/1000000000;
    printf("*********************************************************\n");
    printf("Workload      Concurrency      MyCPUBench(GigaOPS) \n");
    printf("*********************************************************\n");
    printf( "%s \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),flops_ops);
    //printf("The total time consumed by the CPU is %lf \n ", total_time);
    //printf("The speed of the processor is %lf GigaOPS \n ", flops_ops);
    //printf("The number of threads executed is %d \n", atoi(number_of_arguments[2]));
    
}

int main(int argc, char *argv[]){
    
    number_of_arguments = argv;
    clock_operations_per_sec();
    return 0;
}




































    
    
    
   // double cpu_clock_time,start,end;
   // start = clock();
   // end = clock();
   // printf("%d",a4);
   // cpu_clock_time = (end - start)/CLOCKS_PER_SEC;
    //printf("The clock time is %f",cpu_clock_time);
   // return 0;

//}













































//FILL ME IN


