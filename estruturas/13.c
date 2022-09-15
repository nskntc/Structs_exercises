#include <stdio.h>
#include <math.h>

typedef struct {
    double r, i;
} Complex;

typedef struct {
    Complex r[2];
} RaizEq2;

RaizEq2 calc_RaizEq2(double a, double b, double c);

int main() {

    double a, b, c;
    RaizEq2 raiz;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        raiz=calc_RaizEq2(a, b, c);
        printf("X1 = ");
        if(raiz.r[0].r!=0 && raiz.r[0].i!=0)printf("%.2lf", raiz.r[0].r);
        if(raiz.r[0].i==1) printf("+i");
        if(raiz.r[0].i==-1) printf("-i");
        printf("\n");
        printf("X2 = ");
        if(raiz.r[1].r!=0 && raiz.r[1].i!=0)printf("%.2lf", raiz.r[1].r);
        if(raiz.r[1].i==1) printf("+i");
        if(raiz.r[1].i==-1) printf("-i");
        printf("\n");
    }


    return 0;
}

RaizEq2 calc_RaizEq2(double a, double b, double c) {
    RaizEq2 raiz;
    double delta;
    delta=b*b-4*a*c;
    if(delta==0) {
        raiz.r[0].r=-b/(2*a);
        raiz.r[0].i=0;
        raiz.r[1]=raiz.r[0];
        return raiz;
    }
    else if(delta<0) {
        delta=sqrt(-delta);
        raiz.r[0].r=-b/(2*a);
        raiz.r[0].i=delta/(2*a);
        raiz.r[1].r=-b/(2*a);
        raiz.r[1].i=-delta/(2*a);
        return raiz;
    }
    else {
        delta=sqrt(delta);
        raiz.r[0].r=(-b+delta)/(2*a);
        raiz.r[0].i=0;
        raiz.r[1].r=(-b-delta)/(2*a);
        raiz.r[1].i=0;
        return raiz;
    }
}