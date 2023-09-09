t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    arr=[]
    dp=[[0 for j in range(10)] for i in range(151515)]
    for asdf in range(n):
        arr.append(list(map(int,input().split())))
    arr.sort()
    for i in range(n,-1,-1):
        for j in range(0,k+1):
            if i==n:dp[i][j]=0;continue
            a=0
            if j==0:a=arr[i][0]
            else:a=min(arr[i][0],dp[i+1][j-1])
            dp[i][j]=max(a-arr[i][1],dp[i+1][j])
    print(dp[0][k])