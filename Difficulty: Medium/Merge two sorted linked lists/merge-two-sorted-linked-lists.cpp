/* Link list Node
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
    Node* sortedMerge(Node* h1, Node* h2) {
        // code here
        if(h1==NULL)
        return h2;
        if(h2==NULL)
        return h1;
        if(h1->data<=h2->data){
            h1->next=sortedMerge(h1->next,h2);
            return h1;
        }
        else{
            h2->next=sortedMerge(h1,h2->next);
            return h2;
        }
        
    }
};