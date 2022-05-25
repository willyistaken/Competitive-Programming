#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> store[500005];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr[i]=a;
        store[a].push_back(i);
    }
    mt19937 gen(time(NULL));//this line is a preformance bottle-neck, I guess that makes sense
    for(int j=0;j<q;j++){
        int l,r;cin>>l>>r;
        l-=1;r-=1;
        uniform_int_distribution<int> dis(l,r);
        bool find=0;
        for(int i=0;i<20;i++){
            int loc = dis(gen);
            int range = upper_bound(store[arr[loc]].begin(),store[arr[loc]].end(),r)-lower_bound(store[arr[loc]].begin(),store[arr[loc]].end(),l);
            if(range>(r-l+1)/2){
                cout<<arr[loc]<<endl;
                find=1;
                break;
            }
        }
        if(!find){
            cout<<0<<endl;
        }

    } 
return 0;
}