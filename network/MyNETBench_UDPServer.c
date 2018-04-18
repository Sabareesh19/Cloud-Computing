#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

//strcmp(number_of_arguments[1] - To indicate the type of connection
//Format - UDP 1024 1


char **number_of_arguments;
long NUMBER_OF_ITERATIONS = 100000000;
int NUMBER_OF_THREADS = 1;
void udpServer();


//Establishing the UDP Socket
void* UDPprotocolSocket(void* arg)
{
   //int UDP_client_socket = (int)socket;
   char receive,send;
   char buffer_element[1024];
   struct sockaddr_in serverAddr;
   struct sockaddr_in serverAddrfrom;
   int length_receive = sizeof(serverAddr);
   int length_send = sizeof(serverAddrfrom);
       
   int UDPsocket_server = socket(AF_INET,SOCK_DGRAM, 0);
   char * buffer = (char*)malloc(sizeof(char)*1000);
   memset(buffer, 1 , sizeof(buffer));

   for(int i=0; i<NUMBER_OF_ITERATIONS; i++)
	{       
                
		receive = recvfrom(UDPsocket_server, buffer, sizeof(buffer) , 0, (struct sockaddr *)&serverAddr,&length_receive);
                //printf("Bye udp %d",i);
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
        free(buffer);
        return NULL;
      

}

void udpServer(int buffer_value,int NUMBER_OF_THREADS)
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
	
	UDPsocket_server = socket(AF_INET, SOCK_DGRAM, 0);							//Creation of UDP Socket Server
	if(UDPsocket_server < 0)
	{
		exit(0);
                printf("Error in binding data \n");
	}	
	socket_bind = bind(UDPsocket_server, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));		//Binding of UDP Socket


	if(socket_bind < 0)
	{
		exit(0);
                printf("Error in opening socket \n");
	}
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_t threads[NUMBER_OF_THREADS];
		pthread_create(&threads[i], NULL, UDPprotocolSocket, UDPthread_args);
	}
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{	
		pthread_t threads[NUMBER_OF_THREADS];
		pthread_join(threads[i], NULL);
	}

	close(UDPsocket_server);
}

//FILL ME IN
int main(int argc, char *argv[])
{
        number_of_arguments = argv;
	int buffer_value = atoi(argv[2]);
	int NUMBER_OF_THREADS = atoi(argv[3]);

	if (strcmp(number_of_arguments[1], "UDP") == 0)
	{
		udpServer(buffer_value,NUMBER_OF_THREADS);
	} 

        if (argc != 4)
	{
		printf("Input is expected to have three arguments: Type of the protocol connection to be called, Size of the buffer and number of threads. \n");
		return 0;
	}

    return 0;
}
