/* 
 * @Author: Rohit Agarwal(agarwalr98)
 * @Email: agarwal.r1998@gmail.com
 *
 * Merge Sort Algorithm
 */
#include <bits/stdc++.h>

using namespace std;

int inf=999999999;

void merge(int p,int q,int r,int a[100])
{
	int i,j;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i=1;i<=n1;i++)
	{
		L[i]=a[p+i-1];

	}
	for (int i = 1; i <= n2; ++i)
	{
		R[i]=a[q+i];
	}
	L[n1+1]=inf;
	R[n2+1]=inf;
	i=1;
	j=1;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}

}

void recursive(int p,int r,int a[100])
{
	if(p<r)
	{
		int q=(p+r)/2;
		recursive(p,q,a);
		recursive(q+1,r,a);
		merge(p,q,r,a);
	}
}

int main()
{
	cout<<"Number of elements in an array "<<endl;
	int n;
	cin>>n;
	int a[100];
	cout<<"Enter n elements separated by space or new line"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=1;
	recursive(p,n,a);
	cout<<"Elements in sorted array are:"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
}