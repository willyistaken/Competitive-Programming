
from math import log10
a = [0,1,5,6]


def check(i):
    s = str(i)
    if(i==(i*i)%(10**(len(s)))):
        return 1;
    else:
        return 0;

tp=10
for i in range(2,102):
    g = len(a)
    for j in range(1,10):
        for f in a:
            if(f>tp):
                break
            if(check(j*tp+f)):
                a.append(j*tp+f)
    tp*=10




for i in a:

    if(i>(1e100)):
        break
    if(check(i)):
        print("\"{}\"".format(i),end=', ')

print(len(a))
