#include <stdio.h>
#include <omp.h>

#define tamanho 80
#define maxthreads 32

int main() {

    int a[tamanho];
    int resultado = 0;
    int resultado_local[maxthreads] = {0};
    int numero_threads = 0;

    for(int i = 0; i < tamanho; i++){
        a[i] = i;
    }

    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        numero_threads = omp_get_num_threads();

        int carga_trabalho = (tamanho + numero_threads - 1) / numero_threads;

        int inicio = ID * carga_trabalho;
        int fim = inicio + carga_trabalho;

        for(int i = inicio; (i < fim) && (i < tamanho); i++){
            resultado_local[ID] += a[i];
        }
    }

    for(int i = 0; i < numero_threads; i++){
        resultado += resultado_local[i];
    }

    printf("Resultado: %d\n", resultado);

    return 0;
}