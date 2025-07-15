/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */

 // This is the submission for the problem Merge Strings Alternately question easy based on array
var mergeAlternately = function (word1, word2) {
    const l1 = word1.length
    const l2 = word2.length

    let i = 0;
    let finalString = ``;
    for (; i < l1; i++) {
        if (word1.charAt(i)) {
            finalString += word1.charAt(i)
        }
        if (word1.charAt(i)) {
            finalString += word2.charAt(i)
        }
    };

    if (i < l2) {
        finalString += word2.slice(i)
    }

    return finalString
}