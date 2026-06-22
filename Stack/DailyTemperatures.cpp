class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> S;
        vector<int> result(n, 0);

        for(int i=0; i< n; i++){
            while(!S.empty() && temperatures[S.top()] < temperatures[i]){
                int index = S.top();
                result[index] = i - index;
                S.pop();
            }

            S.push(i);
        }
        return result;
    }
};

# Complexity
- Time complexity: O(n) 
- Space complexity: O(n) Worst case (all temperatures are in decreasing order [10, 20, 30, 40, 50]), stack size will grow to N