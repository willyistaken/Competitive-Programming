#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int po[4] = {1,3,9,27};
int x(int a,int b){
	int s= 0;
	for(int i=0;i<4;i++){
		s+=po[i]*((3-((a+b)%3))%3);
		a/=3;
		b/=3;
	}
	return s;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int arr[20]={0,5,6,11,13,17,18,23,24,39,41,56,57,62,63,67,69,74,75,80};
	int n;cin>>n;
	for(int i=0;i<n;i++){
		for(int k=0;k<20;k++){
			cout<<x(i,arr[k])<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
