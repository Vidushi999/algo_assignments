#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E; // no of vertices and edges
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge)); // initialization of edges

	return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

    // initialization
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

    // iteration over all edges |V|-1 times and updating
    // weights
	for (int i = 1; i <= V-1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

    // checking negative weight cycles: if weight less than
    // updated previously is possible
	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			printf("Graph contains negative weight cycle");
	}

    // printing the respective vertices
    printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);


	return;
}

// Driver program to test above functions
int main()
{

    clock_t begin = clock();

	int V = 8; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 3;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 0;
	graph->edge[3].weight = 2;

	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	graph->edge[5].src = 6;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 7;
	graph->edge[6].weight = 1;

	graph->edge[7].src = 5;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;



	BellmanFord(graph, 0);

    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);

	return 0;
}

