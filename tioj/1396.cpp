#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int X,Y;
struct line{
	int l;
	int r;
};
int solve(int n,vector<line> &arr){
	if(X==Y){
		for(int i=0;i<n;i++){
			if(arr[i].l<=X && arr[i].r>=Y) return 1;
			else return INT_MAX;
		}
	}
	
	int ans=0;int cur = X;int maxn = X;
	int i=0;
	while(cur<Y){
		while(i<n && arr[i].l<=cur){
			maxn = max(maxn,arr[i].r);
			i++;
		}
		if(maxn<=cur) return INT_MAX;
		ans++;
		cur = maxn;
	}

	return ans;

}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int na,nb;
	while(cin>>na>>nb){
	vector<line> aline(na);	
	vector<line> bline(nb);	
	for(int i=0;i<na;i++) cin>>aline[i].l>>aline[i].r;
	for(int i=0;i<nb;i++) cin>>bline[i].l>>bline[i].r;
	cin>>X>>Y;
	sort(aline.begin(),aline.end(),[](const line &a,const line &b){return (a.l==b.l)?a.r<b.r:a.l<b.l;});
	sort(bline.begin(),bline.end(),[](const line &a,const line &b){return (a.l==b.l)?a.r<b.r:a.l<b.l;});
	int aans = solve(na,aline);
	int bans = solve(nb,bline);
	if(aans==INT_MAX && bans==INT_MAX){
		cout<<"TIE\n";
	}else{
		if(aans<=bans ){
			cout<<"A WIN\n";
		}else{
			cout<<"B WIN\n";
		}
	}
	}
	return 0;
}
