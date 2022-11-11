#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct node{
	node* next;
	int g;
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	node* cur = new node;
	node* head = cur;
	cur->g = 1;	
	for(int i=2;i<=n;i++){
		cur->next = new node;
		cur = cur->next;
		cur->g = i;
	}
	cur->next = head;
	for(int i=0;i<n;i++){
		cur = cur->next;
		node* b = cur;
		cur = cur->next;
		cout<<cur->g<<" ";
		b->next= cur->next;
	}
	cout<<"\n";
	return 0;
}
