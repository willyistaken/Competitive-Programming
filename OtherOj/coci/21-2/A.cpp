#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct section{
	string title;
	vector<section> sub;
};

vector<section> text;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	while(q--){
		string type;cin>>type;
			section k;
			cin>>k.title;
		if(type=="section"){
			text.push_back(k);
		}else if(type=="subsection"){
			text.back().sub.push_back(k);	
		}else if(type=="subsubsection"){
			text.back().sub.back().sub.push_back(k);
		}
	}
	for(int i=1;i<=text.size();i++){
		cout<<i<<" "<<text[i-1].title<<"\n";
		for(int j=1;j<=text[i-1].sub.size();j++){
			cout<<i<<"."<<j<<" "<<text[i-1].sub[j-1].title<<"\n";
			for(int k=1;k<=text[i-1].sub[j-1].sub.size();k++){
				cout<<i<<"."<<j<<"."<<k<<" "<<text[i-1].sub[j-1].sub[k-1].title<<"\n";
			}
		}
	}
	return 0;
}
