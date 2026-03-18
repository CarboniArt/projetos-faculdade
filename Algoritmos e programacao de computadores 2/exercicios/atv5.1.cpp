/* 
//ex1
#include <iostream>
using namespace std;

int multiplicacao(int numero1, int numero2);

int main(){
    int num1;
    cin >> num1;
    int num2;
    cin >> num2;
    int resultado = multiplicacao(num1, num2);
    cout << "O resultado da multiplicação é: " << resultado << endl;
    return 0;
}

int multiplicacao(int numero1, int numero2){
    int resultado = numero1 * numero2;
    return resultado;
}
*/

/* 
//ex2
#include <iostream>
using namespace std;

int multiplicacao(int &numero1, int &numero2);

int main(){
    int num1;
    cin >> num1;
    int num2;
    cin >> num2;
    int resultado = multiplicacao(num1, num2);
    cout << "Resultado da multiplicação: " << resultado << endl;

    return 0;
}

int multiplicacao(int &numero1, int &numero2){
    int resultado = numero1 * numero2;
    return resultado;
}
*/

/*
//ex3
#include <iostream>
using namespace std;

int soma(int numero1);

int main(){
    int num1;
    cin >> num1;
    int resultado = soma(num1);
    cout << "Resultado da soma: " << resultado << endl;

    return 0;
}

int soma(int numero1){
    int resultado = numero1 + 10;
    return resultado;
}
*/

/*
//ex4
#include <iostream>
using namespace std;

int soma(int &numero1);

int main(){
    int num1;
    cin >> num1;
    int resultado = soma(num1);
    cout << "Resultado da soma: " << resultado << endl;

    return 0;
}

int soma(int &numero1){
    int resultado = numero1 + 10;
    return resultado;
}
*/

/*
//ex5
#include <iostream>
using namespace std;

int subtracao(int numero1);

int main(){
    int num1;
    cin >> num1;
    int resultado = subtracao(num1);
    cout << "Resultado da subtracao: " << resultado << endl;

    return 0;
}

int subtracao(int numero1){
    int resultado = numero1 - 5;
    return resultado;
}
*/

/*
//ex6
#include <iostream>
using namespace std;

int subtracao(int &numero1);

int main(){
    int num1;
    cin >> num1;
    int resultado = subtracao(num1);
    cout << "Resultado da subtracao: " << resultado << endl;

    return 0;
}

int subtracao(int &numero1){
    int resultado = numero1 - 5;
    return resultado;
}
*/

/*
//ex7
#include <iostream>
using namespace std;
void vet(int x[]);
int main(){
int x[8], y;
for(int i=0; i<8; i++){   
    cin >> y;
    x[i]=y;
}
vet(x);
}
void vet(int x[]){
    int aux=7;
    int xcerto[8];
    for(int i=0; i<8; i++){
        xcerto[i]=x[aux];
        aux--;
    }
    for(int i=0; i<8; i++){
        cout << xcerto[i];
    }
}
*/

/*
//ex8
#include <iostream>
using namespace std;

void inverter(string *palavra)

int main(){
    string palavra;
    getline (cin, palavra);
    inverter(&palavra);
    cout << palavra;
}

void inverter(string *palavra){
    string invertida;
    for (int i = (*palavra).length() - 1; i>=0; i--){
        invertida += (*palavra)[i];
    }
    *palavra = invertida;
}

*/
