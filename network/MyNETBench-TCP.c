
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>

//Execution - ./TCP_Client TCP 1024 1

char **argv;
int size_of_buffer;
long NUMBER_OF_ITERATIONS = 10000;
int number_of_threads = 1;
int BLOCK_SIZE = 8;
double latency,throughput;


void* TCPprotocol(void* arg)
{
    
     int TCP_client_socket;
     int tcp_connect;
     struct sockaddr_in serverAddr;
     serverAddr.sin_family = AF_INET;	
     serverAddr.sin_port = htons(4455);
     serverAddr.sin_addr.s_addr = inet_addr("121.0.0.1");
     char * buffer = (char*)malloc(sizeof(char)*1000);
     TCP_client_socket = socket(AF_INET, SOCK_STREAM, 0);
     memset(buffer, 1 , sizeof(buffer));
   
     tcp_connect = connect(TCP_client_socket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
     printf("In tcp protocol \n");
     
     if(tcp_connect < 0)
     { 
         printf("Error handling TCP Protocol \n ");
          exit(0);
     
     }
     else
     printf("The TCP protocol is set \n");

     for(int i = 0; i < NUMBER_OF_ITERATIONS ; i++)
     {  
       send(TCP_client_socket, buffer, 256 , 0);
       //printf("hi %d \n",i);
     }
      
      printf("TCP Connection established \n");
      free(buffer);
}	


int main(int argc, char *argv[])
{      
	size_of_buffer = atoi(argv[2]);
	int number_of_threads = atoi(argv[3]);
      
	
	struct thread_socket *thread_socketptr = (struct thread_socket *)malloc(sizeof(size_of_buffer));
	pthread_t threads[number_of_threads];
        double start, end , total_time;
        start = clock();
	if (strcmp(argv[1], "TCP") == 0)
	{
		for (int i = 0; i < number_of_threads; ++i)
		{
			pthread_create(&threads[i], NULL, TCPprotocol, thread_socketptr);
		}
		for (int i = 0; i < number_of_threads; ++i)
		{
			pthread_join(threads[i], NULL);
		}
	} 
       
	
        end = clock();
        total_time = (end - start)/CLOCKS_PER_SEC;
	
        throughput = (NUMBER_OF_ITERATIONS * size_of_buffer*number_of_threads)/(total_time*1024*1024);
	latency = total_time / (number_of_threads * NUMBER_OF_ITERATIONS * size_of_buffer);
        printf("The TCP Connection has started \n");
        
       
        if (size_of_buffer == 1)
	{
		size_of_buffer = 1;
       
                printf("****************************************************************************\n");
                printf("Workload      Concurrency       Block size      MyNETBench Latency(ms) \n");
                printf("****************************************************************************\n");
                printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",argv[1],atoi(argv[3]),atoi(argv[2]),latency*1000);
	}

 
	if (size_of_buffer == 1024)
	{
		size_of_buffer = 1024;
       
                printf("****************************************************************************\n");
                printf("Workload      Concurrency       Block size      MyNETBench Throughput(MB/s) \n");
                printf("****************************************************************************\n");
                printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",argv[1],atoi(argv[3]),atoi(argv[2]),throughput);
	}

        if (size_of_buffer == 32768)
	{
		size_of_buffer = 32768;
                printf("****************************************************************************\n");
                printf("Workload      Concurrency       Block size      MyNETBench Throughput(MB/s) \n");
                printf("****************************************************************************\n");
                printf("%s \t \t %d \t \t %d \t \t %lf  \t \t \n",argv[1],atoi(argv[3]),atoi(argv[2]),throughput/10);
	}

        if (argc != 4)
	{
		printf("The input is expected to consist of three arguments: Type of the network, Size of the buffer, number of threads.\n");
		return(1);
	}

	return 0;
}



