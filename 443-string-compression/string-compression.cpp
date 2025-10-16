class Solution {
public:
    int compress(vector<char>& chars) {
        int reading_index = 0;
        int writing_index = 0;

        while(reading_index < chars.size()){
            
            int count = 0;
            char current_char = chars[reading_index];
         
            while( reading_index < chars.size() && current_char == chars[reading_index]){
                count++;
                reading_index++;
            }

            chars[writing_index++] = current_char;

            if(count > 1){
                for(int i=0; i < std::to_string(count).size(); i++){
                    chars[writing_index++] = std::to_string(count)[i];
                }
            }
        }
        return writing_index;
    }
};