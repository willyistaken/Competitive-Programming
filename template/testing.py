def yes(num):
    square=num*num    
    while(num>0):   
        if(num%10!=square%10):  
            return False;
        num=num//10                        
        square=square//10   
    return True;


for i in range(int(1e9)):
    if(yes(i)):
        print(i)