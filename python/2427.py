import sys
input=sys.stdin.readline
save=[0 for i in range(151515)]
n,p,v=map(int,input().rstrip().split())
i=0
while 1:
    save[i]=1
    j=2
    while i-v-j*p>=0:
        save[i]=max(j*save[i-v-j*p],save[i])
        j+=1
    if save[i]>=n:
        exit(print(i))
    i+=1