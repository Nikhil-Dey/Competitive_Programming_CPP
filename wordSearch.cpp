#include<bits/stdc++.h>
using namespace std;



int xMoves[] = {0,0,1,-1};
int yMoves[] = {1,-1,0,0};


bool isSafe(vector<vector<char>> &board, string word, vector<vector<bool>>& visited,int index, int x, int y, const int &R, const int &C){
    return (x >= 0 && x < R && y >= 0 && y < C && (word[index] == board[x][y]) && !(visited[x][y]));
}



bool exist(vector<vector<char>> &board, string word, vector<vector<bool>>& visited,int index, int x, int y, const int &R, const int &C){
    if(index >= word.length()){
        return true;
    }
    
    visited[x][y] = true;
    
    for(int i = 0; i<4; i++){
        if(isSafe(board, word, visited, index + 1, x + xMoves[i], y + yMoves[i], R, C)){
            if(exist(board, word, visited, index + 1, x + xMoves[i], y + yMoves[i], R, C))
                return true;
        }
    }
    
    visited[x][y] = false;
    
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word == "")
        return true;
    
    int R = board.size();
    if(R == 0)
        return false;
    
    int C = board[0].size();
    vector<vector<bool>> visited(R,vector<bool>(C, false));
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(board[i][j] == word[0]){
                if(exist(board, word, visited, 1, i, j, R, C )){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>board[i][j];
        }
    }
    string word;
    cin>>word;
    if(exist(board, word)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
}