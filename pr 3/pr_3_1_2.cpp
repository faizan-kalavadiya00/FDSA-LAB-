#include<iostream>
using namespace std;

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Your sorted marks are"<<arr[i];
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
     selectionSort(arr,n);

     return 0;

}