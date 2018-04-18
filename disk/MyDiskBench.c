#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

int NUMBER_OF_THREADS = 1;
long NUMBER_OF_ITERATIONS = 1000000000;
int BLOCK_SIZE = 2;
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
  //pthread_exit(NULL);
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
    
}

void MyDiskbench_results_Sequential_write(double total_time, double throughput, double latency) {
   
    if (SELECT=='W') 
    {   
       
       
	if (BLOCK_SIZE==1000000)
        {
            //printf("The latency of the disk for the Sequential write access pattern, 1MB block size, %d thread  %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential write access pattern, 1MB block size, %d thread  %lf GB per second\n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==10000000) 
        {
            //printf("The latency of the disk for the Sequential write access pattern, 10MB block size, %d thread  %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential write access pattern, 10MB block size, %d thread -%lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==100000000)
        {
            //printf("The latency of the disk for the Sequential write access pattern, 100MB block size, %d thread  %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential write access pattern, 100MB block size, %d thread  %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        } 
    
    }
}

void MyDiskbench_results_Sequential_read(double total_time, double throughput, double latency) 
{

    if (SELECT=='S') 
    {
        if (BLOCK_SIZE==1000000)
        {
            //printf("The latency of the disk for the Sequential read access pattern, 1MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential read access pattern, 1MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==100000000)
	{
            //printf("The latency of the disk for the Sequential read access pattern, 10MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential read access pattern, 10MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==1000000000) 
        {
            //printf("The latency of the disk for the Sequential read access pattern, 100MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Sequential read access pattern, 100MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        } 
    } 
}

void MyDiskbench_results_Random_write(double total_time, double throughput, double latency) 
{
    if (SELECT=='R') 
    {

        if (BLOCK_SIZE==1000)
        {
            printf("The latency of the disk for the Random write access pattern, 1KB block size, %d thread  %lf milli second \n",NUMBER_OF_THREADS,latency);
            //printf("The Throughput of the disk for the Sequential write access pattern, 1MB block size, %d thread  %lf GB per second\n",NUMBER_OF_THREADS,throughput);
        }

        if (BLOCK_SIZE==1000000)
        {
            //printf("The latency of the disk for the Random write access pattern, 1MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random write access pattern, 1MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==100000000)
	{
           // printf("The latency of the disk for the Random write access pattern, 10MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random write access pattern, 10MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==1000000000) 
        {
            //printf("The latency of the disk for the Random write access pattern, 100MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random write access pattern, 100MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        } 
    } 
}
    

void MyDiskbench_results_Random_read(double total_time, double throughput, double latency)
{ 
   if (SELECT=='E') 
    {

        if (BLOCK_SIZE==1000)
        {
            printf("The latency of the disk for the Random read access pattern, 1KB block size, %d thread  %lf milli second \n",NUMBER_OF_THREADS,latency);
            //printf("The Throughput of the disk for the Sequential write access pattern, 1MB block size, %d thread  %lf GB per second\n",NUMBER_OF_THREADS,throughput);
        }

        if (BLOCK_SIZE==1000000)
        {
            //printf("The latency of the disk for the Random read access pattern, 1MB block size, %d thread  %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random read access pattern, 1MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
 	if (BLOCK_SIZE==10000000)
	{
            //printf("The latency of the disk for the Random read access pattern, 10MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random read access pattern, 10MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
        }
	if (BLOCK_SIZE==100000000) 
        {
            //printf("The latency of the disk for the Random read access pattern, 100MB block size, %d thread %lf milli second \n",NUMBER_OF_THREADS,latency);
            printf("The Throughput of the disk for the Random read access pattern, 100MB block size, %d thread %lf GB per second \n",NUMBER_OF_THREADS,throughput);
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
      
       pthread_t thread_id[NUMBER_OF_THREADS];
       int thread[NUMBER_OF_THREADS]; 

       void pthread_sequential_write_access()
       {
         
          for (int i=0;i<NUMBER_OF_THREADS;i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_write_access,fileptr);
          }
       }
 
       void pthread_sequential_read_access()
       {
         
          for (int i=0;i<NUMBER_OF_THREADS;i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_read_access,fileptr);
          }
       }

       void pthread_random_write_access()
       {
         
          for (int i=0;i<NUMBER_OF_THREADS;i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_write_access,fileptr);
          }
       } 

       void pthread_random_read_access()
       {
         
          for (int i=0;i<NUMBER_OF_THREADS;i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_read_access,fileptr);
          }
       } 

     
       if(SELECT == 'W') 
       {
          pthread_sequential_write_access();
       } 
       if (SELECT == 'S')
       {
         pthread_sequential_read_access();
       } 
       if (SELECT == 'R')
       {
         pthread_random_write_access();
       }
       if (SELECT == 'E')  
       {
         pthread_random_read_access();
       }

      for (int i=0;i<NUMBER_OF_THREADS;i++)
      {
      pthread_join(thread_id[i], NULL);
      }
      
      end = clock();
      total_time = (end - start)/CLOCKS_PER_SEC;
      printf("The total time taken is %f \n ",total_time);
      double throughput = (NUMBER_OF_ITERATIONS*BLOCK_SIZE*NUMBER_OF_THREADS)/total_time;
      throughput = throughput/1000000000;
      double latency = (total_time/(NUMBER_OF_ITERATIONS*BLOCK_SIZE))*1000000;
     

      MyDiskbench_results_Sequential_read(total_time,throughput,latency);
      MyDiskbench_results_Sequential_write(total_time,throughput,latency);
      MyDiskbench_results_Random_read(total_time,throughput,latency);
      MyDiskbench_results_Random_write(total_time,throughput,latency);
  

}

int main(int argc, char *argv[]){
    int arg;
    while((arg=getopt(argc, argv, "1234i:t:b:")) != -1) {
        switch(arg) {
            case '1':         
            {  
               SELECT = 'W';
	       if(SELECT != 'W')
	       {
                 printf("Error in the file \n");
               }
               printf("The selection made is sequential write \n");
            }
            break;

            case '2':           
            {  
               SELECT = 'S';
               if(SELECT != 'S')
	       {
                 printf("Error in the file \n");
               }
               printf("The selection made is sequential read \n");
            }
            break;

            case '3':         
            {  
               SELECT = 'R';
               if(SELECT != 'R')
	       {
                 printf("Error in the file \n");
               }
               printf("The selection made is random write \n");
            }
            break;

            case '4':          
            {  
               SELECT = 'E';
               if(SELECT != 'E')
	       {
                 printf("Error in the file \n");
               }
               printf("The selection made is random read \n");
            }
            break;
        
            case 'i':
	    {
              NUMBER_OF_ITERATIONS=atoi(optarg);
	    }
            break;

	    case 't':
	    {
              NUMBER_OF_THREADS=atoi(optarg);
            }
            break;

	    case 'b':           
	    {
            BLOCK_SIZE=atoi(optarg);
            }
            break;

            default:
            break;
        }
   }
    MyDiskBench();
    return 0;
}
