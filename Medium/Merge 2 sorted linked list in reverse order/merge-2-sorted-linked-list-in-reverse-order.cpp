//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node * reverse(Node *node)
    {
        Node *prv=NULL;
        Node *curr=node;
        Node *nxt=curr->next;
        while(nxt)
        {
            curr->next=prv;
            prv=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        curr->next=prv;
        return curr;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node* node=newNode(-1);
        Node* newlist=node;
        if(node1==NULL and node2==NULL)return node1;
        while(node1!=NULL and node2!=NULL)
        {
            if(node1->data<=node2->data){
                Node *nn=newNode(node1->data);
                node->next=nn;
                nn->next=NULL;
                node=node->next;
                node1=node1->next;
                
            }
            else
            {
                Node *nn=newNode(node2->data);
                node->next=nn;
                nn->next=NULL;
                node=node->next;
                node2=node2->next;
            }
        }
        while(node1!=NULL)
        {
                Node *nn=newNode(node1->data);
                node->next=nn;
                nn->next=NULL;
                node=node->next;
                node1=node1->next;
        }
        while(node2!=NULL)
        {
        
                Node *nn=newNode(node2->data);
                node->next=nn;
                nn->next=NULL;
                node=node->next;
                node2=node2->next;
        }
     
        return reverse(newlist->next);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends