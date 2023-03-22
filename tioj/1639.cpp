#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct node{
	node* next = nullptr;
	ll val = 0;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	node* head = new node;		
	int n;cin>>n;
	node* cu = head;
	for(int i=0;i<n;i++){
		node* e = new node;
		cin>>e->val;
		cu->next = e;
		cu = e;
	}
	ll ans = 0;	
	for(int i=0;i<n-1;i++){
		node* cur = head->next;
		node* tobemerge = cur;
		ll minsum = 1e18;
		if(cur->next==nullptr) continue;
		while(cur->next!=nullptr){
		//	cout<<cur->val<<" ";
			if(minsum>cur->val+cur->next->val){
				tobemerge = cur;
				minsum = cur->val+cur->next->val;
			}
			cur = cur->next;
		}
		//cout<<cur->val<<"\n";
		ans+=minsum;
		tobemerge->val+=tobemerge->next->val;
		tobemerge->next = tobemerge->next->next;
	}
	cout<<ans<<"\n";
	return 0;
}
