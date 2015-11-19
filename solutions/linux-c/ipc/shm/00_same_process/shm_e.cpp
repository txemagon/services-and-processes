#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int factorial(int n){
    if (n<1)
	return 1;
    return n * factorial(n-1);
}

long double e(int n){
    if (n>20)
	return 0;
    return 1. / factorial(n) + e(n+1);
}

int main(int argc, char *argv[]){
    pid_t child;
    int status;
    int segment_id;
    long double *valor;

    segment_id = shmget(IPC_PRIVATE, sizeof(long double), 
	    IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    child = fork();
    if (child){
	waitpid(child, &status, 0);
	valor =  (long double *) shmat(segment_id, 0, 0);
	printf("2e = %Lf\n", *valor * 2);
	shmdt(valor);
	shmctl(segment_id, IPC_RMID, 0);
    } else {
	/* attach valor con la memoria compartida */
	valor =  (long double *) shmat(segment_id, 0, 0);
	/* calcular e */
	/* Ponerlo en la memoria compartida */
	*valor = e(0);
	/* detach de valor con la memoria compartida */
	shmdt(valor);

    }
    return EXIT_SUCCESS;
}
