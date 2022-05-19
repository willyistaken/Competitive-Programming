


n = int(input())

sum=0
time=0
maxn = -1000
minn = 1000
for i in range(n):
    a = int(input())
    
    if(a>0):
        time+=1
    else:
        a=-a
    sum+=a
    maxn = max(maxn,a)
    minn = min(minn , a)

print("Average time: {:.3f} sec(s).".format((sum-maxn-minn)/(n-2)))
print("Winning rate: {:.3f} %.".format(100*time/(n)))

#what is 魔法氣泡...