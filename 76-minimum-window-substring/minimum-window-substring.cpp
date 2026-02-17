class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        vector<int> need(128, 0);
        for (char c : t)
            need[c]++;
        
        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;
        
        while (right < s.size()) {
            
            if (need[s[right]] > 0)
                count--;
            
            need[s[right]]--;
            right++;
            
            // When valid window found
            while (count == 0) {
                
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                
                need[s[left]]++;
                
                if (need[s[left]] > 0)
                    count++;
                
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
