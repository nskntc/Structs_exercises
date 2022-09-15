#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int likes;
    int retweets;
    int mencoes;
} Twitter;

int main() {

    Twitter **A=NULL;
    int dim, ocup;
    int l, c, maiorL=0;
    int i;
    int somaLikes=0, somaret=0, somaMen=0;
    int likes, ret, men;
    int slotsVazios;
    scanf("%d%*c",&dim);
    scanf("%d%*c", &ocup);
    A=(Twitter **)malloc(dim*sizeof(Twitter *));
    for(l=0; l<dim; l++) {
        A[l]=(Twitter *)malloc(dim*sizeof(Twitter));
    }
    if(A==NULL) exit(1);
    for(i=0; i<ocup; i++) {
        scanf("%d %d%*c", &l, &c);
        if(l>maiorL) maiorL=l;
        scanf("%d %d %d%*c", &((A[l][c]).likes), &((A[l][c]).retweets), &((A[l][c]).mencoes));
    }
    for(l=0; l<=maiorL; l++) {
        likes=0;
        ret=0;
        men=0;
        for(c=0; c<dim; c++) {
            likes+=A[l][c].likes;
            ret+=A[l][c].retweets;
            men+=A[l][c].mencoes;
        }
        printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", l, likes, ret, men);
        somaLikes+=likes;
        somaret+=ret;
        somaMen+=men;
    }
    slotsVazios=(dim*dim)-ocup;
    printf("Slots vazios: %d\n", slotsVazios);
    printf("Media de likes por usuario: %.2lf\n", ((double)somaLikes/(maiorL+1)));
    printf("Media de retweets por usuario: %.2lf\n", ((double)somaret/(maiorL+1)));
    printf("Media de mencoes por usuario: %.2lf\n", ((double)somaMen/(maiorL+1)));
    for(l=0; l<dim; l++) {
        free(A[l]);
    }
    free(A);
    
    return 0;
}