#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseorder(ListNode* head){
    if (!head || !head->next) return head;
    ListNode* pre = head;
    ListNode* cur = head->next;
    pre->next = NULL;
    while(cur){
        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}
void reorderList(ListNode* head) {
    if (!head) return;
    int len = 0;
    ListNode* temp = head;
    while(temp){
        temp = temp->next;
        ++len;
    }
    if (len <= 2) return;
    int halflen = len - len/2;
    temp = head;
    for (int i = 1; i < halflen; i++){
        temp = temp->next;
    }
    ListNode* rightstart = temp->next;
    temp->next = NULL;
    rightstart = reverseorder(rightstart);
    ListNode* leftstart = head;
    ListNode* tempnextleft = leftstart->next;
    ListNode* tempnextright = rightstart->next;
    while(tempnextleft != NULL){
        leftstart->next = rightstart;
        rightstart->next = tempnextleft;
        leftstart = tempnextleft;
        rightstart = tempnextright;
        tempnextleft = tempnextleft->next;
        if (tempnextright)
            tempnextright = tempnextright->next;
    }
    if (rightstart){
        leftstart->next = rightstart;
    }
    return;
}

int main()
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    a->next = b;
    b->next = c;
    reorderList(a);
    ListNode* temp = a;
    while(temp){
        cout << temp->val << endl;
        temp = temp->next;
    }
}


