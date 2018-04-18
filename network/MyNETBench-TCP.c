
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


#define PORT 4455

long NUMBER_OF_ITERATIONS = 10000;
int NUMBER_OF_THREADS = 1;
int BLOCK_SIZE = 8;


void* TCPprotocol(void* arg)
{
printf("in tcp protocol");
   int TCP_client_socket;
   int tcp_connect;
   struct sockaddr_in serverAddr;
   char * buffer = (char*)malloc(sizeof(int)*1000);
   TCP_client_socket = socket(PF_INET, SOCK_STREAM, 0);
   memset(buffer, 1 , sizeof(buffer));
   
   tcp_connect = connect(TCP_client_socket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
printf("connect %f", tcp_connect);
   if(tcp_connect == -1)
   { 
printf("Error handling TCP Protocol \n ");
     exit(0);
     
   }
   else
   printf("The TCP protocol is set \n");

   for(int i = 0; i < NUMBER_OF_ITERATIONS ; i++)
   {
     send(TCP_client_socket, buffer, 8 , 0);
   }
   recv(TCP_client_socket,buffer,256,0);
   printf("TCP Connection established \n",buffer);

}	

int size_of_buffer; 
int number_of_threads; 

void* UDPprotocol(void* arg)
{
   int UDP_client_socket;
   
   struct sockaddr_in serverAddr;
   char * buffer = (char*)malloc(sizeof(int)*1000);
   UDP_client_socket = socket(PF_INET, SOCK_DGRAM, 0);
   memset(buffer, 1 , sizeof(buffer));
   
   if(UDP_client_socket <= 0)
   { 
     exit(0);
     printf("Error handling UDP Protocol \n ");
   }
   else
   printf("The UDP protocol is set \n");

   for(int i = 0; i < NUMBER_OF_ITERATIONS ; i++)
   {
     sendto(UDP_client_socket, buffer, sizeof(buffer) , 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
   }
   
   printf("UDP Connection established \n",buffer);

}

void TCPprotocol_result(double latency, double throughput)
   {
printf("in tcp");
	
//if (strcmp(argv[1], "TCP") == 0)
	if (size_of_buffer == 1000)
	{
		size_of_buffer = 1000;
	}
        if (size_of_buffer == 32000)
	{
		size_of_buffer = 32000;
	}
	printf("The number of threads executed to the TCP Protocol is %d threads \n",number_of_threads);
	printf("The latency of the TCP Protocol is  %10.9f ms and the throughput is %10f Mb/s\n",latency);
	printf("The throughput of the TCP Protocol is %10f Mb/s\n",throughput);
   }
        
void UDPprotocol_result(double latency, double throughput)
{
	//if (strcmp(argv[1], "UDP") == 0)
	if (size_of_buffer == 1000)
	{
		size_of_buffer = 1000;
	}
        if (size_of_buffer == 32000)
	{
		size_of_buffer = 32000;
	}
	printf("The number of threads executed to the UDP Protocol is %d threads \n",number_of_threads);
	printf("The latency of the UDP Protocol is  %10.9f ms and the throughput is %10f Mb/s\n",latency);
	printf("The throughput of the UDP Protocol is %10f Mb/s\n",throughput);
   }

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("The input is expected to consist of three arguments: Type of the protocol connection to be called, Size of the buffer and number of threads.\n");
		return(1);
	}
        
	int size_of_buffer = atoi(argv[2]);
	int number_of_threads = atoi(argv[3]);

	


	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;	
	serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   
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
        if (strcmp(argv[1], "UDP") == 0) 
        {
		for (int i = 0; i < number_of_threads; ++i)
		{
			pthread_create(&threads[i], NULL, UDPprotocol, thread_socketptr);
		}
		for (int i = 0; i < number_of_threads; ++i)
		{
			pthread_join(threads[i], NULL);
		}
	}
	
        end = clock();
        total_time = (end - start)/CLOCKS_PER_SEC;
	
	double throughput = (number_of_threads * NUMBER_OF_ITERATIONS * size_of_buffer / (1024.0 * 1024.0)) / (total_time / 1000.0);
	double latency = total_time / (number_of_threads * NUMBER_OF_ITERATIONS * size_of_buffer);
printf("starting tcp");
	TCPprotocol_result(latency,throughput);
        UDPprotocol_result(latency,throughput);

	return 0;
}




