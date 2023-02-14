#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> mul[1000001];

struct dsu{
	vector<int> arr;
	void init(int n){
		arr.resize(n);
		for(int i=0;i<n;i++) arr[i]=i;
	}
	int query(int x){
		if(arr[x]==x) return x;
		arr[x] = query(arr[x]);
		return arr[x];
	}
	void join(int a,int b){
		a = query(a);
		b= query(b);
		arr[a]=b;
	}
} s;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	s.init(n);
	for(int i=0;i<n;i++){
		int k;cin>>k;
		int g = 1;
		for(;g*g<k;g++){
			if(k%g==0)  {
				mul[g].push_back(i);
				mul[k/g].push_back(i);
			}
		}
		if(g*g==k){
			mul[g].push_back(i);
		}
	}
	ll sum = 0;
	int cnt = 0;
	for(int i=1e6;i>=1;i--){
		for(int j=0;j<((int)mul[i].size())-1;j++){
			if(s.query(mul[i][j])!=s.query(mul[i][j+1])){
				s.join(mul[i][j],mul[i][j+1]);	
				cnt++;
				sum+=i;
			}
			if(cnt==n-1){
				cout<<sum<<"\n";
				return 0;
			}
		}
	}

	return 0;
}
