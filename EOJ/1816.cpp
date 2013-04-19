#include <cstdio>
#include <cstdlib>

#include <list>
#include <vector>
#include <algorithm>

typedef std::list<int> ListNode;
typedef std::list<int>::iterator ListNode_it;

typedef std::vector<ListNode> AdjacencyList;
typedef std::vector<ListNode>::iterator AdjacencyList_it;

typedef std::vector<bool> TraversalMap;
typedef std::vector<bool>::iterator TraversalMap_it;

void visitList( ListNode list );
void visitVertex( int vertex );

TraversalMap *tm;
AdjacencyList *al;

int main(){
    int vertexes, edges;
    int from, to;
    scanf("%d%d", &vertexes, &edges);
    ListNode allocator;
    al = new AdjacencyList(vertexes, allocator);
    tm = new TraversalMap(vertexes, false);
    while( scanf("%d%d", &from, &to) != EOF ){
        (*::al)[from - 1].push_back(to - 1);
        (*::al)[to - 1].push_back(from - 1);
    }
    visitVertex( 0 );
    TraversalMap_it judge = std::find( tm->begin(), tm->end(), false );
    if( judge == tm->end() )
        printf("yes\n");
    else printf("no\n");
    delete ::tm;
    delete ::al;
    return 0;
}

void visitList( ListNode list ){
    std::for_each( list.begin(), list.end(), visitVertex );
}

void visitVertex( int vertex ){
    if( (*::tm)[vertex] )
        return;
    (*::tm)[vertex] = true;
    visitList( (*::al)[vertex] );
}
