# Bench Marking
    auto begin = chrono::high_resolution_clock::now();
    ## code here ##
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> time=end-begin;
    cout<<time.count()<<"s"<<endl;
# IO Optimization
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

# Prama Compiler Optimization
    #pragma GCC optimize("Ofast")