#include <bits/stdc++.h>
using namespace std;
 void Report(int ind){
    cout<<ind<<endl;
} 
//meet in the middle algorithm


void solve(int N,long long K,long long a[]){
    pair<long long,int> store[1LL<<(N/2)];
    for(int i=0;i<(1LL<<(N/2));i++){
        long long sum=0;
        for(int j=0;j<N/2;j++){
            sum+= a[j]*((i>>j)&1);
        }
        store[i]={sum,i};
    } 
    sort(store,store+(1LL<<(N/2)));
    for(int i=0;i<(1LL<<(N-(N/2)));i++){
        long long sum=0;
        for(int j=0;j<(N-(N/2));j++){
            sum+=a[j+(N/2)]*((i>>j)&1);
        }
        // binary search
        int l=-1;int r=(1LL<<(N/2))+1;
        while(r-l>1){
            int mid = (r+l)/2;
            if(store[mid].first>K-sum){
                r=mid;
            }else{
                l=mid;
            }
        }
        int ind = l;
        if(ind<0) continue;
        if(sum+store[ind].first==K){
            long long all = store[ind].second+((1LL*i)<<(N/2));
            for(int i=0;i<N;i++){
                if(((all>>i)&1)) Report(i+1);
            }
            Report(-1);
            return ;
        }
    }

    Report(-1);
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long a[3]={6,8,9};
    solve(3,23,a);







    return 0;
}    