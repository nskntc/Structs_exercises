#include <stdio.h>

typedef struct {
    int num;
    int den;
} tRacional;

int MDC(int x, int y);

tRacional racional(int a, int b);

void negativo(tRacional r);

tRacional soma(tRacional r1, tRacional r2);

tRacional sub(tRacional r1, tRacional r2);

tRacional mult(tRacional r1, tRacional r2);

tRacional div(tRacional r1, tRacional r2);

tRacional reduzFracao(tRacional r);

int main(void) {

    tRacional r1, r2, r3, r3red;
    int a, b;
    char op;
    while (scanf("%d %d %c %d %d", &r1.num, &r1.den, &op, &r2.num, &r2.den)!=EOF) {
        if(op=='+') {
            r3=soma(r1, r2);
            r3red=reduzFracao(r3);
            printf("%d %d\n", r3red.num, r3red.den);
        }
        if(op=='-') {
            r3=sub(r1, r2);
            r3red=reduzFracao(r3);
            printf("%d %d\n", r3red.num, r3red.den);
        }
        if(op=='*') {
            r3=mult(r1, r2);
            r3red=reduzFracao(r3);
            printf("%d %d\n", r3red.num, r3red.den);
        }
        if(op=='/') {
            r3=div(r1, r2);
            r3red=reduzFracao(r3);
            printf("%d %d\n", r3red.num, r3red.den);
        }
    }

    return 0;
}

int MDC(int x, int y) {
    int i, c;
    if(x<0) x=-x;
    if(y<0) y=-y;
    for(i=x; i>=1; i--) {
        for(c=y; c>=1; c--) {
            if(i==c && y%c==0 && x%i==0) return i;
        }
    }
}

tRacional racional(int a, int b) {
    tRacional fra;
    fra.num=a;
    fra.den=b;
    return fra;
}

void negativo(tRacional r) {
    if(r.num<0 && r.den<0) {
        r.num=-r.num;
        r.den=-r.den;
    }
}

tRacional soma(tRacional r1, tRacional r2) {
    tRacional r3;
    negativo(r1);
    negativo(r2);
    r3.den=r1.den*r2.den;
    r3.num=((r3.den/r1.den)*r1.num)+((r3.den/r2.den)*r2.num);
    return r3;
}

tRacional sub(tRacional r1, tRacional r2) {
    tRacional r3;
    negativo(r1);
    negativo(r2);
    r3.den=r1.den*r2.den;
    r3.num=((r3.den/r1.den)*r1.num)-((r3.den/r2.den)*r2.num);
    return r3;
}

tRacional mult(tRacional r1, tRacional r2) {
    tRacional r3;
    r3.num=r1.num*r2.num;
    r3.den=r1.den*r2.den;
    return r3;
}

tRacional div(tRacional r1, tRacional r2) {
    int t;
    tRacional r3;
    t=r2.num;
    r2.num=r2.den;
    r2.den=t;
    r3=mult(r1, r2);
    return r3;
}

tRacional reduzFracao(tRacional r) {
    tRacional r2;
    int mdc;
    mdc=MDC(r.num, r.den);
    if(mdc>0) {
        r2.num=(r.num/mdc);
        r2.den=(r.den/mdc);
    }
    return r2;
}