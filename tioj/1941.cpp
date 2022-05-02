#include <bits/stdc++.h>
using namespace std;
//----------this does not work------------------- consider the case below
/*
 -
 -
 ----
   --
-
*/
//use treap to make the dp faster
//dp[i] means choose i_th pokemon return pair<ans,k> where k is the min place to choose k
//dp[i].ans = max(dp[j]) where dp[j].k is not bigger than i.r
//dp[i].k  =  max(max(dp[j]).k,i.l)

//-----------------------------------------------------------------------

/*
//second attemp: naive dp → work!
//use segment tree to opimize it
//because the same layer is  nonstricly increasing
//only consider the case where dp[i][k] where k>r = dp[i][r](this means that dp[i-1][k]=dp[i-1][r])
//find the righter most k where dp[i-1][k] is not greater than dp[i-1][r]
// and use segement tree to add in a range
//this works but somehow tle
//need to imporve search function
int nextPowerOf2(int n) 
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

void addrange(int l,int r,int k,vector<int> &segment){
    int reall = l+nextPowerOf2(n);
    int realr = r+nextPowerOf2(n)+1;
    segment[reall]+=k;
    while(reall!=1){
        reall/=2;
        segment[reall]=segment[reall*2]+segment[(reall*2)+1];
    }
    if(realr<2*nextPowerOf2(n)){
        segment[realr]-=k;
        while(realr!=1){
            realr/=2;
            segment[realr]=segment[realr*2]+segment[(realr*2)+1];
        }
    }
}
int search(int cur,int key,vector<int> &segment){
        if(2*cur>=2*nextPowerOf2(n)) return cur-nextPowerOf2(n);
        if(segment[2*cur]>key){
            return search(2*cur,key,segment);
        } else{
            return search(2*cur+1,key-segment[2*cur],segment);
        }
}
int query(int l,int r,vector<int> segment){
    int ans=0;
    int ql=l+nextPowerOf2(n);
    int qr=r+nextPowerOf2(n);
    while(ql<qr){
        if(ql%2) ans+=segment[++ql];
        ql/=2;
        if(qr%2) ans+=segment[--qr];
        qr/=2;
    }
    return ans;
}
*/
int n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    /*
    int n;cin>>n;
    int dp[n][2]={{0}};
    pair<int,int> lr[n];
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        lr[i] = make_pair(a,b);
        dp[i][0] = (i>= lr[0].first && i<=lr[0].second );
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0) dp[j][i%2] = dp[j][(i-1)%2]+ (j>= lr[i].first && j<=lr[i].second );
            if(j){
                dp[j][i%2]=max(dp[j-1][i%2] +(j==lr[i].first),dp[j][(i-1)%2]+(j>= lr[i].first && j<=lr[i].second));
            }
        }
    }
    cout<<dp[n-1][(n-1)%2]<<endl;
    */
//---------------------------------------------------------------------
   /*
   cin>>n;
   vector<int> segment(2*nextPowerOf2(n),0);
   int fl,fr;cin>>fl>>fr;
   addrange(fl,n-1,1,segment);
    for(int i=1;i<n;i++){
        int l,r;cin>>l>>r;
        int key =search(1,query(0,r+1,segment),segment);//query(0,r+1,segment);//
        addrange(l,key+1,1,segment);
    }

    cout<<query(0,n,segment)<<endl;
    */

   //this works by magic
   //ok fine:
   //the size of s in every step means the rightest vaule of dp table in row n
   //when inserting an array and there is no segment left to it's right , it means that the rightest vaule need to be added one
   //if there is, this means that we need to keep the row of dp in a increasing manner(which means don't change the rightest most value)
   //but in the next step we don't need to worry about the increasing dp vaule (because it already is unless the new segment is still being block)
   //so this will work
   cin>>n;
   multiset<int> s;
   for(int i=0;i<n;i++){
       int l,r;cin>>l>>r;
       s.insert(l);
       auto k = s.upper_bound(r);
       if(k!=s.end()) s.erase(k);
   }
   cout<<s.size()<<endl;
}

