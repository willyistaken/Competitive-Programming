#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int l[2];int r[2];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	l[0]=l[1]=r[0]=r[1]=-1;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		bool c = i&1;
		if(l[c]==-1 && r[c]==-1) l[c]=r[c]=x;
		else if(l[c]-1!=x && r[c]+1!=x) l[!c]=r[!c]=-1;
		l[c]=min(l[c],x);
		r[c]=max(r[c],x);
	}
	if(r[0]-l[0]>r[1]-l[1]) cout<<"Repkironca\n";
	if(r[0]-l[0]<r[1]-l[1]) cout<<"BrineTW\n";
	if(r[0]-l[0]==r[1]-l[1]) cout<<"Aaw\n";
	return 0;
}
