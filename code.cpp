#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct BinaryTrie
    {
        vector<vector<int>> nxt;
        vector<int>cnt;
        int w, BIT, ptr;
        BinaryTrie(int _w, int _BIT) : w(_w), BIT(_BIT), ptr(0)
        {
            nxt.resize(w * BIT, vector<int>(26));
            cnt.resize(w * BIT);
        }

        void add(T x)
        {
            int curr = 0;
            for (int i = BIT - 1; i >= 0; i--)
            {
                int t = (x >> i) & 1;
                if (!nxt[curr][t])
                    nxt[curr][t] = ++ptr;
                cnt[curr = nxt[curr][t]]++;
            }
        }
        bool exist(string x)
        {
            int curr = 0;
            for (int i = BIT - 1; i >= 0; i--)
            {
                int t = (x >> i) & 1;
                if (!nxt[curr][t])
                    return false;
                if (!cnt[curr = nxt[curr][t]])
                    return false;
            }
            return true;
        }
    }

    bool
    wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        vector<bool> arr(n + 1, 0);

        arr[0] = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;

            for (string &word : wordDict)
            {
                if (i + word.size() <= n && s.substr(i, word.size()) == word)
                    arr[i + word.size()] = 1;
            }
        }

        return arr[n];
    }
};