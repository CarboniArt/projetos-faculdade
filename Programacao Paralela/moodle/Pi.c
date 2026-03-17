#include <stdio.h>
#include <omp.h>
#define n 100000

double calc(double x) {
    return (4.0 / (1.0 + x * x));
}

int main() {
    double resultado = 0;
    double X0 = 0, X1 = 1;
    double dx = (X1 - X0) / n;
    int num_threads = omp_get_max_threads();
    double somas_parciais[num_threads];

    
    for (int i = 0; i < num_threads; i++) {
        somas_parciais[i] = 0;
    }

    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        
        for (int i = ID; i < n; i += num_threads) {
            double temp = calc(X0 + i * dx);
            somas_parciais[ID] += temp * dx;
        }

        printf("Thread: %d: %f\n", ID, somas_parciais[ID]);
    }

    for (int i = 0; i < num_threads; i++) {
        resultado += somas_parciais[i];
    }

    printf("Resultado final: %f\n", resultado);
    return 0;
}