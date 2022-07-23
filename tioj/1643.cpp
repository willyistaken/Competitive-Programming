#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,l;
vector<pair<int,int> > arr;

int solve(int l,int r){
	if(r-l==1) return 1;
	int result = max(solve(l,(l+r)/2),solve((l+r)/2,r));
	
	// prepare for binary search
	pair<int,int> lside[((r+l)/2)-l];
	pair<int,int> rside[r-((r+l)/2)];
	lside[0] = arr[(l+r)/2-1];
	for(int i=1;i<((r+l)/2)-l;i++){
		lside[i] = {max(lside[i-1].first,arr[((l+r)/2-1)-i].first),min(lside[i-1].second,arr[((l+r)/2-1)-i].second)};
	}
	rside[0] = arr[(l+r)/2];
	for(int i=1;i<r-((r+l)/2);i++){
		rside[i] = {max(rside[i-1].first,arr[(r+l)/2+i].first),min(rside[i-1].second,arr[(r+l)/2 +i].second)};
	}
	
	// binary search;
	// x|max,min
	int maxn=0;
	for(int i=0;i<r-((r+l)/2);i++){
		if(rside[i].first-rside[i].second>l) break;
		
	}
	//max,min|x
	
	//max|min
	
	//min|max
	


}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>l;
	arr.resize(m,{0,0});	

	return 0;
}


/*
SEE: this problem is the same as find the biggest n,m such that in  x,y to x+n,y+m  max-min <=L
size is n and m;
Brute force: N^3M^3 just check it 1 by 1
Stuck: how to improve:
KNOW: can check maxn and min in log(n)^2 so can optimize solution to N^4log(n)^2
Stuck: not enough? what is the point that I am stuck on? how can I not check all possible square
AHA: if I emuerate the biggest number in the square I can do it in NMNNM by the biggest square (if  MAX-L<x<MAX 1 else it is 0)
Stuck this is not enough
AHA: 0<L<=20; so what?
TRY: the 1D version:
	AHA: the previous idea can work in n^2log(n);
	STUCK: how can i improve this:
	TRY: D & Q?:
		A(l,r) = max(A(l,r/2),A(r/2,r));
		and the cross between :
		STUCK: how to combine this
		RECALL: min max D & Q 3 case:
			max and min the same side: max-min is mono can binary search
			max one side min the other: can search mono and binary search
			so it is log(n);
		CHECK: TIME complexity: T(n) = 2T(n/2) + log(n); O(nlogn);
		I guess I solve it:
Stuck: is there a way to extend 1D to 2D:
AHA: by emuerate one dim(segment) I can do it in n^3log(n);
CHECK: is it good enough? I guess
ATTACK:enumerate length;

*/
