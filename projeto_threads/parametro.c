#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
	int   value;
	char  string[128];
} thread_parm_t;

void *threadfunc(void *parm);

int main(int argc, char *argv[]) {
	pthread_t             thread;          // Thread ID
	int                   rc;              // Return code
	pthread_attr_t        pta;             // Thread attributes
	thread_parm_t         *parm=NULL;      // Parameters to pass to thread

    // Create the thread attributes object
	printf("Create a thread attributes object\n");
	rc = pthread_attr_init(&pta);
	if(rc) {
		fprintf(stderr, "pthread_attr_init() failed, rc=%d\n", rc);
		exit(1);
	}

    // Create the thread, passing multiple parameters
	printf("Create thread using the default attributes e vários parâmetros\n");
	/* Set up multiple parameters to pass to the thread */
	parm = malloc(sizeof(thread_parm_t));
    if(parm==NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(1);
    }
	parm->value = 77;
	strcpy(parm->string, "Inside secondary thread");
	rc = pthread_create(&thread, &pta, threadfunc, (void *)parm);
	if(rc) {
		fprintf(stderr, "pthread_create() failed, rc=%d\n", rc);
		exit(1);
	}

    // Destroy attributes object. Important to avoid memory leak
	printf("Destroy thread attributes object\n");
	rc = pthread_attr_destroy(&pta);
	if(rc) {
		fprintf(stderr, "pthread_attr_destroy() failed, rc=%d\n", rc);
		exit(1);
	}
	rc = pthread_join(thread, NULL);
	if(rc) {
		fprintf(stderr, "pthread_join() failed, rc=%d\n", rc);
		exit(1);
	}

	printf("Main completed\n");
	return 0;
}

/**
* Funcao executada pela thread
* @param parm Ponteiro para os parâmetros da thread (deve ser convertido para thread_parm_t *)
* @return NULL
*/
void *threadfunc(void *parm) {
	thread_parm_t *p = (thread_parm_t *)parm;
	printf("%s, parm = %d\n", p->string, p->value);
	free(p);
	return NULL;
}