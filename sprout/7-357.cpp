#include <bits/stdc++.h>
using namespace std;

long long damage(int s,int h,vector<pair<int,int> > &spells,int n,int m){
    //binary search for h:
    int l=-1;int r=n-1;
    while(r-l>1){
        int mid = (l+r)/2;
        if(spells[mid].first>(h/m)){
            r=mid;
        }else{
            l=mid;
        }
    }
    //find the sum of the s_th largest c:
    if(n-r>=s){
        long long sum=0;
        for(int i=r;i<n;i++){
            sum+=spells[i].second;
        }
        return sum;
    }else{
        long long sum=0;
        int temparr[n-r];
        for(int i=r;i<n;i++){
            temparr[i-r]=spells[i].second;
        }
        nth_element(temparr,temparr+s-1,temparr+n-r);
        for(int i=n-r-1;i>=n-r-s;i--){
            sum+=temparr[i];
        }
        return sum;
    }
}

int main(){
    int n,m,r;cin>>n>>m>>r;
    vector<pair<int,int> > spells(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        int p,c;cin>>p>>c;
        spells[i]=make_pair(p,c);
    }
    sort(spells.begin(),spells.end());
    long long dp[2]={m,m};
    bool stop=false;
    int i=1;
    while(!stop){
        dp[i%2]=min(dp[(i-1)%2]-damage(i,dp[(i-1)%2],spells,n,m)+r,(long long)m);
        if(i>n+1 && dp[0]==dp[1]){
            stop=1;
            continue;
        }
        cout<<dp[i%2]<<"+"<<damage(i,dp[(i-1)%2],spells,n,m)<<endl;
        if(dp[i%2]<=0){
            break;
        }
        i++;
    }
    if(stop){
        cout<<-1<<endl;
    }else{
        cout<<i<<endl;
    }


}