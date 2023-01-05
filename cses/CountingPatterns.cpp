#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct node{
	bool head=0;
	vector<int> end;
	int cnt=0;
	node* ch[26];
	node* fail;
	vector<node*> adj;
	node(node* a = nullptr){
		fail = a;
		for(int i=0;i<26;i++) ch[i] = a;	
	}
};

struct AC{
	node* head = new node;
	int t = 0;
	AC(){
		head->head = 1;
		for(int i=0;i<26;i++) head->ch[i] = head;
		head->fail = head;
	}
	void insert(string &s){
		auto cur = head;
		for(auto i : s){
			if(cur->ch[i-'a']==head) cur->ch[i-'a'] = new node(head);
			cur = cur->ch[i-'a'];
		}
		cur->end.push_back(++t);
	}
	void built(){
		queue<node*> q;
		for(int i=0;i<26;i++){
			if(head->ch[i]!=head) q.push(head->ch[i]);
			head->ch[i]->fail = head;
		}
		while(q.size()){
			node* cur = q.front();
			q.pop();
			for(int i=0;i<26;i++){
				if(cur->ch[i]!=head){
					cur->ch[i]->fail = cur->fail->ch[i];
					q.push(cur->ch[i]);
				}else{
					cur->ch[i] = cur->fail->ch[i];
				}
			}
			cur->fail->adj.push_back(cur);
		}
	}
	void search(string &s){
		node* cur = head;
		for(auto i : s){
			cur = cur->ch[i-'a'];
			cur->cnt++;
		}
	}
} match;
vector<int> ans;
int dfs(node* cur){
	int r = cur->cnt;
	for(auto i : cur->adj){
		r+=dfs(i);
	}
	for(auto i : cur->end){
		ans[i]+=r;
	}
	return r;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int t;cin>>t;
	ans.resize(t+1,0);
	for(int i=0;i<t;i++){
		string a;cin>>a;
		match.insert(a);
	}
	match.built();
	match.search(s);
	dfs(match.head);
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
