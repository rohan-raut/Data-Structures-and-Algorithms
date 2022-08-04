/*
*   author: rohanraut
*   created on: 12.10.2021 20:06:38
*/

// Reference Links: 
// https://www.youtube.com/watch?v=ddIWsXj7kVk&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=5


// Constructing max heap

#include <bits/stdc++.h>

using namespace std;

void delete_(vector<int> &v, int &i){
    swap(v[1],v[i]);
    i--;
    int temp = i;
    int l_child = INT_MIN, r_child = INT_MIN;
    while(temp*2<=i || (temp*2+1)<=i){
        int flag = 0;     // flag=0 -> no swap, flag=1 -> swap with left child, flag=2 -> swap with right child
        if(temp*2<=i){
            l_child = v[temp*2];
        }
        if(temp*2+1 <= i){
            r_child = v[temp*2+1];
        }

        if(l_child > r_child){
            flag=1;
        }
        else{
            flag=2;
        }

        if(flag == 1 && v[temp] < l_child){
            swap(v[temp], v[temp*2]);
            temp = temp*2;
        }
        else if(flag == 2 && v[temp] < r_child){
            swap(v[temp], v[temp*2+1]);
        }
        else{
            break;
        }
    }
}



void insert_(vector<int> &v, int &i, int value){
    v.push_back(value);
    i++;
    int temp = i;
    while(temp/2>0 && v[temp]>v[temp/2]){
        swap(v[temp],v[temp/2]);
        temp=temp/2;
    }
}


void printHeap(vector<int> &v, int j){
    for(int i=1; i<=j; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    vector<int> maxHeap(1,0);
    int i=0;

    insert_(maxHeap,i,10);
    insert_(maxHeap,i,20);
    insert_(maxHeap,i,13);
    printHeap(maxHeap,i);
    delete_(maxHeap,i);
    printHeap(maxHeap,i);




    return 0;
}


// Notes:
// N = Total number of nodes in Heap 
// Insertion time complexity: O(log N)
// Deletion time complexity: O(log N)

// Declaration of Priority Queue:
// Max Priority Queue: priority_queue<int> hp;
// Min Priority Queue: priority_queue<int, vector<int>, greater<int>> hp;