#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> ans;
struct node{
	bool head;
	node* fail;
	vector<int> end;
	node* ch[26];
	int cnt = 0;
	vector<node*> adj;
	node(){
		fail = nullptr;
		for(int i=0;i<26;i++) ch[i] = nullptr;
	}
};
struct AC{
	int t =0;
	node* head = new node;	
	AC(){
		head->head = 1;
		head->fail = head;
	}
	void insert(string s){
		node* cur = head;
		for(auto i : s){
			if(cur->ch[i-'a']==nullptr) cur->ch[i-'a'] = new node;	
			cur = cur->ch[i-'a'];
		}
		cur->end.push_back(++t);
	}
	void built(){
		queue<node*> q;
		for(int i=0;i<26;i++){
			if(head->ch[i]!=nullptr) q.push(head->ch[i]);
			else head->ch[i] = head;
			head->ch[i]->fail  = head;
		}
		while(q.size()){
			node* cur = q.front();
			q.pop();
			// core code
			for(int i=0;i<26;i++){
				if(cur->ch[i]!=nullptr){
					cur->ch[i]->fail = (cur->fail->ch[i]);
					q.push(cur->ch[i]);
				}else{
					cur->ch[i] =  (cur->fail->ch[i]);
				}
			}
			cur->fail->adj.push_back(cur);
			// very important
		}
	}
	void search(string& s){
		node* cur = head;
		for(int i=0;i<s.size();i++){
			cur = cur->ch[s[i]-'a'];
			cur->cnt++;
		}
	}
};

int dfs(node* cur){
	int r = cur->cnt;	
	for(auto i : cur->adj){
		r+=dfs(i);
	}
	for(auto i : cur->end){
		ans[i] = r;
	}
	return r;
}


