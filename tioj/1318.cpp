#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


vector<ll > lowpro;
vector<pair<int,int> > hpro;
int h,m;

int intime(ll t){
	if(t<0) return -1e9;
	int l=0;int r = m;
	while(r-l>1){
		int mid = (l+r)/2;
		if(lowpro[mid]>t) r= mid;
		else l = mid;
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;cin>>n>>t;
	for(int i=0;i<n;i++){
		int c,h;cin>>c>>h;
		if(2*h<=c){
			lowpro.push_back(h);
			lowpro.push_back(c-h);
		}else{
			hpro.push_back({h,c-h});
		}
	}
	lowpro.push_back(0);
	sort(lowpro.begin(),lowpro.end());
	m = lowpro.size();
	for(int i=1;i<m;i++) lowpro[i] = lowpro[i]+lowpro[i-1];
	sort(hpro.begin(),hpro.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.first+a.second<b.first+b.second;});	
	h = hpro.size();
	int lmax = 0;int rmin[h+1];
	fill(rmin,rmin+h+1,INT_MAX);
	for(int i=h-1;i>=0;i--) rmin[i] = min(rmin[i+1],hpro[i].first);
	int ans = intime(t);
	ll ktime=0;
	for(int i=0;i<h;i++){
		lmax = max(lmax,hpro[i].second);
		ktime+=hpro[i].first+hpro[i].second;
		ans = max(ans,2*(i+1)+intime(t-ktime));
		ans = max(ans,2*(i+1)-1+intime(t-ktime+lmax));
		ans = max(ans,2*(i+1)+1+intime(t-ktime-rmin[i+1]));
	}





	cout<<ans<<"\n";
	return 0;
}
