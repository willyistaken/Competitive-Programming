#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct node{
	vector<node*> ch;
	int l;
	ll ans = 0;
	node* p;
};
vector<ll> result;
vector<int> rbscnt;
void dfs(node* a){
	ll ans = 0;
	for(auto i : a->ch){
		dfs(i);
		ans+=i->ans;
	}
	int s = a->ch.size();
	ans+= (1LL*s*(s-1))/2;
	ans++;
	a->ans = ans;
	if(a->l<1000000){
	result[a->l+1] = a->ans;
	rbscnt[a->l+1] = 1;
	}
}

int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	result.resize(n+1,0);
	rbscnt.resize(n+1,0);
	string s;cin>>s;
	stack<int> open;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			open.push(i);
		}else{
			if(open.size()) open.pop();	
			else{
				s[i] = '.';
			}
		}
	}
	while(open.size()){
		s[open.top()] = '.';
		open.pop();
	}
	node* head = new node;
	head->l = 1e9;
	int r[n];
	int tol[n];
	for(int i= 0;i<n;i++){
		r[i] = 1e9;
		tol[i]=1e9;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			node* newnode = new node;
			head->ch.push_back(new node);	
			head->ch.back()->p = head;
			head = head->ch.back();
			head->l = i;
		}else if(s[i]==')'){
			r[head->l] = i;
			tol[i] = head->l;
			head = head->p;
		}
	}
	dfs(head);
	for(int i=1;i<=n;i++){
		rbscnt[i] =rbscnt[i-1]+(result[i]!=0);
		result[i] = result[i-1]+result[i];
		cout<<result[i]<<" "<<rbscnt[i]<<endl;
	}
	
	while(q--){
		int t;cin>>t;
		int ql,qr;cin>>ql>>qr;
		ql--;qr--;
		ll anssum = result[tol[qr]+1]-result[ql];
		ll rbcnt = rbscnt[tol[qr]+1]-rbscnt[ql];
		cout<<anssum+(rbcnt*(rbcnt-1))/2<<"\n";
	}
	return 0;
}
