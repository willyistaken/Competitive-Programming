#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int v;

pair<int,int> minsum(int i){
	int m  = v/i;
	pair<int,int> ans  = {-1,-1};
	int mins = 1e9;
	for(int j = i;j*j<=m;j++){
		if(m%j==0){
			if(mins>j+m/j){
				mins = j+m/j;
				ans = {m/j,j};
			}
		}
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>v;	
	int mins = 1e9;
	int k[3];
	
	for(int i=1;i*i*i<=v;i++){
		if(v%i==0){
			pair<int,int> temp = minsum(i);
			if(temp.first==-1 && temp.second==-1) continue;
			if(mins>i*(temp.first+temp.second)+(v/i)){
				mins = i*(temp.first+temp.second)+(v/i); 	
				k[0] = i;
				k[1] = temp.first;
				k[2] = temp.second;
			}
		}
	}
	sort(k,k+3);
	cout<<2*mins<<" "<<k[0]<<" "<<k[1]<<" "<<k[2]<<"\n";
    return 0;
}
