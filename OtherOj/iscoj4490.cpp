#include<cstdio>
using namespace std;
typedef long long ll;



int main(){
	int n;scanf("%d",&n);
	while(n--){
		int k;scanf("%d",&k);
		if(k>=80) puts("AaW不可能是電神一定是成績改錯了");
		else if(k>=60) puts("好扯竟然有及格");
		else if(k>=40) puts("快去準備補考");
		else puts("沒救了QAQ");
	}
	return 0;
}
