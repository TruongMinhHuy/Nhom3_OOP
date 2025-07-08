#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

/**
 * @brief Represents a Bishop piece in chess
 * 
 * Bishops move diagonally any number of squares, but cannot jump over
 * other pieces. Each player starts with two bishops, one on light squares
 * and one on dark squares.
 */
class Bishop : public Piece {
public:
    /**
     * @brief Constructor for Bishop
     * @param color The color of the bishop
     * @param position Initial position of the bishop
     */
    explicit Bishop(Color color, Position position);
    
    /**
     * @brief Get all legal moves for this bishop
     * @param board Current board state
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves(const Board& board) const override;
    
    /**
     * @brief Check if bishop can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    bool canMoveTo(Position target, const Board& board) const override;
    
    /**
     * @brief Get piece symbol
     * @return 'B' for white bishop, 'b' for black bishop
     */
    char getSymbol() const override;
    
    /**
     * @brief Create a copy of this bishop
     * @return Unique pointer to bishop copy
     */
    std::unique_ptr<Piece> clone() const override;

private:
    /**
     * @brief Get moves in a specific diagonal direction
     * @param board Current board state
     * @param rowDir Row direction (-1 or 1)
     * @param colDir Column direction (-1 or 1)
     * @return Vector of moves in the specified diagonal direction
     */
    std::vector<Move> getMovesInDirection(const Board& board, int rowDir, int colDir) const;
    
    /**
     * @brief Check if path is clear to target position
     * @param target Target position
     * @param board Current board state
     * @return True if diagonal path is clear
     */
    bool isDiagonalPathClear(Position target, const Board& board) const;
    
    /**
     * @brief Check if move is diagonal
     * @param target Target position
     * @return True if move is diagonal
     */
    bool isDiagonalMove(Position target) const;
};

#endif // CHESS_BISHOP_H