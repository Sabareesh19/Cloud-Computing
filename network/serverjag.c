#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>


#define LOOPS 100000

//Defining Thread Structure.....
struct thread_struct
{
	int sock;
	int value_buffer;
};



//UDP server receiving data.....
void *udpConnect(void *arg)
{
	struct thread_struct *thread_arg = (struct thread_struct *)arg;
	struct sockaddr_in client_addr;

	char * buffer = (char *)malloc(sizeof(char) * thread_arg -> value_buffer);
	int size_sockaddr = sizeof(struct sockaddr_in);
	memset(buffer, 0, sizeof(char) * thread_arg -> value_buffer);


	int i = 0;
	while (i < LOOPS) {
		recvfrom(thread_arg -> sock, buffer, thread_arg -> value_buffer, 0, (struct sockaddr *)&client_addr, &size_sockaddr);
	}
	i++;
	printf("UDP server receiving Data....\n" );
}

//UDP server Functioning....
void udpServer(int value_buffer, int thread_num)
{
	int sock_server, s_bind;
	struct sockaddr_in server_addr;
	if (value_buffer == 65000)
	{
		value_buffer = 64500;
	}
	char * buffer = (char *)malloc(sizeof(char) * value_buffer);
	memset(buffer, 0, sizeof(char) * value_buffer);
	memset(&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(4567);

	//Createing socket...
	sock_server = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_server == -1)
	{
		exit(-1);
	}

	//Bind socket....
	s_bind = bind(sock_server, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	if(s_bind == -1)
	{
		exit(-1);
	}

	pthread_t threads[thread_num];
	int i = 0;

	struct thread_struct * thread_arg = (struct thread_struct *)malloc(sizeof(struct thread_struct));
	thread_arg -> sock = sock_server;
	thread_arg -> value_buffer = value_buffer;

	//Create many threads to process.
	for (i = 0; i < thread_num; ++i)
	{
		pthread_create(&threads[i], NULL, udpConnect, thread_arg);
	}
	for (i = 0; i < thread_num; ++i)
	{
		pthread_join(threads[i], NULL);
	}

	close(sock_server);
}

//TCP Server receiving data....
void *tcpConnect(void *arg)
{
	struct thread_struct *thread_arg = (struct thread_struct *)arg;
	char * buffer = (char *)malloc(sizeof(char) * thread_arg -> value_buffer);
	memset(buffer, 0, sizeof(char) * thread_arg -> value_buffer);

	int i = 0;
	for (i = 0; i < LOOPS; ++i)
	{
		recv(thread_arg -> sock, buffer, thread_arg -> value_buffer, 0);
	}
	free(buffer);
    return NULL;
}

//TCP Server functioninf.....
void tcpServer(int value_buffer, int thread_num)
{
	int sock_server, sock_client, s_bind;
	struct sockaddr_in myserver_address;
	struct sockaddr_in client_addr;
	if (value_buffer == 65000)
	{
		value_buffer = 64500;
	}
	memset(&myserver_address, 0, sizeof(myserver_address));
	myserver_address.sin_family = AF_INET;
	myserver_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	myserver_address.sin_port = htons(4567);

	//create socket.
	sock_server = socket(AF_INET, SOCK_STREAM, 0);
	s_bind = bind(sock_server, (struct sockaddr *)&myserver_address, sizeof(struct sockaddr));
	if(s_bind == -1)
	{
		exit(-1);
	}

	//Begin listening.
	listen(sock_server, 10);
	printf("Server is listening....\n");
	int size_sockaddr = sizeof(struct sockaddr_in);
	pthread_t threads[thread_num];

	//Create many threads to process.
	int i = 0;
	while(i < thread_num)
	{
		sock_client = accept(sock_server, (struct sockaddr *)&client_addr, &size_sockaddr);
		if(sock_client == -1)
		{
			exit(-1);
		}
		struct thread_struct * thread_arg = (struct thread_struct *)malloc(sizeof(struct thread_struct));
		thread_arg -> sock = sock_client;
		thread_arg -> value_buffer = value_buffer;
		pthread_create(&threads[i], NULL, tcpConnect, thread_arg);
		pthread_join(threads[i], NULL);
		i++;
	}

	close(sock_client);
	close(sock_server);
}


//Main function, select protocol according to the input.
int main(int argc, char *argv[])
{
	int value_buffer = atoi(argv[2]);
	int thread_num = atoi(argv[3]);

	if (strcmp(argv[1], "UDP") == 0)
	{
		udpServer(value_buffer, thread_num);
	} else {
		tcpServer(value_buffer, thread_num);
	}
	if (argc != 4)
	{
		printf("Input three arguments: Connection type, buffer size and number of threads\n");
		return 1;
	}

	return 0;
}
