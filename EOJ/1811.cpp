#include <cstdio>
#include <cstdlib>
#include <cctype>

struct TNode {
    int elem;
    TNode* fc;
    TNode* nsib;
};

TNode* newNode(int elem);
void appendChild(TNode* tr, int elem);
void printTree(TNode* tr);
void destroyTree(TNode* tr);

int main(void){
    int n,N;
    int mod,ch,lev;
    int *mp;
    scanf("%d",&n);
    N = n;
    int* list = new int[52];
    int count = 0;
    char buf[10];
    do{
        scanf("%s", buf);
        for(int i = 0; buf[i]; ++i){
            if(isdigit(buf[i])){
                if(isdigit(buf[i + 1])){
                    lev = 10 * (buf[i] - '0') + buf[i + 1] - '0';
                    ++i;
//                  printf("inserting %d: ", lev);
                }
                else{
                    lev = buf[i] - '0';
//                  printf("inserting %d: ", lev);
                }
            }
            else if(isalpha(buf[i])){
                ch = buf[i];
//              printf("%c(flag)\n", ch);
            }
        }
        list[count*2] = lev;
        list[count++*2 + 1] = ch;
    }while(count < N);
    TNode* root = newNode(list[1]);
    for(count = 1; count < N; ++count){
        TNode* ins = root;
        for(int t = 0; t < list[count*2] - 1; ++t){
            while(ins->nsib)
                ins = ins->nsib;
            ins = ins->fc;
        }
        while(ins->nsib)
            ins = ins->nsib;
//      printf("%c is child of %c\n", list[count*2 + 1], ins->elem);
        appendChild(ins, list[count*2 + 1]);
    }
    delete list;
    printTree(root);
    destroyTree(root);
    putchar('\n');
    return 0;
}

TNode* newNode(int elem){
    TNode* t = new TNode;
    t->fc = NULL;
    t->nsib = NULL;
    t->elem = elem;
    return t;
}

void appendChild(TNode* tr, int elem){
    TNode* c;
    if(tr->fc)
        c = tr->fc;
    else{
        tr->fc = newNode(elem);
        return;
    }
    while(c->nsib)
        c = c->nsib;
    c->nsib = newNode(elem);
}

void printTree(TNode* tr){
    if(tr->fc)
        printTree(tr->fc);
    putchar(tr->elem);
    if(tr->nsib)
        printTree(tr->nsib);
}

void destroyTree(TNode* tr){
    if(tr->fc)
        destroyTree(tr->fc);
    if(tr->nsib)
        destroyTree(tr->nsib);
    delete tr;
}
