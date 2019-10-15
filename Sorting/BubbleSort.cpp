#include <iostream>
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

// Number of array elements 10
int main()  
{  
    int arr[10]; 
    for(int i=0;i<10;i++) {
        cin>>arr[i];
    }

    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10-i-1; j++) {
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
    }
    }

    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    }
}  
