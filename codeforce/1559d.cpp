#include <bits/stdc++.h>
using namespace std;


int querry(int array[],int target){
    if(array[target]==target){
        return array[target];
    }

   
    array[target]=querry(array , array[target]);
    return array[target];
}
void add(int array[],int to_add,int target){
    int t1=querry(array,to_add);
    int t2=querry(array,target);
    if(t1!=t2){
        array[t2]=t1;
    }
}



int main(){
int n;cin>>n;
int m1,m2;cin>>m1>>m2;
int forest1[n];
int forest2[n];
for(int i=0;i<n;i++){
    forest1[i]=i;
    forest2[i]=i;
}
for(int i=0;i<m1;i++){
    int from,to;cin>>from>>to;
    add(forest1,from-1,to-1);
}
for(int i=0;i<m2;i++){
    int from,to;cin>>from>>to;
    add(forest2,from-1,to-1);
}
int max=0;
queue<pair<int,int>> canadd;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
            if(querry(forest1,i)!=querry(forest1,j) && querry(forest2,i)!=querry(forest2,j)){
                add(forest1,i,j);
                add(forest2,i,j);
                canadd.push(make_pair(i,j));
                max++;
        }
    }
}
cout<<max<<endl;
while(!canadd.empty()){
    cout<<canadd.front().first+1<<" "<<canadd.front().second+1<<endl;
    canadd.pop();
}
}