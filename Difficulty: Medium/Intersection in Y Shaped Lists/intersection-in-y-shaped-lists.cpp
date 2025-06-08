// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        if(head1==head2)
        return head1;
        Node*l1=head1;
        Node*l2=head2;
        while(l1!=l2){
            if(l1){
                l1=l1->next;
            }
            else
            l1=head2;
            if(l2)
            l2=l2->next;
            else
            l2=head1;
        }
        return l1;
    }
};