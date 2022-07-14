#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char stuff[5] = {' ','C','D','H','S'};
struct card{
	int number;
	int type;
	void print(){
		cout<<stuff[type]<<" "<<number<<"\n";
	}
};
bool mycomp(const card a,const card b){
	return (a.number==b.number)?a.type>b.type:a.number>b.number;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	card arr[n];
	unordered_map<char,int> mp;
	mp.insert({'S',4}); mp.insert({'H',3}); mp.insert({'D',2}); mp.insert({'C',1});
	for(int i=0;i<n;i++){
		char type;cin>>type;
		cin>>arr[i].number;
		arr[i].type = mp[type];
	}
	int m;cin>>m;
	nth_element(arr,arr+m-1,arr+n,mycomp);
	arr[m-1].print();
	return 0;
}
