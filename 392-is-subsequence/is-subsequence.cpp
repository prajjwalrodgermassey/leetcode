// NOTE :- Using for loops for this problem and in general the 2 pointer technique helps us to minimize the code but while loop helps us better visualize the concept
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int s_length = s.length(), t_length = t.length(), s_index = 0;
        // char current_char = s[s_index]
        if (s_length == 0)
        {
            return true;
        }

        // NOTE :- We dont have to use the current_char we can directly access the character with s_index and the s i.e. s[s_index]
        for (int i = 0; i < t_length; i++)
        {
            if (t[i] == s[s_index])
            {
                s_index++;
                // NOTE :- We're using early return because we increment s_index every time and then replace the current_char but in reality if the s_index is already at the last index we'd increment it and then try to access the invalid out of bounds index which would cause the undefined behaviour
                if (s_index == s_length)
                {
                    return true;
                }
            }
        }

        return false;
    }
};