# Sample C++ codes :computer:
Some of the C++ codes, containing:
1. Sparse Table Algorithms
2. String Algorithms
3. Sorting Algorithms
4. Dynamic Programming
    * -Tabluation Method
    * -Memoization Method
5. Searching Algorithms
6. Greedy Approach
7. Backtracking Algorithms
8. Divide and Conquer Approach
9. Data Structures
	* -Stack
	* -Queue

# Important points to be considered before making a Pull Request:
1. Read the existing codes CAREFULLY. Do not submit any code that is already existing in the repository, else that PR will be marked as spam
2. You are free to submit your codes in any language you want, just make a folder for that specific language
3. Provide proper CODE files, not TXT files or files without any extension, to maintain code portability.
4. Try to keep your codes genuine (Not a hard-and-fast rule tbh :stuck_out_tongue_closed_eyes: )

Lastly, do not submit useless PRs. That would be marked as spam straightforwadly
# And most importantly
Do a git pull before contributing any code, to prevent merge conflicts. Any PR that will cause merge conflicts won't be accepted


// Inserion sort

#include<iostream>
using namespace std;
int main ()
{
	int i,j,n,num,hole;
	
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
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
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
