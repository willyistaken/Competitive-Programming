#pragma GCC optimize("O2")


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> mono;
    mono.push_back(0);
    int amount[n] = {0};
    long long ans=0;
    for (int i = 1; i < n; ++i)
    {   
        int pop=0;
        while (!mono.empty() && arr[mono.back()] < arr[i])
        {
            pop++;
            mono.pop_back();
        }
        if(!mono.empty()){
            if(arr[mono.back()]==arr[i]){
                if(arr[mono[0]]==arr[i]){
                    amount[i]=pop+mono.size();
                }else{
                   int guess=(mono.size()-2)/2;
                   int low=0;
                   int high=mono.size()-2;
                   while(!(arr[mono[guess]]>arr[i] && arr[mono[guess+1]]==arr[i]) && low<=high){
                       if(arr[mono[guess]]==arr[i]){
                            high=guess-1;
                       }else{
                          low=guess+1;
                       }
                       guess=(high+low)/2;
                   }
                   amount[i]=pop+(mono.size()-guess);
                }
              
            }else{
                amount[i]=pop+1;
            }
        }else{
            amount[i]=pop;
        }
        mono.push_back(i);
        ans+=(long long) amount[i];
    }
    cout<<ans<<"\n";
    }
    
}