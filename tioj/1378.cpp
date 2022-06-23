#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    stack<char> later;
    for (auto i : s) {
        if (i == '(') {
            later.push(i);
        }else if (i == ')') {
            while (later.top() != '(') {
                cout << later.top();
                later.pop();
            }
            later.pop();
        } else if (i == '+' || i == '-') {
            while (!later.empty()&&later.top() != '(' ) {
                cout << later.top();
                later.pop();
            }
            later.push(i);
        } else if (i == '*' || i == '/') {
            while (!later.empty() && later.top() != '+' && later.top() != '-' && later.top() != '(' ) {
                cout << later.top();
                later.pop();
            }
            later.push(i);
        } else
            cout << i;
    }
    while(!later.empty()){
        cout<<later.top();
        later.pop();
    }
    cout<<"\n";
    return 0;
}

// http://sptutor.dyu.edu.tw/DSTutor/exprDemo.jsp