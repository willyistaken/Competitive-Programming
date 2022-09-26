#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

int allmycnt;
int digit(int a){
	allmycnt++;
	int cnt=0;
	while(a){
		cnt++;
		a/=10;
	}
	return cnt;
}


int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		allmycnt=0;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		vector<int> b(n);
		for(int i=0;i<n;i++) cin>>b[i];
		map<int,int> cnt;
		for(int i=0;i<n;i++) cnt[a[i]]++;
		vector<int> bs;
		for(int i=0;i<n;i++){
			if(cnt[b[i]]){
				cnt[b[i]]--;
			}else{
				bs.push_back(b[i]);
			}
		}
		vector<int> as;
		for(auto i : cnt){
			for(int j=0;j<i.second;j++) as.push_back(i.first);
		}
		int cnta[10]={0};
		for(int i=0;i<as.size();i++){
			if(as[i]>9) as[i] = digit(as[i]);
			cnta[as[i]]++;
		}
		int s=0;
		int sa=0;
		for(int i=0;i<bs.size();i++){
			if(bs[i]>9) bs[i] = digit(bs[i]);
			if(!cnta[bs[i]]){
			 sa++;
			 if(bs[i]!=1) s++;
			}
			else cnta[bs[i]]--;
		}
		cout<<allmycnt+s+sa-cnta[1]<<"\n";
	}

	return 0;
}
