#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	srand( time(NULL) );
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = rand()%100+5;
	int k = rand()%10000;
	cout<<n<<" "<<k<<"\n";	
	int arr[n];
	for(int i=0;i<n;i++) arr[i] = i+1;
	random_shuffle(arr,arr+n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int m = (rand()%2)?(1):(-1);
			cout<<m*rand()%1000<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
