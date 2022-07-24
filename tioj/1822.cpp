/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300005;
bitset<MAXN> ans;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	bitset<MAXN> apply;
	for(int i=0;i<m;i++){
		apply.reset();
		int k;cin>>k;
		apply[k]=1;
		for(int i=0;i<10;i++){
			apply |= (apply<<(k*(1<<i)));
		}
		ans^=apply;
	}
	int onbit=0;
	queue<int> all;
	for(int i=1;i<=n;i++){
		if(ans[i]) {
			onbit++;
			all.push(i);
		}
	}
	cout<<onbit<<"\n";
	while(all.size()){
		cout<<all.front()<<"\n";
		all.pop();
	}
	return 0;
}
*/
//bitset does not work
// AHA n << m , by the //pigion pole principle, there must be duplicate, just clean up the dupe

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 300005;
bitset<MAXN> ans;
bitset<MAXN> appear;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ans.reset();
	appear.reset();
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int k;cin>>k;
		appear.flip(k);
	}
	for(int i=1;i<=n;i++){
		if(appear[i]){
			for(int j=1;j*i<=n;j++){
				ans.flip(j*i);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ans[i]) cnt++;
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=n;i++){
		if(ans[i]) cout<<i<<"\n";
	}
	return 0;
}


// note to self: check the range of testdata , find weird size differnce that may be the cracking point
