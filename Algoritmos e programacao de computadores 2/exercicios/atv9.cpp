/*
//1

#include <iostream>
using namespace std;

int main(){
    int a, *p;
    p = &a;
    a = 112;
    (*p)++;
    cout << *p << endl;
    (*p)--;
    cout << *p << endl;
}
*/

/*
//2
#include <iostream>
using namespace std;
int main(){
    int a, b, *p;
    p = &a;
    a = 10;
    b = 10;
    (*p)+=b;
    cout << *p << endl;
}
*/

/*
//3
#include <iostream>
using namespace std;
int main(){
    int a, b, *p;
    p = &a;
    a = 20;
    b = 10;
    (*p)-=b;
    cout << *p << endl;
}
*/

/*
//4
#include <iostream>
using namespace std;
int main(){
    int a, b, *p, *p2;
    p = &a;
    p2 = & b;
    a = 20;
    b = 10;
    (*p) = *p - *p2;
    cout << *p << endl;
}
*/

/*
//5
#include <iostream>
using namespace std;
int main(){
    int a, b, *p, *p2;
    p = &a;
    p2 = &b;
    cin >> a >> b;
    if (*p<*p2){
        cout << "o primeiro numero e menor";
    }
    else{
        cout << "o primeiro numero nao e menor";
    }
}
*/

/*
//6
#include <iostream>
using namespace std;


void soma(int &x){
    static int c = 0;
    x += x;
    c++;
    cout << "Voce somou " << c << " vezes" << endl;
}


int main(){
    int x;
    bool y = true;
    cout << "Digite um numero" << endl;
    cin >> x;
    while(y){
        char sn;
        cout << "Deseja soma-lo com o proprio numero? (>s< para sim e >n< para nao)" << endl;
        cin >> sn;
        if(sn == 's'){
            y = true;
            soma(x);
            cout << "resultado " << x << endl;
        }
        else{
            y = false;
        }
    }
}
*/

/*
//7 
#include <iostream>
using namespace std;

int variavelGlobal = 18;

//arquivo 2

extern int variavelGlobal;

int main() {
    variavelGlobal = 32;
    cout << variavelGlobal << endl;
    return 0;
}
*/

/*
//8
#include <iostream>
using namespace std;

void incrementarVariavelRegistro(){
    static int registro = 0;
    registro++;
    cout << "Valor do registro: " << registro << endl;
}

int main(){
    for (int i = 0; i < 5; ++i){
        incrementarVariavelRegistro();
    }
    return 0;
}
*/

/*
//9
#include <iostream>
using namespace std;

int main(){
    const int tArray = 5;
    int meuArray[tArray] = {10, 20, 30, 40, 50};
    int *ponteiro = &meuArray[0];
    for (int i = 0; i < tArray; ++i){
        cout << "Elemento " << i << ": " << *(ponteiro + i) << endl;
    }
    return 0;
}
*/

/*
//10
#include <iostream>
using namespace std;
int main(){
    int v1, v2;
    cin >> v1;
    cin >> v2;
    int *p1 = &v1;
    int *p2 = &v2;
    if (p1 > p2){
        cout << "A primeira variavel esta em um endereco de memoria mais alto" << endl;
    } else if (p2 > p1){
        cout << "A segunda variavel esta em um endereco de memoria mais alto" << endl;
    } else {
        cout << "Ambos os enderecos sao os mesmos" << endl;
    }
    return 0;
}
*/
