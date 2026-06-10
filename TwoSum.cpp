#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        vector<pair<int, int>> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices.push_back({nums[i], i});
        }
        sort(indices.begin(), indices.end());
        int i = 0;
        int j = indices.size() - 1;
        while (i < j) {
            if (indices[i].first + indices[j].first == target) {
                answer.push_back(indices[i].second);
                answer.push_back(indices[j].second);
                return answer;
            } else if (indices[i].first + indices[j].first < target) {
                i++;
            } else {
                j--;
            }
        }
        return answer;
    }
};

