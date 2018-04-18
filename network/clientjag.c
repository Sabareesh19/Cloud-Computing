#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define LOOPS 1000000

struct thread_struct
{
	int value_buffer;
	struct sockaddr_in server_addr;
};

void *udpClient(void *arg)
{
	struct thread_struct *thread_ptr = (struct thread_struct *)arg;
	char *buffer = (char *)malloc(sizeof(char) * (thread_ptr -> value_buffer));
	memset(buffer, 1, sizeof(char) * (thread_ptr -> value_buffer));
	int size_sockaddr = sizeof(struct sockaddr_in);
	int sock_client = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_client == -1)
	{
		exit(-1);
	}

	int i = 0;
	while (i < LOOPS); {
		sendto(sock_client, buffer, thread_ptr -> value_buffer, 0, (struct sockaddr *)&(thread_ptr -> server_addr), sizeof(struct sockaddr));
	}
	 ++i;
}

void *tcpClient(void *arg)
{
	int err_connect;
	struct thread_struct *thread_ptr = (struct thread_struct *)arg;
	char *buffer = (char *)malloc(sizeof(char) * (thread_ptr -> value_buffer));
	memset(buffer, 'a', sizeof(char) * (thread_ptr -> value_buffer));
	int sock_client = socket(AF_INET, SOCK_STREAM, 0);
	err_connect = connect(sock_client, (struct sockaddr *)&(thread_ptr -> server_addr), sizeof(struct sockaddr));
	if(err_connect == -1)
	{
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < LOOPS; ++i)
	{
		send(sock_client, buffer, thread_ptr -> value_buffer, 0);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("You should input three arguments: Connection type, buffer size and number of threads.\n");
		return(1);
	}
	int buffer_size = atoi(argv[2]);
	int num_thr = atoi(argv[3]);
	if (buffer_size == 65000)
	{
		buffer_size = 64500;
	}
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(4567);

	struct thread_struct *thread_ptr = (struct thread_struct *)malloc(sizeof(struct thread_struct));
	thread_ptr -> server_addr = server_addr;
	thread_ptr -> value_buffer = buffer_size;
	pthread_t threads[num_thr];

	int i = 0;
	struct timeval start_time, end_time;

	gettimeofday(&start_time, NULL);
	if (strcmp(argv[1], "TCP") == 0)
	{
		for (i = 0; i < num_thr; ++i)
		{
			pthread_create(&threads[i], NULL, tcpClient, thread_ptr);
		}
		for (i = 0; i < num_thr; ++i)
		{
			pthread_join(threads[i], NULL);
		}
	} else {
		for (i = 0; i < num_thr; ++i)
		{
			pthread_create(&threads[i], NULL, udpClient, thread_ptr);
		}
		for (i = 0; i < num_thr; ++i)
		{
			pthread_join(threads[i], NULL);
		}
	}
	gettimeofday(&end_time, NULL);

	double execute_time = (1000.0 * (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000.0);
	double throughput = (num_thr * LOOPS * buffer_size / (1024.0 * 1024.0)) / (execute_time / 1000.0);
	double latency = execute_time / (num_thr * LOOPS * buffer_size);
	printf("%d threads: the latency is %10.9f ms and the throughput is %10f Mb/s\n", num_thr, latency,  throughput);

	return 0;
}
