#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int monthday[13] ={-1,31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int year){
	if(year%400==0) return 1;
	if(year%100==0) return 0;
	if(year%4==0) return 1;
}

bool palable(int year){
	int ka =isleap(year) ;
	int day = (year%10)*10+(year/10)%10;
	year/=100;
	int month = (year%10)*10+(year/10)%10;
	if(month<=0 || month>=13) return 0;
	if(month==2){
		if(day>=1 && day<=monthday[month]+ka) return 1;
		else return 0;
	}else{
		if(day>=1 && day<=monthday[month]) return 1;
		else return 0;
	}
}

void solve(){
	string s;cin>>s;
	int day = (s[0]-'0')*10+s[1]-'0';
	int month = (s[3]-'0')*10+s[4]-'0';
	int year = (s[6]-'0')*1000 + (s[7]-'0')*100 + (s[8]-'0')*10 +s[9]-'0';
	if(palable(year)){
		int kyear = year;
		int kday = (kyear%10)*10+(kyear/10)%10;
		kyear/=100;
		int kmonth = (kyear%10)*10+(kyear/10)%10;
		if(make_pair(kmonth,kday)>make_pair(month,day)){
			cout<<setfill('0')<<setw(2)<<kday<<".";
			cout<<setfill('0')<<setw(2)<<kmonth<<".";
			cout<<setfill('0')<<setw(4)<<year<<".\n";
			return ;
		}
	}

	for(int i=year+1;i<=9092;i++){
		if(palable(i)){
			int kyear = i;
			int kday = (kyear%10)*10+(kyear/10)%10;
			kyear/=100;
			int kmonth = (kyear%10)*10+(kyear/10)%10;
			cout<<setfill('0')<<setw(2)<<kday<<".";
			cout<<setfill('0')<<setw(2)<<kmonth<<".";
			cout<<setfill('0')<<setw(4)<<i<<".\n";
			return ;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		solve();
	}

	return 0;
}
