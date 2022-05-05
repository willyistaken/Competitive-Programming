#include <bits/stdc++.h>
using namespace std;


int main(){

	int a,b,c;
	while(cin>>a>>b>>c){
		int sum=a+b+c;
		bool yes=0;
		if(sum-a ==a) yes=1;
		if(sum-b==b) yes=1;
		if(sum-c==c) yes=1;
		string arr[2]={"Not Good Pair\n","Good Pair\n"};
		cout<<arr[yes];



	}




}
