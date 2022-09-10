#pragma GCC optimize("Ofast")
#include"lib2056.h"
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	int t = Testcase();			
	while(t--){
		int n = Init();
		for(int i=0;i<n;i++){
			int now = Query(i);
			int prev=i;
			while(now!=i){
				prev = now;
				now = Query(now);
			}
			Answer(prev);
		}
	}
	return 0;
}

//https://www.youtube.com/watch?v=iSNsgj1OCLA&t=465s
