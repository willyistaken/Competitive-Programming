#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

/*
sol:
observation: 
	(1)	 colors can be splited
	(2)	 reverse the adding process is simpler 
	(3)  calculate the node where there is no color x in its paths is easier
my solution:
set a limit B:
for every color:
if color_cnt>B:
	use a simple dsu and count sz, everytime a node got remove , combine componets
	and when query, return the sz of its componets
	there is only N/B this kind of color, which make the complexity O(Q(N/B));
else:
	goal: make modify O(sz log(N)) and query O(log(N));
	uses bit and adding value to node and getting sum from root to node to get ans
	specificlly: 
		aaabbbaaabbbaaabbb		
*/


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);


	return 0;
}
