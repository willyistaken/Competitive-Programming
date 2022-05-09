import math
import random
sum=0
n=100000
for i in range(n):
    a=random.randint(1,n)
    b=random.randint(1,n)
    sum+=abs(a-b)
print(sum/n)





