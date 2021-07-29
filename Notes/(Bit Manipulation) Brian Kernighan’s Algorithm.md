Brian Kernighan’s Algorithm
---

Subtracting 1 from a decimal number **flips all the bits after the rightmost set bit** including the rightmost set bit. To count number of bits, use

```c++
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
```