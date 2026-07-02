class Solution {
    private:
    ListNode* MergeListHelper(vector<ListNode*>& lists , int start , int end ){
        if(start == end ){
            return lists[start] ;
        }
         if(start+1  == end) {
            return merge(lists[start] , lists[end]);
         }
         int mid = start + (end - start)/2 ;
         ListNode* left = MergeListHelper(lists , start , mid );
         ListNode* right = MergeListHelper(lists , mid + 1 , end );

       return   merge(left , right ) ;
    }

    ListNode* merge(ListNode* list1 , ListNode* list2  ){
        ListNode* dummy = new ListNode(-1);
        ListNode *temp = dummy ;

        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                temp->next = list1 ;
                list1 = list1->next ;
                temp = temp -> next ;
            }
            else{
                temp->next = list2 ;
                list2 =list2->next ;
                temp= temp->next ;
            }

        }
       temp->next = (list1) ? list1 : list2;


      return dummy -> next ;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL ;
        }
        return MergeListHelper(lists , 0 , lists.size() - 1 );
    }
};