#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numJogo;
    int numero[6];
} CARTELA;

int main() {

    int i, k, t;
    int quantApostas;
    int acertos, premios=0;
    int numCertos[6], counter;
    CARTELA *jogo=NULL, concurso;
    scanf("%d%*c", &quantApostas);
    jogo=(CARTELA *)malloc(quantApostas*sizeof(CARTELA));
    for(i=0; i<quantApostas; i++) {
        scanf("%d %d %d %d %d %d %d%*c", &jogo[i].numJogo, &jogo[i].numero[0], &jogo[i].numero[1], &jogo[i].numero[2], &jogo[i].numero[3], &jogo[i].numero[4], &jogo[i].numero[5]);
    }
    scanf("%d %d %d %d %d %d %d%*c", &concurso.numJogo, &concurso.numero[0], &concurso.numero[1], &concurso.numero[2], &concurso.numero[3], &concurso.numero[4], &concurso.numero[5]);
    for(i=0; i<quantApostas; i++) {
        counter=0;
        acertos=0;
        for(t=0; t<6; t++) {
            for(k=0; k<6; k++) {
                if(jogo[i].numero[t]==concurso.numero[k]) {
                    acertos++;
                    numCertos[counter]=jogo[i].numero[t];
                    counter++;
                }
            }
        }
        if(acertos==4) {
            printf("QUADRA %d: ", jogo[i].numJogo);
            for(counter=0; counter<4; counter++) {
                printf(" %d", numCertos[counter]);
            }
            printf("\n");
            premios++;
        }
        if(acertos==5) {
            printf("QUINA %d: ", jogo[i].numJogo);
            for(counter=0; counter<5; counter++) {
                printf(" %d", numCertos[counter]);
            }
            printf("\n");
            premios++;
        }
        if(acertos==6) {
            printf("SENA %d: ", jogo[i].numJogo);
            for(counter=0; counter<6; counter++) {
                printf(" %d", numCertos[counter]);
            }
            printf("\n");
            premios++;
        }
    }
    if(premios==0) printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", concurso.numJogo);

    return 0;
}