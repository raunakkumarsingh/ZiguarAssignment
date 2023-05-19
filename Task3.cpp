#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};


 ListNode* middleNode(ListNode* head) {
        
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while( (fast->next!=NULL) ){
            slow=slow->next;
            if(fast->next==NULL){
                return slow;
            }
            if(fast->next->next==NULL){
                return slow;
            }
            fast=(fast->next)->next;
        }
        
        return slow;
    }

int main(){
    int n;
    cin>>n;
    ListNode *list=new ListNode();
    ListNode *t=list;

    int k;

    for(int i=0;i<n;i++){
        cin>>k;
        ListNode *temp=new ListNode();
        t->val=k;
        if(i!=n-1){
        temp->val=k;
        t->next=temp;
        t=t->next;
        }
          
    }

      ListNode *tt=list;

      while(tt!=NULL){
        tt=tt->next;
      }



    cout<<middleNode(list)->val;

}