#include <stdio.h>

typedef struct {
    int mat;
    int dia;
    int mes;
    int ano;
    char nome[200];
} aluno;

int ComparaDataNasc(aluno a1, aluno a2);

int main(void) {

    int num_alunos;
    int i;
    int k, t;
    scanf("%d", &num_alunos);
    aluno aluno[num_alunos], aux;
    for(i=0; i<num_alunos; i++) {
        scanf("%d %d %d %d %[^\n]%*c", &aluno[i].mat, &aluno[i].dia, &aluno[i].mes, &aluno[i].ano, aluno[i].nome);
    }
    for(k=1; k<num_alunos; k++) {
        aux=aluno[k];
        for(t=k; (t>0) && (ComparaDataNasc(aluno[t-1], aux)==0); t--) {
            aluno[t]=aluno[t-1];
        }
        aluno[t]=aux;
    }
    for(i=0; i<num_alunos; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", aluno[i].mat, aluno[i].nome, aluno[i].dia, aluno[i].mes, aluno[i].ano);
    }
    return 0;
}

int ComparaDataNasc(aluno a1, aluno a2) {
    if(a1.ano>a2.ano) return 1;
    if(a1.ano==a2.ano && a1.mes>a2.mes) return 1;
    if(a1.ano==a2.ano && a1.mes==a2.mes && a1.dia>a2.dia) return 1;
    if(a1.ano==a2.ano && a1.mes==a2.mes && a1.dia==a2.dia) return 1;
    return 0;
}