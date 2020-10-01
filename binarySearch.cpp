#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int val)
{		
    int s=0 ,e = n-1;
    
    while(s<=e)
    {
        int mid = s + (e-s)/ 2;  // middle point = starting position + Half of current search space
        if(arr[mid]==val)		
            return mid;	         // return it if you found it in the middle
	    
	// not found ? will move rigth or left depend on its value ( Sorted Array :)  )
        else if(arr[mid]<val)	 
            s=mid+1;		 // get rid of the left half : new starting position = after the previous middle
        else if(arr[mid>val])	
            e = mid-1;		// get rid of the right half : new end position = before the previous middle
    }

    return -1;
}

int main()
{
	int n;
	cout<<"Enter the number of elements in the array"<<endl;
	cin>>n;
	int* arr = new int[n] ;
	
    	for(int i=0 ;i<n ;i++)	
           cin>>arr[i];
	
    	sort(arr, arr+n);

	int val;
	cout<<"Enter the value to be searched in the array"<<endl;
	cin>>val;
	
	int res  = binarySearch(arr,n,val);
	
	if(res==-1)
		cout<<"Element does not exist in the array"<<endl;
	else
		cout<<"Element "<<val<<" found at index "<<res<<" in the array"<<endl;
	
	delete arr;
}
