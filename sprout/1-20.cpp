#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    for(int mnm=1;mnm<=t;mnm++){
        cout<<"Line #"<<mnm<<endl;
        int n;cin>>n;
    short group[1000000]={0};
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int in;cin>>in;
            group[in]=i;

        }
    }
    vector<queue<int>> line;
    int grouploc[1005]={0};
    int m;cin>>m;
    int total=1;
    int deleted=0;
    for(int p=0;p<m;p++){
        string c;cin>>c;//cout<<total<<","<<deleted<<"|\n";
        if(c=="DEQUEUE"){
            int gtem;
            cout<<line[deleted].front()<<endl;
            gtem=group[line[deleted].front()];
            line[deleted].pop();
            if(line[deleted].empty()){
                grouploc[gtem]=0;
                deleted++;
            }
        }else{
            int num;cin>>num;
            if(group[num]==0){
                queue<int> temp;
                temp.push(num);
                line.push_back(temp);
                total++;
            }else{
                if(grouploc[group[num]]==0){
                queue<int> temp;
                temp.push(num);
                line.push_back(temp);
                grouploc[group[num]]=total;
                //cout<<grouploc[1]<<"|"<<grouploc[2]<<"|"<<total<<endl;
                total++;
            }else{
                line[grouploc[group[num]]-1].push(num);
            } 
            }
           
        }
    }
    }
    
}
    

