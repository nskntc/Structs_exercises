#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    double valor_por_credito;
    char *curso;
} valor_por_credito_curso;

typedef struct {
    char *nome;
    int codigo;
    int quant_creditos;
} registro_aluno;

int main(int argc, char *argv[]) {

    int num_cursos, num_alunos;
    int i, c;
    double mensalidade, vcredito;
    int ncredito;
    int len;
    valor_por_credito_curso *val;
    registro_aluno *aluno;
    scanf("%d", &num_cursos);
    val=(valor_por_credito_curso *)malloc(num_cursos*sizeof(valor_por_credito_curso));
    for(i=0; i<num_cursos; i++) {
        val[i].curso=(char *)malloc(1000*sizeof(char));
        scanf("%d%*c", &val[i].codigo);
        scanf("%lf%*c", &val[i].valor_por_credito);
        scanf("%[^\n]%*c", val[i].curso);
        len=strlen(val[i].curso);
        val[i].curso=(char *)realloc(val[i].curso, (len+1));
    }
    scanf("%d%*c", &num_alunos);
    aluno=(registro_aluno *)malloc(num_alunos*sizeof(registro_aluno));
    for(i=0; i<num_alunos; i++) {
        aluno[i].nome=(char *)malloc(1000*sizeof(char));
        scanf("%[^\n]%*c", aluno[i].nome);
        scanf("%d%*c", &aluno[i].codigo);
        scanf("%d%*c", &aluno[i].quant_creditos);
        len=strlen(aluno[i].nome);
        aluno[i].nome=(char *)realloc(aluno[i].nome, (len+1));
    }
    for(i=0; i<num_alunos; i++) {
        for(c=0; c<num_cursos; c++) {
            if(aluno[i].codigo==val[c].codigo) {
                ncredito=aluno[i].quant_creditos;
                vcredito=val[c].valor_por_credito;
                mensalidade=ncredito*vcredito;
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n", aluno[i].nome, val[c].curso, aluno[i].quant_creditos, val[c].valor_por_credito, mensalidade);

            }
        }
    }
    for(i=0; i<num_alunos; i++) free(aluno[i].nome);
    for(i=0; i<num_cursos; i++) free(val[i].curso);
    

    return 0;
}