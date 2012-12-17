#include <cstdio>
#include <cstdlib>

struct cell{
	int line;
	int column;
	int value;
};

int comp( const void* a, const void* b ){
	cell *m, *n;
	m = (cell*)a;
	n = (cell*)b;
	if(m->column == n->column)
		return m->line - n->line;
	else
		return m->column - n->column;
}

int main(void){
	int line, column, count;
	while(scanf("%d%d%d", &line, &column, &count) != EOF){
		cell *mat = (cell*)calloc( sizeof(cell), count );
		for (int i = 0; i < count; ++i)
			scanf("%d%d%d", &(mat[i].line), &(mat[i].column), &(mat[i].value));
		qsort( mat, count, sizeof(cell), comp);
		for (int i = 0; i < count; ++i)
			printf("%d %d %d\n", mat[i].column, mat[i].line, mat[i].value);
		free(mat);
	}
	return 0;
}
