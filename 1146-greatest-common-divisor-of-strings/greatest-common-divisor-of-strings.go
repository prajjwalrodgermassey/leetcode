import "fmt"

//The logic is similar to the HCF/GCD of the numbers and the strings should be completely divislbe, there will be no decimal points airthematic, so the highest length that divides both the string will be the common substring among both the string which when multiplied n times will return in str1 and str2.
func gcd(a,b int) int {
    //Using fmt package to log and it's Printf method to use the verbs like %d and %f
    //fmt.Println cannot use verbs
    fmt.Printf("arg1: %d \t arg2: %d\n", a, b)
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}


func gcdOfStrings(str1 string, str2 string) string {
//This condition is used to check if both the strings are multiple of the same substring or not because this condition will only hold true if both the strings are created using a common substring.
//e.g. str1 = abcdabcd str2= abcdabcdabcdabcd then the common substring is abcdabcd
    if str1+str2 != str2+str1 {
        return ""
    }

    //len() function is used to find the length of the string and the arrays or the slices.
    return str1[:gcd(len(str1), len(str2))]
}