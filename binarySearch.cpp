#include "iostream"
#include "algorithm"
using namespace std;

int binarySearch(int arr[], int n, int val)
{		
    int s=0 ,e = n-1;
    
    while(s<=e)
    {
        int mid = s + (e-s)/ 2;
        if(arr[mid]==val)
            return mid;
        else if(arr[mid]<val)
            s=mid+1;
        else if(arr[mid>val])
            e = mid-1;
    }

    return -1;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	
    	for(int i=0 ;i<n ;i++)	
           cin>>arr[i];
	
    	sort(arr, arr+n);

	int val;
	cout<<"enter value to be searched in the array"<<endl;
	cin>>val;
	
	int res  = binarySearch(arr,n,val);
	
	if(res== -1)	
           cout<<"element is not present in the array"<<endl;
	else	
           cout<<"element is present in array"<<endl;
}
