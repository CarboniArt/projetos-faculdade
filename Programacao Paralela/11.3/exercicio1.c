#include "omp.h"
#define tamanho 80

int main(){
    int a[tamanho], resultado;
    for(int i = 0; i < tamanho; i++)
    {
        a[i] = i;
    }


    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        int numero_threads = omp_get_num_threads();

        int carga_trabalho = (tamanho + numero_threads -1) / numero_threads;

        int inicio = ID * carga_trabalho;

        int fim = inicio + carga_trabalho;

        for(int i = inicio; (i < fim) && (i < tamanho); i++)
        {
            resultado += a[i];
        }
    }
}