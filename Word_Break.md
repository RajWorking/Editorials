# Word-Break Editorial

## Approach
Using DP with bottom-up approach.

## Intuition
One of the ways to solve this problem is to use Dynamic Programming. I have used bottom up approach in my implementation but if you understand this, you can easily convert it to a top down method.  

The problem wants us to check if it is possible to form the string from the words available in the dictionary. We can do this check for each prefix of the string. If we get true for a certain prefix (say, p), we can then seek to find other prefixes in string s by extending p using words from the dictionary. If we cannot form the prefix p, there is no reason to extend it further. 

## Algorithm
We iterate over all prefixes from 0 to n-1 and whenever we get a valid prefix (boolean TRUE), we find other valid prefixes in the string as said above. The prefix upto n-1 is the string itself, so the boolean value at n-1 will be our answer.

## C++ code
```cpp
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // number of characters in the given string
        int n = s.size();

        /*
            This boolean array stores TRUE (1) and FALSE (0) for each 
            of the n positions of the string. 

            TRUE means: there exists a possible combination of words
                        from the dictionary to create the prefix upto
                        the position i-1. (substring [0..i-1])

            FALSE means: since the prefix cannot be made, it is useless
                         to go on.
        */
        vector<bool> arr(n + 1, 0); // initialised to False

        // first position is obviously true because the prefix is an empty string
        arr[0] = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0) // FALSE => no valid prefix upto i-1
                continue;
            
            /*
                we loop over all words in the dictionary to find all further
                extensions of the prefix
            */

            for (string &word : wordDict)
            {
                if (i + word.size() <= n && s.substr(i, word.size()) == word)
                    arr[i + word.size()] = 1;
            }
        }

        /* arr[n] represents if it is possible to create the substring [0..n-1],
           which is the string itself, and hence our answer */
           
        return arr[n];
    }
};
```
## Complexity Analysis:

### Space complexity
The string given to us is of size `n`, so we can assume that the max size of any word given in the dictionary will be `n`. Let the number of words in the dictionary be `w`.
This gives us space used of the order:  
`O(n + n*w)` which can be approximated `O(n*w)`

Also, we created a boolean array in the implementation of our algorithm. But it will take up space `O(n)`, so again we have,  
`O(n + n*w)` which can be written as ***O(nw)*** (size of the dictionary itself).

### Time complexity
In our optimised algorithm, we loop over each of the `n` positions in the string s.  
For each position we go over each of the word of the dictionary (`w` words).  
Each word is compared against its corresponding substring, so this will take up time `O(n)`.

Hence we get the time complexity of the order ***O(n<sup>2</sup> w)***


## Animated explanation:  

![](word-break-gif.gif)