#include "grader.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

std::string find_next(std::string str) {
	int K = str.size();
	int l = 0;int r = K+1;
	while(r-l>1){
		int mid = (l+r)/2;
		string ask;
		ask.resize(K);
		for(int i=0;i<mid;i++){
			ask[i] = str[i];
		}
		for(int i=mid;i<K;i++){
			ask[i]='_';
		}
		pair<string,string> stp = get_min_max(ask);
		if(stp.first.size()) l = mid;
		else r = mid;
	}
	if(l==K)  return str;
	string ask;
	ask.resize(K);
	for(int i=0;i<l;i++) ask[i] = str[i];
	for(int i=l;i<K;i++) ask[i]='_';
	char nxt[4]={'A','C','G','T'};
	for(int i=0;i<4;i++){
		if(str[l]==nxt[i]){
			for(int j=i+1;j<4;j++){
				ask[l]=nxt[j];
				pair<string,string> stp = get_min_max(ask);
				if(stp.first.size()){
					for(int i=l+1;i<K;i++) ask[i]='?';
					stp = get_min_max(ask);
					return stp.first;
				}
			}
		}
	}
	return "";
}
