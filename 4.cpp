#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> paper;
int n,m;
int Dostuff(string type,int k){
    cout<<type<<"this";
    cout<<(type=="LD")<<endl;
    if(type=="R"){

        for(int i=0;i<n;i++){
            for(int j=k-1;j>=0;j--){
                int a=paper[i][m-k-j-1]+paper[i][m-k+j];
                paper[i][m-k-j-1]=a;
            }
            for(int m=0;m<k;m++){
                paper[i].pop_back();
            }
        }
        m-=k;
        return 0;
    }
    if(type=="L"){

        for(int i=0;i<n;i++){
            for(int j=k-1;j>=0;j--){
                paper[i][k-1+j+1]+=paper[i][k-1-j];
                
            }
            for(int m=0;m<k;m++){
                 paper[i].erase(paper[i].begin());
            }
           
        }
        m-=k;
        return 0;
    }
    if(type=="U"){

          for(int j=k-1;j>=0;j--){
            for(int i=0;i<m;i++){
                paper[k-1+j+1][i]+=paper[k-1-j][i];
                
            }
            paper.erase(paper.begin());
          }
            n-=k;
    }
    if(type=="D"){

           for(int j=k-1;j>=0;j--){
            for(int i=0;i<m;i++){
                paper[n-k-j-1][i]+=paper[n-k+j][i];
            }
            paper.pop_back();
            
          }
            n-=k;
            return 0;
    }
    if(type=="LU"){
        for(int i=0;i<k;i++){
            for(int j=0;j<k-i;j++){
               paper[k-j][k-i]+=paper[i][j];
               paper[i][j]=0;
            }
            cout<<endl;
        }
        return 0;
    }
    if(type=="LD"){
        
        for(int i=0;i<k;i++){
            for(int j=m-k+i;j<=m-1;j++){
                cout<<paper[i-k+1][j-k+1]<<"hello";
                //cout<<i<<","<<j<<" ";
                //paper[i][j]+=paper[j][i];
                //paper[j][i]=0;
            }
            cout<<endl;
        }
        return 0;
    }
     if(type=="RU"){

        for(int i=0;i<k;i++){
            for(int j=m-k+i;j<=m-1;j++){
                paper[i][j]+=paper[j][i];
                paper[j][i]=0;
            }
        }
        return 0;
    }
    if(type=="RD"){
        for(int i=n-1;i>=n-k;i++){
            for(int j=m-k-i+n-1;j<=m-1;j++){
                paper[i][j]+=paper[k-1-i][k-1-j];
                paper[k-1-i][k-1-j]=0;
            } 
        }
        return 0;
    }
    cout<<"why";
}
int main(){
    int q;cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        vector<int> g;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            g.push_back(a);
        }
        paper.push_back(g);
    }
    for(int m=0;m<1;m++){
        string temp;
        cin>>temp;
        string a;
        int b;
        a=temp;
        cin>>b;
        cout<<a<<","<<b<<endl;
        Dostuff(a,b);
    }
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<paper[i][j]<<" ";
        }
        cout<<endl;
    }
}