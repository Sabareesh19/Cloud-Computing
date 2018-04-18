#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <immintrin.h>


//FILL ME IN

long TRILLION_DATA = 1000000000;
int THREAD_COUNT = 1;
char FLOPS = 'F';

void* FLOPS_Calculation(int* arg)
{

   //Calculation of Single Precision
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

   //Calculation of Half Precision
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

   //Calculation of SIngle Precision
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

    //Calculation of Double Precision
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
   pthread_exit(NULL);
}

//Clock using pthreads
void clock_operations_per_sec(){
    pthread_t thread_id[THREAD_COUNT];
    int thread[THREAD_COUNT];
    
    double start_time, end_time;
    start_time = clock();
    end_time = clock();
    //gettimeofday(start_time, NULL );
    
    if(FLOPS == 'F') {
        for (int i=0;i<THREAD_COUNT;i++) {
            thread[i] = pthread_create(&(thread_id[i]),NULL,FLOPS_Calculation,NULL);
        }
    } 

    for (int i=0;i<THREAD_COUNT;i++) {
      pthread_join(thread_id[i], NULL);
    }
    
    //gettimeofday(end_time, NULL);
    double total_time = ((end_time+(end_time/1000000.0))-(start_time+(start_time/1000000.0)));
    double ops;
	if (FLOPS == 'F') {
		ops = (THREAD_COUNT*TRILLION_DATA*26)/total_time;
	} 
	printf("CPU, %d threads, speed = %.2lf Giga %s\n",THREAD_COUNT,ops/1000000000,FLOPS == 'F'?"FLOPS/sec":"IOPS/sec");

    
}

int main(int argc, char *argv[]){
   int arg;
    while((arg=getopt(argc, argv, "ifo:t:")) != -1) {
        switch(arg) {
            
            case 'f':
            FLOPS='F'; // for FLOPS calculation
            break;
            case 'o':
            TRILLION_DATA=atoi(optarg);
            case 't':
            THREAD_COUNT=atoi(optarg);
            break;
            default:
            break;
        }
    }
    calculate_operations_per_sec();
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


