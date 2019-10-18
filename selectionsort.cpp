#include<iostream>
using namespace std;
void sort(int a[],int n);

int main()
{
    int n;
    cin>>n; //size of array;
    int a[n];
     for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    sort(a,n);
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
}
void sort(int a[],int n) //Selection Sort
{
	int i,hole,j,num;
	for(i=1;i<n;i++)
	{
		hole=i;
		j=i-1;
		num=a[i];
		while(j>=0)
		{
			if(num<a[j])
			{
				a[j+1]=a[j];
				hole=hole-1;
				}
			j=j-1;
		}
		a[hole]=num;
		
	}
		
}
