/*
6 june 2024
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minfreq(26);
        for(char c:words[0]){
            minfreq[c-'a']++;
        }

        
        for(int i=1;i<words.size();i++){
            vector<int> charcount(26,0);
            for(char c:words[i]){
                charcount[c-'a']++;
            }

            for(int j=0;j<26;j++){
                minfreq[j]=min(minfreq[j],charcount[j]);
            }
        }

        vector<string> result;
        for(int i=0;i<26;i++){
            while(minfreq[i]>0){
                result.push_back(string(1,i+'a'));
                minfreq[i]--;
            }
        }
        return result;
    }
};