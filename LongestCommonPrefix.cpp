#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = strs[0];
        if (word.length() == 0) return "";

        for (int i = 0; i < word.length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (word[i] != strs[j][i]) {
                    return word.substr(0, i);
                }
            }
        }
        return word;
    }
};