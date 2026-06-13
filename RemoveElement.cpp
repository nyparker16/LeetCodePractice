#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] == val && nums[j] == val) {
                j--;
            } else if (nums[i] != val && nums[j] == val) {
                i++;
                j--;
            } else if (nums[i] == val && nums[j] != val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            } else {
                i++;
            }
        }
        return (i == j) ? i+1 : i; 
    }
};