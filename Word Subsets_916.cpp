You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int>max_freq(26,0);
        for(string word2:words2){
            vector<int>temp(26,0);
            for(char c2:word2){
                temp[c2-'a']++;
            }
            for(int i=0;i<26;i++){
                max_freq[i]=max(max_freq[i],temp[i]);
            }
        }
        for(string word1:words1){
            vector<int>temp(26,0);
            for(char c:word1){
                temp[c-'a']++;
            }
            bool check=true;
            for(int i=0;i<26;i++){
                if(max_freq[i]>temp[i]){
                    check=false;
                    break;
                }
            }

            if(check){
                result.push_back(word1);
            }


            

            temp.clear();
        }
        return result;
    }
};