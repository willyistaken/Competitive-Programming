#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int euler_phi(int n) {
  int ans = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}

int pow(int n,int p){
	int ans = 1;
	for(int i=0;i<p;i++) ans*=n;
	return ans;
}

int calc(int k){
	int ans = 0;
	for(int i=1;i<=k;i++){
		if(k%i==0) ans+=euler_phi(i*i);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<100;i++)	{
		cout<<calc(i)<<"\n";
	}
	return 0;
}
