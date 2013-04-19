#include <algorithm>
#include <list>
#include <vector>

#include "graph.hpp"

#ifdef DEBUG
#include <cstdio>
#endif

_Cell::_Cell(int to, int weigh){
    this->to = to;
    this->distance = weigh;
}

_Head::_Head(){ this->visited = false; }

Graph::Graph(int vert_cont):
        adjacencyList(vert_cont)
{
    this->vert_cont = vert_cont;
    this->retrospect = new int[vert_cont];
    this->distance = new int[vert_cont];
    for(int i = 0; i < vert_cont; ++i)
        this->adjacencyList[i].id = i + 1;
}
Graph::~Graph(){
    delete retrospect;
    delete distance;
}
void Graph::addEdge( int from, int to, int weigh ){
    this->adjacencyList[from-1].list.push_back(Cell(to-1, weigh));
#ifdef DEBUG
    printf("Adding %d to %d\n", to, from);
#endif
}
void Graph::Dijkstra( int start ){
    this->cleanMark();
    for( int i = 0; i < this->vert_cont; ++i ){
        distance[i] = INF;
        retrospect[i] = NOT_A_VERTEX;
    }
    distance[start - 1] = 0;
    int v;
    while(1){
#ifdef DEBUG
        printf("\n\nThe Table is:\n");
        printf("|\tV\t|\tflag\t|\tdist\t|\tret\t|\n");
        for( int i = 0; i < vert_cont; ++i ){
            printf("|\t%d\t|\t%-4d\t|\t%d\t|\t%d\t|\n",
                    i + 1, adjacencyList[i].visited?1:0,
                    distance[i], retrospect[i] + 1);
        }
        getchar();
#endif
        v = smallestUnknwonVert();
        if(v == NOT_A_VERTEX)
            break;
        adjacencyList[v].visited = true;
#ifdef DEBUG
        printf("visiting %d\n", v + 1);
#endif
#ifndef CPP0X
        for( Cell_it it = adjacencyList[v].list.begin();
                it != adjacencyList[v].list.end(); it++ ){
            int alt = distance[v] + (*it).distance;
#ifdef DEBUG
            printf("Calculated distance is %d. Essentially %d\n",
                   alt, distance[(*it).to]);
#endif
            if( alt < distance[(*it).to] ){
#ifdef DEBUG
                printf("Reducing distance\n");
#endif
                distance[(*it).to] = alt;
                retrospect[(*it).to] = v;
            }
        }
#else
        std::for_each( adjacencyList[v].list.begin(), adjacencyList[v].list.end(),
                [&]( Cell vertex ){
                int alt = distance[v] + vertex.distance;
#ifdef DEBUG
                printf("Calculated distance is %d. Essentially %d\n",
                    alt, distance[vertex.to]);
#endif
                if( alt < distance[vertex.to] ){
#ifdef DEBUG
                printf("Reducing distance\n");
#endif
                distance[vertex.to] = alt;
                retrospect[vertex.to] = v;
                } } );
#endif
    }
}

int Graph::shortestPath( int start ){
    return distance[start - 1];
}

void Graph::_PrintPath( int start ){
    if( retrospect[start] != NOT_A_VERTEX ){
        _PrintPath( retrospect[start] );
        printf(" to ");
    }
    printf("%d", start + 1);
}

void Graph::PrintPath( int start ){
    _PrintPath(--start);
    putchar('\n');
}

int Graph::smallestUnknwonVert(){
    int min, first, iter, found = 0;
    for( iter = 0; adjacencyList[iter].visited && iter < vert_cont; ++iter ){}
    if( iter == vert_cont )
        return NOT_A_VERTEX;
    first = iter;
    for( ; adjacencyList[iter].visited && iter < vert_cont; ++iter ){}
    if( iter == vert_cont )
        return first;
    min = distance[iter] < distance[first]? iter:first;
    for( ; iter < vert_cont; ++iter ){
        if( adjacencyList[iter].visited )
            continue;
        min = distance[iter] < distance[min]? iter:min;
        found = 1;
    }
    if(found)
        return min;
    else
        return NOT_A_VERTEX;
}

void Graph::cleanMark(){
#ifndef CPP0X
    for( Head_it it = adjacencyList.begin();
      it != adjacencyList.end(); it++ )
        (*it).visited = false;
#else
    std::for_each( adjacencyList.begin(), adjacencyList.end(), [&](Head h){ h.visited = false; } );
#endif
}
    
