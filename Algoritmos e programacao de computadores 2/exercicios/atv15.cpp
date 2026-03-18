//ex 1
#include <iostream>
#define N 5
using namespace std;


int busca_sequencial(int *v, int x);

int main(){
    int v[N] = {1, 3, 5, 7, 9,};
    int indice, x;
    x = 8;
    indice = busca_sequencial (v, x);
    cout << "O índice j tal que v[j] < x ≤ v[j+1] e " << indice;
    return 0;
}

int busca_sequencial(int *v, int x){
    int j = 0; 
    while (j < N && v[j] < x) {
        j++;
    }
    return j;
}

//ex 2
int busca_bin_r(int x, int *v, int inicio, int fim){
    int meio;
    if (inicio > fim){
        return -1;
    } 
    else{
        meio = (inicio + fim) / 2;
    }
    if ((meio == 0 || x > v[meio - 1]) && x <= v[meio]){
        return meio;
    }
    else if (x <= v[meio]){
            return busca_bin_r(x, v, inicio, meio - 1);
        }
        else{
            return busca_bin_r(x, v, meio + 1, fim);
        }
}

//ex 3 
int busca_sequencial(int x, int *v, int n){
    if (n == 0){
        return 0;
    }
    if (v[n-1] == x){
        return n-1;
    }
    busca_sequencial(x, v, n-1);
}

//ex 4
int busca_bin_r(int x, int *v, int inicio, int fim){
    int meio;
    if (inicio > fim){
        return -1;
    }
    else{
        meio = (inicio + fim)/2;
    }
    if (x >= v[meio]){
        return meio;
    }
    else if (x < v[meio]){
        busca_bin_r(x, v, inicio, meio - 1);
    }
    else{
        busca_bin_r(x, v, meio + 1, fim);
    }
}

//ex5
