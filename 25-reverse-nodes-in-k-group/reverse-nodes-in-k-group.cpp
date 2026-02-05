/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
 ListNode* temp = head ;
int cnt = 0 ;
while(cnt < k){
    if(temp == NULL){
        return head ;
    }
    temp = temp->next ;
    cnt++;

}

// recursive call 
 ListNode* prev = reverseKGroup(temp , k);

// reinsialize the value of temp and head 
temp = head ;
cnt = 0 ;

// reverse the current group 

while(cnt < k ){
ListNode* next = temp->next ;
temp->next = prev ;
prev = temp ;
temp = next ;
cnt++ ;
}

return prev ;
    }
};