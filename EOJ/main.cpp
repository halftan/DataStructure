#include <cstdio>

#include "graph.hpp"

int main(){
    int vert_cont, edge_cont;
    int _from, _to, _weigh;
    scanf("%d%d", &vert_cont, &edge_cont);
    Graph g(vert_cont);
    for(int i = 0; i < edge_cont; ++i){
        scanf("%d%d%d", &_from, &_to, &_weigh);
        g.addEdge(_from, _to, _weigh);
    }
#ifdef DEBUG
    for( Head_it it = g.adjacencyList.begin();
            it != g.adjacencyList.end(); it++ ){
        for( Cell_it ct = (*it).list.begin();
                ct != (*it).list.end(); ct++ ){
            printf("%d ", (*ct).to);
        }
        putchar('\n');
    }
#endif
    g.Dijkstra(1);
#ifdef DEBUG
    g.PrintPath(vert_cont);
#endif
    int ans = g.shortestPath(vert_cont);
    if( ans == INF )
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
