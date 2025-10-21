class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // NOTE:- Using double so that we have the decimal values as well in the answer
        //(CE):- Instead of using std::accumulate we can also run a loop and find the sum of the first k elements of the vector nums
        double max_sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double current_sum = max_sum;

//NOTE:- Using k to initialize (i) so that first k elements are skipped for sum        
        for(int i = k ; i < nums.size(); i++){
  //NOTE :- using (i-k) to remove the starting index and using (i) to add the new index thus sliding the window
            current_sum = current_sum - nums[i-k] + nums[i];
            
            if(current_sum > max_sum){
                max_sum = current_sum;
            }
        }

        return max_sum/k;
    }
};