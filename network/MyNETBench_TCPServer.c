#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

//Execution - ./TCP_Server TCP 1024 1 

char **number_of_arguments;
long NUMBER_OF_ITERATIONS = 10000000;
int NUMBER_OF_THREADS = 1;
int TCPclient_server;

//Implementation of TCP Server Protocol
void *TCPprotocolConnect(void *arg)
{  

   	
   	int receive;
   	char buffer_element[1024];
   	struct sockaddr_in serverAddr;
   	char * buffer = (char*)malloc(sizeof(char)*1000);
  	memset(buffer,0, sizeof(buffer));

   	for(int i=0; i<NUMBER_OF_ITERATIONS; i++)
	{
		receive = recv(TCPclient_server, buffer, sizeof(buffer), 0);
                //printf("bye %d \n",i);
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


void tcpServer(int buffer_value, int NUMBER_OF_THREADS)
{

	int TCPsocket_server, socket_bind;
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

       

	if (buffer_value == 1024 )
	{
		buffer_value = 1024;
	}
        if ( buffer_value == 32768 )
	{
		buffer_value = 32768;
	}
	char * buffer = (char *)malloc(sizeof(char) * 1000);
	memset(buffer, 0, sizeof(char) * 1000);
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4455);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	
	TCPsocket_server = socket(AF_INET, SOCK_STREAM, 0);								//creation of socket.
	socket_bind = bind(TCPsocket_server, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));
	if(socket_bind == -1)
	{
		exit(-1);
	}

	listen(TCPsocket_server,5);  											//Begins to listen.
	printf("Server is listening....\n");
	int size_sockaddr = sizeof(clientAddr);
	pthread_t threads[NUMBER_OF_THREADS];
	
	for(int i=0; i<NUMBER_OF_THREADS; i++)
	{
		TCPclient_server = accept(TCPsocket_server, (struct sockaddr *)&clientAddr, &size_sockaddr);
        
	}
        printf("I accepted the message \n");
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

int main(int argc, char *argv[])
{
        number_of_arguments = argv;
	int buffer_value = atoi(argv[2]);
	int NUMBER_OF_THREADS = atoi(argv[3]);

	if (strcmp(number_of_arguments[1], "TCP") == 0)
	{
		tcpServer(buffer_value,NUMBER_OF_THREADS);
	} 

        if (argc != 4)
	{
		printf("Input is expected to have three arguments: Type of the protocol connection to be called, Size of the buffer and number of threads. \n");
		return 0;
	}

    return 0;
}
