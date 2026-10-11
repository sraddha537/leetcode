class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int ans = nums[0];

        // Left to Right :-  First negative ko include karke, last negative se pehle ka maximum product dhoondhta hai.
        int product = 1;

        for (int i = 0; i < n; i++) {

            product *= nums[i];
            ans = max(ans, product);   

            // 0 mil gaya -> new subarray start
            if (product == 0) {
                product = 1;
            }
        }

        // Right to Left :- Last negative ko include karke, first negative ke baad ka maximum product dhoondhta hai.
        product = 1;

        for (int i = n - 1; i >= 0; i--) {

            product *= nums[i];
            ans = max(ans, product);

            // 0 mil gaya -> reset
            if (product == 0) {
                product = 1;
            }
        }
        return ans;
    
    }

};