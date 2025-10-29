// NOTE :- this approach is basically simple and straightforward, we use the property of prefix sum, i.e. we calculate the sum of entire array;
// We know if we have the sum of entire array and we subtract the sum of any subarray from that we'll get the sum of the remaining sub array
// We've used the same property we're calculating the sum from left the only thing is we don't include the index that is currently being processed that is our pivot index;
// Example :- [1,2,3,4,5] the sum of this subarray = 15; if we want the sum of the subarray starting from index 0 till index 2 we can just subtract the sum of this subarray from the total sum that would be 15 - 6 = 9; which would be the sum of the right subarray; we can also take a range of indices i.e. let's say we want the sum of indicies starting from 1 to 3 the sum of the reamaining subarray would be 15 - 9 = 6

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        int left_sum = 0;

        for(const int &i : nums){
            sum += i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(left_sum == (sum - left_sum - nums[i])){
                return i;
            }
            left_sum += nums[i];
        }

        return -1;
    }
};