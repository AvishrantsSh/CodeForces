#include <iostream>
using namespace std;

void swap(char &x, char &y)
{
    char tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int size, time;
    string seq;
    cin >> size >> time >> seq;
    for (int round = 0; round < time; round++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (seq[i] == 'B' && seq[i + 1] == 'G'){
                swap(seq[i], seq[i + 1]);
                i++;
            }
        }
    }
    cout << seq;
}