//
//  main.cpp
//  2048
//
//  Created by Li Jiajie on 3/20/17.
//  Copyright © 2017 Li Jiajie. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

class ChessBoard {
    
public:
    
    ChessBoard(){
    // chessboard inintialize
        for(int i=0; i<4; i++){
            board[i] = 0;
        }
        
        int x1 = xrandom(4);
        int y1 = xrandom(4);
        int x2, y2;
        
        do {
            x2 = xrandom(4);
            y2 = xrandom(4);
        }while(x1!=x2 && y1!=y2);
        
        board[x1*4+y1] = 2;
        board[x2*4+y2] = 2;
        
    }
    
    void goWest() {
        for (int i=0; i<4; i++){
            align(1, -1, i);
        }
        
    }
    
    void goEast() {
        for (int i=0; i<4; i++) {
            align(1, 1, i);
        }
    }
    
    void goNorth() {
        for (int i=0; i<4; i++) {
            align(0, 1, i);
        }
    }
    
    void goSouth() {
        for (int i=0; i<4; i++) {
            align(0, -1, i);
        }
    }
    
    
    

    
private:
    
    int board[16];
    
    int xrandom(int x) {
    // return a random number between 0-x
        srand((unsigned)time(0));
        return rand() % x;
    }
    
    void align(int direction, int sex, int k){
        
        
        int ff[4]={0,0,0,0};
        int p = 0;
        int position;
        for (int i=0; i<4; i++) {
            position = k*(3*direction+1)+i*(-3*direction+4);
            if(board[position]) {
                ff[p] = board[position];
            }
        }
        
        int start = 3/2*(sex+1);
        int end = 3/2*(1-sex);
        
        for (int i = start; i!=end; i=i-sex){
            if (ff[i]==ff[i+sex]){
                ff[i] = 2*ff[i];
                ff[i+1]= 0;
                break;
            }
        }
        
        p = 0;
        
        int ifnil = 0;
        
        for (int i = start; i!=end; i=i-sex){
            position = k*(3*direction+1)+i*(-3*direction+4);
            
            
            if (!ifnil) {
                for (int j = p; p<4; p++){
                    if (j==3) {
                        ifnil = 1;
                    }
                    if (ff[j]) {
                        board[position] = ff[j];
                        p = j+1;
                        break;
                    }
                }
            }else{
                board[position] = 0;
            }

        }
        
        
    }
    
    void blink() {
        // TODO 空白处生成一个2
        
    }
    



    
};

int main() {
    
    ChessBoard cb;



    return 0;
}

