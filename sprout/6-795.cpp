#include <bits/stdc++.h>
using namespace std;
long long dis(int x,int y,int ax,int ay){
    if(((long long) (x-ax)*(x-ax))+((long long) (y-ay)*(y-ay))==0) return LONG_LONG_MAX;
    return ((long long) (x-ax)*(x-ax))+((long long) (y-ay)*(y-ay));
}
long long solve(vector<pair<int, int> > &pointset,int l,int r){
    if(r-l<=1){
        return dis(pointset[r].first,pointset[r].second,pointset[l].first,pointset[l].second);
    }
    int mid = (l+r)/2;
    long long left = solve(pointset,l,mid);
    long long right= solve(pointset,mid+1,r);
    int xmid = (pointset[mid].first+pointset[mid+1].first)/2;
    int d = ceil(sqrt(min(left,right)) );
    int rind = mid+1;
    while(pointset[rind].first<=xmid+d && rind<r){
        rind+=1;
    }
    int lind = mid;
    while(pointset[lind].first>=xmid-d && lind>l){
        lind-=1;

    }
    long long mincd = __LONG_LONG_MAX__;
    for(int i = lind;i<=mid;i++){
        for(int j=mid+1;j<=rind;j++){
            mincd = min(mincd,dis(pointset[i].first,pointset[i].second,pointset[j].first,pointset[j].second));
        }
    }
    return min(mincd,min(left,right));
}
int main(){
    int n;cin>>n;
    vector<pair<int,int> > pointset(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        pointset[i].first = x;
        pointset[i].second = y;
    }
    sort(pointset.begin(),pointset.end());
    cout<<solve(pointset,0,n-1)<<endl;
}