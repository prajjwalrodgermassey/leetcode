/**
 * @param {character[]} chars
 * @return {number}
 */

/** This problem uses 2 pointers approach more comments */

var compress = function(chars) {
    
    let readingIndexPointer = 0
    let writingIndexPointer = 0
    const length = chars.length

    while(readingIndexPointer < length){
        let count = 0
        const currentChar = chars[readingIndexPointer]

        while(readingIndexPointer < length && currentChar === chars[readingIndexPointer] ){
            count++
            readingIndexPointer++
        }

        chars[writingIndexPointer] = currentChar
        writingIndexPointer++

    
        if(count !== 1)
        {
            if(count >= 10){
            for(let intFromCount of count.toString()){
                chars[writingIndexPointer] = intFromCount.toString()
                writingIndexPointer++
                }
            }else{
            chars[writingIndexPointer] = count.toString()
            writingIndexPointer++
        }
        }
        
    }
    return writingIndexPointer

};