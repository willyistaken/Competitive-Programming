#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

string s;
int n ;
vector<int> rk;

vector<int> num;
void sa(){
	rk.resize(n);	
	num.resize(n);
	for(int i=0;i<n;i++) num[i] = i;
	for(int i=0;i<n;i++) rk[i] = s[i]-'#';
	for(int p = 0;p<20;p++){
		pair<int,int> temp[n];
		for(int i=0;i<n;i++){
			temp[i] = {rk[i],rk[(i+(1<<p))%n]};
		}
		sort(num.begin(),num.end(),[&](int a,int b){return temp[a]<temp[b];});
		int prev = 0;
		rk[num[0]]= 0;
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
	s+='#';
	n = s.size();	
	sa();	
	for(int i=0;i<n;i++) rk[num[i]] = i;	
	int lcp[n] = {0};
	int k = 0;
	for(int i=0;i<n-1;i++){
		int pi = rk[i];	
		int j = num[pi-1];
		while(j+k<n && i+k<n && s[j+k]==s[i+k]) k++;
		lcp[pi] = k;
		if(k) k--;
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans+=lcp[i];
	}
	ll total = (1LL*(n-1)*n)/2;
	cout<<total-ans<<"\n";
	return 0;
}

