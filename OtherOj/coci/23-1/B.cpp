#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,m;
int mp(int x,int y){
	return m*(x-1)+(y-1);
}

struct dsu{
	int p[10005];
	void init(){
		for(int i=0;i<10005;i++){
			p[i]=i;
		}
	}
	int query(int a){
		if(p[a]==a) return a;
		p[a] = query(p[a]);
		return p[a];
	}
	void join(int a,int b){
		p[query(b)]=query(a);
	}
} D[16];
vector<pair<int,int> > color[4];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	map<char,int> ctn;
	ctn.insert({'P',0});
	ctn.insert({'C',1});
	ctn.insert({'Z',2});
	ctn.insert({'N',3});
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<m;j++){
			int a = mp(i,j)	;
			int b = mp(i,j+1);
			color[ctn[s[j-1]]].push_back({a,b});
		}
	}
	for(int i=1;i<n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			int a = mp(i,j);
			int b = mp(i+1,j);
			color[ctn[s[j-1]]].push_back({a,b});
		}
	}
	for(int M=0;M<16;M++) D[M].init();
	for(int c=0;c<4;c++){
		for(auto i : color[c])	{
			for(int M=0;M<16;M++){
				if((M>>c)&1){
					D[M].join(i.first,i.second);
				}
			}
		}
	}
	int q;cin>>q;
	while(q--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		int x = mp(a,b);
		int y = mp(c,d);
		int minn = 4;
		for(int M=0;M<16;M++){
			if(D[M].query(x)==D[M].query(y)){
				minn = min(minn,__builtin_popcount(M));
			}
		}
		cout<<minn<<"\n";
	}
	return 0;
}
