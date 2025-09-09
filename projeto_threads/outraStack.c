#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread(void *vargp);

char **p; // (GLOBAL) Ponteiro para vetor de strings

int main (void) {
	long i;
	pthread_t tid; // Identificador da thread

	char *vMsgs[] = {
		"Primeira mensagem",
		"Segunda mensagem"
	};

	p = vMsgs; // ponteiro para o vetor de strings

    // Cria as 2 threads
    fprintf(stderr, "Vou criar as threads\n");
	for (i=0; i<2; i++) {
		int rc = pthread_create(&tid, NULL, thread, (void *) i);
        if (rc) {
            fprintf(stderr, "Erro: pthread_create() retornou %d\n", rc);
            return 1;
        }
	}
	fprintf(stderr, "Fim da thread principal\n");
	pthread_exit(NULL);

	return 0;
}

/*
* Funcão que a thread executa
*
* @param vargp Argumento passado para a thread (indice da mensagem a imprimir)
* @return NULL
*/
void *thread(void *vargp) {
	int id;
	static int sVar = 0; // (STATIC) Variável compartilhada entre as threads (uma por função e não por thread)

	id = (long) vargp;
	printf ("Thread %d: %s (sVar = %d)\n", id, p[id], ++sVar);
	sleep (30);

	return NULL;
}