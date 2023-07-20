#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int l,w,n;cin>>l>>w>>n;
	if(l*w%n!=0){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	int N = (l*w)/n;
	int a,b;
	for(int i=1;i<=N;i++){
		if(N%i==0){
			if(l%i==0 && w%(N/i)==0){
				a = i;
				b = (N/i);
				break;
			}
		}
	}
	for(int i=0;i<l;i++){
		for(int j=0;j<w;j++){
			int ch = (j/b)*(l/a)+(i/a);
			cout<<(char)(ch+'A');
		}
		cout<<"\n";
	}
	return 0;
}
