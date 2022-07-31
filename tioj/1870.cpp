#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct segtree{
	struct node{
		int bin[21]={0};
		int tag=0;
		int len=1;
		void print(){
			ll number=0;
			for(int i=20;i>=0;i--){
				cerr<<bin[i];
				number+= (bin[i]*(1LL<<i));
			}
			cerr<<":"<<number<<" tag: "<<tag<<" len: "<<len<<"\n";
		}	
		void apply(int k){
			tag^=k;
			for(int i=0;i<21;i++){
				if(k&1) bin[i] = len-bin[i];			
				k>>=1;
			}
		}

		void combine(const node &a,const node &b){
			len = a.len+b.len;
			for(int i=0;i<21;i++){
				bin[i] = a.bin[i]+b.bin[i];
			}
			int dtag=tag;
			tag=0;
			apply(dtag);
			// note to self: remember to reset the tag when doing this, you always forget this step
		}
	};
		
	vector<node> arr;
	void init(){
		arr.resize(2*n);
		for(int i=0;i<n;i++){
			int g;cin>>g;
			arr[i+n].apply(g);
		}
		for(int i=n-1;i>=1;i--){
			arr[i].combine(arr[2*i],arr[2*i+1]);
		}
	}
	void pull(int ind){
		if(ind==1) return;
		pull(ind>>1);
		ind>>=1;
		arr[2*ind].apply(arr[ind].tag);
		arr[2*ind+1].apply(arr[ind].tag);
		arr[ind].tag=0;
	}
	void push(int ind){
		ind>>=1;
		while(ind){
			arr[ind].combine(arr[2*ind],arr[2*ind+1]);
			ind>>=1;
		}
	}
	
	void modify(int l,int r,int v){
		l+=n;r+=n;
		int tl=l;int tr=r;
		pull(l);pull(r-1);
		while(l<r){
			if(l%2) arr[l++].apply(v);
			if(r%2) arr[--r].apply(v);
			l>>=1;r>>=1;
		}
		push(tl);push(tr-1);
	}

	ll query(int l,int r){
		l+=n;r+=n;
		pull(l);pull(r-1);
		int ans[21]={0};
		while(l<r){
			if(l%2) {
				for(int i=0;i<21;i++) ans[i]+=arr[l].bin[i];
				l++;
			}
			if(r%2){
				--r;
				for(int i=0;i<21;i++) ans[i]+=arr[r].bin[i];
			}
			l>>=1;r>>=1;
		}
		ll result=0;
		for(int i=0;i<21;i++){
			result += (ans[i]*(1LL<<i));
		}
		return result;
	}
	void print(){
		for(int i=1;i<2*n;i++){
			cerr<<i<<"::";
			arr[i].print();
		}
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	segtree orz;
	orz.init();
	//orz.print();
	int q;cin>>q;
	while(q--){
		int type;cin>>type;
		if(type==1){
			int l,r;cin>>l>>r;
			l--;
			cout<<orz.query(l,r)<<"\n";	
		}else{
			int l,r,v;cin>>l>>r>>v;
			l--;
			orz.modify(l,r,v);
		}
		//orz.arr[4].print();
		//orz.print();
	}
	return 0;
}
