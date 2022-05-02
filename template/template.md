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

# Check Memory Allocation
    static int s_AllocCount = 0;
    void* operator new(size_t size) {
        s_AllocCount++;
        std::cout << "Allocating " << size << "bytes\n";
        return malloc(size);
    }

    // in main()
    std::cout<<"This program allocates memories "<<s_AllocCount<<" times"<<std::endl;