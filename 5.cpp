#include <bits/stdc++.h>
using namespace std;
vector<int> stuff;
int convert(int l,int r,int layer){
    for(int i=l;i<=r;i++){
        if(stuff[i]==-1){
            stuff[i]=-3;
            stuff.insert(stuff.begin()+i,-5);//(<i
            stuff.insert(stuff.begin()+i+2,-4);//i>(
            stuff.insert(stuff.begin()+i+2,-2);
            stuff.insert(stuff.begin()+i+2,-4);
            stuff.insert(stuff.begin()+r+5,-5);
            stuff.insert(stuff.begin()+r+6,-5);
            stuff.insert(stuff.begin()+l,-4);
            stuff.insert(stuff.begin()+l,-2);
            stuff.insert(stuff.begin()+l,-4);
            stuff.insert(stuff.begin()+l,-2);
            //convert(l,i+6,layer+1);
            convert(i+8,r,layer+1);
            return 0;
        }
        
    }
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
            stuff.push_back(-1);
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


    
