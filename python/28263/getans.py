from itertools import combinations

a=23471078400
p=[
    10187101, 10478161, 10886401, 11289601, 12192769, 12224521, 12418561, 13305601, 
    13335841, 13582801, 13970881, 14817601, 15240961, 18627841, 20374201, 20697601, 
    20956321, 21732481, 22809601, 24837121, 26671681, 28449793, 29338849, 29937601, 
    30561301, 34771969, 37255681, 39513601, 39916801, 45841951, 47900161, 50803201, 
    52157953, 55883521, 59270401, 59875201, 66679201, 78236929, 88905601, 91683901, 
    93139201]
for i in list(combinations(p,11)):
    n=1
    for j in i:n=n*j%a
    if n%a==1:exit(print(*i,sep=' '))