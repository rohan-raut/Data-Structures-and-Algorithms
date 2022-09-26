/*
*   author: rohanraut
*   created on: 26.09.2022 11:13:15
*/

#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
    private:
    int N;
    vector<int> tree;

    public:

    SegmentTree(int n){
        tree.resize(4*n+1);
        N = n;
    }

    void Print(){
        for(auto x: tree){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    void Build(vector<int> &arr, int index, int l, int r){
        if(r < l){
            return;
        }

        if(l == r){
            tree[index] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(arr, index*2, l, mid);
        Build(arr, index*2+1, mid+1, r);
        tree[index] = tree[index*2] + tree[index*2+1];
    }


    int Query(vector<int> &arr, int index, int l, int r, int ql, int qr){
        // No Overlap
        if(r < ql || qr < l){
            return 0;
        }

        // Complete Overlap
        if(ql <= l && qr >= r){
            return tree[index];
        }

        // Partial Overlap
        int mid = (l + r) >> 1;
        int left = Query(arr, index*2, l, mid, ql, qr);
        int right = Query(arr, index*2+1, mid+1, r, ql, qr);
        return (left + right);
    }

    void UpdateNode(vector<int> &arr, int index, int l, int r, int val, int i){
        // Leaf Node
        if(l == r){
            tree[index] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if(i <= mid){
            UpdateNode(arr, index*2, l, mid, val, i);
        }
        else{
            UpdateNode(arr, index*2+1, mid+1, r, val, i);
        }
        tree[index] = tree[index*2] + tree[index*2+1];
    }

    void UpdateRange(vector<int> &arr, int index, int l, int r, int ql, int qr, int inc){
        // No Overlap
        if(r < ql || qr < l){
            return;
        }

        // Leaf Node
        if(l == r){
            tree[index] = tree[index] + inc;
            return;
        }
        
        int mid = (l + r) >> 1;
        UpdateRange(arr, index*2, l, mid, ql, qr, inc);
        UpdateRange(arr, index*2+1, mid+1, r, ql, qr, inc);
        tree[index] = tree[index*2] + tree[index*2+1];
    }
};

int main()
{

    vector<int> arr = {1, 2, 3, 4 ,5, 6};
    SegmentTree segTree(6);
    segTree.Build(arr, 1, 0, 5);

    cout<<segTree.Query(arr, 1, 0, 5, 2, 3)<<endl;

    segTree.UpdateRange(arr, 1, 0, 5, 2, 3, 5);
    cout<<segTree.Query(arr, 1, 0, 5, 2, 3);

    
    
    return 0;
}