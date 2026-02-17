class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;
        for (string& word : words)
            wordMap[word]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            int count = 0;
            unordered_map<string, int> seen;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordMap.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount)
                        result.push_back(left);
                }
                else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
