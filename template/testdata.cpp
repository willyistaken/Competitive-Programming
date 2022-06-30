#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	srand(time(0));
	int arr[9]={0,1,2,3,4,5,6,7,8};
	random_shuffle(arr,arr+9);
	for(int i=0;i<9;i++) cout<<arr[i]<<" ";
	cout<<"\n";
	random_shuffle(arr,arr+9);
	for(int i=0;i<9;i++) cout<<arr[i]<<" ";



    return 0;
}
