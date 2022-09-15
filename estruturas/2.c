#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char fruta[50];
    double preco;
} precos ;

typedef struct {
    char fruta[50];
    int quant;
} quantidade ;

int main () {

    int i, casos;
    int quant_vend, quant_comp;
    int c, t, m; //contadores
    double preco_total=0;
    scanf("%d", &casos);
    for(i=0; i<casos; i++) {
        scanf("%d", &quant_vend);
        precos prec[quant_vend];
        for(c=0; c<quant_vend; c++) {
            scanf("%s %lf", prec[c].fruta, &prec[c].preco);
        }
        scanf("%d", &quant_comp);
        quantidade quant[quant_comp];
        for(c=0; c<quant_comp; c++) {
            scanf("%s %d", quant[c].fruta, &quant[c].quant);
        }
        for(c=0; c<quant_comp; c++) {
            for(t=0; t<quant_vend; t++) {
                if(strcmp(prec[t].fruta, quant[c].fruta)==0) {
                    for(m=0; m<quant[c].quant; m++) {
                        preco_total+=prec[t].preco;
                    }
                }
            }
        }
        printf("R$ %.2lf\n", preco_total);
        preco_total=0;
    }

    return 0;
}