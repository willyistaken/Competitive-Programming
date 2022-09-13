#include<bits/stdc++.h>
using namespace std;


int main(){
	int r=1;
	int arr[6] = {0};
	for(int i=0;i<6;i++){
		int k;cin>>k;
		for(int i=0;i<k;i++){
			int d;cin>>d;
			arr[d-1]++;
		}
	}
	for(int i=0;i<6;i++){
		r*=(6-arr[i]);
	}
	cout<<r<<"\n";
}
