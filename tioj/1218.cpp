#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(true){
		getline(cin,s);
		int firstnz=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]!='0'){
				firstnz=i;
				break;
			}
		}
		if(firstnz==-1) return 0;
		if(firstnz==s.size()-1){
			if(s[s.size()-1]=='1'){
				cout<<"LOSE WIN\n";
				continue;
			}
			if(s[s.size()-1]=='2'){
				cout<<"WIN LOSE\n";
				continue;
			}
			if(s[s.size()-1]=='3'){
				cout<<"LOSE WIN\n";
				continue;
			}
			
		}
		if((s[s.size()-1]-'0')%2){
			cout<<"LOSE LOSE\n";
		}else{
			cout<<"WIN WIN\n";
		}
	}

}


/*
(1)  the same as (2) every odd number is loosing state every even number is winning state ;


(2)  if n-1 is loosing state n is winning state
and every odd number >=5 is a loosing state: because odd number can only reach even number and every even number except for 2 is winning state since every odd number is loosing state(n-1);
instead of 1,2,3 1 is win 2 is loose 3 is win
*/
