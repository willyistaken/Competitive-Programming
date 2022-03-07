#include <bits/stdc++.h>
using namespace std;
struct car{
    int next=0;
    int prev=0;
    int index;
};
int main(){
    int n;cin>>n;
    car arr[n+1];
    for(int i=1;i<=n;i++){
        car newcar;
        newcar.index=i;
        if(i>1){
            newcar.prev=i-1;
        }
        if(i<n){
            newcar.next=i+1;
        }
        arr[i]=newcar;
    }
    int start=1;
    int m;cin>>m;
    for(int j=0;j<m;j++){  
      /*  cout<<start<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i].index<<","<<arr[i].prev<<","<<arr[i].next<<endl;
    }*/
        int c;cin>>c;
        int num;cin>>num;
        if(c){
            int temp = arr[num].prev;
            if(num!=start){ 
            int p,pp,n;
            p=arr[num].prev;
            pp=arr[arr[num].prev].prev;
            n=arr[num].next;
            arr[pp].next=num;
            arr[num].prev=pp;
            arr[num].next=p;
            arr[p].prev=num;
            arr[p].next=n;
            arr[n].prev=p;
            }
            if(temp==start){
                start=num;
            }
         
        }else{
            if(num==start){
                start=arr[num].next;
            }
            arr[arr[num].prev].next=arr[num].next;
            arr[arr[num].next].prev=arr[num].prev;
            arr[num].prev=0;
            arr[num].next=0;
        }
    }
    car now=arr[start];
     /*  cout<<start<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i].index<<","<<arr[i].prev<<","<<arr[i].next<<endl;
    }*/
    while(now.next!=0){
        cout<<now.index<<" ";
        now=arr[now.next];
    }
    cout<<now.index<<endl;
}