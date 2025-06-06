/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node*slow=head;
        Node*fast=head;
        Node *x=head;
        while(fast->next!=NULL&& fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                int ct=0;
                while(x!=slow->next){
                    x=x->next;
                }
                while(x!=slow){
                    ct++;
                    x=x->next;
                }
                return ct+1;
            }
        }
        return 0;
    }
};