#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 16;
int DP[1<<N][N*N];

struct card{
	bool c;
	int r;
	int b;
};


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	vector<card> arr(n);
	int Bsum = 0;
	int Rsum = 0;
	for(int i=0;i<n;i++){
		char c;
		cin>>c>>arr[i].r>>arr[i].b;
		Bsum+=arr[i].b;
		Rsum+=arr[i].r;
		arr[i].c=(c=='B');
	}
	for(int m=0;m<(1<<n);m++){
		for(int p=0;p<=(n*n+n)/2;p++){
			DP[m][p]=-1e9;
		}
	}
	DP[0][0]=0;
	//save this much money , max money got
	for(int m=1;m<(1<<n);m++){
		int ccnt[2] = {0,0};
		for(int i=0;i<n;i++){
			if((m>>i)&1){
				ccnt[arr[i].c]+=1;
			}
		}
		for(int i=0;i<n;i++){
			if(!((m>>i)&1)) continue;
			int x = ccnt[0]-(arr[i].c==0);
			int y = ccnt[1]-(arr[i].c==1);
			for(int p=min(x,arr[i].r);p<=(n*n+n)/2;p++){
				DP[m][p] = max(DP[m][p],DP[m-(1<<i)][p-min(x,arr[i].r)]+min(y,arr[i].b));
			}
		}
	}
	/*
	for(int m=1;m<(1<<n);m++){
		for(int p=0;p<=(n*n+n)/2;p++){
			cout<<DP[m][p]<<" ";
		}
		cout<<" | ";
		for(int i=0;i<n;i++) cout<<((m>>i)&1);
		cout<<"\n";
	}
	*/
	int ans = 1e9;
	for(int rl = 0;rl<=(n*n+n)/2;rl++){
	 	if(DP[(1<<n)-1][rl]<0) continue;
		ans = min(ans,max(Rsum-rl,Bsum-DP[(1<<n)-1][rl]));
	}
	cout<<ans+n<<"\n";
}

/*
4
B 5 0
R 5 8
B 4 10
B 7 5
*/
