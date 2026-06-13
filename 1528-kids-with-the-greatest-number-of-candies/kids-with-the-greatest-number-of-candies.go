func kidsWithCandies(candies []int, extraCandies int) []bool {
    var maxCount int
    // better approach to create this slice would be to use make method as it would create an underlying array of the given length and capacity so at runtime the program doesn't have to recreate and allocate fresh memory as the slice is currently nil.
    var truthArray []bool

    // range returns the index as the first return value and the element of the slice or array as second
    for _, count := range candies {
        if maxCount < count{
            maxCount = count
        }
    }

    for _, count := range candies {
        if extraCandies + count >= maxCount {
            //Using append to append to the slice as we have only declared a nil slice and therefore if we'd try to assign any value based on index it'd fail and cause a panic
            truthArray = append(truthArray, true)
        }else {
            truthArray = append(truthArray, false)
        }
    }

    return truthArray
}