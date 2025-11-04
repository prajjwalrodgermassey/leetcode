// IMPLEMENTED USING QUEUE
/* The questions of these type doesn't necessarily mean to use Queue data structure directly but instead we 
create our queues from the given input and then perform operations on the queues which we have dervied from 
the given data */

class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> r_index_queue, d_index_queue;

        if(senate.length() == 0){
            return "";
        }
/* Here we store indices of the R's and the D's into the qeueue which are taken from the given string*/
        for(int i = 0; i < senate.length(); i++){
            if(senate[i] == 'R'){
                r_index_queue.push(i);
            }else{
                d_index_queue.push(i);
            }
        }

//Here we check if any one of the queue is empty we early return the other winner
            if(d_index_queue.empty()){
                return "Radiant";
            }else if(r_index_queue.empty()){
                return "Dire";
            }

/* Here we run our loops over the 2 queues together simultaneously which gives an impression if the index of R 
is smaller than the index of D it means that R appeared in front of the D and thus can override the powers of the D and vice versa we also insert the respective index of R or D whichever is smaller again into their respective index queue as this will ensure that the winner is decided round after round we increment the index by the length of the given string and insert it into the queue making sure if there is an R or D which can override the other if one appears at the end.
*/
        while(!r_index_queue.empty() && !d_index_queue.empty()){
            int r_index = r_index_queue.front();
            int d_index = d_index_queue.front();

             r_index_queue.pop();
             d_index_queue.pop();

                std::cout << "r index: " << r_index <<" d_index: " << d_index << std::endl; 
            if(r_index < d_index){
                r_index_queue.push(r_index + senate.length());
            }else{
                d_index_queue.push(d_index + senate.length());
            }

            if(d_index_queue.empty()){
                return "Radiant";
            }else if(r_index_queue.empty()){
                return "Dire";
            }
        }
        return "";
    }
};