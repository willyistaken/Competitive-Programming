#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
string s;
int dp[5005];
struct trie{
	struct node{
		int cnt;
		node* child[26];
		node(){
			for(int i=0;i<26;i++) child[i]=  nullptr;
			cnt = 0;
		}
	};
	node* head = new node;	
	void insert(string k){
		node* cur = head;	
		for(int i=0;i<k.size();i++){
			if(cur->child[k[i]-'a']==nullptr){
				cur->child[k[i]-'a'] = new node;
			}
			cur = cur->child[k[i]-'a'];
		}
		cur->cnt++;
	}
	void get(int i){
		node* cur = head;
		for(int t=i;t<s.size();t++){
			if(cur->child[s[t]-'a']==nullptr) break;
			cur = cur->child[s[t]-'a'];
			dp[i]+=(1LL*(cur->cnt)*dp[t+1])%MOD;
			dp[i]%=MOD;
		}
	}

};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	dp[s.size()]=1;
	trie r;	
	int t;cin>>t;
	while(t--){
		string g;cin>>g;
		r.insert(g);
	}
	for(int i=s.size()-1;i>=0;i--){
		r.get(i);
	}
	cout<<dp[0]<<"\n";
	return 0;
}
