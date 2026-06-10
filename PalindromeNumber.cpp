#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        std::vector<int> num_array(digits(x));
        for (int i = 0; i < num_array.size(); i++) {
            num_array[i] = x % 10;
            x = x / 10;
        }
        for (int i = 0; i < num_array.size() / 2; i++) {
            if (num_array[i] != num_array[num_array.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    int digits(int x) {
        if (x == 0) {
            return 1;
        }
        int count = 0;
        while (x != 0) {
            x = x / 10;
            count++;
        }
        return count;
    }
};