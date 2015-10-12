ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* returnval = temp;
        temp->next = NULL;
        while (head){
            int value = head->val;
            if (head->next && head->next->val == value){
                while(head && head->next && head->next->val == value){
                    head = head->next;
                }
                if (head){
                    head = head->next;
                }
            else{
                temp->next = head;
                head = head->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }
	ListNode* returnhead = returnval->next;
	delete returnval;
        return returnhead;
    }
