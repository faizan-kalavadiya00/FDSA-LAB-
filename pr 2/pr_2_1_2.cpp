#include<iostream>
using namespace std;

int checkPlate(int arr[],int n,int i,int key)
{
    if(n==i)
    {
        return 0;
    }
    if(n>i)
    {
         if(arr[i]==key)
         {
            return i+1;
         }

         else
         {
            return checkPlate( arr, n, i+1, key);
         }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"How many plates you want to enter"<<endl;
    cin>>n;

    int i=0;
    int arr[n];
    int key;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter plate no"<<endl;
        cin>>arr[i];
    }
    cout<<"Enter key to check"<<endl;
    cin>>key;
    cout<<"Your plate find at "<< checkPlate(arr,n,i,key)<<endl;

   return 0;

}