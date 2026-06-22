class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(string t : tokens){
            if(t != "-" && t != "+" && t != "*" && t != "/"){
                int val = stoi(t);
                S.push(val);
            }
            else {

                int secondOpernad = S.top(); S.pop();
                int firstOperand = S.top(); S.pop();

                int result = 0;

                if (t == "+") result = firstOperand + secondOpernad;
                else if (t == "-") result = firstOperand - secondOpernad;
                else if (t == "*") result = firstOperand * secondOpernad;
                else if (t == "/") result = firstOperand / secondOpernad;

                S.push(result);
            }
        }
        
        return S.top();

    }
};

# Complexity
- Time complexity: O(n) 
- Space complexity: O(n) In worst case (all numbers and no operators), stack size will grow to n