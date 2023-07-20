#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n=0;
struct vec{
	int g = 0;
	set<int> loc;
};

vec nt(vec a){
	vec result;
	result.g = !a.g;
	int head = 0;
	for(int i=1;i<=n;i++){
		if(!a.loc.count(i)){
			result.loc.insert(i);
		}
	}
	return result;
}

vec ad(vec a,vec b){
	vec result;
	result.g = a.g&b.g;
	for(auto x:a.loc){
		if(b.loc.count(x)){
			result.loc.insert(x);
		}
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<vec> filter(6);					
	int d = 1;
	for(int i=0;i<6;i++){
		string s;
		for(int ch = 0;ch<26;ch++){
			if(!((ch/d)&1)){
				filter[i].g|=(1<<ch);
				s.push_back((char)('a'+ch));
			}
		}
		cout<<"? "<<s<<endl;
		int howmany;cin>>howmany;	
		n = max(n,howmany);
		for(int loc=0;loc<howmany;loc++){
			int x;cin>>x;
			filter[i].loc.insert(x);
		}
		d*=2;
	}
	vector<char> ans(n);
	for(int ch=0;ch<26;ch++){
		vec h = filter[5];
		int dd = 2;
		for(int i=4;i>=0;i--){
			if(((ch/dd))&1){
				h = ad(h,filter[i]);
			}else{
				h = ad(h,nt(filter[i]));
			}
			dd*=2;
		}
		
		for(auto x : h.loc){
			ans[x-1]=(char)('a'+ch);
		}
	}
	cout<<"! ";
	for(int i=0;i<n;i++) cout<<ans[i];
	cout<<endl;
	
	return 0;
}
