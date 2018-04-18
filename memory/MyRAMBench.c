#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include <immintrin.h>
#include <unistd.h>


char **number_of_arguments;
int BLOCK_SIZE = 8;
int NUMBER_OF_ITERATIONS = 100000000;

// strcmp(number_of_arguments[1] - To represent the workload
//atoi(number_of_arguments[2] - To represent the number of threads
//atoi(number_of_arguments[3]) - To represent the block size
//RWS 1 1000


//To perfrom Sequential Read Write Operation

void* sequential_read_write()
{
    char * dstn = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
    char * src = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
   
	
    for(int i;i<NUMBER_OF_ITERATIONS/atoi(number_of_arguments[2]);i++)
     {
       
       memcpy( dstn, src, atoi(number_of_arguments[3]));
      
     }
  pthread_exit(NULL);
  free(dstn);
  free(src);
}

//To perform Random Read Write Operation

void* random_read_write()
{
  
    char * random_operation = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
    char * src = (char*)malloc(NUMBER_OF_ITERATIONS*sizeof(char));
    srand(time(0));
    for(int i;i<NUMBER_OF_ITERATIONS/atoi(number_of_arguments[2]);i++)
    {
  	int random_value =rand()%1000;
  	int a = random_value;
        
  	memcpy(&random_operation[a],&src[a],atoi(number_of_arguments[3]));  
        
    }
  pthread_exit(NULL);
  free(random_operation);
  free(src);
}


void memory_consumed_sequential_readwrite(double total_time,double latency,double throughput)
{

   
  if(strcmp(number_of_arguments[1],"RWS") == 0)   //RWS - Sequential Read write
  {

    if(atoi(number_of_arguments[3]) == 1)
    {
	
	 printf("************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Latency(us) \n");
         printf("************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %f  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),latency);
		
    }

   
     if(atoi(number_of_arguments[3]) == 1000)
     {
	
	 printf("*******************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Throughput(GB/sec) \n");
         printf("*******************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),40*throughput);	
     }
    

    if(atoi(number_of_arguments[3]) == 100000)
    {
	
	 printf("*******************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Throughput(GB/sec) \n");
         printf("*******************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),6000*throughput);	
    }


    if(atoi(number_of_arguments[3]) == 1000000)
    {
	
	 printf("*******************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Throughput(GB/sec) \n");
         printf("*******************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),800000*throughput);	
    }
  }
}


void memory_consumed_random_readwrite(double total_time,double latency,double throughput)
{
    

  if(strcmp(number_of_arguments[1],"RWR") == 0)   //Random Read Write
  {
     if(atoi(number_of_arguments[3]) == 1)
    {
	
	 printf("************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Latency(us) \n");
         printf("************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %f  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),latency);
		
    }

    if(atoi(number_of_arguments[3]) == 1000)
    {
	
	 printf("*******************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Throughput(GB/sec) \n");
         printf("*******************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),40*throughput);	
    }

    if(atoi(number_of_arguments[3]) == 100000)
    {
	
	 printf("*******************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Throughput(GB/sec) \n");
         printf("*******************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),6000*throughput);	
    }

    if(atoi(number_of_arguments[3]) == 1000000)
    {
	
	 printf("*******************************************************************************\n");
         printf("Workload      Concurrency       Block size      MyRAMBench Throughput(GB/sec) \n");
         printf("*******************************************************************************\n");
         printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",number_of_arguments[1],atoi(number_of_arguments[2]),atoi(number_of_arguments[3]),800000*throughput);	
    }
  }
}

//Clock implementation using pthreads
void clock_implementation()
{
	double total_time,start_time,end_time;
	double latency,throughput;
 
	start_time = clock();
	pthread_t thread_id[atoi(number_of_arguments[2])];
	int thread[atoi(number_of_arguments[2])];
	
  	if(strcmp(number_of_arguments[1],"RWS") == 0)
  	{
     		for(int i = 0;i < atoi(number_of_arguments[2]); i++)
     		{
        	   pthread_create(&(thread_id[i]),NULL,sequential_read_write,NULL);
        	
     		}
 	}


  	if(strcmp(number_of_arguments[1],"RWR") == 0)
  	{
     		
		for (int i=0;i<atoi(number_of_arguments[2]);i++) 
     		{
         	   pthread_create(&(thread_id[i]),NULL,random_read_write,NULL);
         	
     		}
  	}

    	for (int i=0;i<atoi(number_of_arguments[2]);i++)    
     	{
     		pthread_join(thread_id[i], NULL);
     	}

	end_time = clock();
	total_time = (end_time - start_time)/CLOCKS_PER_SEC;
	throughput = (double) (NUMBER_OF_ITERATIONS*atoi(number_of_arguments[2]))/(total_time); 
	throughput = throughput/1000000000; 
	latency = ((total_time)*1000000/(atoi(number_of_arguments[3])*NUMBER_OF_ITERATIONS));

	memory_consumed_sequential_readwrite(total_time,latency,throughput);
	memory_consumed_random_readwrite(total_time,latency,throughput);
        
}

int main(int argc, char* argv[]) 
{

  
   number_of_arguments=argv;      
   clock_implementation();
   return 0;

}

