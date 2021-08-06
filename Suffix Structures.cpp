#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> stringSet;
    bool flag = false;
    int s_size = s.size(), t_size = t.size();

    if (t_size > s_size)
    {
        cout << "need tree";
        return 0;
    }

    int t_diff = t_size, j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        stringSet[s[i]] += 1;
        if (s[i] == t[j])
        {
            j++;
            t_diff--;
        }
    }

    if(t_diff == 0){
        cout << "automaton";
        return 0;
    }

    for (int i = 0; i < t_size; i++)
    {
        if (stringSet.find(t[i]) == stringSet.end())
        {
            cout << "need tree";
            return 0;
        }
        stringSet[t[i]]--;
        if (stringSet[t[i]] < 0)
            flag = true;
    }

    if (s_size == t_size){
        if (flag)
            cout << "need tree";
        else
            cout << "array";
    }
    else if(flag)
        cout << "need tree";
        
    else
        cout << "both";
}