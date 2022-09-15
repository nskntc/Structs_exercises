#include <stdio.h>

struct data{
        int dia;
        int mes;
        int ano;
    };

void data_print(struct data d);

int main(int argc, char *argv[]) {
    
    struct data nasc, vacina; //variaveis nasc e vacina serao do tipo struct data.
    nasc.dia=25;
    nasc.mes=4;
    nasc.ano=2002;

    vacina.dia=22;
    vacina.mes=2;
    vacina.ano=2022;

    data_print(nasc);
    data_print(vacina);

    return 0;
}

void data_print(struct data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}