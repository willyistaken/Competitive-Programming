#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*sol:
 if every single edge in the selected vertex set has two neighbor in the vertex set , then we call that vertex set good
 sol: hash edges and add(or subtract) it in to it's node, then query the sum of all the node ,if it is zero, it means it has cancel out completely else it is not
*/ 
vector<ll> Xornode;

int hsh(int a,int b){
	if(a>b) swap(a,b);
	return (a*17)+(b*289);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	Xornode.resize(n+1,0);
	for(int f=0;f<m;f++){
		int type;cin>>type;
		if(type==0){
			int a,b;cin>>a>>b;
			if(a>b) swap(a,b);
			Xornode[a]-=hsh(a,b);
			Xornode[b]+=hsh(a,b);
		}else if(type==1){
			int a,b;cin>>a>>b;
			if(a>b) swap(a,b);
			Xornode[b]-=hsh(a,b);
			Xornode[a]+=hsh(a,b);
		}else{
			int r = 0;
			int k;cin>>k;
			for(int i=0;i<k;i++){
				int g;cin>>g;
				r+=Xornode[g];
			}
			cout<<(r==0)<<"\n";
		}
	}
    
    return 0;
}
