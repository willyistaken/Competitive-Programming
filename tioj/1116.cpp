#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(cin>>s){
		for(int i=0;i<4;i++){
				if(s[i]=='b'){
						cout<<"X";
				}else{
					bool flag=0;
					if(s[(i+3)%4]=='b' || s[(i+3)%4]=='c'){
							cout<<"A";
							flag=1;
					}
					if(s[(i+1)%4]=='b' || s[(i+1)%4]=='c'){
							cout<<"B";
							flag=1;
					}
					if(s[(i+2)%4]=='b' || s[(i+2)%4]=='c'){
							cout<<"C";
							flag=1;
					}
					if(!flag) cout<<"Y";
				}
				cout<<((i==3)?("\n"):(", "));
		}
	}

	return 0;
}
