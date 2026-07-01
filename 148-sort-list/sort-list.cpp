class Solution {
public:

ListNode* middle (ListNode* head){
    if(head == NULL || head->next == NULL){
        return head ;
    }
    ListNode* slow = head ;
    ListNode* fast = head->next ;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next -> next ;
        slow = slow ->next ;
    }
    return slow ;
}
ListNode* merge(ListNode* list1 , ListNode * list2 ){
ListNode* dummyNode = new ListNode(-1);
ListNode* temp = dummyNode ;



while(list1 != NULL && list2 != NULL){
    if(list1->val < list2 ->val ){
        temp->next = list1 ;
        list1 = list1->next ;
        temp = temp ->next ;       
    }
    else {
        temp->next = list2 ;
       list2 =  list2->next ;
       temp = temp->next ;
    }
  
}
  if(list1) {
        temp->next = list1 ;
    }
    if(list2){
        temp->next = list2 ;
    }

    return dummyNode->next ;

}
ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head ;
        }
        ListNode* mid= middle(head);
        ListNode * leftHead = head ;
        ListNode* rightHead = mid->next ;
        mid->next = NULL ;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

         return merge(leftHead , rightHead);

    }
};