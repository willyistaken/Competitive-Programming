#include<bits/stdc++.h>
using namespace std;
#define ll long long



int arr[1050];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=1024;i++){
		arr[(i*101)/100]=i;	
	}
	int x;
	while(cin>>x){
		if(x<0 || x>1035){
			cout<<"stupid\n";	
		}else{
			if(x){
				if(arr[x]) cout<<arr[x]<<endl;
				else cout<<"stupid\n";
			}else{
				cout<<0<<endl;	
			}
		}
	}
	return 0;
}
