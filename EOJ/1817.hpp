#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>

#define NOT_A_VERTEX (-1)
#define INF (1000001)


struct _Cell{
    int to;
    int distance;
    _Cell(int to=NOT_A_VERTEX, int weigh=0);
}
typedef struct _Cell Cell;

struct _Head{
    std::list<Cell> list;
    int id;
    bool visited;
};
typedef struct _Head Head;

typedef std::vector<Head>::iterator Head_it;
typedef std::list<Cell>::iterator Cell_it;

class Graph{
public:
    std::vector<Head> adjacencyList;
    int vert_cont;
    Graph(int vert_cont);
    ~Graph();
    void addEdge( int from, int to, int weigh=1 );
    void Dijkstra( int start );
    int shortestPath(int start);
    void PrintPath(int start);
private:
    void _PrintPath(int start);
    int smallestUnknwonVert();
}
#endif
