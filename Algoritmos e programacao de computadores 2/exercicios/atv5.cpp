#include <iostream>
#include <iomanip>
using namespace std;

/*
//A1
void ordem(int* , int*);

int main (){
    cin >> x >> y;
    ordem(&x , &y);
}
  
  void ordem(int *x , int *y){
    int aux;
    if(*x > *y){
        aux = *x;
        *x = *y;
        *y = aux;
    }
    cout << "a ordem e: " << *x << " , " << *y << endl;
}
*/

/*
//A2
void decimal(double*);

int main (){
    double b;
    cin >> b;
    decimal(&b);
}

void decimal(double *b){
    int i = 0;
    double d = 0;
    i = *b;
    d = *b - i;
    cout << "a parte inteira e " << i << " e a parte decimal e " << d << endl;
}

/*
//b
bool has_zero(int[], int);

int main(){
    int y, x;
    cin >> y;
    int *a = new int[y];
    for (x = 0; x < y; x++){
        cin >> a[x];
    }
    cout << has_zero(a, y);
    delete[] a;
}

bool has_zero(int a[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] == 0) {
            return true;
        }
    }
    return false;
}
*/

/*
//c1 
int main(){
    int x, y, a[N];
    cin >> x;
    for (y = 0; y < x; y++){
        cin >> a[y];
    }
    cout << "o maior valor deste vetor e: " << maiorValor(x , a) << endl << endl;
}

int maiorValor(int x , int a[]){
    int maior = INT16_MIN;
    for(int i = 0; i < x; i++){
        if(a[i] > maior){
            maior = a[i];
        }
    }
    return maior;
}
*/

/*
//c2 
int media(int x, int a[]);

int main(){
    int x;
    cin >> x;
    int a[x]; 
    for (int y = 0; y < x; y++){
        cin >> a[y];
    }
    cout << "Media = " << media(x, a) << endl;
    return 0; 
}

int media(int x, int a[]){
    int soma = 0, media = 0;
    for (int i = 0; i < x; i++){
        soma += a[i];
    }
    media = soma / x;
    return media;
}
*/

/*
//c3 
#include <iostream>
using namespace std;

int positivos(int a[] , int x);

int main(){
    int x;
    cin >> x;
    int a[x]; 
    for (int y = 0; y < x; y++){
        cin >> a[y];
    }
    cout << "Positivos " << positivos(a , x) << endl;
    return 0; 
}

int positivos(int a[] , int x)
{
    int i , contagem = 0;
    for(i = 0; i < x; i++){
        if(a[i] > 0){
            contagem++;
        }
    }
    return contagem;
}
*/

/*
//c4
#include <iostream>
using namespace std;

void preencherVetor(int* vetor, int tamanho);

void apresentarVetor(int* vetor, int tamanho);

int main(){
    int n;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    int* vetor = new int[n];
    preencherVetor(vetor, n); 
    apresentarVetor(vetor, n); 
    delete[] vetor;

    return 0;
}

void preencherVetor(int* vetor, int tamanho){
    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> vetor[i];
    }
}

void apresentarVetor(int* vetor, int tamanho){
    cout << "Valores no vetor: ";
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}
*/

//6) Na linha 16, é impresso o valor de *ss, que é inicializado como 0 na função e tem i somado a ele sempre que x (inicializado como a) é divisível por i, até que i seja igual a c.

//7) Na linha 19, é feita uma decisão para determinar se o número possui a característica desejada. Isso ocorre quando o quadrado da soma do resto da divisão desse número por 100 é igual ao próprio número.

//8) A linha imprime a quantidade de divisores que um número possui.

//1) Na linha 16, é impresso o valor de s, que é inicializado como 0 na função e tem i somado a ele conforme x (inicializado como a) é divisível por i, até que i seja igual a c.

//2) Na linha 19, é feita uma decisão para determinar se o número possui a característica desejada. Isso ocorre quando o quadrado da soma do resto da divisão desse número por 100 é igual ao próprio número.

//3) Na linha 16, é impresso o valor de s, que na função é inicializado como 0 e tem i somado a ele conforme i (inicializado como b) é divisível por a, até que i seja igual a c.

