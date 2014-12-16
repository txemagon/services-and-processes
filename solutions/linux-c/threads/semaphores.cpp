#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 100000
#define BUITRES 20

int carne_vaca = N;
pthread_mutex_t comer_despacio = PTHREAD_MUTEX_INITIALIZER;
sem_t simul;

int comer(){
    int comido = 0;
	pthread_mutex_lock(&comer_despacio);
    if (carne_vaca > 0) {
	carne_vaca--;
	comido = 1;
	printf("\rCarne: %i                              ", carne_vaca);
	fflush(stdout);
    }
	pthread_mutex_unlock(&comer_despacio);

    return comido;
}

void *buitre(void *p){
    int carrona = 0;
    while(carne_vaca > 0){
	sem_wait(&simul);
	carrona += comer();
	sem_post(&simul);
    }
    return (void *) carrona;
}

int main(int argc, char *argv[]) {

    pthread_t buitre_id[BUITRES];
    double porcentajes[BUITRES];
    void *res;

    sem_init(&simul, 0, 5);
    for (int i=0; i<BUITRES; i++)
	pthread_create(&buitre_id[i], NULL, buitre, NULL);


    for (int i=0; i<BUITRES; i++){
	pthread_join(buitre_id[i], &res);
	porcentajes[i] = (int) res * 100. / N;
    }
    printf("\n");

    for (int i=0; i<BUITRES; i++)
	printf("%.2lf  ", porcentajes[i]);


    printf("\n");
    sem_destroy(&simul);

    return EXIT_SUCCESS;
}
