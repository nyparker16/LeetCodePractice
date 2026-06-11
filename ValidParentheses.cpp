#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.length() == 0) return true;

        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;

        map<char, char> brackets = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        int counter = 0;
        char open = s[0];

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == open) {
                counter += 1;
            } else if (s[i] == brackets[open]) {
                if (counter == 0) {
                    if (!isValid(s.substr(1, i - 1))) return false; 
                    if (i == s.length() - 1) return true;
                    return isValid(s.substr(i + 1));
                }
                counter -= 1;
            }
        }
        return false;
    }
};