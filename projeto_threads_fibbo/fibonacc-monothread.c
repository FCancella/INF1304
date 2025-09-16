#include <stdio.h>
#include <stdlib.h>

#define EVER ;;

long qtd = 0;

struct lista_fibonacci {
    int valor;
    long chamadas;
    struct lista_fibonacci *proximo;
};

// cada task é uma lista encadeada de fibos (sequencia até um certo limite)
struct lista_tasks {
    struct lista_fibonacci *fibos;
    struct lista_tasks *proximo;
};

long fibonacci(int n) {
    qtd++;
    
    // Monothread recursive Fibonacci (inefficient)
    // if (n <= 1)
    //     return n;
    // return fibonacci(n - 1) + fibonacci(n - 2);
    
    long a=0, b=1, c;
    if (n == 0) return 0;
    for (int i=2; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(void) {
    struct lista_tasks *new_task = NULL; // head da lista de tasks
    // if (new_task == NULL) {
    //     pass;
    // }
    int i;
    long result;
    for (long limit=0;;limit++) {
        struct lista_tasks *new_task = malloc(sizeof(struct lista_tasks));
        new_task->fibos = NULL;
        new_task->proximo = tasks;
        tasks = new_task;
        // aq comeca uma nova task
        for (i=0;i<limit;i++){
            result = fibonacci(i);
            struct lista_fibonacci *new_fibo = malloc(sizeof(struct lista_fibonacci));
            new_fibo->valor = result;
            new_fibo->chamadas = qtd;
            new_fibo->proximo = NULL;

            qtd = 0;
            printf("(%d) Fib: %ld - Chamadas: %ld\n", i, result, qtd); // Cálculo ineficiente de Fibonacci
        
            // para casa
        
        }
        // COLOCA OS RESULTADOS DO FIBO EM UMA LISTA ENCADEADA (TAREFA CPU BOUND QUE GASTA POUCA MEMORIA)
        // aq termina uma nova task
    }
        return 0;
}