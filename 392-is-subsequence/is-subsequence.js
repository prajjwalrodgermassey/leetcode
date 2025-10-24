/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

 // TECH :- Remeber we always don't have to use the 2 pointers on the same array or string like we are using 2 pointers on 2 different strings here and also remember whenever we have to use true or false or we have to compare something we can always use the index to the length to check whether our code has run to the end of the length of the array or string or not.
 //NOTE :- Using the while loop variant and managing the 2 pointers manually for better visualization
var isSubsequence = function(s, t) {
    let p1 = 0, p2 = 0;

    while(p1 < s.length && p2 < t.length){
        if(s[p1] === t[p2]){
            p1++;
        }
        p2++;
    }
    return p1 === s.length;
};