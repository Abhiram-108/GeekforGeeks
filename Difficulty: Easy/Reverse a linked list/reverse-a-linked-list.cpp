/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node*x=NULL;
        while(head){
            Node *p=head;
            head=head->next;
            p->next=x;
            x=p;
        }
        return x;
    }
};