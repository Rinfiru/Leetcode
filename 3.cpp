class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) {
            return 0;
        }

        std::unordered_map<char, int> charIndexMap;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            if (charIndexMap.count(current_char)) {
                left = std::max(left, charIndexMap[current_char] + 1);
            }
            
            charIndexMap[current_char] = right;
            
            maxLen = std::max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};