#include <bits/stdc++.h>
using namespace std;
double dis(int x,int y,int ax,int ay){
    if(((double) (x-ax)*(x-ax))+((double) (y-ay)*(y-ay))==0) return LONG_LONG_MAX;
    return ((double) (x-ax)*(x-ax))+((double) (y-ay)*(y-ay));
}
double solve(vector<pair<int, int> > &pointset,int l,int r){
    if(r-l<=1){
        if(pointset[r].second<pointset[l].second){
            swap(pointset[r],pointset[l]);
        }
        return dis(pointset[r].first,pointset[r].second,pointset[l].first,pointset[l].second);
    }
    int mid = (l+r)/2;
    int xmid = (pointset[mid].first+pointset[mid+1].first)/2;
    double left = solve(pointset,l,mid);
    double right= solve(pointset,mid+1,r);
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
    double mincd=LONG_LONG_MAX;
    for(int i=l;i<=r;i++){
        pointset[i] = q.front();

        q.pop();
    }
    for(int i=l;i<=r;i++){
        if(abs(pointset[i].first-xmid)<=d){
            int j=1;
        while(pointset[i+j].second-pointset[i].second<=d && i+j<=r){
            if(abs(pointset[i+j].first-xmid)<=d && i+j<=r){
                mincd = min(mincd,dis(pointset[i].first,pointset[i].second,pointset[i+j].first,pointset[i+j].second));
            }
            j++;
        }
        j=-1;
        while(pointset[i+j].second-pointset[i].second>=-d && i+j>=l){
            if(abs(pointset[i+j].first-xmid)<=d && i+j>=l){
                mincd = min(mincd,dis(pointset[i].first,pointset[i].second,pointset[i+j].first,pointset[i+j].second));
            }
            j--;
        }
        }
    }
    return min(mincd,min(left,right));

}
int main(){
    int n;
    while(cin>>n){
    vector<pair<int,int> > pointset(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        pointset[i].first = x;
        pointset[i].second = y;
    }
    sort(pointset.begin(),pointset.end());
    printf("%.6lf\n",sqrt(solve(pointset,0,n-1)));
    }
}