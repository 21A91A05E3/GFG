//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
    void merge(int low,int mid,int high,vector<int>&v,int &ans)
    {
        int i = low , j = mid+1 ;
        while(i <= mid && j <= high)
        {
            if(v[i] > v[j]){
                ans += mid-i+1;
                j++;
            }
            else i++;
        }
        sort(v.begin()+low,v.begin()+high+1);
    }
    void mergesort(int i , int j , vector<int>&v , int &ans)
    {
        if(i<j)
        {
            int m = (i+j)/2;
            mergesort(i,m,v,ans);
            mergesort(m+1,j,v,ans);
            merge(i,m,j,v,ans);
        }
    }
    void inorder(Node *root,vector<int>&v)
    {
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int>v;
        inorder(root,v);
        int ans = 0;
        mergesort(0,v.size()-1,v,ans);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends