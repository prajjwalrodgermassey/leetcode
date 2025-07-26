/** LOOP INVARIANCE OF THE MAX_SUBARRAY PROBLEM FOR THIS SOLUTION :-
During each loop step, we maintain the rule that:

current_sum is always the sum of the best subarray that ends at the current index.

max_so_far is always the highest subarray sum we've seen so far, no matter where it ends.

This loop invariant holds before and after every iteration — and that’s what guarantees the correctness of Kadane’s Algorithm.
 * 
 */

/** (CE) :- the maximum subarray problem best case scenario is sum of all elements in array and all are positive,
 * (CE) if there is a number in the subarray lets say arr[i] adding which to the sum makes it negative, then the new subarray
 * (CE) should be started beginning from the next index if it is positive
 * (CE) i.e. if arr[i] is big negative number which makes the sum less than or equal to 0
 * (CE) then the new subarray should be started for maximum sum starting from arr[i+1] if arr[i+1] is positive integer
 * (CE) if it is negative then it would make the sum even more negative. Until we find a next positive integer in the array
 * (CE) the calculation of the next subarray sum could not begin.
 */

const arr = [10, -8, 9];

function maxSub(arr: number[]) {
  let max = arr[0];
  let sum = arr[0];
  for (let i = 1; i < arr.length; i++) {
    /**(CE) :- checking here if the number existing at arr[i] is negative enough when it is added
     * (CE) makes the sum even smaller than arr[i], conversly it says that sum should already be negative, because
     * (CE) that is the only case which would make adding arr[i] to it (the sum) smaller than arr[i] itself
     * (CE) e.g. sum = -2 and arr[i] = 5 adding these 2 would always result in sum being smaller
     * (CE) e.g. sum = -2 and arr[i] = -5 adding these 2 would also always result in sum being smaller
     *
     * (CE) Assigning arr[i] to sum in this case as it would mark the beginning of the new array, if arr[i] is positive
     * (CE) and if arr[i] is negative then it just puts sum equals to the arr[i] which would
     * (CE) obvisouly not be the maximum subarray as adding these 2 would obviously result in a number smaller than
     * (CE) sum.
     */

    if (sum + arr[i] <= arr[i]) {
      sum = arr[i];
    } else {
      sum += arr[i];
    }

    /**(CE) :- checking if the new sum is greater than the max which was previously calculated
     * (CE) and replacing max with sum if it is greater than the max.
     */

    if (sum > max) {
      max = sum;
    }
  }

  return max;
}

console.log(maxSub(arr));
