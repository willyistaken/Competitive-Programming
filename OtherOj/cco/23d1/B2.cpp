    #pragma GCC optimize("Ofast","O3")
    #pragma GCC target("avx","avx2")
    #include <bits/stdc++.h>
    using namespace std;
    #define all(x) x.begin(),x.end()
    //#define int long long 
    #define ll long long 
    #define LCBorz ios_base::sync_with_stdio(false);cin.tie(0);
    const int N=1000005;
    const int mod=1e6+3;
    const int INF=2e9;
    int n;
    struct segtree{
        int v[N<<2];
        void pull(int id){
            v[id]=min(v[id<<1],v[id<<1|1]);
        }
        void add(int id,int l,int r,int p,int x){
            if(r-l==1){
                v[id]=x;
                return;
            }
            int m=(l+r)>>1;
            if(p<m)add(id<<1,l,m,p,x);
            else add(id<<1|1,m,r,p,x);
            pull(id);
        }
        int ask(int id,int l,int r,int a,int b){
            if(a<=l&&b>=r)return v[id];
            int m=(l+r)>>1;
            if(b<=m)return ask(id<<1,l,m,a,b);
            if(a>=m)return ask(id<<1|1,m,r,a,b);
            return min(ask(id<<1,l,m,a,b),ask(id<<1|1,m,r,a,b));
        }
        void add(int a,int b){
            add(1,1,n+1,a,b);
        }
        int ask(int a,int b){
            return ask(1,1,n+1,a,b);
        }
    }st;
    int32_t main(){
        LCBorz;
        cin>>n;
        vector<int> v(n+2),pre(n+2),suf(n+2);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        for(int i=1;i<=n;i++){
            pre[i]=max(pre[i-1],v[i]);
        }
        for(int i=n;i>=1;i--){
            suf[i]=max(suf[i+1],v[i]);
        }
        for(int i=1;i<=n;i++){
            st.add(1,1,n+1,i,v[i]);
        }
        ll ans=0;
        vector<pair<int,int>> leave,join;
        vector<int> tim;
        for(int i=1;i<=n;i++){
            join.push_back({v[i],i});
            leave.push_back({min(pre[i],suf[i]),i});
            tim.push_back(v[i]);
            tim.push_back(min(pre[i],suf[i]));
        }
        sort(all(tim));
        tim.resize(unique(all(tim))-tim.begin());
        sort(all(join),greater<>());
        sort(all(leave),greater<>());
        set<int> t;
        for(int i=0;i<(int)tim.size()-1;i++){
            ll val=tim[i],val1=tim[i+1];
            while(join.size()&&join.back().first<=val){
                auto [a,b]=join.back();
                join.pop_back();
                st.add(b,INF);
                t.insert(b);
            }
            while(leave.size()&&leave.back().first<=val){
                auto [a,b]=leave.back();
                leave.pop_back();
                t.erase(b);
            }
            int m=t.size();
            if(m==0){
                continue;
            }
            auto cal=[&]()->ll {
                return 1ll*(val+val1-1)*(val1-val)/2%mod;
            };
            if(m==1){
                int p=*t.begin();
                ans+=cal()+1ll*(val1-val)*(st.ask(1,p)+st.ask(p+1,n+1));
                ans%=mod;
                continue;
            }
            int p1=*t.begin();
            int p2=*(--t.end());
            ll tmp=0ll+st.ask(1,p1)+st.ask(p1+1,n+1)+st.ask(p2+1,n+1);
            ll tmp1=0ll+st.ask(1,p2)+st.ask(p2+1,n+1)+st.ask(1,p1);
            ans+=1ll*(val1-val)*(min(tmp,tmp1)+1)+cal()*3;
            ans+=1ll*(m-2)*(3*cal()+2*(val1-val));
            ans%=mod;
        }
        cout<<ans<<endl;
        
        return 0;
    }
