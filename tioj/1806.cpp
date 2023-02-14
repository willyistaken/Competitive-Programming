#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<vector<int> > side;
vector<int> ans;
vector<int> p;
string s;
void parse(){
	int n = s.size();	
	int cur = 0;
	int node = -1;
	for(int i=0;i<n;i++){
		if(s[i]=='['){
			side.push_back(vector<int>());
			ans.push_back(0);
			if(node>=0) side[node].push_back(p.size());
			p.push_back(node);
			node = p.size()-1;
		}else if(s[i]==']'){
			if(cur) ans[ans.size()-1] = (cur/2)+1;
			cur=0;
			node = p[node];
		}else{
			cur*=10;
			cur+=s[i]-'0';
		}
	}
}

void dfs(int cur){
	vector<int> st;	
	for(auto i : side[cur]){
		if(!ans[i]) dfs(i);
		st.push_back(ans[i]);
	}
	sort(st.begin(),st.end());
	for(int i=0;i<=(st.size()/2);i++){
		ans[cur]+=st[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		vector<vector<int> >().swap(side);
		vector<int>().swap(ans);
		vector<int>().swap(p);
		cin>>s;
		parse();
		dfs(0);
		cout<<ans[0]<<"\n";
	}

	return 0;
}
