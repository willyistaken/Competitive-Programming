vector<int> d;
sort(d.begin(),d.end());
d.resize(unique(d.begin(),d.end())-d.begin());
