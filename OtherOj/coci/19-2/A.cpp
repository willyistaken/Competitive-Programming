#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct stand{
	int solved=0;
	int time=0;
	string name;
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<stand> arr(n);
	int de = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i].name;
		if(arr[i].name == "NijeZivotJedanACM"){
			de = i;
			for(int j=0;j<m;j++){
				string s;cin>>s;
			}
			continue;
		}
		for(int j=0;j<m;j++){
			string s;cin>>s;
			if(s[0]=='+' || s[0]=='?'){
				int tries = s[1]-'0';
				int times = (s[4]-'0')*3600 + 60*((s[6]-'0')*10+(s[7]-'0')) + ((s[9]-'0')*10+s[10]-'0');
				times+=(tries-1)*20*60;
				arr[i].solved++;
				arr[i].time+=times;
			}
		}
	}
	cin>>arr[de].name;
	for(int j=0;j<m;j++){
			string s;cin>>s;
			if(s[0]=='+' || s[0]=='?'){
				int tries = s[1]-'0';
				int times = (s[4]-'0')*3600 + 60*((s[6]-'0')*10+(s[7]-'0')) + ((s[9]-'0')*10+s[10]-'0');
				times+=(tries-1)*20*60;
				arr[de].solved++;
				arr[de].time+=times;
			}
	}
	sort(arr.begin(),arr.end(),[](const stand &a,const stand &b){return (a.solved==b.solved)?((a.time==b.time)?(a.name<b.name):(a.time<b.time)):(a.solved>b.solved);});
	for(int i=0;i<n;i++){
		if(arr[i].name=="NijeZivotJedanACM"){
			cout<<i+1<<"\n";
			return 0;
		}
	}
	return 0;
}
