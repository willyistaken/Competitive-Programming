#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> get(int n,int k){
	assert(k%2);
	assert(k<n);
	vector<int> ans;	
	if(k==1){
		if(n==2){
			ans.push_back(0);
			ans.push_back(1);
			ans.push_back(3);
			ans.push_back(2);
			return ans;
		}
		vector<int> g = get(n-1,k);
		for(int j=0;j<(int)g.size();j++){
			bool f = j&1;
			ans.push_back((f*(1<<(n-1)))+g[j]);
			ans.push_back(((!f)*(1<<(n-1)))+g[j]);
		}
		return ans;
	}
	if(k+1==n){
		ans = get(n,1);
		int b = 0;
		for(int i=0;i<n;i++) b+=(1<<i);
		for(int i=0;i<(int)ans.size();i++){
			if(i&1) ans[i]^=b;
		}
		return ans;
	}
	vector<int> g = get(n-1,k);
	int b = (g.back()&(-g.back()));
	b = g.back()-b;
	b+=(1<<(n-1));
	for(auto i : g) ans.push_back(i);
	reverse(g.begin(),g.end());
	for(auto i : g) ans.push_back(i^b);
	return ans;
}
int n,k,t;
int to_num(string &a){
	int r = 0;
	for(int i=0;i<n;i++) r^=((1<<i)*(a[i]=='1'));
	return r;
}

void print(int a,int f){
	for(int i=0;i<f;i++) cout<<((a>>i)&1);
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k>>t;
	string s;cin>>s;
	if(k%2==0){
		cout<<"-1\n";
		return 0;
	}
	int b = to_num(s);
	vector<int> ans = get(n,k);
	cout<<(1<<n)<<"\n";
	for(auto i : ans) print(i^b,n);
	sort(ans.begin(),ans.end());
	assert(unique(ans.begin(),ans.end())-ans.begin()==(1<<n));

	return 0;
}
