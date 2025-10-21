/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    let max_sum = 0, current_sum = 0;

    //NOTE :- Calculating the sum of first k elements of the array
    for(let i = 0; i < k; i++){
        max_sum += nums[i];
    }

    current_sum = max_sum;
//NOTE:- Initalizing with k as we have already calculated the sum of the previous k elements so we want our loop to start from the (k)th element, using i-k to remove the starting index and using i to add the element thus sliding the window.
    for(let i = k; i < nums.length; i++){
        current_sum = current_sum - nums[i-k] + nums[i];
        if(current_sum > max_sum){
            max_sum = current_sum;
        }
    }
    return max_sum/k;
};