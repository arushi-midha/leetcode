/*
-------6/2/24-------

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*int n=strs.size();
        vector<string> newstr;
        vector<bool> pushed(n);
        vector<vector<string>> ans(2*n);
        for(int i=0;i<n;i++){
            newstr.push_back(strs[i]);
        }
        for(int i=0;i<n;i++){
            sort(strs[i].begin(),strs[i].end());
        }

        ans[0].push_back(newstr[0]);
        pushed[0]=true;
        int pointer=0;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(pushed[j]!=true){
                    if(strs[i]==strs[j]){
                        ans[pointer].push_back(newstr[j]);
                        pushed[j]=true;
                    }
                }  
            }
            pointer++;
            ans[pointer].push_back(newstr[i]);
        }
        
        return ans;*/

           unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*int n=strs.size();
        vector<string> newstr;
        vector<bool> pushed(n);
        vector<vector<string>> ans(2*n);
        for(int i=0;i<n;i++){
            newstr.push_back(strs[i]);
        }
        for(int i=0;i<n;i++){
            sort(strs[i].begin(),strs[i].end());
        }

        ans[0].push_back(newstr[0]);
        pushed[0]=true;
        int pointer=0;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(pushed[j]!=true){
                    if(strs[i]==strs[j]){
                        ans[pointer].push_back(newstr[j]);
                        pushed[j]=true;
                    }
                }  
            }
            pointer++;
            ans[pointer].push_back(newstr[i]);
        }
        
        return ans;*/

           unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};