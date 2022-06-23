//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;int ans;
void merge(vector<int> &arr,int l,int r){
    if(r-l<=1) return;
    merge(arr,l,(r+l)/2);
    merge(arr,(r+l)/2,r);
    queue<int> next;
    int lhead=l;
    int rhead=(r+l)/2;
    while(lhead<(r+l)/2 && rhead<r){
        if(arr[lhead]<=arr[rhead]){
            next.push(arr[lhead]);
            lhead++;
        }else{
            ans+=((r+l)/2)-lhead;
            next.push(arr[rhead]);
            rhead++;
        }
    } 
    while(lhead<(r+l)/2){
        next.push(arr[lhead]);
        lhead++;
    }       
    while(rhead<r){
        next.push(arr[rhead]);
        rhead++;
    }
    for(int i=l;i<r;i++){
        arr[i] = next.front();
        next.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        ans=0;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int k;cin>>k;
            arr.push_back(k);
        }
        merge(arr,0,n);
        cout<<ans<<endl;

    }







    return 0;
}