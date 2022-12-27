// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent an adjacency list node
struct AdjListNode {
	int dest;
    int weight;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList {
	struct AdjListNode* head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph {
	int V;
	struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
    newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists. Size of array will be V
	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an directed graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	// Add an edge from source to destination. A new node is
	// added to the adjacency list of source. The node
	// is added at the beginning
	struct AdjListNode* check = NULL;
	struct AdjListNode* newNode = newAdjListNode(dest, weight);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {

		check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;
		}
		//graph->array[src].head = newNode;
		check->next = newNode;
	}

	// Since graph is undirected, add an edge from
	// dest to src also
	/*newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL) {
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else {
		check = graph->array[dest].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}*/

	// newNode = newAdjListNode(src);
	// newNode->next = graph->array[dest].head;
	// graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}
void searchDFS(struct Graph* graph ,int src ,int* tested){
    /*for(int i=0;i<graph->V;++i){
        printf("%d=[%d]\t",i,tested[i]);
    }
    printf("\n");
	if(tested[graph->array[src].head->dest])
        return;*/
		
    printf("->%d", src);
    tested[src]= true;
    if(!graph->array[src].head)
        return;

    //printf("121221  %d\n",graph->array[src].head->dest);
	struct AdjListNode* pCrawl = graph->array[src].head;
	while (pCrawl){
		if(!(tested[pCrawl->dest]))
    		searchDFS(graph, pCrawl->dest, tested);
		pCrawl = pCrawl->next;
	}
}
void DFS(struct Graph* graph){
    int *tested = (int*)malloc(sizeof(bool) * graph->V);
    for(int i=0; i< graph->V;++i){
        if(!tested[i]){
            printf("source");
            searchDFS(graph, i, tested);
            printf("\n");
        }
    }
    //searchDFS(graph, src, tested);
   
    free(tested);
    
    
}

// Driver program to test above functions
int main()
{
	// create the graph given in above figure
	int V = 5;
	struct Graph* graph = createGraph(V);
	//addEdge(graph, 0, 1, 0);
	addEdge(graph, 0, 4 ,0);
    addEdge(graph, 1, 4 ,0);
	addEdge(graph, 1, 1 ,0);
	addEdge(graph, 1, 3 ,0);
	//addEdge(graph, 1, 4 ,0);
	addEdge(graph, 2, 0 ,0);
	addEdge(graph, 3, 2 ,0);
    //addEdge(graph, 4, 2 ,0);

	// print the adjacency list representation of the above
	// graph
	//printGraph(graph);
    DFS(graph);

	return 0;
}
