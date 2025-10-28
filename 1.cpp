class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& num, int target) {
        std::unordered_map<int, int> numMap;    
    
        for (int i = 0; i < num.size(); ++i) {
            int currentNum = num[i];
            int complement = target - currentNum;

            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            numMap[currentNum] = i;
        }
        return {};
    }
};