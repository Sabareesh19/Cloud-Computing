#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

int NUMBER_OF_THREADS = 1;
long NUMBER_OF_ITERATIONS = 10000000;
int BLOCK_SIZE = 8;
char SELECT = 'W';

//Reading the file with sequential write access pattern
void* sequential_write_access(void* arg)
{
      FILE * fileptr;
      fileptr = fopen("file.text","w");
      if(fileptr == NULL)
      {
        exit(1);
      }
      char * fptr1 = (char*)malloc(1000*sizeof(int));
      for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
      { 
        fwrite(fptr1,BLOCK_SIZE,2,fileptr);
      }
  fclose(fileptr);
  pthread_exit(NULL);
}


//Reading the file with sequential read access pattern
void* sequential_read_access(void* arg){
      FILE * fileptr;
      fileptr = fopen("file.text","r");
      if(fileptr == NULL)
      {
       exit(1);
      }
      char * fptr1 = (char*)malloc(1000*sizeof(int));
      for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
      { 
        fread(fptr1,BLOCK_SIZE,2,fileptr);
      }
  fclose(fileptr);
  pthread_exit(NULL);
}


//Reading the file with random write access pattern
void* random_write_access(void* arg){
      FILE * fileptr;
      fileptr = fopen("file.text","w");
      if(fileptr == NULL)
      {
       exit(1);
      }
      char * fptr1 = (char*)malloc(1000*sizeof(int));
      for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
      { 
        int random_operation = rand()%BLOCK_SIZE;
        fseek(fileptr,random_operation,SEEK_SET);
        fwrite(fptr1,BLOCK_SIZE,2,fileptr);
      }
   fclose(fileptr);
   pthread_exit(NULL);
}


//Reading the file with random read access pattern
void* random_read_access(void* arg){
     FILE * fileptr;
     fileptr = fopen("file.text","r");
     if(fileptr == NULL)
     {
      exit(1);
     }
     char * fptr1 = (char*)malloc(1000*sizeof(int));
     for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
     { 
       int random_operation = rand()%BLOCK_SIZE;
       fseek(fileptr,random_operation,SEEK_SET);
       fread(fptr1,BLOCK_SIZE,2,fileptr);
     }
    fclose(fileptr);
    pthread_exit(NULL);
}

void MyDiskbench_results(double total_time, double throughput, double latency) {
   
    if (SELECT=='W') 
    {
       
	if (BLOCK_SIZE==1000)
        {
            printf("The latency of the disk for the Sequential write access pattern, 1KB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential write access pattern, 1KB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==1000000) 
        {
            printf("The latency of the disk for the Sequential write access pattern, 1MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential write access pattern, 1MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==10000000)
        {
            printf("The latency of the disk for the Sequential write access pattern, 10B block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential write access pattern, 10MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        } 
    
    }
    else if (SELECT=='S') 
    {
        if (BLOCK_SIZE==1000)
        {
            printf("The latency of the disk for the Sequential read access pattern, 1KB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential read access pattern, 1KB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==1000000)
	{
            printf("The latency of the disk for the Sequential read access pattern, 1MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential read access pattern, 1MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==10000000) 
        {
            printf("The latency of the disk for the Sequential read access pattern, 10MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential read access pattern, 10MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        } 
    } 
    else if (SELECT=='R') 
    {
         if (BLOCK_SIZE==1000)
        {
            printf("The latency of the disk for the Random write access pattern, 1KB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random write access pattern, 1KB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==1000000)
	{
            printf("The latency of the disk for the Random write access pattern, 1MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random write access pattern, 1MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==10000000) 
        {
            printf("The latency of the disk for the Random write access pattern, 10MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random write access pattern, 10MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        } 
    } 
    else 
    {
        if (BLOCK_SIZE==1000)
        {
            printf("The latency of the disk for the Random read access pattern, 1KB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random read access pattern, 1KB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==1000000)
	{
            printf("The latency of the disk for the Random read access pattern, 1MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random read access pattern, 1MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==10000000) 
        {
            printf("The latency of the disk for the Random read access pattern, 10MB block size, %d thread - %lf ms\n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random read access pattern, 10MB block size, %d thread - %lf MB/sec\n",NUMBER_OF_THREADS,throughput);
        } 
    }

}

void MyDiskBench() 
{
       FILE *fileptr;
       char *fptr1 = (char *)malloc(BLOCK_SIZE*100000);
       fileptr = fopen( "file.txt" , "w" );
       fwrite(fptr1,BLOCK_SIZE,2,fileptr);
       
       double start,end,total_time;
      start = clock();	
       
       //struct timeval start_time, end_time;
       //gettimeofday(&start_time, NULL );
       pthread_t thread_id[NUMBER_OF_THREADS];
       int thread[NUMBER_OF_THREADS]; 
       if(SELECT == 'W') 
       {
          for (int i=0;i<NUMBER_OF_THREADS;i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_write_access,fileptr);
          }
       } 
       else if (SELECT == 'S')
       {
          for (int i=0;i<NUMBER_OF_THREADS;i++)
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_read_access,fileptr);
          }
       } 
       else if (SELECT == 'R')
       {
        for (int i=0;i<NUMBER_OF_THREADS;i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_write_access,fileptr);
          }
       }
       else  
       {
        for (int i=0;i<NUMBER_OF_THREADS;i++)
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_read_access,fileptr);
          }
        }
      for (int i=0;i<NUMBER_OF_THREADS;i++)
      {
      pthread_join(thread_id[i], NULL);
      }
      
      end = clock();
      //gettimeofday(&end_time, NULL);
      //double total_time = ((end_time.tv_sec+(end_time.tv_usec/1000000.0))-(start_time.tv_sec+(start_time.tv_usec/1000000.0)));
      total_time = (end - start)/CLOCKS_PER_SEC;
      printf("The total time taken is %f \n ",total_time);
      double throughput = (NUMBER_OF_ITERATIONS*BLOCK_SIZE*NUMBER_OF_THREADS)/total_time;
      throughput = throughput/1000000;
      double latency = (total_time/(NUMBER_OF_ITERATIONS*BLOCK_SIZE))*1000000;
      printf("The latency is %f \n ",latency);

      MyDiskbench_results(total_time,throughput,latency);

}

int main(int argc, char *argv[]){
    int arg;
    while((arg=getopt(argc, argv, "wsreo:t:b:")) != -1) {
        switch(arg) {
            case 'w':
            SELECT='W'; // for sequential write
            break;
            case 's':
            SELECT='S'; // for sequential read
            break;
            case 'r':
            SELECT='R'; // for random read
            break;
            case 'e':
            SELECT='E'; // for random write
            break;
            case 'o':
            NUMBER_OF_ITERATIONS=atoi(optarg);
            break;
            case 't':
            NUMBER_OF_THREADS=atoi(optarg);
            break;
            case 'b':
            BLOCK_SIZE=atoi(optarg);
            break;
            default:
            break;
        }
   }
    MyDiskBench();
    return 0;
}
}

