#include <bits/stdc++.h>
using namespace std;
long long dis(int x,int y,int ax,int ay){
    if(((long long) (x-ax)*(x-ax))+((long long) (y-ay)*(y-ay))==0) return LONG_LONG_MAX;
    return ((long long) (x-ax)*(x-ax))+((long long) (y-ay)*(y-ay));
}
long long solve(vector<pair<int, int> > &pointset,int l,int r){
    if(r-l<=1){
        if(pointset[r].second<pointset[l].second){
            swap(pointset[r],pointset[l]);
        }
        return dis(pointset[r].first,pointset[r].second,pointset[l].first,pointset[l].second);
    }
    int mid = (l+r)/2;
    int xmid = (pointset[mid].first+pointset[mid+1].first)/2;
    long long left = solve(pointset,l,mid);
    long long right= solve(pointset,mid+1,r);
    int d = ceil(sqrt(min(left,right)) );
    queue<pair<int,int> > q;
    int lhead = l;
    int rhead = mid+1;
    for(int i=l;i<=r;i++){
        if(rhead>r){
            q.push(pointset[lhead]);
            lhead++;
        }else if(lhead>mid){
            q.push(pointset[rhead]);
            rhead++;
        }else{
        if(pointset[lhead].second<pointset[rhead].second){
            q.push(pointset[lhead]);
            lhead++;
        }else{
            q.push(pointset[rhead]);
            rhead++;
        }
        }
    }
    long long mincd=LONG_LONG_MAX;
    for(int i=l;i<=r;i++){
        pointset[i] = q.front();

        q.pop();
    }
    for(int i=l;i<=r;i++){
        if(abs(pointset[i].first-xmid)<=d){

        for(int j=-3;j<=3;j++){
            if(j && i+j>=l && i+j<=r){
                mincd = min(mincd,dis(pointset[i].first,pointset[i].second,pointset[i+j].first,pointset[i+j].second));
            }
        }
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