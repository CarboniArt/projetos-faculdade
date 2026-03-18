/*
//ex1
#include <iostream>
#include <string>
using namespace std;
typedef struct {
    string nome;
    int idade;
    float nota;
} aluno;

int main() {
    aluno aluno1 = {"Jotape", 69, 01};
    cout << aluno1.nome << "/" << aluno1.idade << "/" << aluno1.nota << endl;
    return 0;
}
*/

/*
//ex2
#include <iostream>
#include <string>
using namespace std;
typedef struct {
    string nome;
    int idade;
    float nota;
} aluno;
int main() {
    aluno alunos[3];
    alunos[0] = {"Jotape", 69, 01};
    alunos[1] = {"Arthur", 18, 100};
    alunos[2] = {"Giovane", 25, 99};
    for (int i = 0; i<3; i++){
    cout << alunos[i].nome << "/" << alunos[i].idade << "/" << alunos[i].nota << endl;
    }
    return 0;
}
*/

/*
//ex3
#include <iostream>
#include <string>
using namespace std;
typedef struct {
    string nome;
    int idade;
    float nota;
} aluno;

int main() {
    aluno aluno1 = {"Jotape", 69, 01};
    aluno *ponteiroaluno = &aluno1;
    cout << ponteiroaluno->nome << "/" << ponteiroaluno->idade << "/" << ponteiroaluno->nota << endl;
    ponteiroaluno->idade = 55;
    ponteiroaluno->nota = 25;
    cout << ponteiroaluno->nome << "/" << ponteiroaluno->idade << "/" << ponteiroaluno->nota << endl;
    return 0;
}
*/

/*
//ex4
#include <iostream>
#include <string>
using namespace std;
typedef struct{
    string nome;
    int idade;
    float nota;
} aluno;

typedef struct{
    aluno estudante;
}curso;

int main(){
    aluno aluno1 = {"Jotape", 69, 01};
    curso cursoA = {aluno1};
    cout << cursoA.estudante.nome << "/" << cursoA.estudante.idade << "/" << cursoA.estudante.nota << endl;
    return 0;
}
*/
