#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

long GB_DATA = 1000000000;
int BLOCK_SIZE = 8;
int NUMBER_OF_ITERATIONS = 1000;
int NUMBER_OF_THREADS =1;
char TYPE = 'W';

//To perfrom Sequential Read Write
struct sequential_read_write{
   char * dstn;
   char * src;
};

void* sequential_read_write(void* arg){
struct  sequential_read_write *RW_Seq = (struct  sequential_read_write *)arg;
for(int i;i<NUMBER_OF_ITERATIONS;i++)
{
  memcpy(RW_Seq -> dstn, RW_Seq -> src, BLOCK_SIZE);
  
}
//pthread_exit(NULL);
}

//To perform Random Read Write
struct random_read_write{
   char * dstn;
   char * src;
   char random_operation;
};
void* random_read_write(void* arg){
struct random_read_write *RW_random = (struct random_read_write *)arg;

for(int i;i<NUMBER_OF_ITERATIONS;i++)
{
  memcpy(RW_random -> random_operation, RW_random -> src, BLOCK_SIZE);
  
}
//pthread_exit(NULL);
}

void print_result(double total_time, double throughput) {
   
    if (TYPE=='W') {
        if (BLOCK_SIZE==8) {
            printf("Memory, Latency -> Read write operations, 8B block size, %d thread - %.6lf us\n",NUMBER_OF_THREADS,(total_time/(NUMBER_OF_ITERATIONS*BLOCK_SIZE))*1000000);
        } else if (BLOCK_SIZE==8192){
            printf("Memory, Throughput -> Read write operations, 8KB block size, %d thread - %.2lf MB/sec\n",NUMBER_OF_THREADS,throughput/1048576);
        } else if (BLOCK_SIZE==8388608) {
            printf("Memory, Throughput -> Read write operations, 8MB block size, %d thread - %.2lf MB/sec\n",NUMBER_OF_THREADS,throughput/1048576);
        } else {
            printf("Memory, Throughput -> Read write operations, 80MB block size, %d thread - %.2lf MB/sec\n",NUMBER_OF_THREADS,throughput/1048576);
        }
    } 
    else {
        if (BLOCK_SIZE==8) {
            printf("Memory, Latency -> Write random operations, 8B block size, %d thread - %.6lf us\n",NUMBER_OF_THREADS,(total_time/(NUMBER_OF_ITERATIONS*BLOCK_SIZE))*1000000);
        } else if (BLOCK_SIZE==8192){
            printf("Memory, Throughput -> Write random operations, 8KB block size, %d thread - %.2lf MB/sec\n",NUMBER_OF_THREADS,throughput/1048576);
        } else if (BLOCK_SIZE==8388608) {
            printf("Memory, Throughput -> Write random operations, 8MB block size, %d thread - %.2lf MB/sec\n",NUMBER_OF_THREADS,throughput/1048576);
        } else {
            printf("Memory, Throughput -> Write random operations, 80MB block size, %d thread - %.2lf MB/sec\n",NUMBER_OF_THREADS,throughput/1048576);
        }
    }

}

void calculate_memory_benchmark(){
    char * source = (char *)malloc(BLOCK_SIZE*NUMBER_OF_ITERATIONS);
    char * dest = (char *)malloc(BLOCK_SIZE);
    
    memset(source, 2, BLOCK_SIZE*NUMBER_OF_ITERATIONS);
    memset(dest, 1, BLOCK_SIZE);
    
    struct sequential_read_write{
     char * dstn;
     char * src;
    };

    struct random_read_write{
      char * dstn;
      char * src;
      int random_operation;
    };
    
    struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL );

    pthread_t thread_id[NUMBER_OF_THREADS];
    int thread[NUMBER_OF_THREADS]; int i;
    if(TYPE == 'W') {
    struct  sequential_read_write *RW_Seq;
        for (i=0;i<NUMBER_OF_THREADS;i++) {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_read_write,(void *)&RW_Seq);
        }
    } 

     else {
      struct random_read_write *RW_random;
        for (i=0;i<NUMBER_OF_THREADS;i++) {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_read_write,RW_random);
        }
    }
    for (i=0;i<NUMBER_OF_THREADS;i++) {
      pthread_join(thread_id[i], NULL);
    }
    
    gettimeofday(&end_time, NULL);
	double total_time = ((end_time.tv_sec+(end_time.tv_usec/1000000.0))-(start_time.tv_sec+(start_time.tv_usec/1000000.0)));
	
    double bytes_accessed = (double) (BLOCK_SIZE*NUMBER_OF_ITERATIONS*NUMBER_OF_THREADS);
	double throughput = bytes_accessed/total_time;
    print_result(total_time,throughput);
}


int main(int argc, char *argv[]){
    int arg;
printf("\nmsin\n");
   //while((arg=getopt(argc, argv, "wsro:t:b:")) != -1) {
        switch(arg) {
            case 'w':
            TYPE='W'; // for sequential read-write
            break;
            case 's':
            TYPE='S'; // for random read write
            break;
            //case 'r':
            //TYPE='R'; // for random write
            //break;
            //case 'o':
            //NUMBER_OF_ITERATIONS=atoi(optarg);
            //break;
            //case 't':
            //THREAD_COUNT=atoi(optarg);
           // break;
            //case 'b':
            //BLOCK=atoi(optarg);
            //break;
            default:
            break;
        }

    //printf("The loop is executed \n ");
    calculate_memory_benchmark();
    return 0;

}





