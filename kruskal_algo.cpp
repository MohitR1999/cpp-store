#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int first;
	int second;
	int w;
};

struct node_
{
	node_ *parent;
	int key;
	int height;
};

void merge(edge *E,int from, int to)
{
	int n;
	n = to-from+1;
	edge A[n];
	for(int i=0;i<n;i++)
	{
		A[i] = E[from+i]; 
	}

	int i,j;
	i=0;
	j= (n%2==0)? (n/2) : (n/2)+1;
	int count=from,mid=j;

	while(i!=mid && j!=(n))
	{
		if(A[i].w < A[j].w)
		{
			E[count++] = A[i];
			i++;
		}
		else
		{
			E[count++] = A[j];
			j++;
		}
	}


	if(i==mid)
	{
		while(j!=(n))
		{
			E[count++] = A[j];
			j++;
		}
	}
	else 
	{
		while(i!=mid)
		{
			E[count++] = A[i];
			i++;
		}
	}

}

void merge_sort(edge *E,int from,int to)
{
	if(to == from)
		return;

	merge_sort(E,from, (from+to)/2);
	merge_sort(E,(from+to)/2 +1,to);
	merge(E,from,to);
}

int find_set(node_ E)
{
	while((E.parent)->key != E.key)
	{
		E = *(E.parent);
	}

	return E.key;
}

void union_set(node_ *A, node_ *B)
{
	if(A->height > B->height)
	{
		B->parent = A;
	}
	else if(A->height < B->height)
	{
		A->parent = B;
	}
	else
	{
		A->parent = B;
		(B->height)++;
	}
}

int main()
{
	int n,e;
	cout<<"No. of Nodes and no. of edges"<<endl;
	cin>>n>>e;

	cout<<"Describe edges : from to weight"<<endl;

	edge E[e];

	for (int i = 0; i < e; ++i)
	{
		cin>>E[i].first>>E[i].second>>E[i].w;
	}

	merge_sort(E,0,e-1);

	// 

	node_ N[n];

	for(int i=0;i<n;i++)
	{
		N[i].parent = &N[i];
		N[i].key = i;
		N[i].height = 1;
	}

	for(int i=0;i<e;i++)
	{
		int a,b; 
		a = find_set(N[E[i].first]);
		b = find_set(N[E[i].second]);

		if(a!=b)
		{
			cout<<E[i].first<<" "<<E[i].second<<endl;
			union_set(&N[a],&N[b]);
		}
	}



}