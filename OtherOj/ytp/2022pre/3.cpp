#include<bits/stdc++.h>
using namespace std;
typedef long long ll;





void getou(vector<int>&q,int k)

{
    if(k==1)
    {
        return ;
    }
    q.push_back(k);
    for(int i=2;i<k;i++)
    {
        q.push_back(i);
        q.push_back(k);
    }
    q.push_back(1);
    getou(q,k-1);
}

int main(){
	vector<int> q;
	int n;cin>>n;
	getou(q,n);
	vector<bool> pass(n,0);
	int g=-1;
	cout<<n*n+1<<"\n";
	for(auto i : q){
		i--;
		if(g<0) g=i;
		if(!pass[i]){
			cout<<i<<" ";
			pass[i]=1;
		}
		cout<<i<<" ";
	}
	cout<<g<<"\n";
}
