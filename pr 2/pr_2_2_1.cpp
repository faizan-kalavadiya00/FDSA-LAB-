#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"How many book code you want to enter"<<endl;
    cin>>n;

    int mid=0,position=0;
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

    while(left<=right)
    {
        mid=left+(right-left)/2;
        
        if(arr[mid]==bookCode)
        {
            position=mid+1;
            break;
        }
        else if(arr[mid]<bookCode)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }


    }

    cout<<"You found your book at "<<position;
    
return 0;

}