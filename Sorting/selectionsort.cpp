
#include <bits/stdc++.h> 
using namespace std; 
  
void selectionSort(vector <int > &vect)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < vect.size()  -1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < vect.size() ; j++)  
        if (vect[j] < vect[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element 
        int temp = vect[min_idx];
        vect[min_idx] = vect[i];
        vect[i] = temp; 
    }  
}  
  
/* Function to print an array */
void printArray(vector <int > &vect)  
{  
    for (int i = 0;i<vect.size();i++)
        cout<<vect[i]<<" ";
}  
  
// Driver program to test above functions  
int main()  
{  
    cout<<"Number of elements in an array "<<endl;
    int n;cin>>n;
    vector <int> vect(n);
    cout<<"Enter elements separated by space"<<endl;
    for (int i =0;i<n;i++)
        cin>>vect[i];
    selectionSort(vect);  
    cout << "Sorted array: \n";  
    printArray(vect);  
    return 0;  
}  