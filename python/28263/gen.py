from sympy import divisors, isprime

n=23471078400
divs=divisors(n)
possible_p=[d+1 for d in divs if 10**7<=d+1<10**8]
prime_candidates=[p for p in possible_p if isprime(p)]
valid_primes=[p for p in prime_candidates if n%p!=0]
print(valid_primes,len(valid_primes))