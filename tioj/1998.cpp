#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	bitset<2> s;
	node* next[2]={nullptr,nullptr};
	bool end=0;
};

struct trie{
	node first;
	void init(){
		first.s.reset();
		first.next[0] =nullptr;
		first.next[1] =nullptr;
	}
	void insert(string st){
		node* cur = &first;
		for(int i=0;i<st.size();i++){
			if(cur->s[st[i]-'0']){
				cur = cur->next[st[i]-'0'];
			}else{
				cur->s[st[i]-'0']=1;
				node* newnode = new node;
				cur->next[st[i]-'0'] = newnode;
				cur = newnode;
			}
			if(i==st.size()-1) cur->end=1;
		}
	}

	bool query(string st){
		node* cur = &first;
		for(int i=0;i<st.size();i++){
			if(cur->s[st[i]-'0']){
				cur = cur->next[st[i]-'0'];	
			}else{
				return 0;
			}
			if(cur->end) return 1;
		}
		return 0;
	}
} mytrie;
string arr[2]={"FALSE\n","TRUE\n"};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mytrie.init();
	int m,n;cin>>m>>n;
	for(int i=0;i<m;i++){
		string s;cin>>s;
		string add="";
		int number=0;
		for(int i=0;i<s.size();i++){
			
			if(s[i]=='.' || s[i]=='/'){
				add+=bitset<8>(number).to_string();		
				number=0;
				continue;
			}
			number*=10;
			number+=s[i]-'0';
		}
		mytrie.insert(add.substr(0,number));
	}
	for(int i=0;i<n;i++){
		string s;cin>>s;
		string add="";
		int number=0;	
		for(int i=0;i<s.size();i++){
			
			if(s[i]=='.' ){
				add+=bitset<8>(number).to_string();		
				number=0;
				continue;
			}
			number*=10;
			number+=s[i]-'0';
		}
		add+=bitset<8>(number).to_string();		
		cout<<arr[mytrie.query(add)];
	}
	
	return 0;
}
