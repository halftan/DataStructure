#include <cstdio>

int
pow(int n){
    int t = 1;
    while(n-- > 0)
        t *= 2;
    return t;
}

int
getDepth(int n){
    int i = 0;
    int sum = 0;
    while( (sum += pow(i++)) < n);
    return i;
}

int main(void){
    int n;
    scanf("%d",&n);
    printf("%d",getDepth(n));
    return 0;
}

