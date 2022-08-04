/*
*   author: rohanraut
*   created on: 02.05.2022 12:00:42
*/

#include <bits/stdc++.h>

using namespace std;


void printChess(vector<vector<char>> &chess){
    for(int i=0; i<chess.size(); i++){
        for(int j=0; j<chess[i].size(); j++){
            cout<<chess[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

bool safe(vector<vector<char>> &chess, int i, int j){
    int x=i, y=j;
    while(x>=0){
        if(chess[x][y]=='Q'){
            return false;
        }
        x--;
    }

    x=i;
    y=j;
    while(x>=0 && y>=0){
        if(chess[x][y]=='Q'){
            return false;
        }
        x--;
        y--;
    }

    x=i;
    y=j;
    while(x>=0 && y<chess[i].size()){
        if(chess[x][y]=='Q'){
            return false;
        }
        x--;
        y++;
    }

    return true;
}


void n_queen(vector<vector<char>> &chess, int i){
    if(i==chess.size()){
        printChess(chess);
        return;
    }

    for(int j=0; i<chess[i].size(); j++){
        if(safe(chess, i, j)){
            chess[i][j]='Q';
        }
        n_queen(chess, i+1);
        chess[i][j]='.';
    }
}

int main()
{

    int n=4;
    vector<char> temp(n,'.');
    vector<vector<char>> chess(n,temp);
    n_queen(chess,0);


    
    #ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms/n";
    #endif
    return 0;
}