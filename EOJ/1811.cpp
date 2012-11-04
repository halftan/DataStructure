#include <cstdio>
#include <cstdlib>

int
main(void){
    int n,N;
    int mod,ch,lev;
    int *mp;
    scanf("%d",&n);
    N = n;
    mp = (int*)calloc(sizeof(int), n*n);
    do{
        scanf("%c%d%c%c%c",&mod,&lev,&mod,&ch,&mod);
        if(mod == ')')--n;
        int t = 0;
        while(*(mp + lev * N + t))++t;
        *(mp + lev * N + t) = ch;
    }while(n > 0);
    for(int i = N - 1; i >= 0; --i)
        for(int j = 0; j < N; ++j)
            if(mp[i * N + j])
                putchar(mp[i * N + j]);
    free(mp);
    return 0;
}

    
