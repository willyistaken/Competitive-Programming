#include<iostream>

 

using namespace std;

const int N = 2e5 + 10;

int a[N], b[N], n;

 

bool check(int mid){

       int t = 0;

       for(int i = 1;i <= n;i++){

              if((mid - t - 1) <= a[i] && t <= b[i]) t++;

       }

      

       if(t >= mid) return true;

       return false;

}

 

void solve(){

       scanf("%d", &n);

       for(int i = 1;i <= n;i++) scanf("%d %d", &a[i], &b[i]);

      

       int l = 1, r = n, ans;

       while(l <= r){

              int mid = (l + r) >> 1;

              if(check(mid)){

                     ans = mid;

                     l = mid + 1;

              }

              else r = mid - 1;

       }

       printf("%d\n", ans);

}

 

int main(void){

       int t;

       scanf("%d", &t);

       while(t--) solve();

      

       return 0;

}