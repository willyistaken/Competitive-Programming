#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int cnt[10005];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int x=1;x<=100;x++)	{
		for(int y=1;y<=100;y++)	{
			for(int z=1;z<=100;z++)	{
				int num = x*x+y*y+z*z+x*y+z*y+x*z;
				if(num<=10000) cnt[num]++;
			}
		}	
	}
	int N;cin>>N;
	for(int i=1;i<=N;i++) cout<<cnt[i]<<"\n";
	return 0;
}
