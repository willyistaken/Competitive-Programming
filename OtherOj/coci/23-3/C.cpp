#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<int> pos(n+1);
    for(int i=1; i<=n; i++) {
        cin>>pos[i];
    }
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        a--;
        arr[a] = pos[i+1];
    }
    //for(auto i : arr) cout<<i<<" ";
    vector<int> A;
    for(int i=0; i<n; i++) {
        int k = lower_bound(A.begin(),A.end(),arr[i])-A.begin();
        if(k>=A.size()) A.push_back(arr[i]);
        else A[k]=arr[i];
    }
    cout<<A.size()<<"\n";
    return 0;
}
