#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *stack = NULL;
int stack_size;

void clearStack() {
    if ( stack )
        free(stack);
    stack = (char*)calloc( sizeof(char), 30 );
    stack_size = 0;
}

void push( char e ) {
    stack[ stack_size++ ] = e;
}

void split( char *str, int pos, char **left, char **right ) {
    int len;
    len = strlen(str);
    if ( pos == 0 ) {
        if ( len == 1 ) {
            *left = NULL;
            *right = NULL;
            return;
        } else {
            *left = NULL;
            *right = (char*)calloc( sizeof(char), len );
            strncpy( *right, str + 1, len );
            return;
        }
    } else if ( pos == len - 1 ) {
        *right = NULL;
        *left = (char*)calloc( sizeof(char), len );
        strncpy( *left, str, pos );
        return;
    } else {
        *left = (char*)calloc( sizeof(char), pos + 1 );
        *right = (char*)calloc( sizeof(char), len - pos );
        strncpy( *left, str, pos );
        strncpy( *right, str + pos + 1, len - pos );
        return;
    }
}

int searchFirst( char *str, char *dict ) {
    int i, j;
    int len1, len2;
    len1 = strlen(str);
    len2 = strlen(dict);
    for ( i = 0; i < len2; ++i ) {
        for ( j = 0; j < len1; ++j ) {
            if ( dict[i] == str[j] )
                return j;
        }
    }
    return -1;
}

void printReversely( char *str ) {
    int len = strlen(str);
    for( --len; len >= 0; --len )
        putchar(str[len]);
}

void convertTraversal( char *midT, char *fstT ) {
    char *left, *right;
    int rootPos = searchFirst(midT, fstT);
    split( midT, rootPos, &left, &right );
    push( midT[rootPos] );
    if ( right )
        convertTraversal( right, fstT );
    if ( left )
        convertTraversal( left, fstT );
    free(left);
    free(right);
}

int main() {
    char mid[30], fst[30];
    while( scanf("%s%s", fst, mid) != EOF ) {
        clearStack();
        convertTraversal( mid, fst );
        printReversely( stack );
        putchar('\n');
    }
    return 0;
}
