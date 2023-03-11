#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
string s;
bool is_num(char a){
	return (a-'0'>=0 && a-'0'<=9);
}
vector<int> get(int l,int r){
	vector<int> ans(26);
	fill(ans.begin(),ans.end(),0);
	int all = 1;
	if(is_num(s[l])){
		all = s[l]-'0';
		l++;
	}
	int cur = 0;
	int cnt = 0;
	for(int i=l;i<=r;i++){
		if(!is_num(s[i])){
			ans[cur]+=all*cnt;
			cur = s[i]-'A';
			cnt=1;
		}else{
			cnt=s[i]-'0';
		}
	}
	ans[cur]+=all*cnt;
	return ans;
}

vector<int> parse(int l,int r){
	vector<int> ans(26,0);
	int rl = l;
	vector<int> temp(26,0);
	for(int i=l;i<=r;i++){
		if(s[i]=='+'){
			temp = get(rl,i-1);
			rl = i+1;
			for(int i=0;i<26;i++) ans[i]+=temp[i];
		}
	}
	temp = get(rl,r);
	for(int i=0;i<26;i++) ans[i]+=temp[i];
	return ans;
}



void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='-'){
			vector<int> a = parse(0,i-1);	
			vector<int> b= parse(i+2,s.size()-1);
			//for(auto i:a) cout<<i<<" ";
			//cout<<"\n";
			//for(auto i:b) cout<<i<<" ";
			//cout<<"\n";
			for(int i=0;i<26;i++){
				if(a[i]!=b[i]){
					cout<<"NE\n";
					return ;
				}
			}
			cout<<"DA\n";
		}
	}


}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
