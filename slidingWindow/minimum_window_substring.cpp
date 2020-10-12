/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

*/

class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> m(128,0);
        int count=0;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
            count++;
        }
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int lptr=0;
        while(j<s.size()){
            if(m[s[j]]>0){
                count--;
            }
            m[s[j]]--;
            if(count==0){
                //substring found
                while(i<j && m[s[i]]<0){
                    m[s[i]]++;
                    i++;
                }
                if(ans>(j-i+1)){
                    ans = j-i+1;
                    lptr=i;
                }
                m[s[i]]++;
                i++;
                count++;
                
            }
            j++;
        }
        
        return ans==INT_MAX?"":s.substr(lptr,ans);
    }
};
