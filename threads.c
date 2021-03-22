/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:37:31 by javrodri          #+#    #+#             */
/*   Updated: 2021/03/22 13:33:21 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


static int arg = 10;

void *thread_routine(void *unused)
{
	for(int i = 0; i < 10000; i++)
	{
//	  printf("0-[%i]\n", arg);
	  arg++;
	}
	// int i = 0;
	// int nr_lines = *((int*)arg);
	// int fd;
	// char buf[] = "Nueva linea \n";

	// printf("El hilo comienza a ejecutarse...\n");
	// while(i < nr_lines)
	// {
	// 	fd = open("test.txt", O_WRONLY|O_APPEND);
	// 	write(fd, buf, sizeof(buf) -1);
	// 	close(fd);
	// 	i++;
	// }
	return(0);
}

void *thread_routine1(void *unused)
{
	for(int i = 0; i < 10000; i++)
	
	{	
  		arg--;
//		printf("1-[%i]\n", arg);
	}
	
	// int i = 0;
	// int nr_lines = *((int*)arg);
	// int fd;
	// char buf[] = "Nueva linea \n";

	// printf("El hilo comienza a ejecutarse...\n");
	// while(i < nr_lines)
	// {
	// 	fd = open("test.txt", O_WRONLY|O_APPEND);
	// 	write(fd, buf, sizeof(buf) -1);
	// 	close(fd);
	// 	i++;
	// }
	return(0);
}

void errorExit(char *strerr)
{

  perror(strerr);
  exit(1);
}

int main(int argc, char **argv)
{
	pthread_t thread1, thread2; //Identificador del hilo
	

	// value = atoi(argv[1]);
	if(0 != pthread_create(&thread1, NULL, thread_routine, NULL))
		errorExit("thread1 cannot be created"); 
	if(0 != pthread_create(&thread2, NULL, thread_routine1, NULL))
		errorExit("thread2 cannot be created");	
			//Puntero al identificador del hilo.
			//Atributos del hilo(NULL = atributos por defecto)
			//Rutina que va a comenzar al inicializar
			//Argumentos de entrada
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("[%i]\n", arg);
  return(0);
}
