class Solution {
public:
    bool isValid(string s) {
        if(s.empty() || s.size() == 1) return false;
        map<char, char> mapper ={ {')', '('}, {'}', '{'}, {']', '['} };
        stack<char> S;
        for(auto str : s){
            //first pushed all opening parantheses
            if(str == '(' || str == '{'|| str == '['){
                S.push(str);
                continue;
            }
            //check element if it match the Top of the stack
            if(S.empty() || S.top() != mapper[str]) return false;
            S.pop();
        }
        return S.empty();

        }

};

//Complexity
//- Time complexity: O(n) 
//- Space complexity: O(n)