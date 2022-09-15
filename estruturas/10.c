#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double coef;
    int exp;
} polinomios;

void le_poli(int n, polinomios *p);

void sum_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2);

void sub_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2);

void print_poli(polinomios *p, int n);

void ordena_poli(polinomios *p3, int n);

int main(void) {

    int casos, i;
    char op;
    int num_termosp1, num_termosp2;
    polinomios *p1, *p2, *res;
    scanf("%d%*c", &casos);
    for(i=0; i<casos; i++) {
        scanf("%c", &op);
        scanf("%d%*c", &num_termosp1);
        p1=(polinomios *)calloc(num_termosp1, sizeof(polinomios));
        le_poli(num_termosp1, p1);
        scanf("%d%*c", &num_termosp2);
        p2=(polinomios *)calloc(num_termosp2, sizeof(polinomios));
        le_poli(num_termosp2, p2);
        res=(polinomios *)calloc((num_termosp1+num_termosp2), sizeof(polinomios));
        if(op=='+') sum_poli(p1, p2, res, num_termosp1, num_termosp2);
        if(op=='-') sub_poli(p1, p2, res, num_termosp1, num_termosp2);
        print_poli(res, (num_termosp1+num_termosp2));
        free(p1);
        free(p2);
        free(res);
    }

    return 0;
}

void le_poli(int n, polinomios *p) {
    int i;
    for(i=0; i<n; i++) {
        scanf("%lf %d%*c", &p[i].coef, &p[i].exp);
        if(p[i].exp==32) p[i].exp=0;
    }
}

void sum_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2) {
    int i, c, r, k;
    for(i=0; i<n1; i++) {
        r=0;
        for(c=0; c<n2; c++) {
            if(p1[i].exp==p2[c].exp) {
                p3[i].coef=p1[i].coef+p2[c].coef;
                p3[i].exp=p1[i].exp;
                r++;
            }
        }
        if(r==0) {
            p3[i].coef=p1[i].coef;
            p3[i].exp=p1[i].exp;
        }
    }
    for(c=0; c<n2; c++) {
        r=0;
        for(k=0; k<n1; k++) {
            if(p2[c].exp==p1[k].exp) r++;
        }
        if(r==0) {
            p3[i].coef=p2[c].coef;
            p3[i].exp=p2[c].exp;
            i++;
        }
    }
    ordena_poli(p3, (n1+n2));
}

void sub_poli(polinomios *p1, polinomios *p2, polinomios *p3, int n1, int n2) {
    int i, c, r, k;
    for(i=0; i<n1; i++) {
        r=0;
        for(c=0; c<n2; c++) {
            if(p1[i].exp==p2[c].exp) {
                p3[i].coef=p1[i].coef-p2[c].coef;
                p3[i].exp=p1[i].exp;
                r++;
            }
        }
        if(r==0) {
            p3[i].coef=p1[i].coef;
            p3[i].exp=p1[i].exp;
        }
    }
    for(c=0; c<n2; c++) {
        r=0;
        for(k=0; k<n1; k++) {
            if(p2[c].exp==p1[k].exp) r++;
        }
        if(r==0) {
            p3[i].coef=p2[c].coef;
            p3[i].exp=p2[c].exp;
            i++;
        }
    }
    ordena_poli(p3, (n1+n2));
}

void print_poli(polinomios *p, int n) {
    int i;
    for(i=0; i<n; i++) {
        if(p[i].coef>0 && p[i].exp!=0) printf("+%.2lfX^%d", p[i].coef, p[i].exp);
        if(p[i].coef>0 && p[i].exp==0) printf("+%.2lf", p[i].coef);
        if(p[i].coef<0 && p[i].exp==0) {
            printf("%.2lf", p[i].coef);
        }
        if(p[i].coef<0 && p[i].exp!=0) {
            printf("%.2lfX^%d", p[i].coef, p[i].exp);
        }
    }
    printf("\n");
}

void ordena_poli(polinomios *p3, int n) {
    int k2, t;
    polinomios aux;
    for(k2=1; k2<n; k2++) {
        aux=p3[k2];
        for(t=k2; (t>0) && (aux.exp>p3[t-1].exp); t--) {
            p3[t]=p3[t-1];
        }
        p3[t]=aux;
    }
    
}
