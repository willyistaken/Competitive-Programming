#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
	
	int ans1=0;
	long long ans2=0;
	int money;
	while(cin>>money && money){
		if(ans1==0) cout<<money<<" ";	
		ans1+=1;
		ans2+=money;
	}
	if(ans1==0) break;
	cout<<ans1<<" "<<ans2<<endl;
}

}
