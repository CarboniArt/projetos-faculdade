/*
//ex1
#include <iostream>
using namespace std;

int main(){
    int *p;
    int num1, num2, soma;
    cin >> num1 >> num2;
    soma = num1 + num2;
    *p=soma;
    num1 = *p - num1;
    num2 = *p - num2;
    cout << "numero 1: " << num1 << endl << "numero 2: " << num2;
}
*/

/*
//ex2
#include <iostream>
using namespace std;
int main(){
    int tam;
    int *p;
    cin >> tam;
    int v[tam];
    for(int i=0; i<tam; i++){
        cin >> v[i];
    }
    for(int i=0; i<tam; i++){
        *p = v[i];
        cout << *p << " ";
    }
}
*/

/*
//ex3
#include <iostream>
using namespace std;

void dobrar(int *num){
    (num)*=2;
}

int main(){
    int *num, pao;
    cin >> pao;
    num = &pao;
    dobrar(num);
    cout << *num;
}
*/

/*
//ex4
#include <iostream>
using namespace std;

void contarVogais(string palavra, int *p){
    for(int i=0; i<palavra.length(); i++){
        switch(palavra[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                *p+=1;
        }
    }
}

int main(){
    string palavra;
    int p=0;
    cin >> palavra;
    contarVogais(palavra, &p);
    cout << p;
}
*/


/*
//ex5
#include <iostream>
using namespace std;

void inverter(string *palavra){
    string invertida;
    for (int i = (*palavra).length() - 1; i>=0; i--){
        invertida += (*palavra)[i];
    }
    *palavra = invertida;
}

int main(){
    string palavra;
    getline (cin, palavra);
    inverter(&palavra);
    cout << palavra;
}
*/
