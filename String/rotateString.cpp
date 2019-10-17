//Rotate a string from right to left by specified positions

#include "iostream"
#include "string"
using namespace std;

void reverse(char [], int, int);
int main()
{
	int n, j, m, i;
	string s;
	cin >> s;                             //Input string
	n = s.size();
	cin >> m;                             //Input positions
	char ss[n];
	for(i=0;i<n;i++)                      //Copy string to char array
		ss[i]=s[i];
		
	m %= n;	                              //Reduce the number of rotations to less than size of string 
	reverse(ss, 0, m-1);                  //Reverse the first m characters  
	reverse(ss, m, n-1);                  //Reverse the rest of the characters    
	reverse(ss, 0, n-1);                  //Reverse the whole array    
	
	for(i=0;i<n;i++)                      //Display rotated string	
		cout<<ss[i]<<" ";			      
	
	return 0;
}
void reverse(char a[], int i, int j)
{
	int x,y,temp;
	for(x=i,y=j;x<y;x++,y--)
	{
		temp = a[x];
		a[x]=a[y];
		a[y]=temp;		
	}
}

