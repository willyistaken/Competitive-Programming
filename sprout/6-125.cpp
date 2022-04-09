#include <bits/stdc++.h>
using namespace std;

const int divide = 10000019;

void mergesort(vector<int> &arr,int front,int end,int* sum){
    if(end-front<=1){
        if(arr[front]>arr[end]){
         *sum+=arr[end];
        *sum+=arr[front];
        *sum%=divide;  
        swap(arr[end],arr[front]); 
        }
    }else{
        int mid = (front+end)/2;  
        mergesort(arr,front,mid,sum);
        mergesort(arr,mid+1,end,sum);
        int fronthead=0;
        int endhead=0;
        queue<int> order;
        long long frontsum=0;
        for(int i=front;i<=mid;i++){
            frontsum+= (long long) arr[i];
        }
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
                *sum +=(frontsum%divide);
                *sum%=divide;
                *sum+= ((long long)(mid-front-fronthead+1)*arr[mid+1+endhead])%divide;
                *sum%=divide;
                order.push(arr[mid+1+endhead]);
                endhead++;
            }else{
                frontsum -= (long long) arr[front+fronthead];
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
    int n;cin>>n;
    vector<int> arr(nextPowerOf2(n),-1);

    for(int i=nextPowerOf2(n)-n; i<nextPowerOf2(n);i++) cin>>arr[i];
    int sum=0;
    mergesort(arr,0,nextPowerOf2(n)-1,&sum);
    cout<<sum%divide<<endl;
    /* for(int i=0;i<nextPowerOf2(n);i++){
        cout<<arr[i];
    } */
}