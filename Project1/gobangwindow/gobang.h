/*!
 * @brief 实现棋盘 包括对于局势的记录以及胜负判断
 */

#ifndef PROJECT1_GOBANG_H
#define PROJECT1_GOBANG_H

#include <QImage>
#include <QLabel>
#include "string"


#define SIZE 15 ///< 棋盘大小
#define BLACK (-1)
#define EMPTY 0
#define WHITE 1


/*!
 * @brief 棋子
 * @param state 该棋子的状态(事实上把没下也算了一种状态）
 * @param if_last 这个棋子是不是最后下的
 */
typedef struct {
    int state;
    bool if_last;
} ChessPiece;

/*!
 * @brief 玩家信息
 * @param id 玩家ID,用大于0小于0区分就行
 * @param color 执子颜色 最好和enum ChessState那里保持一致
 * @param first 是否下一个落子
 */
typedef struct {
    int id;
    int color;
    bool first;
    QImage chess;
} Player;

/*!
 * @brief 棋盘
 * @param chess 采用线性表结构 记录每个点的状态
 * @param last_chess 指向最后一次落的子
 * @param player1 玩家1
 * @param player2 玩家2
 * @param chesspiece_num 记录棋盘上棋子数目
 */
class Gobang{
private:
    ChessPiece** chess;
    ChessPiece* last_chess;
    Player* player1;
    Player* player2;
    int chesspiece_num;
    int winner;
public:
    Gobang();
    Gobang(Gobang&)=delete;
    ~Gobang();

    void InitGobang(int);
    void InitPlayer(int);
    ChessPiece* Move(int ,int);
    void Win(int, int);
    [[nodiscard]] bool Full() const;
    ChessPiece** GetChess();
    void Record();
    void Replay();
    [[nodiscard]] int GetPieceNum()const;
    Player* GetPlayer1();
    [[nodiscard]] ChessPiece* GetLastChessPiece()const;
    [[nodiscard]] ChessPiece* GetChessPiece(int, int)const;
    [[nodiscard]] int GetWinner()const;
    void SetWinner(int);

};


#endif //PROJECT1_GOBANG_H
