#include <cstdio>
#define MAX(x,y) x>y?x:y
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
    int n, max, t, tt;
    scanf("%d",&n);
	max = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &t, &tt);
		t = MAX(t,tt);
        max = MAX(max,t);
	}
    printf("%d",getDepth(max));
    return 0;
}

