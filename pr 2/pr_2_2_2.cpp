#include<iostream>
using namespace std;

int findBook(int arr[],int bookCode,int left,int right)
{
    int mid=left+(right-left)/2;

         if(left>=right)
         {
            return -1;
         } 
         else if(arr[mid]==bookCode)
         {
            return mid+1;
         } 
         else if(arr[mid]<bookCode)
         {
            return findBook( arr, bookCode, mid+1, right);
         }  
         else 
         {
           return findBook( arr, bookCode, right, mid-1);
         }  

         return -1;
}
int main()
{
    int n;
    cout<<"How many book code you want to enter"<<endl;
    cin>>n;

    int position=0;
    int left=0;
    int right=n-1;
    int bookCode;
    int arr[n];


    for(int i=0;i<n;i++)
    {
       cout<<"Enter book code"<<endl;
       cin>>arr[i];
    }
    cout<<"Enter book code that you want to search"<<endl;
    cin>>bookCode;

    cout<<"Your book found at position "<<findBook(arr,bookCode,left,right)<<endl;
    
}