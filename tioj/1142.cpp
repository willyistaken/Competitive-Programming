#pragma GCC optimize("O2")
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long ll;
const int S=5e4;
char outbuf[S]; int outp;int head;int maxtime;int nw;queue<int> inzero;short ans;
bitset<100050> s;
inline void W(int n){
	static char buf[12], p;
	if(n == 0) outbuf[outp++] = '0';
	p = 0;
	if(n < 0){
		outbuf[outp++] = '-';
		while(n) buf[p++] = '0' - (n % 10), n /= 10;
	} else {
		while(n) buf[p++] = '0' + (n % 10), n /= 10;
	}
	for(--p; p >= 0; --p) outbuf[outp++] = buf[p];
	outbuf[outp++] = '\n';
	if(outp > S-12) fwrite(outbuf, 1, outp, stdout), outp = 0;
}

int main(){
    int n,m;scanf("%d %d",&n,&m);
    short time[n];
    for(int i=0;i<n;i++) scanf("%d",time+i);
    vector<vector<int> > sides(n);
    vector<vector<int> > rsides(n);
    int in[n]={0};
    for(int i=0;i<m;i++){
        int a,b;scanf("%d %d",&a,&b);
        sides[a-1].push_back(b-1);
        in[b-1]+=1;
        rsides[b-1].push_back(a-1);
    }
   int toposort[n];
   for(int i=0;i<n;i++){
       if(in[i]==0) inzero.push(i);
   } 
   
    while(!inzero.empty()){
        int temp = inzero.front();
        inzero.pop();
        toposort[nw]=temp;
        ++nw;
        for(auto i :sides[temp]){
            in[i]-=1;
            if(in[i]==0){
                inzero.push(i);
            }
        }
    }
    pair<int,int> dp[n]={{0,-1}};
    
    for(int i=0;i<n;i++){
        int maxn=0;
        int maxid=-1;
        for(auto j: rsides[toposort[i]] ){
             maxid = (maxn<dp[j].first) ? j:maxid;
             maxn = max(maxn,dp[j].first);
        }
        dp[toposort[i]]={maxn+time[toposort[i]],maxid};
        maxtime=max(maxtime,dp[toposort[i]].first);
    }
    
    
    for(int i=0;i<n;i++){
        if(dp[i].first>=maxtime){
            head=i;
            while(head>=0){
                ans+=!s[head];
                s.set(head);
                head=dp[head].second;
            } 
        }
    }
      
    W(ans);
    fwrite(outbuf, 1, outp, stdout);
    return 0;
}