#include <bits/stdc++.h>
using namespace std;
vector<int> stuff;
int convert(int l,int r,int layer){
    int yes=0;
    int smallest=l;
    for(int i=l;i<=r;i++){
        if(stuff[i]<=-6){
            yes=1;
            if(stuff[i]<stuff[l]){
                smallest=i;
            }
        }
    }
    if(yes){stuff[smallest]=-3;
            
            stuff.insert(stuff.begin()+smallest+1,-4);//i>(
            stuff.insert(stuff.begin()+smallest+1,-2);
            stuff.insert(stuff.begin()+smallest+1,-4);
            stuff.insert(stuff.begin()+r+3,-5);
            stuff.insert(stuff.begin()+r+3,-5);
            stuff.insert(stuff.begin()+smallest,-5);//)<i
             stuff.insert(stuff.begin()+smallest,-5);//)<i
            stuff.insert(stuff.begin()+l,-4);
            stuff.insert(stuff.begin()+l,-2);
            stuff.insert(stuff.begin()+l,-4);
            stuff.insert(stuff.begin()+l,-2);
            convert(smallest+8,r,layer+1);
            convert(l,smallest+6,layer+1);
            return 0;}
        return 0;
        }
    

int main(){
    string result="";
    int n,m;cin>>n>>m;
    int p[m]={0};
    int countp=0;
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        if(a=="("){
            countp++;
            stuff.push_back(-4);
        }else if(a==")"){
            countp--;
            stuff.push_back(-5);
        }else if(a=="and"){
            stuff.push_back(-6-countp);
        }else if(a=="not"){
            stuff.push_back(-2);
        }else if(a=="or"){
            stuff.push_back(-3);
        }else{
            stuff.push_back(stoi(a));
        }
        p[m]=countp;    
        }
   // for(int i=0;i<m;i++){
      //  cout<<stuff[i]<<" "<<p[i]<<endl;
   // }
   // cout<<endl<<endl<<endl;
    convert(0,m-1,0);
    cout<<stuff.size()<<endl;
    string arr[5]={"and","not","or","(",")"};
    for(auto i:stuff){
        //cout<<"original "<<i<<endl;
        if(i>0){
            cout<<i<<" ";
        }else{
            cout<<arr[-i-1]<<" ";
        }
        
    }
    }


    
