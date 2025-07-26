/**
 * @param {character[]} chars
 * @return {number}
 */

/** This problem uses 2 pointers approach more comments */

/* (CE) : We've used 2 pointers approach in this question one pointer keeps the track where to insert the character, and another pointer keeps the track from where to read the character
 */

var compress = function (chars) {
  let readingIndexPointer = 0;
  let writingIndexPointer = 0;
  const length = chars.length;

  while (readingIndexPointer < length) {
    let count = 0;
    const currentChar = chars[readingIndexPointer];

    /* (CE) :- Lookin at these 2 while loops one might think that these are nested loops hence the time complexity of O(n2) but that is not the case
     * (CE) 1) The first loop starts from 0 (read pointer = 0) and runs till the length of the loop
     * (CE) 2) The second loop starts from (read pointer) and also checks if the currentChar is equal to the one which was one index before it,
     * (CE)  if the condition is satisfied it increments the reading pointer by one and count by 1.
     * (CE) Hence whenever the outer loop will begin its next iteration it will not be starting from the (reading pointer + 1) but instead from the
     * (CE) reading pointer which has been set by the inner loop. Therefore these 2 loops working together might look like nested but in reality they both combined run once till the length of the array
     * (CE) eg:- [a,a,a,b,b] for this array the first iteration of outer loop will start from reading pointer being 0 but the 2nd iteration will be from reading pointer being 3
     */
    while (
      readingIndexPointer < length &&
      currentChar === chars[readingIndexPointer]
    ) {
      count++;
      readingIndexPointer++;
    }

    chars[writingIndexPointer] = currentChar;
    writingIndexPointer++;

    /* (CE) :- One catch in this algorithm is we don't print the count of the characters if the occurence is only once but we simple print the character itself
     * (CE) This is done because having only a single charachter and printing its length on the next index will modify the array and hence result in the lost data which
     * (CE) might be presesnt on the next index.
     * (CE) eg: [a,b,b] => if we write the output as [a,1] then the resulting array would be modified to [a,1,b] and thus the element at index 2 would be lost.
     */
    if (count !== 1) {
      /* (CE) :- Here we check if the occurence of the character is equal to or more than 10 then we convert the (count) to string and use for of loop to retrieve its every element
       * (CE) to push into the array, if the occurence of the character is 10 times then the greatest number we could mention in those 10 indicies would be 9999999999 but
       * (CE) but we'd have to write only 10
       * (CE) eg: [a,a,a,a,a,a,a,a,a,a] => the resulting array would be [a,1,0]
       */
      if (count >= 10) {
        for (let intFromCount of count.toString()) {
          chars[writingIndexPointer] = intFromCount.toString();
          writingIndexPointer++;
        }
      } else {
        chars[writingIndexPointer] = count.toString();
        writingIndexPointer++;
      }
    }
  }
  return writingIndexPointer;
};
