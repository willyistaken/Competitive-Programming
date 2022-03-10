#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr[0]=1e9;
    vector<int> mono;
    mono.push_bakc(0);
    for(int i=1;i<=n;i++){
        int h=mono.size()-1;
        int l=0;
        int mid;
        int cur=mid;
        while(l<=h){
            mid=(l+h)/2;
            if(arr[mono[mid]]>arr[i]){
                l=mid+1;
                cur=mid;
            }else{
                h=mid-1;
            }
        }
        
    }
}