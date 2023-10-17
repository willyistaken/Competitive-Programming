#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1000000007;
const int N = 5e5+5;
ll dp[N][26];
priority_queue<int,vector<int>,greater<int> > belongs[4];
ll re[4][26];

void remove(int v,int k){
	//cerr<<"removing "<<v<<" from "<<k<<"\n";
	for(int c=0;c<26;c++){
		re[k][c]-=dp[v][c];
		re[k][c]%=MOD;
	}
}
void add(int v,int k){
	//cerr<<"adding "<<v<<" to "<<k<<"\n";
	for(int c=0;c<26;c++){
		re[k][c]+=dp[v][c];
		re[k][c]%=MOD;
		//cout<<re[k][c]<<" ";
	}
	//cout<<"\n";
}
vector<int> ran[N][2];
void printbelongs(){
	cout<<"--------------------\n";
	cout<<"printing...:\n";
	for(int k=0;k<4;k++){
		priority_queue<int,vector<int>,greater<int> > cloneb = belongs[k];
		while(cloneb.size()) {cout<<cloneb.top()<<" ";cloneb.pop();}
		cout<<"\n";
	}
	cout<<"--------------------\n";
}
void mantain(int r,bool t){
	if(!t){
		while(belongs[0].size() && belongs[0].top()<=r){
			belongs[2].push(belongs[0].top());
			remove(belongs[0].top(),0);
			add(belongs[0].top(),2);
			belongs[0].pop();
		}
		while(belongs[1].size() && belongs[1].top()<=r){
			belongs[3].push(belongs[1].top());
			remove(belongs[1].top(),1);
			add(belongs[1].top(),3);
			belongs[1].pop();
		}
	}else{
		while(belongs[0].size() && belongs[0].top()<=r){
			belongs[1].push(belongs[0].top());
			remove(belongs[0].top(),0);
			add(belongs[0].top(),1);
			belongs[0].pop();
		}
		while(belongs[2].size() && belongs[2].top()<=r){
			belongs[3].push(belongs[2].top());
			remove(belongs[2].top(),2);
			add(belongs[2].top(),3);
			belongs[2].pop();
		}
	}
}

ll getrange(int l,int r,int k){
	if(l>r) return 0;
	ll result = re[k][r];
	if(l) result = (result-re[k][l-1])%MOD;
	return result;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;	
		bool w=  0;	
		if(a>b){w=1;swap(a,b);}
		ran[a+1][w].push_back(b);
	}
	for(int i=n;i>=1;i--){
		belongs[0].push(i);
		for(int c=1;c<26;c++){
			for(int k=0;k<4;k++){
				re[k][c]=(re[k][c]+re[k][c-1])%MOD;
			}
		}
		for(int c=0;c<26;c++){
			if(i==n) dp[i][c]=1;
			else{
				for(int k=0;k<4;k++){
					if(k==0) dp[i][c]+=(getrange(0,c-1,k)+getrange(c+1,25,k))%MOD;
					if(k==1) dp[i][c]+=getrange(0,c-1,k);
					if(k==2) dp[i][c]+=getrange(c+1,25,k);
					dp[i][c]%=MOD;
				}
				dp[i][c]++;
				dp[i][c]%=MOD;
			}
		//	cout<<dp[i][c]<<" ";
		}
		for(int c=25;c>=1;c--){
			for(int k=0;k<4;k++){
				re[k][c] = (re[k][c]-re[k][c-1])%MOD;
			}
		}
		//cout<<"\n";
		for(int k=0;k<4;k++) if(belongs[k].size() && belongs[k].top()==i) add(i,k);
		for(int b=0;b<2;b++){for(auto v : ran[i][b]) mantain(v,b);}
		/*
		cout<<"k:";
		for(int k=0;k<4;k++){
			for(int c=0;c<26;c++){
			cout<<re[k][c]<<" ";
			}
			cout<<"\n";
		}
		printbelongs();
		*/
	}
	ll ans = 0;
	for(int i=0;i<26;i++) ans=(ans+dp[1][i])%MOD;
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
	return 0;
}

// abba works...

/*
4 3
2 3
3 1
1 4
*/
