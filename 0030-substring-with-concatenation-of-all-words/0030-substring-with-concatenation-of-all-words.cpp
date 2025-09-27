class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        unordered_map<string,int> need;
        for (auto &w : words) need[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, right = offset;
            unordered_map<string,int> seen;
            int count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (need.find(word) != need.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);
                    }

                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};
