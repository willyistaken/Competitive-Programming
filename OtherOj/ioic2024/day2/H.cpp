#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 105;
int arr[N];
inline void solve() {
    int n;
    scanf("%d",&n);
    if(n%2) {
        int head = 1;
        int u =1;
        for(int i=0; i<n; i++) {
            arr[i]=head;
            head+=2*u;
            if(head>n) {
                head-=3;
                u = -1;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) printf("%d ",arr[(i+j)%n]);
			printf("\n");
        }
    } else {
        int head = 1;
        int u = 1;
        for(int i=0; i<n; i++) {
            arr[i]=(head);
            head+=2*u;
            if(head>n) {
                head--;
                u = -1;
            }
        }
        if(n%4) {
            for(int i=0; i<n; i++) {
            	for(int j=0; j<n; j++) printf("%d ",arr[(i+j)%n]);
				printf("\n");
            }
        }else{
            for(int i=0; i<n; i+=2) {
            	for(int j=0; j<n; j++) printf("%d ",arr[(i+j)%n]);
				printf("\n");
            }
            for(int i=0; i<n; i+=2) {
            	for(int j=n-1; j>=0; j--) printf("%d ",arr[(i+j)%n]);
				printf("\n");
            }
		}
    }
}


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
	scanf("%d",&t);
    while(t--) {
        solve();
    }

    return 0;
}

