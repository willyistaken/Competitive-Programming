#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int h[500005];
int v[500005];
struct mono{
	deque<int> arr;
	ll sum=0;
	void popfront(){
		sum-=v[arr.front()];
		arr.pop_front();
	}
	void popback(){
		sum-=v[arr.back()];
		arr.pop_back();
	}
	void pushback(int ind){
		sum+=v[ind];
		arr.push_back(ind);
	}
	int get() {return sum;}
	int front() {return arr.front();}
	int back() {return arr.back();}
};

int main(){

	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>v[i];
	ll ans=0;
	int ind=0;
	mono M;
	for(int i=0;i<n;i++){
		while(!(M.arr).empty()){
			if(M.front()<=i-k) M.popfront();
			else{
				if(h[M.back()]<=h[i]) M.popback();
				else break;
			}
		}
		M.pushback(i);
		if(ans<M.get()){
			ans=M.get();
			ind = i;
		}
	}
	cout<<ind+1<<" "<<ans<<"\n";
	return 0;

}
