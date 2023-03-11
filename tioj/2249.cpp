#include "lib2249.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

string solve(int n0,int n2){
		if(n2==0 || n0==0) return "-1";
		if(n2%2==0){
			string ans;
			if(n0==1){
				for(int i=0;i<n2-2;i++) ans.push_back('2');
				ans+="022 220";
				for(int i=0;i<n2-2;i++) ans.push_back('2');
				return ans;
			}
			for(int i=0;i<n2-1;i++) ans.push_back('2');
			ans+="002";
			for(int i=0;i<n0-2;i++) ans.push_back('0');
			ans.push_back(' ');
			for(int i=0;i<n0-1;i++) ans.push_back('0');
			ans+="220";
			for(int i=0;i<n2-2;i++) ans.push_back('2');
			return ans;
		}
		if(n2<11 || n0<10){
			return "-1";
		}
		string stuff=  "2020202020202020202";
		n2-=11;
		n0-=10;
		if(n2){
			string fi;
			string se;
			for(int i=0;i<n0;i++) se.push_back('0');
			se+=stuff;
			se+="220";
			for(int i=0;i<n2-1;i++) se.push_back('2');
			if(n0==0){
				for(int i=0;i<n2-1;i++) fi.push_back('2');
				fi+="022";
				fi+=stuff;
			}else if(n0==1){
				for(int i=0;i<n2;i++) fi.push_back('2');
				fi+="0";
				fi+=stuff;
				fi+="02";
			}else{
				for(int i=0;i<n2;i++) fi.push_back('2');
				fi+=stuff;
				fi+="0002";
				for(int i=0;i<n0-2;i++)	fi.push_back('0');	
			}
			return fi+" "+se;
		}else{
			if(n0==0) return "-1";
			if(n0==1){
				return "0"+stuff+"02 "+stuff+"020";
			}
			string ans;	
			ans+=stuff;
			ans+="0002";
			for(int i=0;i<n0-2;i++) ans.push_back('0');
			ans+=" ";
			for(int i=0;i<n0-1;i++) ans.push_back('0');
			ans+=stuff;
			ans+="020";
			return ans;
		}

}
