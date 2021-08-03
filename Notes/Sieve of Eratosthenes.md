Sieve of Eratosthenes
---------------------

The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so
```c++
void Prime_Sieve(````vector<bool> sieve, ll n)
{
    sieve[0] = false;
    sieve[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j = j + i)
                sieve[j] = false;
        }
    }
}
```