#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    int count=0;
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n-1-i;j++)
     {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            count++;
        }
     }
       if(count==0)
       {
        break;
       }

    }

    for(int i=0;i<n;i++)
    {
        cout<<"Your sorted marks are"<<arr[i]<<endl;
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
     bubbleSort(arr,n);

     return 0;

}


