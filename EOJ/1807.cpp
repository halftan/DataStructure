#include <cstdio>
#include <cstdlib>

void
select_sort(int *arr,int n){
    int i,j,min,t;
    for(i = 0;i < n - 1;++i){
        min = i;
        for(j = i + 1;j < n;++j)
            if(arr[min] > arr[j])
                min = j;
        if(min != i){
            t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
        }
    }
}

inline void
Swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int
Median3(int A[], int left, int right){
    int centre = (left + right) / 2;
    if(A[left] > A[centre])
        Swap(&A[left], &A[centre]);
    if(A[left] > A[right])
        Swap(&A[left], &A[right]);
    if(A[centre] > A[right])
        Swap(&A[centre], &A[right]);

    Swap(&A[centre], &A[right - 1]);
    return A[right - 1];
}

void
Qsort(int A[], int left, int right){
    int i,j;
    int pivot;

    if(left + 10 <= right){
        pivot = Median3(A,left,right);
        i = left;
        j = right - 1;
        for(;;){
            while(A[++i] < pivot){}
            while(A[--j] > pivot){}
            if(i < j){
                int t;
                t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
            else break;
        }
        int t = A[i];
        A[i] = A[right - 1];
        A[right - 1] = t;
        
        Qsort(A,left,i - 1);
        Qsort(A,i + 1,right);
    }
    else
        select_sort(A + left, right - left + 1);
}

int
main(int argc, char *argv[]){
    int n,*A;
    A = (int*)calloc(sizeof(int),20000);
    while((scanf("%d",&n)) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d",A + i);
        Qsort(A, 0, n - 1);
        for(int i = 0; i < n - 1; ++i)
            printf("%d ",A[i]);
        printf("%d\n",A[n - 1]);
    }
    free(A);
    return 0;
}
