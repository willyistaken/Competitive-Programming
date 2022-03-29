#include <bits/stdc++.h>
using namespace std;
bool able(vector<int> &ancient_char, int &m, int &x , int &n){
    int people=0;
    int tempsum=0;
    for(int i=0;i<n;i++){
        if(x<ancient_char[i]) return 0;
        tempsum+=ancient_char[i];
        if(tempsum>x){
            people+=1;
            tempsum=ancient_char[i];
        }
    }
    return (people+1<=m);
}
int main(){
    int t;cin>>t;
    while(t--){
    int n,m;cin>>n>>m;
    vector<int> ancient_char;
    int maxn=-1;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        maxn = max(maxn , temp);
        ancient_char.push_back(temp);
    }
    int l=maxn-1;int r=1e9;
    int mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(able(ancient_char,m,mid,n)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<endl;

    }




}