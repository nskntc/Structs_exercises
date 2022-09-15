#include <stdio.h>
#include <stdlib.h>

int main() {

    char *v;
    int i, n;
    scanf("%d%*c", &n);
    v=(char *)malloc(sizeof(char)*n);
    for(i=0; i<n; i++) {
        scanf("%c%*c", &v[i]);
    }
    for(i=0; i<n; i++) {
        printf("%s\n", v);
    }

    return 0;
}