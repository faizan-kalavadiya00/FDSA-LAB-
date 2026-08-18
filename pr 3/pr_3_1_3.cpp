#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Your sorted marks of sheet"<<arr[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"How many sheets you have"<<endl;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter marks of sheet"<<i+1<<endl;
        cin>>arr[i];

    }
     insertionSort(arr,n);

     return 0;

}