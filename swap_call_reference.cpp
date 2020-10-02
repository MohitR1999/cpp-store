#include<iostream>
using namespace std;
//cpp program to swap a number using call by value
void swap(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
	cout<<*x<<" "<<*y<<endl;
}
int main(){
	
	int x,y;
	cout<<"Enter the numbers to be swapped";
	cin>>x>>y;
	cout<<"\nthe numbers before swapping are: ";
	cout<<x<<" "<<y;
	cout<<"\nthe numbers after swapping are: ";
	swap(&x,&y);
	cout<<x<<" "<<y<<endl;

	return 0;
}
