//Dijkstra's algorithm
#include <iostream>
using namespace std;
#define V 9

int minDistance(int dist[], int path[]) 
{	// Initialize min value
   int min = 200000, min_index;
   for (int v = 0; v < V; v++)
     if (path[v] == -1 && dist[v] <= min)
   min = dist[v], min_index = v;

   return min_index;
}

void sol(int dist[], int n)
{
   cout<<"\n\nVertex Distance from Source\n\n";
   for (int i = 0; i < V; i++)
      cout<<i<<" "<<dist[i]<<endl;
}

void djkAlgo(int graph[V][V], int src)
{
     int dist[V];     // final 
     int path[V]; 
     for (int i = 0; i < V; i++)
  	dist[i] = 200000, path[i] = -1;                         
     
	dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, path);
        path[u] = 1;            
       for (int v = 0; v < V; v++)
   	if ((path[v]) && graph[u][v] && dist[u] != 200000 && dist[u]+graph[u][v] < dist[v])
      	dist[v] = dist[u] + graph[u][v];
     }
	sol(dist, V);
}

int main()
{    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
		      {4, 0, 8, 0, 0, 0, 0, 11, 0},
		      {0, 8, 0, 7, 0, 4, 0, 0, 2},
		      {0, 0, 7, 0, 9, 14, 0, 0, 0},
		      {0, 0, 0, 9, 0, 10, 0, 0, 0},
		      {0, 0, 4, 14, 10, 0, 2, 0, 0},
		      {0, 0, 0, 0, 0, 2, 0, 1, 6},
		      {8, 11, 0, 0, 0, 0, 1, 0, 7},
		      {0, 0, 2, 0, 0, 0, 6, 7, 0}
		     };
    djkAlgo(graph, 0);
	return 0;
}