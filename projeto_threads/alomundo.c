#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *outraThread(void *vargp);

int main (void) {
	pthread_t tid; /* Identificador da thread */

	fprintf(stderr, "Vou criar a thread\n");
	int rc = pthread_create(&tid, NULL, outraThread, NULL); /* Cria a segunda thread */
	if (rc) {
		fprintf(stderr, "Erro: pthread_create() retornou %d\n", rc);
		return 1;
	}

	fprintf(stderr, "Thread criada, esperando pelo término\n");
	rc = pthread_join(tid, NULL); // Se comentar esta linha, o programa principal pode terminar antes da thread
	if (rc) {
		fprintf(stderr, "Erro: pthread_join() retornou %d\n", rc);
		return 1;
	}
	fprintf(stderr, "Fim da thread\n");
	return 0;
}

/*
* Função super legal
*@param vargp Argumento passado para a thread (não usado)
*@return NULL
*/
void *outraThread(void *vargp) {
	puts("Nova thread nascendo...");
	sleep (10);
	puts("Alo mundo!");
	return NULL;
}