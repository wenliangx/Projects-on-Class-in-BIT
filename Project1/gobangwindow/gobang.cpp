#include "gobang.h"

Gobang::Gobang() {
    chess = new ChessPiece*[SIZE];
    for(int i = 0;i<SIZE;++i){
        chess[i] = new ChessPiece[SIZE];
    }
    last_chess = nullptr;
    player1=new Player {1,0,false};
    player2=new Player {-1,0,false};

    InitGobang(1);
    chesspiece_num = 0;
    winner = 0;
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
            chess[i][j].state = EMPTY;
        }
    }
    chesspiece_num = 0;
    winner = 0;
    last_chess = nullptr;
    InitPlayer(a);
}

// TODO(W)这个函数用于初始化玩家，只在InitGobang中被调用,
///<a,由玩家1输入选择，0为黑子，其余为白子
void Gobang::InitPlayer(int a) {
    if(a==-1){
        player1->color=-1;
        player1->first=true;
        player2->color=1;
        player2->first=false;
    }
    else{
        player1->color=1;
        player1->first=false;
        player2->color=-1;
        player2->first=true;
    }
}

// TODO(Z)这个函数是落子的函数，每次落子需要改变相应棋子的状态并调用判断输赢和棋子全满的函数，两个参数分别是行和列（0-14)。如果平局则需要调用Replay函数
ChessPiece* Gobang::Move(int row, int column) {
    if(player1->first==1){
        if(player1->color == 1) {chess[row][column].state=WHITE;}
        else {chess[row][column].state=BLACK;}
	 }else{
        if(player2->color == 1){ chess[row][column].state=WHITE;}
        else{ chess[row][column].state=BLACK;}
	 }
    last_chess = &chess[row][column];
    Record();
	Win(row,column);
    return &chess[row][column];
}

// TODO(Z)这个函数用于判断输赢，在每次落子后会被调用。如果有一方赢了，则需要改变类内的变量作为标志（可以添加在类内，也可以添加在player中）
void Gobang::Win(int row, int column) {
 int left_counter = 0,right_counter = 0,up_counter = 0,down_counter = 0;
 int left_up_counter = 0,right_down_counter = 0,left_down_counter = 0,right_up_counter=0;
	 for(int i=0;i<4&&row-i>0;++i){	     
		 if(chess[row-i-1][column].state!=chess[row][column].state){
		 	break;
		 }
		 ++left_counter; 
	 }
	 for(int i=0;i<4&&row+i+1<SIZE;++i){	     
		 if(chess[row+i+1][column].state!=chess[row][column].state){
		 	break;
		 }
		 ++right_counter; 
	 }
	 for(int i=0;i<4&&column+i+1<SIZE;++i){	     
		 if(chess[row][column+i+1].state!=chess[row][column].state){
		 	break;
		 }
		 ++up_counter; 
	 }
	 for(int i=0;i<4&&column-i>0;++i){	     
		 if(chess[row][column-i-1].state!=chess[row][column].state){
		 	break;
		 }
		 ++down_counter; 
	 }
	 for(int i=0;i<4&&row-i>0&&column+i+1<SIZE;++i){	     
		 if(chess[row-i-1][column+i+1].state!=chess[row][column].state){
		 	break;
		 }
		 ++left_up_counter; 
	 }
	  for(int i=0;i<4&&row+i+1<SIZE&&column-i>0;++i){	     
		 if(chess[row+i+1][column-i-1].state!=chess[row][column].state){
		 	break;
		 }
		 ++right_down_counter; 
	 }
	  for(int i=0;i<4&&row-i>0&&column-i>0;++i){	     
		 if(chess[row-i-1][column-i-1].state!=chess[row][column].state){
		 	break;
		 }
		 ++left_down_counter; 
	 }
	 for(int i=0;i<4&&row+i+1<SIZE&&column+i+1<SIZE;++i){	     
		 if(chess[row+i+1][column+i+1].state!=chess[row][column].state){
		 	break;
		 }
		 ++right_up_counter; 
	 }
	 if(left_counter+right_counter>=4||up_counter+down_counter>=4||left_up_counter+ right_down_counter>=4||left_down_counter+right_up_counter>=4){
         if((chess[row][column].state == BLACK && player1->color == -1)||(chess[row][column].state == WHITE && player1->color == 1)){
             winner = 1;
         }else{
             winner = 2;
         }

	 }
}

//TODO(Z)这个函数用于判断是否下满
bool Gobang::Full() const{
    if(chesspiece_num == SIZE*SIZE){
        return true;
    }
    return false;
}

ChessPiece**Gobang::GetChess() {
    return chess;
}

//TODO(W)这个函数用于记录总手数和下一步该谁下，可以向类内或player添加属性
void Gobang::Record() {
    ++chesspiece_num;
    bool temp = player1->first;
    player1->first = player2->first;
    player2->first = temp;
}

// TODO()这个函数用于重开游戏，会相应调用Init函数
void Gobang::Replay() {

}

//这个函数用于统计棋盘上棋子个数，记录到变量chesspiece_num
int Gobang::GetPieceNum()const{
    return chesspiece_num;
}

Player* Gobang::GetPlayer1() {
    return player1;
}

ChessPiece *Gobang::GetLastChessPiece() const {
    return last_chess;
}

ChessPiece *Gobang::GetChessPiece(int i, int j) const {
    return &chess[i][j];
}

int Gobang::GetWinner() const {
    return winner;
}

void Gobang::SetWinner(int w) {
    if(!winner && !Full()){
        winner = w;
    }
}
