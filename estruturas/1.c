#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int den;
} fracao;

int main() {

    int i, casos;
    int tam=0, t, eq=0, c; //contadores
    char enter;
    scanf("%d", &casos);
    for(i=0; i<casos; i++) {
        fracao fra[50];
        while(enter!='\n') {
            scanf("%d/%d%c", &fra[tam].num, &fra[tam].den, &enter);
            tam++;
        }
        printf("Caso de teste %d\n", i+1);
        for(c=0; c<tam; c++) {
            for(t=c+1; t<tam; t++) {
                if((double)fra[c].num/fra[c].den == (double)fra[t].num/fra[t].den) {
                    printf("%d/%d equivalente a %d/%d\n", fra[c].num, fra[c].den, fra[t].num, fra[t].den);
                    eq++;
                }
            }
        }
        if(eq==0) printf("Nao ha fracoes equivalentes na sequencia\n");
        eq=0;
        tam=0;
        enter=' ';
    }

    return 0;
}