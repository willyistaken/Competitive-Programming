#include <bits/stdc++.h>
using namespace std;


int main(){
	set<int > s;
	s.insert(9);
	s.insert(7);
	s.insert(3);
	s.insert(1);
	cout<<*s.upper_bound(2);
}