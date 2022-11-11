#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


void getbinary(bool te[25],int v){
	for(int i=24;i>=0;i--){
		if((v>>i)&1) te[24-i]=1;
		else te[i]=0;
	}
}
int n;
vector<int> arr;

struct node{
	int cnt=1;
	node* p[2] = {nullptr,nullptr};
};
struct trie{
	int nodecnt(node* a){
		if(a!=nullptr) return a->cnt;
		else return 0;
	}
	node* head = new node;	
	void add(int v){
		bool tobeadd[25]={0};
		getbinary(tobeadd,v);	
		node* cur =head;
		for(int i=0;i<25;i++){
			if(cur->p[tobeadd[i]]!=nullptr){
				cur = cur->p[tobeadd[i]];
				cur->cnt+=1;
			}else{
				cur->p[tobeadd[i]] = new node;
				cur = cur->p[tobeadd[i]];
			}
		}
	}

	void minus(int v){
		bool tobeminus[25]={0};
		getbinary(tobeminus,v);
		node* cur = head;
		for(int i=0;i<25;i++){
			assert(cur->p[tobeminus[i]]!=nullptr);
			if((cur->p[tobeminus[i]])->cnt==1){
				cur->p[tobeminus[i]] = nullptr;
				break;
			}
			cur = cur->p[tobeminus[i]];
			cur->cnt--;
		}
	}

	int get(int v,int m){
		int ans=0;	
		bool va[25]={0};getbinary(va,v);
		bool ma[25]={0};getbinary(ma,m);
		node* cur = head;
		for(int i=0;i<25;i++){
			if(!ma[i]){
				ans+=nodecnt(cur->p[!va[i]]);
				if(cur->p[va[i]]==nullptr) return ans;
				else cur = cur->p[va[i]];
			}else{
				if(cur->p[!va[i]]==nullptr) return ans;
				else cur = cur->p[!va[i]];
			}
		}
		ans+=nodecnt(cur);
		return ans;
	}

};
void clear(node* a){
	if(a==nullptr) return;
	clear(a->p[0]);
	clear(a->p[1]);
	delete(a);
}
ll ans(int l,int r){
	//cout<<l<<" "<<r<<"\n";
	if(r-l==1) return 0;
	ll divide = ans(l,(r+l)/2)+ans((r+l)/2,r);	
	int mid = (r+l)/2;
	int lmax[mid-l+1]={0};
	int rmax[r-mid+1]={0};
	for(int i=1;i<mid-l+1;i++) lmax[i] = max(lmax[i-1],arr[mid-i]);	
	for(int i=1;i<r-mid+1;i++) rmax[i] = max(rmax[i-1],arr[mid+i-1]);
	ll ans=0;
	trie tr;
	for(int i=mid;i<r;i++) tr.add(arr[i]);
	int p = r-mid;	
	for(int i=1;i<mid-l+1;i++){
		while(rmax[p]>lmax[i] && p>0){
			tr.minus(arr[mid+p-1]);
			p--;
		}
		if(p==0) break;
		ans+=tr.get(arr[mid-i],lmax[i]);	
	}
	clear(tr.head);
	trie tr2;
	for(int i=mid-1;i>=l;i--) tr2.add(arr[i]);
	p = mid-l;
	for(int i=1;i<r-mid+1;i++){
		while(lmax[p]>=rmax[i] && p>0){
			tr2.minus(arr[mid-p]);
			p--;
		}
		if(p==0) break;
		ans+=tr2.get(arr[mid+i-1],rmax[i]);
	}
	clear(tr2.head);
	//cout<<l<<" <<r<<" "<<divide+ans<<"\n";
	return divide+ans;	
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<ans(0,n)<<"\n";
	return 0;
}
