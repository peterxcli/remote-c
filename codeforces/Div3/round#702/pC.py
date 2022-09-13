t = int(input()); 
while t:
    x = int(input())
    flag = 0
    if x == 2: flag = 1
    i = 2
    while i*i <= x:
        if x % i == 0:
            j = x // i
            if ((i*i - j) % 3 == 0 and (i*i - j) > 0) : flag = 1
            if ((j*j - i) % 3 == 0 and (j*j - i) > 0) : flag = 1
        i+=1
    if flag :print("yes")
    else : print("no")
    t-=1