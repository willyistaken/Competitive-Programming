#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int n, k;

string query;

vector <string> words;

int cnt = 0;
   
pair<string, string> get_min_max(const string &str) {
	cnt++;
    pair<string, string> result;
	string now; now.resize(k);
	for (int id = 0;id < n;id++) {
		string &word = words[id];
		bool match = true;
		for (int i = 0;i < k;i++) {
			if (str[i] == '?') {
				cnt++;
				now[i] = word[i];
				continue;
			}
			if (str[i] == '_') {
				now[i] = '_';
				continue;			
			}
			if (str[i] != word[i]) {
				match = false;
				break;
			}			
			now[i] = word[i];
		}
		if (match) {
			if (result.first.empty() || result.first > now) {
				result.first = now;
			}
			if (result.second.empty() || result.second < now) {
				result.second = now;
			}
		}
	}

	return result;
}

string find_next(string);

int main() {

	cin >> n >> k;
	words.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> words[i];
	}	
	std::sort(words.begin(),words.end());
	cin >> query;	
	string st = find_next(query);
	int f = lower_bound(words.begin(),words.end(),query)-words.begin();
	string ans = "";
	if(f<words.size()) ans = words[f];

	cout<<"truth:"<<ans<<"  answer:"<<st<<"\n";
	cout<<"used: "<<cnt<<" queries\n";
	
	return 0;
}
