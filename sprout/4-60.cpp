#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int timer(int m,int s,int wait){
    int totalq = m+(wait*d);
    if(b*(totalq/c)>=s){
        if(s%b==0){
         return(s/b)+wait;
        }else{
         return (s/b)+1+wait;
        } 
    }else{
        int left = s-(b*(totalq/c));
        if(left%a==0){
            return (totalq/c)+(left/a)+wait;
        }else{
            return (totalq/c)+(left/a)+1+wait;
        }
    }
}
int furtherst(int m,int t){
    int maxr=0;
    for(int i=0;i<=t;i++){
        int totalq = m+d*i;
        int forwardtime = min(totalq/c,t);
        int dis = b*forwardtime + a*(t-forwardtime);
        maxr = max(dis,maxr);
    }
    return maxr;
}

int main(){
    cin>>a>>b>>c>>d;
    int m,s,t;cin>>m>>s>>t;
    int l=0;int r=t;
    int mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(timer(m,s,mid+1)-timer(m,s,mid)<0){
            l=mid;
        }else{
            r=mid;
        }
    }
    if(timer(m,s,l)<=t || timer(m,s,r)<=t){
        cout<<"Yes\n"<<min(timer(m,s,l),timer(m,s,r))<<endl;
    }else{
        cout<<"No\n"<<furtherst(m,t)<<endl;
    }


}