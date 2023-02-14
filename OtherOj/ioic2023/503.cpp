#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct pt{
	ll x;
	ll y;
};

ll operator^(const pt &a,const pt &b){
	return a.x*b.y-a.y*b.x;
}

pt operator-(const pt &a,const pt &b){
	pt r;
	r.x = a.x-b.x;
	r.y = a.y-b.y;
	return r;
}

ll operator*(pt &a,const pt &b){
	return a.x*b.x+a.y*b.y;
}

int ori(pt &a,pt &b,pt &c){
	ll k =(a-c)^(b-c);
	if(k>0) return 1;
	if(k<0) return -1;
	return 0;
}

bool online(pt a,pt s,pt e){
	pt v1 = s-a;
	pt v2 = e-a;
	if(v1^v2) return 0;
	if(v1*v2>=0) return 0;
	return 1;
}

bool intersect(pt &a,pt &b,pt &c,pt& d){
	if(online(a,c,d) || online(b,c,d) || online(c,a,b) || online(d,a,b)) return 1;
	return (ori(a,c,d)*ori(b,c,d)<0 && ori(c,a,b)*ori(d,a,b)<0);

}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pt arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	int m;cin>>m;
	pair<pt,pt> l[m];
	for(int i=0;i<m;i++){
		cin>>l[i].first.x>>l[i].first.y>>l[i].second.x>>l[i].second.y;
	}
	if(m>500 || n>500) return 0;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(j==i) continue;
			bool flag=1;
			for(int k=0;k<m;k++){
				if(intersect(l[k].first,l[k].second,arr[i],arr[j]))  {
					flag=0;
					break;
				}
			}
			if(flag) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
