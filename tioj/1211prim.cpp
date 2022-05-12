#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct side{
	int v1;
	int v2;
	int w;
};
int father[10005];


int query(int n){
	if(father[n]==n) return n;
	father[n]=query(father[n]);
	return father[n];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m &&( n || m)){
	vector<side> sides;
	for(int i=0;i<m;i++){
		int v1,v2,w;cin>>v1>>v2>>w;
		sides.push_back({v1,v2,w});
	}
	sort(sides.begin(),sides.end(),[](side &a,side &b){return a.w<b.w;});
	for(int i=0;i<=n;i++){
		father[i]=i;
	}
	int sum=0;
	int connect=0;
	for(int i=0;i<m;i++){
		side temp = sides[i];
		if(query(temp.v1)!=query(temp.v2)){
			sum+=temp.w;
			father[query(temp.v2)]=query(temp.v1);//note to self , this is not father[temp.v2]=temp.v1; that will be stupid when using a union-join set
			connect++;
		}
	}
	if(connect!=n-1){
		cout<<-1<<endl;	
	}else{
		cout<<sum<<endl;	
	}
	}
	return 0;
}

//note to self: don't write code in a complicated manner, this will only increase the quantity of bug
