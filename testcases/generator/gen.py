n=int(input())
if n==0:print("ONTAK 2010")
if n==1:
    pass
if n==2:
    arr=[1,1]
    mod=9099099909999099999
    while len(arr)<=10000:
        arr.append((arr[-1]%mod+arr[-2]%mod)%mod)
    print(arr)