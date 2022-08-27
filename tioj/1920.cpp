#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

struct node{
	int v=1;
	node* c[2]={nullptr,nullptr};
};

vector<node*> trie;

void add(int ind,int u){
	bitset<30> arr;
	for(int i=29;i>=0;i--){
		if(u&1) arr[i]=1;
		else arr[i]=0;
		u>>=1;
	}
	node* prev = trie[max(ind-1,0)];
	node* now = trie[ind];
	bool flag=(ind==0);
	for(int i=0;i<30;i++){
		if(!flag && prev->c[arr[i]]==nullptr){
			now->c[!arr[i]] = prev->c[!arr[i]];
			prev = nullptr;
			flag=1;	
		}
		if(flag){
			now->c[arr[i]] = new node;
			now = now->c[arr[i]];
		}else{
			now->c[arr[i]] = new node;
			(now->c[arr[i]])->v = ((prev->c[arr[i]])->v)+1;
			now->c[!arr[i]] = prev->c[!arr[i]];
			now = now->c[arr[i]];
			prev = prev->c[arr[i]];
		}
	}
}


int search(int l,int r,int u){
	
	bitset<30> arr;
	for(int i=29;i>=0;i--){
		if(u&1) arr[i]=0;
		else arr[i]=1;
		u>>=1;
	}
	bitset<30> ans; ans.reset();
	node* lp = (l<0)?(nullptr):(trie[l]);
	node* rp = trie[r];
	for(int i=0;i<30;i++){
		if(lp==nullptr){
			ans[i] = (rp->c[arr[i]]!=nullptr);
			rp = (ans[i])?(rp->c[arr[i]]):(rp->c[!arr[i]]);
		}else{
			int num = (rp->c[arr[i]]==nullptr)?(0):((rp->c[arr[i]])->v);
			num-=(lp->c[arr[i]]==nullptr)?(0):((lp->c[arr[i]])->v);
			ans[i] =(num>0);
			if(ans[i]){
				rp = rp->c[arr[i]];
				lp = lp->c[arr[i]];
			}else{
				rp = rp->c[!arr[i]];
				lp = lp->c[!arr[i]];
			}
		}
	}
	int result=0;
	for(int i=0;i<30;i++){
		result*=2;
		result+=ans[i];
	}
	return result;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	trie.resize(n+1);
	for(int i=0;i<=n;i++){
		trie[i] = new node;
	}
	int p[n+1]={0};
	add(0,0);
	for(int i=1;i<=n;i++){
		cin>>p[i];
		p[i] = p[i]^p[i-1];
		add(i,p[i]);
	}
	while(q--){
		int l,r,v;cin>>l>>r>>v;
		v = p[r]^v;
		cout<<search(l-1,r-1,v)<<"\n";
	}
	return 0;
}
