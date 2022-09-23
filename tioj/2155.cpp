#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::



int s;

vector<int> sa;
vector<pair<pair<int,int> ,int> > temp;
vector<int> lcp;
string total;
void init(){
	sa.resize(s);	
	temp.resize(s);
	for(int i=0;i<s;i++) temp[i] = {{(int)total[i],(int)total[i]},i};
	sort(temp.begin(),temp.end());
	int rank=0;
	sa[temp[0].second] = rank;
	for(int i=1;i<s;i++) {
		if(temp[i].first == temp[i-1].first) sa[temp[i].second] = rank;
		else sa[temp[i].second] = ++rank;
	}

	for(int k=0;k<__lg(s)+1;k++){
		for(int i=0;i<s;i++){
			temp[i] =  {{sa[i],sa[(i+(1<<k))%s]},i};
		}
		sort(temp.begin(),temp.end());
		rank =0;
		sa[temp[0].second] = rank;
		for(int i=1;i<s;i++){
			if(temp[i].first == temp[i-1].first) sa[temp[i].second] = rank;
			else sa[temp[i].second] = ++rank;
		}
	}

}

void lcpinit(){
	lcp.resize(s,0);
	int k=0;
	for(int i=0;i<s;i++){
		int pi = sa[i];
		int j = temp[pi-1].second;
		while(j+k<s && i+k<s && total[j+k]==total[i+k]) k++;
		lcp[pi] = k;
		k = max(0,k-1);
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n==1){
		string s;cin>>s;
		cout<<s<<"\n";
		return 0;
	}
	vector<int> wordlen;
	for(int i=0;i<n;i++){
		string a;cin>>a;
		total+=a;
		total+=(char)(i%10+15);
		wordlen.push_back(total.size());
	}
	s = total.size();	
	init();
	lcpinit();
	int inwhich[s] ={0};
	for(int i=n;i<s;i++){
		inwhich[i] = upper_bound(wordlen.begin(),wordlen.end(),temp[i].second)-wordlen.begin();	
	}
	lcp.push_back(0);	
	deque<int> mono;
	int cnt[n] = {0};
	int type=0;
	for(int i=n;i<2*n;i++){
		cnt[inwhich[i]]++;
		if(cnt[inwhich[i]]==1) type+=1;
		while(mono.size()){
			if(lcp[mono.back()]>=lcp[i]) mono.pop_back();
			else break;
		}
		mono.push_back(i);
	}
	if(mono.front()==n) mono.pop_front();
	int l=n;
	if(type==n && lcp[l]<lcp[mono.front()] && lcp[2*n]<lcp[mono.front()]){
		for(int j = 0;j<lcp[mono.front()];j++) cout<<total[temp[n].second+j];
		cout<<"\n";
		return 0;
	}
	for(int i=2*n;i<s;i++){
		cnt[inwhich[l]]--;
		if(cnt[inwhich[l]]==0) type--;
		l++;
		cnt[inwhich[i]]++;
		if(cnt[inwhich[i]]==1) type++;
		while(mono.size()){
			if(mono.front()<=l) mono.pop_front();
			else break;
		}
		while(mono.size()){
			if(lcp[mono.back()]>=lcp[i]) mono.pop_back();
			else break;
		}
		mono.push_back(i);
		if(type==n && lcp[l]<lcp[mono.front()] && lcp[i+1]<lcp[mono.front()]){
			for(int j=0;j<lcp[mono.front()];j++) cout<<total[temp[i].second+j];
			cout<<"\n";
			return 0;
		}
	}
	cout<<7122<<"\n";
	return 0;
}
