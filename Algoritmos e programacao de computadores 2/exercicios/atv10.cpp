/*
//1 
#include <iostream>
using namespace std;

int main(){
    int tamanho;
    cin >> tamanho;
    int *v = new int[tamanho];
    for (int i = 0; i < tamanho; i++){
    v[i] = i;
    cout << v[i];
    } 
    delete v;
    v = NULL;
    return 0;
}
*/

/*

//b
int main(){
    int tamanho;
    cin >> tamanho;
    int *v = new int[tamanho];
    for (int i = 0; i < tamanho; i++){
        *(v + i) = i;
    }
    for (int i = 0; i < tamanho; i++){
        cout << *(v + i) << " ";
    }
    cout << endl;
    delete v;
    v = nullptr;
    return 0;
}

/*
//c

int calculo(int quantidade){
    int nota, total = 0;
    int *v = new int[quantidade];
    for (int i = 0; i < quantidade; i++){
        cin >> nota;
        v[i] = nota;
        total += nota;
    }
    total = total / quantidade;
    delete v;
    v = NULL;
    return total;
}
int main() {
    int quantidade;
    cin >> quantidade;
    cout << calculo(quantidade) << endl;
    return 0;
}
*/

/*
//d
#include <iostream>
using namespace std;

int calculo(int quantidade) {
    int nota, total = 0;
    int *v = new int[quantidade];
    for (int i = 0; i < quantidade; i++) {
        cin >> nota;
        *(v+i) = nota;
        total += nota;
    }
    total = total / quantidade;
    delete v;
    v = NULL;
    return total;
}

int main() {
    int quantidade;
    cin >> quantidade;
    cout << calculo(quantidade) << endl;
    return 0;
}
*/
 
/*
//e 

typedef struct{
    string nome;
    int serie;
    int nota;
} aluno;

int main(){
    int t, total = 0;
    cin >> t;
    aluno* alunosNovos = new aluno[t];
    for (int i = 0; i < t; i++){
        cout << "Nome do aluno " << i + 1 << ": ";
        cin >> alunosNovos[i].nome;
        cout << "Série do aluno " << i + 1 << ": ";
        cin >> alunosNovos[i].serie;
        cout << "Nota do aluno " << i + 1 << ": ";
        cin >> alunosNovos[i].nota;
    }
    for (int i = 0; i < t; i++){
        total += alunosNovos[i].nota;
    }
    if (t > 0){
        total = total / t;
        cout << "Média das notas: " << total << endl;
    } else{
        cout << "Não há alunos para calcular a média." << endl;
    }

    delete alunosNovos;
    alunosNovos = nullptr;
    return 0;
}
*/
