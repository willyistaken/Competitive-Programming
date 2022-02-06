#include <bits/stdc++.h>
using namespace std;
struct side{
    int from;
    int to;
    int w;
};

bool comp_side(side m,side n){
    return m.w<n.w;
}
int main(){
    int n,m;
    while(cin>>n>>m){
    vector<side> diagram;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        side newside;
        newside.from=a;
        newside.to=b;
        newside.w=c;
        diagram.push_back(newside);
    }
    
    sort(diagram.begin(),diagram.end(),comp_side);
    int sum=0;
    bool in_tree[n]={0};
    for(int i=0;i<m;i++){
        if(!(in_tree[diagram[i].from]&&in_tree[diagram[i].to])){
            in_tree[diagram[i].from]=1;
            in_tree[diagram[i].to]=1;
            sum+=diagram[i].w;
        }
    }

        cout<<sum<<endl;
    }
    
    
}