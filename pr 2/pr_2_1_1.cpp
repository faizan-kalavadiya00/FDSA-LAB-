#include<iostream>
using namespace std;

int main()
{
    int n;
    int search=0;
    cout<<"Enter how many license plate you want to enter"<<endl;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter plate "<<i+1<<endl;
        cin>>arr[i];
    }

    int plate;
    cout<<"Enter plate that you want to search"<<endl;
    cin>>plate;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==plate)
        {
            search=i+1;
        }
    }

    cout<<"Your plate found at position "<<search<<endl;

    return 0;

}