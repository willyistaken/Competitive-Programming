#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
string s;
int n;
vector<int> num;
vector<int> rk;
void sa(){
	num.resize(n,0);
	rk.resize(n,0);
	for(int i=0;i<n;i++) rk[i] = s[i]-'#';
	for(int i=0;i<n;i++) num[i]= i;
	for(int p=0;p<20;p++){
		pair<int,int> temp[n];
		for(int i=0;i<n;i++){
			temp[i] = {rk[i],rk[(i+(1<<p))%n]};
		}
		sort(num.begin(),num.end(),[&](int a,int b){return temp[a]<temp[b];});
		int prev = 0;
		rk[num[0]] = 0;
		for(int i=1;i<n;i++){
			if(temp[num[i]]==temp[num[prev]]){
				rk[num[i]] = rk[num[prev]];
			}else{
				rk[num[i]] = rk[num[prev]]+1;
				prev = i;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	ll k ;cin>>k;
	s+='#';
	n = s.size();
	sa();
	for(int i=0;i<n;i++) rk[num[i]] = i;
	int lcp[n]  = {0};
	int g = 0;
	for(int i=0;i<n-1;i++){
		int po = rk[i];
		int j = num[po-1];
		while(i+g<n && j+g<n && s[i+g]==s[j+g]) g++;
		lcp[po] = g;
		if(g) g--;
	}
	ll now = 0;
	for(int i=0;i<n;i++){
		int q = n-1-num[i] -lcp[i];
		if(now+q>=k){
			int dif = k-now;
			int loc = lcp[i]+dif;
			for(int j = 0;j<loc;j++){
				cout<<s[j+num[i]];
			}
			cout<<"\n";
			return 0;
		}
		now+=q;
	}
	return 0;
}
