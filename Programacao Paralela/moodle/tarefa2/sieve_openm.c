#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 1000

int main() {
    int is_prime[N + 1];
    int i, j;
    int count = 0;
    int num_threads_used = 0;

    #pragma omp parallel for schedule(static) shared(is_prime)
    for (i = 0; i <= N; i++) {
        is_prime[i] = (i >= 2) ? 1 : 0;
    }


    int limit = (int)sqrt((double)N);
    for (i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            #pragma omp parallel for private(j) shared(is_prime) schedule(static)
            for (j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }


    #pragma omp parallel for schedule(static) reduction(+:count) shared(is_prime)
    for (i = 2; i <= N; i++) {
        if (is_prime[i])
            count++;
    }


    #pragma omp parallel shared(num_threads_used)
    {
        #pragma omp single
        num_threads_used = omp_get_num_threads();
    }


    printf("Sieve of Eratosthenes [1, %d] — OpenMP parallel\n\n", N);
    printf("Threads used: %d\n", num_threads_used);
    printf("Total primes found: %d\n\n", count);

    printf("Prime numbers:\n");
    int col = 0;
    for (i = 2; i <= N; i++) {
        if (is_prime[i]) {
            printf("%4d", i);
            col++;
            if (col % 15 == 0) printf("\n");
        }
    }
    if (col % 15 != 0) printf("\n");

    return 0;
}