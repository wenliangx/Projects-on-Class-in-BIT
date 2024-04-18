//
// Created by 18759 on 2024/4/15.
//

#include "gobang.h"

Gobang::Gobang() {
    chess = new ChessPiece*[SIZE];
    for(int i = 0;i<SIZE;++i){
        chess[i] = new ChessPiece[SIZE];
    }
    last_chess = nullptr;
    player1=new Player {1,0,0};
    player2=new Player {-1,0,0};

    InitGobang(1);
    chesspiece_num = 0;
}

Gobang::~Gobang() {
    for(int i = 0;i<SIZE;++i){
        delete chess[SIZE-i];
    }
    delete chess;
    if(!last_chess){
        delete last_chess;
    }
    delete player1;
    delete player2;
}

// TODO(W)这个函数将在构造函数和每次重新开始时调用，需要将所有的变量和状态初始化
void Gobang::InitGobang(int a) {
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            chess[i][j].if_last = false;
            chess[i][j].state = empty;
        }
    }
    last_chess = nullptr;
    InitPlayer(a);
}

// TODO(W)这个函数用于初始化玩家，只在InitGobang中被调用,
///<a,由玩家1输入选择，正数为黑子，其余为白子
void Gobang::InitPlayer(int a) {
    if(a){
        player1->color=-1;
        player1->first=1;
        player2->color=1;
        player2->first=0;
    }
    else{
        player1->color=1;
        player1->first=0;
        player2->color=-1;
        player2->first=1;
    }
}

// TODO(Z)这个函数是落子的函数，每次落子需要改变相应棋子的状态并调用判断输赢和棋子全满的函数，两个参数分别是行和列（0-14)。如果平局则需要调用Replay函数
void Gobang::Move(int, int) {

}

// TODO(Z)这个函数用于判断输赢，在每次落子后会被调用。如果有一方赢了，则需要改变类内的变量作为标志（可以添加在类内，也可以添加在player中）
void Gobang::Win() {

}

//TODO(Z)这个函数用于判断是否下满
bool Gobang::Full() {

}

ChessPiece**Gobang::GetChess() {
    return chess;
}

//TODO(W)这个函数用于记录总手数和下一步该谁下，可以向类内或player添加属性
void Gobang::Record() {
    GetPieceNum();
    if((chesspiece_num%2==0&&player1->color==1)||(chesspiece_num%2==1&&player1->color==-1)){
        player1->first=false;
        player2->first=true;
      }else {
        player1->first=true;
        player2->first=false;
    }
}

// TODO()这个函数用于重开游戏，会相应调用Init函数
void Gobang::Replay() {

}

//这个函数用于统计棋盘上棋子个数，记录到变量chesspiece_num
void Gobang::GetPieceNum(){
    int num=0;
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            if(!chess[i][j].state)++num;
        }
    }
    chesspiece_num=num;
}

Player* Gobang::GetPlayer1() {
    return player1;
}
