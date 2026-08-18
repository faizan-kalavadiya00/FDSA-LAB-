#include<iostream>
using namespace std;

void sortBuckets(int arr[],int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else 
        {
           swap(arr[mid],arr[high]);
           high--;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Your sorted buckets are"<<arr[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter number of buckets"<<endl;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter codes"<<endl;
        cin>>arr[i];
    }

    sortBuckets(arr,n);
}