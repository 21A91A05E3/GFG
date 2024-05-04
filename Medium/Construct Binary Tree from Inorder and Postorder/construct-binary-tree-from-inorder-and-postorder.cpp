//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

   Node *cons_tree(int io_st,int io_ed,int io[],int po_st,int po_ed,int po[],map<int,int>&mp)
    {
        if(io_st>io_ed or po_st>po_ed)return NULL;
        Node *root=new Node(po[po_ed]);
        int ind=mp[root->data];
        int r=ind-io_st;
        root->left=cons_tree(io_st,ind-1,io,po_st,po_st+r-1,po,mp);
        root->right=cons_tree(ind+1,io_ed,io,po_st+r,po_ed-1,po,mp);
        return root;
        
    }
    Node *buildTree(int in[], int post[], int n) {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        return cons_tree(0,n-1,in,0,n-1,post,mp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends