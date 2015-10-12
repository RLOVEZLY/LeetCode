ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* tail = second;
        first->next = head;
        ListNode* temp = first;
        while(temp->next){
            if (temp->next->val < x){
                temp = temp->next;
            }
            else{
                tail->next = temp->next;
                temp->next = temp->next->next;
                tail->next->next = NULL;
                tail = tail->next;
            }
        }
        temp->next = second->next;
        temp = first->next;
        delete first;
        delete second;
        return temp;
    }
