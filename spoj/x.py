import sys,math
MOD=1000000007
def mod_pow(base,exp,mod):
    res=1;
    while(exp>0):
        if(exp%2==1):
            res=(res*base)%mod;
        exp=exp>>1;
        base=(base*base)%mod
    return res
t=int(sys.stdin.readline());
while(t!=0):
    n=int(sys.stdin.readline());
    if(n%3==0):
        a=mod_pow(3,n/3,MOD)%MOD;
        print ("%d" % a);
    elif(n%3==1):
        a=4*mod_pow(3,(n-4)/3,MOD)%MOD;
        print ("%d" % a);
    else:
        a=2*mod_pow(3,(n-2)/3,MOD)%MOD;
        print ("%d" % a);
    t=t-1;
