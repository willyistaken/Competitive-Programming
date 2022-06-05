#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[45] ={1,2,3 ,5 ,8 ,13 ,21 ,34 ,55 ,89 ,144 ,233 ,377 ,610 ,987 ,1597 ,2584 ,4181 ,6765 ,10946 ,17711 ,28657 ,46368 ,75025 ,121393 ,196418 ,317811 ,514229 ,832040 ,1346269 ,2178309 ,3524578 ,5702887 ,9227465 ,14930352 ,24157817 ,39088169 ,63245986 ,102334155 ,165580141 ,267914296 ,433494437 ,701408733 ,1134903170 ,1836311903};

int main(){ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(;n;n--){
        int q; cin>>q;
        if(q<0){
            cout<<"iyada~\n";
            continue;
        }
        int ans=0;
        while(q) {
            q-=arr[upper_bound(arr,arr+45,q)-arr-1];
            ans+=1;
        }
        cout<<ans<<endl;
    }


    return 0;
}