#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int vertex;
	node* next;
};

struct Graph
{
	int numVertices;
	node** adjLists;
};

typedef struct 
{
	int from;
	int to;
	int weight;	
}Edge;

bool compare_edge(Edge edge1,Edge edge2)
{
	if(edge1.from < edge2.from)
		return 0;
	if(edge2.from < edge1.from)
		return 1;
	if(edge1.weight < edge2.weight)
		return 0;
	if(edge2.weight < edge1.weight)
		return 1;
	if(edge1.to < edge2.to)
		return 0;

	return 1;
}

void merge(Edge *edge,int a,int b)
{
	int i,j,count=a;
	i = a;
	j = (a+b)/2 + 1;

	Edge temp[b-a+1];

	for (int k = a; k <= b; ++k)
	{
		temp[k-a] = edge[k]; 
	}

	while(i!= (a+b/2)+1 && j!=(b+1))
	{
		if(compare_edge(temp[i-a],temp[j-a]))
		{
			edge[count++] = temp[j-a];
			j++;
		}
		else
		{
			edge[count++] = temp[i-a];
			i++;
		}
	}

	if(i!=(a+b)/2 +1)
	{
		while(i!=(a+b)/2 + 1)
		{
			edge[count++] = temp[i-a];
			i++;
		}

	}
	else if(j!=(b+1))
	{
		while(j!=(b+1))
		{
			edge[count++] = temp[j-a];
			j++;
		}
	}
}

// a and b are indices

void merge_sort(Edge *edge,int a,int b)
{
	if(a==b)
		return;

	merge_sort(edge,a, (a+b)/2);
	merge_sort(edge,(a+b)/2 +1,b);
	merge(edge,a,b);
}

int main()
{
	ifstream input;
	ofstream output;

	input.open("input.txt");
	output.open("output.txt");

	int V,E;
	input>>V;
	input>>E;

	// cout<<"V: "<<V<<endl;
	// cout<<"E: "<<E<<endl;

	Graph *G;
	G = new Graph;
	G->numVertices = V;
	G->adjLists = new node* [V];

	for (int i = 0; i < V; ++i)
	{
		(G->adjLists)[i]=NULL;
	}



	for(int i=0;i<E;i++)
	{
		int node1,node2;
		input>>node1>>node2;

		node *temp;

		if(G->adjLists[node1-1] == NULL)
		{
			G->adjLists[node1-1] = new node;
			G->adjLists[node1-1]->vertex = node2;
			G->adjLists[node1-1]->next = NULL;
		}
		else
		{
			temp = new node;
			temp->vertex = node2;
			temp->next = G->adjLists[node1-1]->next;

			G->adjLists[node1-1]->next = temp;
		}


	}


	// PRINT ADJACENCY LIST

	/*for(int i=0;i<V;i++)
	{
		while(G->adjLists[i]!=NULL)
		{
			cout<<(G->adjLists[i])->vertex<<" ";
			G->adjLists[i] = G->adjLists[i]->next;
		}
		cout<<endl;

	}*/


	Edge edge[E];
	int in_degree[V+1];
	//counting in degrees
	for (int i = 1; i < (V+1); ++i)
	{
		in_degree[i]=0;
	}

	for (int i = 0; i < V; ++i)
	{
		node *temp;
		temp = G->adjLists[i];

		while(temp!=NULL)
		{
			in_degree[temp->vertex]++;
			temp = temp->next;
		}
	}

	//PRINT IN_DEGREES

	/*for (int i = 1; i < (V+1); ++i)
	{
		cout<<"in_degree of"<<i<<": "<<in_degree[i]<<endl;
	}*/

	int count=0;

	for (int i = 0; i < V; ++i)
	{
		node *temp;
		temp = G->adjLists[i];

		while(temp!=NULL)
		{
			edge[count].to = temp->vertex;
			edge[count].from = i+1;
			edge[count].weight = in_degree[i+1] + in_degree[temp->vertex];
			count++;
			temp = temp->next;
		}
	}

	merge_sort(edge,0,E-1);

	for (int i = 0; i < E; ++i)
	{
		// cout<<edge[i].from<<" "<<edge[i].weight<<" "<<edge[i].to<<endl;
		output<<edge[i].from<<" "<<edge[i].weight<<" "<<edge[i].to<<"\n";
	}


	
	return 0;
}