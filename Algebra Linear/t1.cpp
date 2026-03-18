//soma
#include <iostream>

using namespace std;

void lerMatriz(int matriz[][100], int linhas, int colunas) {
    cout << "Insira os valores da matriz:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> matriz[i][j];
        }
    }
}

void somarMatrizes(int matriz1[][100], int matriz2[][100], int resultado[][100], int linhas, int colunas) {
    cout << "Soma das matrizes:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int linha1, coluna1, linha2, coluna2;

    do {
        cout << "Insira o numero de linhas e colunas da primeira matriz: ";
        cin >> linha1 >> coluna1;
        cout << "Insira o numero de linhas e colunas da segunda matriz: ";
        cin >> linha2 >> coluna2;

        if (coluna1 == coluna2 && linha1 == linha2) {
            break;
        } else {
            cout << "O numero de linhas e colunas da primeira matriz deve ser igual ao da segunda matriz!" << endl;
        }
    } while (true);

    int matriz1[100][100];
    int matriz2[100][100];
    int resultado[100][100];

    lerMatriz(matriz1, linha1, coluna1);
    lerMatriz(matriz2, linha2, coluna2);

    somarMatrizes(matriz1, matriz2, resultado, linha1, coluna1);

    return 0;
}


//subtracao
#include <iostream>

using namespace std;

void lerMatriz(int matriz[][100], int linhas, int colunas) {
    cout << "Insira os valores da matriz:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> matriz[i][j];
        }
    }
}

void subtrairMatrizes(int matriz1[][100], int matriz2[][100], int resultado[][100], int linhas, int colunas) {
    cout << "Subtracao das matrizes:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int linha1, coluna1, linha2, coluna2;

    do {
        cout << "Insira o numero de linhas e colunas da primeira matriz: ";
        cin >> linha1 >> coluna1;
        cout << "Insira o numero de linhas e colunas da segunda matriz: ";
        cin >> linha2 >> coluna2;

        if (coluna1 == coluna2 && linha1 == linha2) {
            break;
        } else {
            cout << "O numero de linhas e colunas da primeira matriz deve ser igual ao da segunda matriz!" << endl;
        }
    } while (true);

    int matriz1[100][100];
    int matriz2[100][100];
    int resultado[100][100];

    lerMatriz(matriz1, linha1, coluna1);
    lerMatriz(matriz2, linha2, coluna2);

    subtrairMatrizes(matriz1, matriz2, resultado, linha1, coluna1);

    return 0;
}




//gaus
#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;

void imprimirMatriz(float **matriz, int linhas);
void resolverMatrizSuperior(float **matrizAumentada, int linhas);
float** eliminacaoDeGauss(float **matrizAumentada, int linhas);

float** eliminacaoDeGauss(float **matrizAumentada, int linhas) {
    float **matriz = matrizAumentada;
    int n = linhas;

    if (matriz[linhas - 1][linhas - 1] == 0.0) {
        exit(-1);
    }

    float m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m = matriz[j][i] / matriz[i][i];
            matriz[j][i] = 0;
            for (int k = i + 1; k < n; k++) {
                matriz[j][k] += -(m * matriz[i][k]);
            }
            matriz[j][n] += -(m * matriz[i][n]);
        }
    }

    return matriz;
}

void resolverMatrizSuperior(float **matrizAumentada, int linhas) {
    float **matriz = matrizAumentada;
    int n = linhas;
    float solucoes[n];
    float soma = 0;

    solucoes[n - 1] = matriz[n - 1][n] / matriz[n - 1][n - 1];
    for (int i = n - 1; i >= 0; i--) {
        soma = 0;
        for (int j = i + 1; j < n; j++) {
            soma += matriz[i][j] * solucoes[j];
        }
        solucoes[i] = (matriz[i][n] - soma) / matriz[i][i];
    }

    cout << "Solucoes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solucoes[i] << endl;
    }
    cout << endl;
}

void imprimirMatriz(float **matriz, int linhas) {
    int n = linhas;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j < n)
                cout << matriz[i][j] << "x" << j + 1 << " ";
            else
                cout << " = " << matriz[i][j];
        }
        cout << endl;
    }
}

float** scanearMatriz(int linhas) {
    float **matriz = (float **)malloc(sizeof(float *) * linhas);
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (float *)malloc(sizeof(float) * (linhas + 1));
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < linhas + 1; j++) {
            cin >> matriz[i][j];
        }
    }
    return matriz;
}

int main() {
    setlocale(LC_CTYPE, "");

    cout << "Bem-vindo ao metodo de eliminacao de Gauss" << endl;
    cout << "Qual e a ordem da matriz? ";

    int linhas;
    cin >> linhas;
    cout << "Sua matriz e " << linhas << "x" << linhas << "!" << endl;

    cout << "Equacao inicial" << endl;
    float **matrizAumentada = scanearMatriz(linhas);
    float **resultado = eliminacaoDeGauss(matrizAumentada, linhas);

    cout << "Equacao final" << endl;
    imprimirMatriz(resultado, linhas);
    cout << endl;

    resolverMatrizSuperior(resultado, linhas);

    for (int i = 0; i < linhas; i++) {
        free(matrizAumentada[i]);
    }
    free(matrizAumentada);

    return 0;
}