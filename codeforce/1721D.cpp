#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


int n;
vector<int> a;
vector<int> b;

bool works(int k,int l){
	map<int,int> cnt;
	for(int i=0;i<n;i++){
		int need=0;
		for(int j=29;j>=29-l;j--){
			need*=2;
			if( ((k>>(l-(29-j))) ^ (a[i]>>j)) & 1 ) need+=1;
		}
		if(cnt.count(need)) cnt[need]++;
		else cnt.insert({need,1});
	}
	for(int i=0;i<n;i++){
		int con=0;
		for(int j=29;j>=29-l;j--){
			con*=2;
			if((b[i]>>j) & 1) con+=1;
		}
		if(!cnt.count(con) || cnt[con]==0) return 0;
		cnt[con]--;
	}
	return 1;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		b.resize(n);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		int rans=0;
		for(int i=0;i<30;i++){
			rans*=2;
			if(works(rans+1,i)) rans+=1;
		}
		cout<<rans<<"\n";
	}

	return 0;
}
