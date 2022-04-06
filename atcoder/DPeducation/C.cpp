#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++){
       cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    char notthis[3][2] = {{1,2},{0,2},{0,1}};
    int ans[n][3]={{0}};
    for(int i=0;i<3;i++) ans[0][i]=arr[0][i];
    for(int day=1;day<n;day++){
        for(int i=0;i<3;i++){
            ans[day][i]=max(ans[day-1][notthis[i][0]],ans[day-1][notthis[i][1]]);
            ans[day][i] +=arr[day][i];
        }
    }
    cout<<max(max(ans[n-1][0],ans[n-1][1]),ans[n-1][2])<<endl;
}