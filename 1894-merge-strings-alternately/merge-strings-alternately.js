/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */

//TODO - add comments
// This is the submission for the problem Merge Strings Alternately question easy based on array
var mergeAlternately = function (word1, word2) {
  const l1 = word1.length;
  const l2 = word2.length;

  let i = 0;
  let finalString = ``;

  /* (CE) :- Here we simple run a loop to the length of the first string and check the character at the index in that string using charAt function
   * (CE) we simply put the character from the first string first and the character from the second string second in our final string.
   * (CE) the (charAt) function returns empty string in case if there is no character present therefore it doesn't break the code if we try to access an invalid index with charAt function
   * (CE) as it would only append an empty string
   */

  for (; i < l1; i++) {
    if (word1.charAt(i)) {
      finalString += word1.charAt(i);
    }
    if (word1.charAt(i)) {
      finalString += word2.charAt(i);
    }
  }

  /* (CE) :- Here we check if the final value of i is less than length of string 2 i.e. length of word1 is less than length of word2 then we slice and append the string 2 at the end
   */
  if (i < l2) {
    finalString += word2.slice(i);
  }

  return finalString;
};
