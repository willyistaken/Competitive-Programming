#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int cnt[100010];
int cntcnt[100010];

int maxn = 0;



void add(int x){
    cntcnt[cnt[x]]--;
    cnt[x]++;
    cntcnt[cnt[x]]++;
    maxn = max(cnt[x],maxn);
}

void minu(int x){
    if(cntcnt[cnt[x]]==1 && maxn==cnt[x]){
        maxn--;
    }
    cntcnt[cnt[x]]--;
    cnt[x]--;
    cntcnt[cnt[x]]++;
}

const int MOD = 1e9+7;

int main() {
	cntcnt[0] = 100005;
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    int p = 0;
    for(int i=0;i<n-k+1;i++){
        while(p-i<k){
            add(arr[i]);
			p++;
        }
        ans = max(maxn,ans);
        minu(arr[i]);
    }
    ll r = 1;
    for(int i=1;i<=ans;i++){
        r = (r*i)%MOD;
    }
    cout<<r<<"\n";
    
    
}
