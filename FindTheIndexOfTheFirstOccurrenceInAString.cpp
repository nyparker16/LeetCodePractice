#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int idx = -1;
        int next = -1;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                idx = i;
                int j = 0;
                while (i < haystack.length() && haystack[i] == needle[j]) {
                    i++;
                    j++;
                }
                if (j ==  needle.length()) {
                    return idx;
                }
                i = idx;
            }
        }
        return -1;
    }
};