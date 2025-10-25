// NOTE :- Simply using the prefix sum technique in this question and checking the highest number in the prefix_sum array while calculating the sum

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> cummulative_array = {0};

        int max = 0;
        int pointer = 0;
        
        while(pointer < gain.size()){
            cummulative_array.push_back(gain[pointer] + cummulative_array[pointer]);
// NOTE :- vector methods like begin() and end() gives us the pointer to the starting or the end of the array and not the elements present over there i.e. we need to use the (*) symbol to access the data at that point.
            if(*(cummulative_array.end() - 1) > max){
                max = *(cummulative_array.end() - 1);
            }
            pointer++;
        }

        return max;
    }
};