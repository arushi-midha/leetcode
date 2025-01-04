class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowelwords;
        int i=0;
        
        for(string c:words){
            
            int n=c.length();
            if((c[0]=='a' or c[0]=='e' or c[0]=='i' or c[0]=='o' or c[0]=='u') and (c[n-1]=='a' or c[n-1]=='e' or c[n-1]=='i' or c[n-1]=='o' or c[n-1]=='u')){
                
                i++;
            }
            vowelwords.push_back(i);
            
        }
        
        vector<int> result;

        for(auto c:queries){
            if(c[0]-1==-1){
                result.push_back(vowelwords[c[1]]);
            }
            else{
                result.push_back(vowelwords[c[1]]-vowelwords[c[0]-1]);
            }
            
        }
        return result;
    }
};



class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowelwords;
        int i=0;
        unordered_set<char> vowels={'a','e','i','o','u'};
        for(string c:words){
            
            int n=c.length();
            if((vowels.find(c[0])!=vowels.end()) and (vowels.find(c[n-1])!=vowels.end())){
                
                i++;
            }
            vowelwords.push_back(i);
            
        }
        
        vector<int> result;

        for(auto c:queries){
            if(c[0]-1==-1){
                result.push_back(vowelwords[c[1]]);
            }
            else{
                result.push_back(vowelwords[c[1]]-vowelwords[c[0]-1]);
            }
            
        }
        return result;
    }
};