#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
 } FUNCIONARIO;

int main() {

    FUNCIONARIO *funcionario=NULL;
    int numFunc;
    int i;
    double mediaIdades, mediaFilhos;
    int somaIdades=0, somaFilhos=0;
    int maiorMdediaIdade=0, fMAiorMediaFilhos=0, mMaiorMediaFilhos=0, rendaPerCapitaBaixa=0;
    double rendaPerCapita;
    scanf("%d%*c", &numFunc);
    funcionario=(FUNCIONARIO *)malloc(sizeof(FUNCIONARIO)*numFunc);
    for(i=0; i<numFunc; i++) {
        scanf("%d %d %d %c %lf%*c", &funcionario[i].matricula, &funcionario[i].idade, &funcionario[i].numFilhos, &funcionario[i].sexo, &funcionario[i].salario);
        somaIdades+=funcionario[i].idade;
        somaFilhos+=funcionario[i].numFilhos;
    }
    mediaIdades=(double)somaIdades/numFunc;
    mediaFilhos=(double)somaFilhos/numFunc;
    for(i=0; i<numFunc; i++) {
        rendaPerCapita=(funcionario[i].salario/(funcionario[i].numFilhos+1));
        if(funcionario[i].idade>mediaIdades && funcionario[i].salario>3600.00) maiorMdediaIdade++;
        if(funcionario[i].sexo=='F' && funcionario[i].numFilhos>mediaFilhos) fMAiorMediaFilhos++;
        if(funcionario[i].sexo=='M' && funcionario[i].numFilhos>mediaFilhos) mMaiorMediaFilhos++;
        if(funcionario[i].idade>47 && rendaPerCapita<2400) rendaPerCapitaBaixa++;
    }
    printf("%d %d %d %d\n", maiorMdediaIdade, fMAiorMediaFilhos, mMaiorMediaFilhos, rendaPerCapitaBaixa);

    return 0;
}