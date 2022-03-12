#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int con = 1000005;
  int behind[con];
  int begin[n + 1];
  int end[n + 1];
  fill(behind, behind + con, -1);
  fill(begin, begin + n + 1, -1);
  fill(end, end + n + 1, -1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string c;
    cin >> c;
    if (c[0] == 'A') {
      int store, id;
      cin >> store >> id;
      if (begin[store] == -1 && end[store] == -1) {
        begin[store] = id;
        end[store] = id;
      } else {
        behind[end[store]] = id;
        end[store] = id;
      }
    } else if (c[0] == 'L') {
      int store;
      cin >> store;
      if (begin[store] == -1 && end[store] == -1) {
        cout << "queue " << store << " is empty!" << endl;
      } else {
        if (begin[store] == end[store]) {
          begin[store] = -1;
          end[store] = -1;
        } else {
          int newb = behind[begin[store]];
          int oldb = begin[store];
          begin[store] = newb;
          if (behind[begin[store]] == -1) {
            end[store] = begin[store];
          }
          behind[oldb] = -1;
        }
      }
    } else if (c[0] == 'J') {
      int from, to;
      cin >> from >> to;
      if (!(begin[from] == -1 && end[from] == -1)) {
        if (begin[to] == -1 || end[to] == -1) {
          begin[to] = begin[from];
          end[to] = end[from];
        } else {
          behind[end[to]] = begin[from];
          end[to] = end[from];
        }
        end[from] = -1;
        begin[from] = -1;
      }
    }

    /* for(int i=1;i<=n;i++){
   cout<<"queue "<<i<<":";
   if(begin[i]==-1 || end[i]==-1){
       cout<<" empty"<<endl;
   }else{
       int head=begin[i];
       while(behind[head]!=-1){
           cout<<" "<<head;
           head=behind[head];
       }
       cout<<" "<<head<<endl;
   }
}*/
  }

  for (int i = 1; i <= n; i++) {
    cout << "queue " << i << ":";
    if (begin[i] == -1 || end[i] == -1) {
      cout << " empty" << endl;
    } else {
      int head = begin[i];
      while (behind[head] != -1) {
        cout << " " << head;
        head = behind[head];
      }
      cout << " " << head << endl;
    }
  }
}