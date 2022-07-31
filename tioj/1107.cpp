#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+5;

double c[MAXN];

void init(){
	c[0]=1;
	c[1]=1;
	for(int i=2;i<MAXN;i++){
		c[i] = ((double)(4*i-2)*c[i-1])/((double)(i+1));
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();	
	int g;
	while(cin>>g && g){
	for(int n=1;n<=g;n++){
		ostringstream streamobj;
		streamobj<<setprecision(3)<<scientific<<c[n];
		string s = streamobj.str();
		int ind=0;
		int mantissa=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='e') s[i]='E';
			if(ind){
				mantissa*=10;
				mantissa+=s[i]-'0';
			}
			if(s[i]=='+') ind=i;
		}
		cout<<n<<":"<<c[n]<<s.substr(0,ind+1)<<mantissa<<"\n";
		//stuck there is a inf issue
	}
	}
	return 0;
}
