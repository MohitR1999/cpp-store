//Counting sort
//Ideal for situations where range of elements is not significantly greater than the number of elements in the vector/array
//Time Complexity : n+k, where n is the number of elements and k is the range of inputs
//Space Complexity: n+k

#include "iostream"
#include "vector"
using namespace std;

void countingSort(vector<int> arr)
{
    int n = arr.size(), i;                      //Store size of input vector in n
    vector<int> sorted (n), count;              //Define two vectors to store the sorted vector and frequency of elements
    int max=INT_MIN;                            

    for(i=0;i<n;i++)                            //Finding the max element in vector for upper bound
        if(arr[i]>max)
            max=arr[i];

    max++;                                                                  
    while(max--)                                //Initialising frequency vector, size is determined by "max" 
        count.push_back(0);

    for(i=0;i<n;i++)                            //Calculating frequencies
        count[arr[i]]++;

    for(i=1;i<count.size();i++)                 //Calculating cumulative frequencies
        count[i]+=count[i-1];

    for(i=n-1;i>=0;i--)                         //For every element of original vector 
    {
        sorted[count[arr[i]] - 1]=arr[i];       //Place it in the sorted vector at position = its frequency in count vector
        count[arr[i]]--;                        //Decrease its frequency by 1
    }

    arr = sorted;                               //Copy sorted vector to original vector

    for(int i=0;i<n;i++)                        //Display the result
        cout<<arr[i]<<" ";
}

int main()
{
    countingSort(vector<int> {9,2,1,4,5,3,1,2,5,9,8,4,2,5,4});
}
