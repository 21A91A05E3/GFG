//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int>v;
        v.push_back(0);
        int x = 0;
        for(auto it : queries){
            if(it[0] == 0) v.push_back(it[1] ^ x);
            else x = x^it[1];
        }
        
        for(int i = 0 ; i < v.size() ; i++)  v[i] = v[i]^x;
             
        sort(v.begin(),v.end());
        return v;
        
        /* here  when a==0 then we push back the b but with the xoring with the totalXor...
        so when we last do the xor with the all elements then it cancle out the effect of this xoring which we do here when a==0 come
        for example {{0, 2}, {1, 3}, {0, 5}} when 2nd 0 comes w push the 5 with the xor with the totalXor and in last when we
        do the xor of all elements with totalXor=3 then this 3^3^5=5 remaining means previously xor's effect is cancle out..
        like wise do for the other test cases... */
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends