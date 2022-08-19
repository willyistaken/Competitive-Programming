#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

bool compb(const string &a,const string &b){
	if(a.size()!=b.size()) return a.size()>b.size();
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return 0;
}

bool comps(const string &a,const string &b){
	if(a.size()!=b.size()) return a.size()<b.size();
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return a[i]<b[i];
	}
	return 0;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		stack<string> one;
		queue<string> two;
		priority_queue<string,vector<string>,function<bool(string,string)> > three(comps);
		priority_queue<string,vector<string>,function<bool(string,string) > > four(compb);
	while(n--){
		string cmd;cin>>cmd;
		if(cmd=="ダメよ～ダメダメ"){
			int x;string y;cin>>x>>y;
			if(x==1) one.push(y);
			else if(x==2) two.push(y);
			else if (x==3) three.push(y);
			else four.push(y);
		}else if(cmd=="しかしお兄ちゃんはわりと弱気だからなぁ……アタシの方からアプローチしないとダメかな"){
			int x,y;
			cin>>x>>y;
			string temp;
			if(x==1){
				if(one.size()){
					temp = one.top();
					one.pop();
				}else{
					continue;
				}
			}else if(x==2){
				if(two.size()){
					temp = two.front();
					two.pop();
				}else{
					continue;
				}
			}else if (x==3){
				if(three.size()){
					temp = three.top();
					three.pop();
				}else{
					continue;
				}
			}else {
				if(four.size()){
					temp = four.top();
					four.pop();
				}else{
					continue;
				}
			}
			if(y==1) one.push(temp);
			else if(y==2) two.push(temp);
			else if(y==3) three.push(temp);
			else four.push(temp);
		}else{
			int x;
			cin>>x;
			if(x==1){
				if(one.size()){
					cout<<one.top()<<"\n";
					one.pop();
				}else{
					cout<<"イヤ...やめてよ...お兄ちゃん...壊れる\n";
				}
			}else if(x==2){
				if(two.size()){
					cout<<two.front()<<"\n";
					two.pop();
				}else{
					cout<<"イヤ...やめてよ...お兄ちゃん...壊れる\n";
				}
			}else if (x==3){
				if(three.size()){
					cout<<three.top()<<"\n";
					three.pop();
				}else{
					cout<<"イヤ...やめてよ...お兄ちゃん...壊れる\n";
				}
			}else {
				if(four.size()){
					cout<<four.top()<<"\n";
					four.pop();
				}else{
					cout<<"イヤ...やめてよ...お兄ちゃん...壊れる\n";
				}
			}


	}
	}
	}

	return 0;
}
