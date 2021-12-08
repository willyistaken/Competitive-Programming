#include<bits/stdc++.h>
using namespace std;//havel theorem
int n;
int arr[10000];
bool pass()
{
    for(int i=0;i<n;i++)
    {
        sort(arr+i,arr+n,greater<int>());
        for(int j=i+1;j<n&&arr[i]>0;j++)
        {
            arr[i]--;
            arr[j]--;
            if(arr[j]<0) return false;
        }
        if(arr[i]>0) return false;
    }
    return true;
}
int main()
{
    
    while(cin>>n,n)
    {
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(pass())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}