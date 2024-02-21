#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 55;
int p[N];
int rnk[N];
int vote[N];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<int> ord;	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		rnk[a]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>vote[i];
	}
	for(int i=1;i<=n;i++){
		ord.push_back(i);
	}
	sort(ord.begin(),ord.end(),[&](const int a,const int b){return rnk[a]<rnk[b];});
	for(int i=0;i<n;i++){
		p[ord[i]]+=(n-i);
	}
	sort(ord.begin(),ord.end(),[&](const int a,const int b){return vote[a]>vote[b];});
	for(int i=0;i<n;i++){
		p[ord[i]]+=(n-i);
	}
	sort(ord.begin(),ord.end(),[&](const int a,const int b){return (p[a]==p[b])?(vote[a]>vote[b]):(p[a]>p[b]);});
	for(int i=0;i<n;i++){
		cout<<(i+1)<<". Kod";
		cout<<(ord[i])/10;
		cout<<(ord[i])%10;
		cout<<" ";
		cout<<"("<<p[ord[i]]<<")\n";
	}

	return 0;
}
