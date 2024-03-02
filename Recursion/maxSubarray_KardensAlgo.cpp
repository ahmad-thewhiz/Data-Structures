class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0, finalSum=INT_MIN;
        for(int num: nums) {
            currSum += num;
            finalSum = max(currSum, finalSum);
            if(currSum<0)
                currSum=0;
        }
        return finalSum;
    }
};
