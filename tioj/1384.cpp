#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){
	int ans = 0; char c = RC(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = RC();
	if(c == '-') minus = true, c = RC();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = RC();
	return minus ? -ans : ans;
}
const int S = 20;
inline void W(int n){
	if(!n) return;
	W(n/10);
	(putchar((char)('0'+(n%10))));
}

int main(){
	int n = R();
	pair<int,int> arr[n];	
	for(int i=0;i<n;i++){
		arr[i].first=R();arr[i].second=R();
	}
	sort(arr,arr+n);
	vector<int> s;
	for(int i=0;i<n;i++){
		auto k = upper_bound(s.begin(),s.end(),arr[i].second);
		if(k==s.end()) s.push_back(arr[i].second);
		else s[k-s.begin()] = arr[i].second;
	}
	if(!(n-s.size())) putchar('0');
	else W(n-s.size());

	return 0;
}
