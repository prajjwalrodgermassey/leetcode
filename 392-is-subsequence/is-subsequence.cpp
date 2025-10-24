class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int s_length = s.length(), t_length = t.length(), s_index = 0, t_index = 0;

        if(s_length == 0){
            return true;
        }

        char current_char = s[s_index];

        for(int i = 0; i < t_length; i++){
            if(t[i] == current_char){
                s_index++;
                current_char = s[s_index];
            }
        }

        return s_index == s_length;
       
    }
};