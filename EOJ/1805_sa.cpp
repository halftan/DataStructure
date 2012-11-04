#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 100250

typedef struct{
    char *adr;
    int height;
}foo;

int
cmp(const void *a,const void *b){
    return strcmp(((foo *)a)->adr, ((foo *)b)->adr); 
}

int
cmp_h(const void *a, const void *b){
    return ((foo *)b)->height - ((foo *)a)->height;
}

int
main(int argc, char **argv){
    char str[MAX];
    foo info[MAX];
    memset(info, 0, sizeof(foo) * MAX);
    char ch;
    char *seperator = NULL;
    int i = 0;
    while( (ch = getchar()) != '\n' && ch != EOF){
        str[i] = ch;
        info[i].adr = str + i;
        ++i;
    }
    seperator = str + i;
    str[i] = ' ';
    info[i].adr = str + i;
    ++i;
    while( (ch = getchar()) != '\n' && ch != EOF){
        str[i] = ch;
        info[i].adr = str + i;
        ++i;
    }
    str[i] = 0;
    qsort(info, i, sizeof(foo), cmp);
    for(i = 1; info[i].adr; ++i){
        if(*info[i].adr == *info[i - 1].adr){
            if(info[i - 1].height > 0)
                info[i].height += info[i - 1].height + 1;
            else{
                int j = 1;
                while(*(info[i].adr + j) == *(info[i - 1].adr + j))
                    ++j;
                info[i].height = j;
            }
        }
        else
            info[i].height = 0;
    }
    qsort(info, i, sizeof(foo), cmp_h);
    for(i = 0; info[i].adr; ++i){
        if( (info[i].adr > seperator && info[i + 1].adr < seperator)
            || (info[i + 1].adr > seperator && info[i].adr < seperator))
            break;
    }
    printf("%d",info[i].height);
    return 0;
}
