#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> paper;
int n,m;

void printstuff(){
    //cout<<endl<<endl<<endl;
    //cout<<"-------------"<<endl;
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<paper[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<"-------------"<<endl;
}
int Dostuff(string type,int k){
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

          for(int i=k-1;i>=0;i--){
            for(int j=0;j<m;j++){
                paper[k+i][j]+=paper[k-1-i][j];
            } 
          }
          for(int m=0;m<k;m++){
              paper.erase(paper.begin());
          }
          
            n-=k;
    }
    if(type=="D"){

           for(int j=k-1;j>=0;j--){
            for(int i=0;i<m;i++){
                paper[n-k-j-1][i]+=paper[n-k+j][i];
            }
          } 
          for(int m=0;m<k;m++){
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
        }
        return 0;
    }
    if(type=="LD"){
        
        for(int i=0;i<k;i++){
            for(int j=1;j<=k-i;j++){
                paper[i+(n-k-1)][i+j]+=paper[i+(n-k-1)+j][i];
                paper[i+(n-k-1)+j][i]=0;
            }
        }
        return 0;
        }
        
     if(type=="RU"){
        for(int i=0;i<k;i++){
            for(int j=1;j<=k-i;j++){
                paper[i+j][i+(m-k-1)]+=paper[i][i+(m-k-1)+j];
                paper[i][i+(m-k-1)+j]=0;
            }
        }
        return 0;
    }
    if(type=="RD"){
        for(int i=0;i<k;i++){
            for(int j=0;j<k-i;j++){
               paper[i+(n-k-1)][j+(m-k-1)]+=paper[k-j+(n-k-1)][k-i+(m-k-1)];
               paper[k-j+(n-k-1)][k-i+(m-k-1)]=0;
            }
        }
        return 0;
    }
    //cout<<"why"<<type;
    return 0;
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
    for(int m=0;m<q;m++){
        string temp;
        cin>>temp;
        string a;
        int b;
        a=temp;
        cin>>b;
        //cout<<a<<","<<b<<endl;
        if(b!=0){
           Dostuff(a,b); 
        }
        
    }
    printstuff();
}



