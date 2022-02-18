#include<bits/stdc++.h>
using namespace std;

// W and B represents a white and black piece respectively
// P => Pawn
// R => Rook
// N => Knight
// B => Bishop
// Q => Queen
// K => King
// An empty cell is represented by two hyphens (--).

vector<vector<string>> chess((8,vector<string> (8)));
char color[] = {'B', 'W'};

char pieces[] = {'P','N','B', 'Q', 'K', 'B', 'N', 'R'};



void setChess(vector<vector<string>> chess){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            
        }
    }
}

void printChess(vector<vector<string>> chess){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    
    cout<<color[1]<<endl;

}