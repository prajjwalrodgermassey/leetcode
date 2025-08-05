/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    
    if(!head){
        return null
    }
    
    let current_elem = head
    let prev_elem = null
    let next_elem = head?.next

    while(current_elem){
        if(current_elem === head){
            current_elem.next = null
        }else{
            current_elem.next = prev_elem
        }
        prev_elem = current_elem
        current_elem = next_elem
        next_elem = current_elem?.next || null
    }

    return prev_elem
};