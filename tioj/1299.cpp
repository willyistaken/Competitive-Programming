#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char* arr[17] = {"D","D","D","C","C","C","B","B","B","B","A","A","A","SA","SA","SA","SA"};
char s[11];
int main(){
	while(scanf("%s",s)!=-1){
		int sum=0;
		int len = strlen(s);
		for(int i=0;i<len;i++){
			sum+= (s[i]>'Z') ? s[i]-'a':s[i]-'A';
			sum=(sum+1)%17;
		}
		puts(arr[sum%17]);
	}

	return 0;
}
