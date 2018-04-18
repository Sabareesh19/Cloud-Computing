#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
long NUMBER_OF_ITERATIONS = 10000;
int NUMBER_OF_THREADS = 1;

//Establishing the UDP Socket Connection
void* UDPprotocolConnect(void* arg)
{
   int UDP_client_socket = (int)socket;
   int receive;
   char buffer_element[1024*32];
   struct sockaddr_in serverAddr;
   char * buffer = (char*)malloc(sizeof(int)*1000);
   memset(buffer, 1 , sizeof(buffer));

   for(int i=0; i<NUMBER_OF_ITERATIONS; i++)
	{
		receive = recvfrom(UDP_client_socket, buffer, buffer_element, 0, (struct sockaddr *)&serverAddr,sizeof(serverAddr));
	}
   if(receive < 0)
	{
		printf("Received data has error \n");
	}
   if(receive >= 0)
	{
		printf("Connected to client \n");
	}
	printf(" Data is received from UDP Protocol \n" );

}

void udpServer(int buffer_value, int NUMBER_OF_THREADS)
{	
	
	int UDPsocket_server, socket_bind;
	struct sockaddr_in serverAddr;
	struct UDPthread_socket
	{
	    int socket_id;
	    int buffer_value;
	};

	struct UDPthread_socket * UDPthread_args = (struct UDPthread_socket *)malloc(sizeof(struct UDPthread_socket));
	UDPthread_args -> socket_id = UDPsocket_server;
	UDPthread_args -> buffer_value = buffer_value;

	if (buffer_value == 1000 )
	{
		buffer_value = 1000;
	}
        if ( buffer_value == 32000 )
	{
		buffer_value = 32000;
	}
	char * buffer = (char *)malloc(sizeof(char) * 1000);
	//memset(buffer, 0, sizeof(char) * 1000);
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4455);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	UDPsocket_server = socket(AF_INET, SOCK_DGRAM, 0);							//Creation of UDP Socket Server
	if(UDPsocket_server < 0)
	{
		exit(0);
	}	
	socket_bind = bind(UDPsocket_server, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));		//Binding of UDP Socket
	if(socket_bind < 0)
	{
		exit(0);
	}
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_t threads[NUMBER_OF_THREADS];
		pthread_create(&threads[i], NULL, UDPprotocolConnect, UDPthread_args);
	}
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{	
		pthread_t threads[NUMBER_OF_THREADS];
		pthread_join(threads[i], NULL);
	}

	close(UDPsocket_server);
}


//Implementation of TCP Server Protocol
void *TCPprotocolConnect(void *arg)
{  

   	int UDP_client_socket = (int)socket;
   	int receive;
   	char buffer_element[1024*32];
   	struct sockaddr_in serverAddr;
   	char * buffer = (char*)malloc(sizeof(int)*1000);
  	memset(buffer, 1 , sizeof(buffer));

   	for(int i=0; i<NUMBER_OF_ITERATIONS; i++)
	{
		receive = recv(UDP_client_socket, buffer, buffer_element, 0);
	}
	if(receive < 0)
	{
		printf("Received data has error \n");
	}
   	if(receive >= 0)
	{
		printf("Connected to client \n");
	}
	printf(" Data is received from TCP Protocol \n" );
        free(buffer);
    return NULL;
}


void tcpServer(int buffer_value, int thread_num)
{

	int TCPsocket_server, socket_bind, TCPclient_server;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	struct TCPthread_socket
	{
	    int socket_id;
	    int buffer_value;
	};

	struct TCPthread_socket * TCPthread_args = (struct TCPthread_socket *)malloc(sizeof(struct TCPthread_socket));
	TCPthread_args -> socket_id = TCPsocket_server;
	TCPthread_args -> buffer_value = buffer_value;

	if (buffer_value == 1000 )
	{
		buffer_value = 1000;
	}
        if ( buffer_value == 32000 )
	{
		buffer_value = 32000;
	}
	char * buffer = (char *)malloc(sizeof(char) * 1000);
	//memset(buffer, 0, sizeof(char) * 1000);
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4455);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	TCPsocket_server = socket(AF_INET, SOCK_STREAM, 0);								//creation of socket.
	socket_bind = bind(TCPsocket_server, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));
	if(socket_bind == -1)
	{
		exit(-1);
	}

	listen(TCPsocket_server, 15);  											//Begins to listen.
	printf("Server is listening....\n");
	int size_sockaddr = sizeof(struct sockaddr_in);
	pthread_t threads[NUMBER_OF_THREADS];
	
	for(int i=0; i<NUMBER_OF_THREADS; i++)
	{
		TCPclient_server = accept(TCPsocket_server, (struct sockaddr *)&clientAddr, size_sockaddr);
	}
	if(TCPclient_server == -1)
	{
		exit(-1);
	}
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, TCPprotocolConnect, TCPthread_args);
	}
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	close(TCPclient_server);
	close(TCPsocket_server);
}

int main(int argc, int* argv[])
{
	int buffer_value = atoi(argv[2]);
	int NUMBER_OF_THREADS = atoi(argv[3]);

	if (strcmp(argv[1], "UDP") == 0)
	{
		udpServer(buffer_value, NUMBER_OF_THREADS);
	} 
	if (strcmp(argv[1], "TCP") == 0) 
	{
		tcpServer(buffer_value, NUMBER_OF_THREADS);
	}
	if (argc != 4)
	{
		printf("Input is expected to have three arguments: Type of the protocol connection to be called, Size of the buffer and number of threads. \n");
		return 0;
	}

	return 0;
}
