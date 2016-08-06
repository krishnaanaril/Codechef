n = input()
for i in range(n):
    k = int(raw_input())
    k-=1
    x, div, mul, res = 1, 5, 10, 0
    p = pow(div, x)
    while p<=k:
        x+=1
        p = pow(div, x)       
    while k:
        x-=1
        p = pow(div, x);
        res+= ((k/p)*2*pow(mul, x));
        k%=p;
    print res
        
