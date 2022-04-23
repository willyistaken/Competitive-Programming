#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct skill
{
int a;
int b;
};
bool compa(skill a, skill b)
{
return a.a < b.a;
}
bool compb(skill a, skill b)
{
return a.b <b.b;
}
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t;cin>>t;
while(t--){
int n, k;
cin >> n >> k;

skill arr[n];
for (int i = 0; i < n; i++)
{
    skill temp;
    int gg;cin>>gg;
    temp.a=gg;
    cin>>gg;
    temp.b=gg;
    arr[i] = temp;
}
sort(arr, arr + n, compa);
priority_queue<skill, vector<skill>, function<bool(skill, skill)>> myq(compb);
int now = 0;
int minn;
while (now < k)
{
     
    myq.push(arr[now]);
    minn = arr[now].a +myq.top().b; 

    now++;
}

while (now < n)
{
    myq.push(arr[now]);
    myq.pop(); 
    if(minn> arr[now].a+myq.top().b) {
        minn= arr[now].a+myq.top().b;
    }
    now++;
}
cout<<minn<<endl;
}
}