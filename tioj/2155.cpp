#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct st{
	int id;
	pair<int,int> rank;
};

struct segtree{
	vector<int> arr;
	int _n;
	void init(int s){
		_n = s;
		arr.resize(2*s);
		fill(arr.begin(),arr.end(),INT_MAX);
	}
	void add(int ind,int v){
		ind+=_n;
		if(v<arr[ind]){
			arr[ind] = min(arr[ind],v);
			while(ind){
				ind>>=1;
				arr[ind] = min(arr[2*ind],arr[2*ind+1]);
			}
		}
	}

	int query(int l,int r){
		int result = INT_MAX;
		l+=_n;r+=_n;
		while(l<r){
			if(l%2) result = min(result,arr[l++]);
			if(r%2) result = min(result,arr[--r]);
			l>>=1;r>>=1;
		}
		return result;
	}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int m = n;
	string s = "";
	for(int i=0;i<n;i++){
		string k;cin>>k;
		s+=k;
		s+=(char)((i%10)+'0');
	}
	s.pop_back();
	s+='$';
	n = s.size();
	int sfa[n]={0};
	st temp[n];
	for(int i=0;i<n;i++){
		temp[i].id = i;
		temp[i].rank={(int)s[temp[i].id],0};
	}
	for(int k=0;k<=__lg(n)+1;k++){
		sort(temp,temp+n,[](const st &a,const st &b){return a.rank<b.rank;});
		for(int i=0;i<n;i++){
			if(i && temp[i].rank == temp[i-1].rank) sfa[temp[i].id] = sfa[temp[i-1].id];
			else sfa[temp[i].id] = i;
		}
		for(int i=0;i<n;i++){
			temp[i].rank.first = sfa[temp[i].id];
			temp[i].rank.second = sfa[(temp[i].id+(1<<k))%n];
		}
	}
	int k=0;
	segtree range;
	range.init(n-2);
	int lcp[n]={0};
	for(int i=0;i<n-1;i++){
		int pi = sfa[i];
		int j = temp[pi-1].id;
		while(j+k<n && i+k<n && s[i+k]==s[j+k]) k++;
		lcp[pi] = k;
		k = max(0,k-1);
	}
	for(int i=1;i<n-1;i++){
		range.add(i-1,lcp[i]);
	}
	for(int i=1;i<n-2-m;i++){
		if(i==0){
			if(range.query(i,i+m)<=range.query(i+1,i+m+1)) continue;
		}else if(i==n-m){
			if(range.query(i,i+m)<=range.query(i-1,i+m-1)) continue;
		}else{
			if(range.query(i,i+m)<=range.query(i-1,i+m-1) || range.query(i,i+m)<=range.query(i+1,i+m+1)) continue;
		}
		int gl = range.query(i,i+m);
		for(int j=0;j<gl;j++) cout<<s[j+i];
		cout<<"\n";
		return 0;
	}
	cout<<"7122\n";
	return 0;
}

