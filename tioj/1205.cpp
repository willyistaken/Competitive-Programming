#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


struct pt{
	ll x;
	ll y;
	void print(){
		cerr<<"("<<x<<","<<y<<")\n";
	}
};

ll operator^(const pt &a,const pt &b){
	return a.x*b.y - a.y*b.x;
}

ll operator*(const pt &a,const pt &b){
	return a.x*b.x+a.y*b.y;
}

bool operator==(const pt &a,const pt &b){
	return (a.x==b.x && a.y==b.y);
}

pt operator-(const pt &a,const pt &b){
	pt r;
	r.x = a.x-b.x;
	r.y = a.y-b.y;
	return r;
}

bool comp(const pt &a,const pt &b,const pt &ce){
	if(b==ce) return 0;
	if(a==ce) return 1;
	if(((a-ce)^(b-ce))>0) return 1;
	else return 0;
}




int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pt> arr(n);
	vector<pt> sed(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;
		sed[i].x = arr[i].x;
		sed[i].y = arr[i].y;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		sort(sed.begin(),sed.end(),[&](const pt &a,const pt &b){return comp(a,b,arr[i]);});		
		int l = 1;int r = 2;
		bool flag=0;
		while(l!=1 || !flag){
			if(l==r) break;
			if(((sed[l]-sed[0])*(sed[r]-sed[0]))>0) r++;
			else if(((sed[l]-sed[0])*(sed[r]-sed[0]))<0) l++;
			else{
			int startr=r;
			bool changel=0;
			while(((sed[l]-sed[0])*(sed[r]-sed[0]))==0) {
				ans++;
				r++;
				changel=1;
			}
			if(changel) l++;
			r=startr;
			}
			r%=n;
			l%=n;
			if(!r) r++;
			if(!l) l++;
			if(l!=1) flag=1;
		}
	}
	cout<<ans<<"\n";	

	return 0;
}
