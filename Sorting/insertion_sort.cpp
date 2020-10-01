#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int value=a[i];
		int hole=i;
		while(hole>0 && value<a[hole-1])
		{
			a[hole]=a[hole-1];
			hole-=1;
		}
		a[hole]=value;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\n";
	}
}
