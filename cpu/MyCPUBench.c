#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <immintrin.h>


//FILL ME IN

char **number_of_arguments;
char SELECT = 'Q';
int NUMBER_OF_THREADS = 1;
long TRILLION_DATA = 1000000000;

//Calculation of Quarter Precision
void* Quarter_precision(void* arg)
{
   if(strcmp(number_of_arguments[1],"Q") == 0) 
   {
   for(int i = 0;i <= TRILLION_DATA;i++)
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
     }
   }
}


//Calculation of Half Precision
void* Half_precision(void* arg)
{  
   if(strcmp(number_of_arguments[1],"H") == 0) 
   {
   for(int i = 0;i <= TRILLION_DATA;i++)
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
    
      }
    }
}

//Calculation of Single Precision
void* single_precision(void* arg)
{  
   if(strcmp(number_of_arguments[1],"S") == 0)  
   {  
   for(int i = 0;i <= TRILLION_DATA;i++)
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
      }
    }
}

//Calculation of Double Precision
void* double_precision(void* arg)
{  
   if(strcmp(number_of_arguments[1],"D") == 0)  
   {    
   for(int i = 0;i <= TRILLION_DATA;i++)
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
       
     if(strcmp(number_of_arguments[1],"Q") == 0) 
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,Quarter_precision,NULL);
            
        }
    } 

     if(strcmp(number_of_arguments[1],"H") == 0) 
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,Half_precision,NULL);
        }
    } 

    if(strcmp(number_of_arguments[1],"S") == 0) 
    {
        for (int i=0;i<atoi(number_of_arguments[2]);i++)
        {
            thread[i] = pthread_create(&(pthread_id[i]),NULL,single_precision,NULL);
        }
    } 

      if(strcmp(number_of_arguments[1],"D") == 0) 
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
    flops_ops = (TRILLION_DATA*100)/(total_time*atoi(number_of_arguments[2]));
    flops_ops = flops_ops/1000000000;
    printf("The total time consumed by the CPU is %lf \n ", total_time);
    printf("The speed of the processor is %lf GigaOPS \n ", flops_ops);
    printf("The number of threads executed is %d \n", atoi(number_of_arguments[2]));
    
}

int main(int argc, char *argv[]){
    
    number_of_arguments = argv;
    clock_operations_per_sec();
    return 0;
}



