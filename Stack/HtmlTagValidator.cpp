class Solution {
public:
    bool isValid(string code) {
        int n = code.length();
        stack<string> S;
        int i = 0;

        if (code.empty()) {
            return false;
        }

        while (i < n) {
            // CDATA
            if (code.compare(i, 9, "<![CDATA[") == 0) {
                if (S.empty()) {
                    return false;
                }

                int j = i + 9;

                while (j < n && code.compare(j, 3, "]]>") != 0) {
                    j++;
                }

                if (j == n) {
                    return false;
                }

                i = j + 3;
            }

            // End Tag
            else if (code.compare(i, 2, "</") == 0) {
                int j = i + 2;

                while (j < n && code[j] != '>') {
                    j++;
                }

                if (j == n) {
                    return false;
                }

                string tagName = code.substr(i + 2, j - (i + 2));

                if (S.empty() ||
                    !isValidTagName(tagName) ||
                    S.top() != tagName) {
                    return false;
                }

                S.pop();
                i = j + 1;

                if (S.empty() && i < n) {
                    return false;
                }
            }

            // Start Tag
            else if (code[i] == '<') {
                int j = i + 1;

                while (j < n && code[j] != '>') {
                    j++;
                }
                if (j == n) {
                    return false;
                }

                string tagName = code.substr(i + 1, j - (i + 1));

                if (!isValidTagName(tagName)) {
                    return false;
                }

                S.push(tagName);
                i = j + 1;
            }

            // Normal text
            else {
                if (S.empty()) {
                    return false;
                }

                i++;
            }
        }

        return S.empty();
    }

    bool isValidTagName(string tagName) {
        if (tagName.length() < 1 || tagName.length() > 9) {
            return false;
        }

        for (char c : tagName) {
            if (!isupper(c)) {
                return false;
            }
        }

        return true;
    }
};


//Complexity 
//-Time Complexity: O(n) : Where n is the length of the input string code
//-Space Complexity: O(n) : in the worst case, we may have to store all the tags in the stack