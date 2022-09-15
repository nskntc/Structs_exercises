#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int moradores;
    int cons;
    int cons_pessoas;
} predios;

int main(void) {

    int im;
    int i, cidade=0; //contadores
    double cons_medio;
    predios *predio;
    int k, t; //contadores para ordenar o vetor
    predios aux; //aux para ordena ro vetor
    int soma_pess, soma_cons;
    int npessoas;
    while(1) {
        scanf("%d", &im);
        predio=(predios *)malloc(im*sizeof(predios));
        if(im==0) break;
        cidade++;
        soma_pess=0;
        soma_cons=0;
        for(i=0; i<im; i++) {
            scanf("%d %d", &predio[i].moradores, &predio[i].cons);
            predio[i].cons_pessoas=predio[i].cons/predio[i].moradores;
            soma_pess+=predio[i].moradores;
            soma_cons+=predio[i].cons;
        }
        for(k=1; k<im; k++) {
            aux=predio[k];
            for(t=k; (t>0) && (aux.cons_pessoas<predio[t-1].cons_pessoas); t--) {
                predio[t]=predio[t-1];
            }
            predio[t]=aux;
        }
        cons_medio=(double)soma_cons/soma_pess;
        printf("Cidade# %d:\n", cidade);
        npessoas=predio[0].moradores;
        for(i=0; i<im; i++) {
            if(predio[i].cons_pessoas==predio[i+1].cons_pessoas) npessoas+=predio[i+1].moradores;
            if(predio[i].cons_pessoas!=predio[i+1].cons_pessoas) {
                printf("%d-%d ", npessoas, predio[i].cons_pessoas);
                npessoas=predio[i+1].moradores;
            }
        }
        printf("\n");
        printf("Consumo medio: %.2lf m3.\n\n", cons_medio);
        free(predio);
    }

    return 0;
}