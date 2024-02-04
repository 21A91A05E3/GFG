//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string fun(string a,string b)
    {
       
        if(a.size()==0 and b.size()==0)return "0";
    
        string r="";
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]>=b[i])
            {
                r+=to_string((a[i]-'0')-(b[i]-'0'));
            }
            else{
                
              if(a[i]!='0')  r+=to_string(10+(a[i]-'0')-(b[i]-'0'));
              else r+=to_string(10-(b[i]-'0'));
                int j=i-1;
               while (a[j] == '0') {
                    a[j] = '9';
                    j -= 1;
                }
                a[j] = ((a[j] - '0') - 1) + '0';
            }
        }
  
        return r;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        Node *temp1=head1;
        Node *temp2=head2;
        string a="",b="",s="";
        while(temp1)
        {
            a+=to_string(temp1->data);
            temp1=temp1->next;
        }
        while(temp2)
        {
            b+=to_string(temp2->data);
            temp2=temp2->next;
        }
       // cout<<"a= "<<a<<" b= "<<b<<"\n";
        //removing leading zeroes
        
        int i=0,aind=0,bind=0;
        while(i<a.size())
        {
            if(a[i]!='0') break;
            else aind+=1;
            i+=1;
        }
        i=0;
        while(i<b.size())
        {
            if(b[i]!='0') break;
            else bind+=1;
            i+=1;
        }
        a=a.substr(aind,a.size()-aind);
        b=b.substr(bind,b.size()-bind);
        
        //adding zeroes to make strings equal
        string res;
        if(a.size()<b.size())
        {
            int d=b.size()-a.size();
            while(d--)
            {
                s+='0';
            }
            s+=a;
            res=fun(b,s);
        }
        else if(b.size()<a.size())
        {
            int d=a.size()-b.size();
            while(d--)
            {
                s+='0';
            }
            s+=b;
            res=fun(a,s);
        }
        else
        {
            
            if(a.compare(b)<0)res=fun(b,a);
            else res=fun(a,b);
        }
      //cout<<"res= "<<res<<"\n";
        reverse(res.begin(),res.end());
        //cout<<"res= "<<res<<"\n";
        i=0;
        int rind=0;
        while(i<res.size())
        {
            if(res[i]!='0') break;
            else rind+=1;
            i+=1;
        }
        res=res.substr(rind,res.size()-rind);
      //  cout<<"res= "<<res<<"\n";
    Node *ans=new Node(-1);
        Node *head=ans;
        int l=res.size();
        int r,d;
        i=0;
        while(i<l)
        {
           
            d=res[i]-'0';
            Node *nn=new Node(d);
            ans->next=nn;
            ans=ans->next;
            i+=1;
        }
        if(head->next==NULL)
        {
            head->data=0;
            return head;
        }
        return head->next;
        
      //return NULL;
       
        
      
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends