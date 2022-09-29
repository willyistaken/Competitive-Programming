#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,L;
struct seg {
    struct node {
        ll v=0;
        ll tag=0;
        void apply(int g) {
            tag+=g;
            v+=g;
        }
    };
    vector<node> arr;
    void init() {
        arr.resize(2*n);
    }
    void pull(int k) {
        if(k<=1) return;
        pull(k>>1);
        arr[k].apply(arr[k>>1].tag);
        arr[k^1].apply(arr[k>>1].tag);
        arr[k>>1].tag=0;
    }
    void push(int k) {
        k>>=1;
        while(k) {
            arr[k].v = min(arr[2*k].v,arr[2*k+1].v)+arr[k].tag;
            k>>=1;
        }
    }
    void modify(int l,int r,int v) {
        l+=n;
        r+=n;
        int tl=l;
        int tr = r;
        pull(l);
        pull(r-1);
        while(l<r) {
            if(l&1) arr[l++].apply(v);
            if(r&1) arr[--r].apply(v);
            l>>=1;
            r>>=1;
        }
        push(tl);
        push(tr-1);
    }

    ll query(int l,int r) {
        l+=n;
        r+=n;
        ll result = 1e18;
        pull(l);
        pull(r-1);
        while(l<r) {
            if(l&1) result = min(arr[l++].v,result);
            if(r&1) result = min(arr[--r].v,result);
            l>>=1;
            r>>=1;
        }
        return result;
    }

};


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>L;
	if(n<90000){
    int h[n+1]={0};
	int w[n+1]={0};
    for(int i=1; i<=n; i++) cin>>h[i]>>w[i];
    ll dp[n+1]= {0};
	dp[1]=h[1];
	for(int i=2;i<=n;i++){
		ll minn = 1e18;	
		int maxh = h[i];
		int totall = w[i];
		for(int j=i-1;j>=0 && totall<=L;j--){
			minn = min(dp[j]+maxh,minn);
			totall+=w[j];
			maxh = max(maxh,h[j]);
		}
		dp[i] = minn;
	}
	cout<<dp[n]<<"\n";
    return 0;
	}

    n++;
    seg	st;
    st.init();
    ll h[n]= {0};
    ll w[n]= {0};
    for(int i=1; i<n; i++) {
        cin>>h[i]>>w[i];
        w[i]=w[i]+w[i-1];
    }
    h[0]=1e12;
    ll dp[n]= {0};
    deque<int> dq;
    int pl=0;
    dq.push_back(0);
    for(int i=1; i<n; i++) {
        while(w[i]-w[pl]>L) pl++;
        while(dq.size()) {
            if(h[dq.back()]<=h[i]) {
                int rr = dq.back();
                dq.pop_back();
                int ll =dq.back();
                st.modify(ll,rr,-h[rr]);
            }
            else break;
        }
        int rl = dq.back();
        st.modify(rl,i,h[i]);
        dq.push_back(i);
        dp[i] = st.query(pl,i);
        st.modify(i,i+1,dp[i]);
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}
