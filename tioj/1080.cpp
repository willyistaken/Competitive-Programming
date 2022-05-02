
#include <bits/stdc++.h>
using namespace std;


void mergesort(vector<int> &arr,int front,int end,long long* sum){
    if(end-front<=1){
        if(arr[front]>arr[end]){
         *sum+=1;
        swap(arr[end],arr[front]); 
        }
    }else{
        int mid = (front+end)/2;  
        mergesort(arr,front,mid,sum);
        mergesort(arr,mid+1,end,sum);
        int fronthead=0;
        int endhead=0;
        queue<int> order;
        for(int i=0;i<=end-front;i++){
            if(front+fronthead>mid || mid+1+endhead>end){
                if(front+fronthead>mid){
                    order.push(arr[mid+1+endhead]);
                    endhead++;
                }else{
                  
                    order.push(arr[front+fronthead]);
                    fronthead++;
                }
            }else{
                if(arr[front+fronthead]>arr[mid+1+endhead]){
                *sum +=mid-(front+fronthead)+1;
                order.push(arr[mid+1+endhead]);
                endhead++;
            }else{
                order.push(arr[front+fronthead]);
                fronthead++;
            }  
            }
          
           
        }
        for(int i=front;i<=end;i++){
            arr[i] = order.front();
            order.pop();
        }
        }
    }


int nextPowerOf2(int n) 
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int t=1;
    while(cin>>n&&n){

    vector<int> arr(nextPowerOf2(n),INT_MIN);

    for(int i=nextPowerOf2(n)-n; i<nextPowerOf2(n);i++) cin>>arr[i];
    long long sum=0;
    mergesort(arr,0,nextPowerOf2(n)-1,&sum);
    cout<<"Case #"<<t<<": "<<sum<<endl;
    ++t;
    /* for(int i=0;i<nextPowerOf2(n);i++){
        cout<<arr[i];
    } */
    }
}