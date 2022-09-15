#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double ca;
    double cb;
    double cc;
    double cd;
    double norma;
} coordenada_norma;

int main() {

    int num_pontos, i;
    int c;
    double ca, cb, cc, cd; //contadores
    int k, t; //contadores para ordenar o vetror
    scanf("%d", &num_pontos);
    coordenada_norma cn[num_pontos], aux;
    for(c=0; c<num_pontos; c++) {
        scanf("%lf %lf %lf %lf%*c", &cn[c].ca, &cn[c].cb, &cn[c].cc, &cn[c].cd);
        ca=cn[c].ca;
        cb=cn[c].cb;
        cc=cn[c].cc;
        cd=cn[c].cd;
        cn[c].norma=sqrt(pow(ca, 2)+pow(cb, 2)+pow(cc, 2)+pow(cd, 2));
    }
    for(k=1; k<num_pontos; k++) {
        aux=cn[k];
        for(t=k; (t>0) && (aux.norma<cn[t-1].norma); t--) {
            cn[t]=cn[t-1];
        }
        cn[t]=aux;
    }
    for(i=0; i<num_pontos; i++) {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", cn[i].ca, cn[i].cb, cn[i].cc, cn[i].cd, cn[i].norma);
    }
    return 0;
}