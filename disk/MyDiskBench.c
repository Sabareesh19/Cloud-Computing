#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

//strcmp(number_of_arguments[1],"WS") == 0 -- To select the workload for example WS- write sequential
//atoi(number_of_arguments[2]) -- To the number of threads
//atoi(number_of_arguments[3]) -- To estimate the block size
//./MyDiskBench WS 1 1000


char **number_of_arguments;
long NUMBER_OF_ITERATIONS = 10000000;
int BLOCK_SIZE = 8;

//Reading the file with sequential write access pattern
void* sequential_write_access(void* arg)
{
      FILE * fileptr;
      fileptr = fopen("file.text","w");
      if(fileptr == NULL)
      {
        exit(1);
      }
      char * fptr1 = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
      for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
      { 
        fwrite(fptr1,atoi(number_of_arguments[3]),1,fileptr);
      }
  fclose(fileptr);
  free(fptr1);
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
      char * fptr1 = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
      for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
      { 
        fread(fptr1,atoi(number_of_arguments[3]),1,fileptr);
      }
  fclose(fileptr);
  free(fptr1);
}


//Reading the file with random write access pattern
void* random_write_access(void* arg){
      FILE * fileptr;
      fileptr = fopen("file.text","w");
      if(fileptr == NULL)
      {
       exit(1);
      }
      char * fptr1 = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
      for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
      { 
        int random_operation = rand()%1000;
        fseek(fileptr,random_operation,SEEK_SET);
        fwrite(fptr1,atoi(number_of_arguments[3]),1,fileptr);
      }
   fclose(fileptr);
   free(fptr1);
}


//Reading the file with random read access pattern
void* random_read_access(void* arg){
     FILE * fileptr;
     fileptr = fopen("file.text","r");
     if(fileptr == NULL)
     {
      exit(1);
     }
     char * fptr1 = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
     for(int i = 0; i< NUMBER_OF_ITERATIONS; i++)
     { 
       int random_operation = rand()%1000;
       fseek(fileptr,random_operation,SEEK_SET);
       fread(fptr1,atoi(number_of_arguments[3]),1,fileptr);
     }
    fclose(fileptr);
    free(fptr1);
}

void MyDiskbench_results_Sequential_write(double total_time, double throughput, double latency) {
   
    if (strcmp(number_of_arguments[1],"WS") == 0)   //WS - Write Sequential
    {   
       
       
	if (atoi(number_of_arguments[3])==1000)
        {
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
 	if (atoi(number_of_arguments[3])==10000) 
        {
            
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
	if (atoi(number_of_arguments[3])==100000)
        {
            
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        } 
    
    }
}

void MyDiskbench_results_Sequential_read(double total_time, double throughput, double latency) 
{

    if (strcmp(number_of_arguments[1],"RS") == 0)     //RS - Read Sequential
    {
        if (atoi(number_of_arguments[3])==1000)
        {
           
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
 	if (atoi(number_of_arguments[3])==10000)
	{
            
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
	if (atoi(number_of_arguments[3])==100000) 
        {
           
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        } 
    } 
}

void MyDiskbench_results_Random_write(double total_time, double throughput, double latency) 
{
    if (strcmp(number_of_arguments[1],"WR") == 0)     //WR - Random write
    {

        if (atoi(number_of_arguments[3])==1)
        {
             printf("************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Latency(ms) \n");
             printf("************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %f  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),latency);
            
        }

        if (atoi(number_of_arguments[3])==1000)       
        {
            
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
 	if (atoi(number_of_arguments[3])==10000)
	{
           
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
	if (atoi(number_of_arguments[3])==100000) 
        {
            
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        } 
    } 
}
    

void MyDiskbench_results_Random_read(double total_time, double throughput, double latency)
{ 
   if (strcmp(number_of_arguments[1],"RR") == 0)      //RR - Random Read
    {

        if (atoi(number_of_arguments[3])==1)
        {
             printf("************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Latency(ms) \n");
             printf("************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %f  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),latency);
            
        }

        if (atoi(number_of_arguments[3])==1000)
        {
           
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
 	if (atoi(number_of_arguments[3])==10000)
	{
           
            printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        }
	if (atoi(number_of_arguments[3])==100000) 
        {
            
             printf("*******************************************************************************\n");
             printf("Workload      Concurrency       Block size      MyDiskBench Throughput(MB/sec) \n");
             printf("*******************************************************************************\n");
             printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),throughput);
        } 
    }

}


void MyDiskBench() 
{
       FILE *fileptr;
       char *fptr1 = (char *)malloc(atoi(number_of_arguments[3]));
       fileptr = fopen( "file.txt" , "w" );
       fwrite(fptr1,atoi(number_of_arguments[3]),2,fileptr);
       
       double start,end,total_time;
       start = clock();	
      
       pthread_t thread_id[atoi(number_of_arguments[2])];
       int thread[atoi(number_of_arguments[2])]; 

       void pthread_sequential_write_access()
       {
         
          for (int i=0;i<atoi(number_of_arguments[2]);i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_write_access,fileptr);
          }
       }
 
       void pthread_sequential_read_access()
       {
         
          for (int i=0;i<atoi(number_of_arguments[2]);i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,sequential_read_access,fileptr);
          }
       }

       void pthread_random_write_access()
       {
         
          for (int i=0;i<atoi(number_of_arguments[2]);i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_write_access,fileptr);
          }
       } 

       void pthread_random_read_access()
       {
         
          for (int i=0;i<atoi(number_of_arguments[2]);i++) 
          {
            thread[i] = pthread_create(&(thread_id[i]),NULL,random_read_access,fileptr);
          }
       } 

     
       if(strcmp(number_of_arguments[1],"WS") == 0 ) 
       {
          pthread_sequential_write_access();
       } 
       if (strcmp(number_of_arguments[1],"RS") == 0)
       {
         pthread_sequential_read_access();
       } 
       if (strcmp(number_of_arguments[1],"WR") == 0)
       {
         pthread_random_write_access();
       }
       if (strcmp(number_of_arguments[1],"RR") == 0)  
       {
         pthread_random_read_access();
       }

      for (int i=0;i<atoi(number_of_arguments[2]);i++)
      {
      pthread_join(thread_id[i], NULL);
      }
      
      end = clock();
      total_time = (end - start)/CLOCKS_PER_SEC;
      free(fptr1);
      
      double throughput = (NUMBER_OF_ITERATIONS*atoi(number_of_arguments[3])*atoi(number_of_arguments[2])*2)/(total_time);
      throughput = throughput/10000000;
      double latency = (total_time*1000)/(NUMBER_OF_ITERATIONS*atoi(number_of_arguments[3]));
     

      MyDiskbench_results_Sequential_read(total_time,throughput,latency);
      MyDiskbench_results_Sequential_write(total_time,throughput,latency);
      MyDiskbench_results_Random_read(total_time,throughput,latency);
      MyDiskbench_results_Random_write(total_time,throughput,latency);
    

}

int main(int argc, char *argv[]){

    number_of_arguments=argv;
    MyDiskBench();
    return 0;
}
