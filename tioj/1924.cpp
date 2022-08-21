#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int pn[n+1]={0};
	int en[n+1]={0};
	int cn[n+1]={0};
	string s;cin>>s;
	for(int i=0;i<n;i++){
		pn[i+1] = pn[i]+(s[i]=='P');
		en[i+1] = en[i]+(s[i]=='E');
		cn[i+1] = cn[i]+(s[i]=='C');
	}
	int maxn=0;
	int pe,pc,ep,ec,cp,ce;
	pe=pc=ep=ec=cp=ce=INT_MIN;
	for(int i=n;i>=0;i--){
		pe = max(pe,pn[i]-en[i]);	
		pc = max(pc,pn[i]-cn[i]);	
		ep = max(ep,en[i]-pn[i]);	
		ec = max(ec,en[i]-cn[i]);	
		cp = max(cp,cn[i]-pn[i]);	
		ce = max(ce,cn[i]-en[i]);	
		maxn = max({cn[i]-pn[i]+pe+en[n],en[i]-pn[i]+pc+cn[n],cn[i]-en[i]+ep+pn[n],pn[i]-en[i]+ec+cn[n],en[i]-cn[i]+cp+pn[n],pn[i]-cn[i]+ce+en[n],maxn});
	}
	cout<<maxn<<"\n";	

	return 0;
}
