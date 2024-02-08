/*
--------9/2/24-------
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

*/


/*
class Solution {
public:
    string frequencySort(string s) {
        
        int n=s.length();
        map<char, int> mymap;
        int count=1;
        int i;
        sort(s.begin(),s.end());
        for(i=1;i<n;i++){
            if(s[i-1]==s[i]){
                count++;
            }
            else{
                mymap[s[i-1]]=count;
                count=1;
            }
        }
        mymap[s[i-1]]=count;

        vector<int> sortedbyfreq;
        for(const auto& pair :mymap){
            sortedbyfreq.push_back(pair.first);
        }
        
        sort(sortedbyfreq.begin(),sortedbyfreq.end(), [&](char a, char b){
            return mymap[a]>mymap[b];
        });

        string ans;
        for(char c: sortedbyfreq){
            ans+= string(mymap[c], c);
        }

        return ans;
    }
};*/

class Solution {
public:
    string frequencySort(string s) {
        
        int n=s.length();
        map<char, int> mymap;
        int count=1;
        int i;

        for(char c:s){
            mymap[c]++;
        }

        vector<int> sortedbyfreq;
        for(const auto& pair :mymap){
            sortedbyfreq.push_back(pair.first);
        }
        
        sort(sortedbyfreq.begin(),sortedbyfreq.end(), [&](char a, char b){
            return mymap[a]>mymap[b];
        });

        string ans;
        for(char c: sortedbyfreq){
            ans+= string(mymap[c], c);
        }

        return ans;
    }
};

