#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct {
    double u;
    double x;
    double y;
    double z;
} pontos;
 
int main() {
 
    int num_pontos;
    int i;
    double dist;
    pontos *ponto;
    scanf("%d", &num_pontos);
    ponto=(pontos *)malloc(num_pontos*sizeof(pontos));
    scanf("%lf %lf %lf %lf", &ponto[0].u, &ponto[0].x, &ponto[0].y, &ponto[0].z);
    for(i=1; i<num_pontos; i++) {
        scanf("%lf %lf %lf %lf", &ponto[i].u, &ponto[i].x, &ponto[i].y, &ponto[i].z);
        dist=sqrt(pow((ponto[i-1].u-ponto[i].u), 2)+pow((ponto[i-1].x-ponto[i].x), 2)+pow((ponto[i-1].y-ponto[i].y), 2)+pow((ponto[i-1].z-ponto[i].z), 2));
        printf("%.2lf\n", dist);
    }
    free(ponto);
 
    return 0;
}