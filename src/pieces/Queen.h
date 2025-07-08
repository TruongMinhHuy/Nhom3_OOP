#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"

/**
 * @brief Represents a Queen piece in chess
 * 
 * The Queen is the most powerful piece, combining the movement of both
 * rook and bishop. It can move any number of squares horizontally,
 * vertically, or diagonally, but cannot jump over other pieces.
 */
class Queen : public Piece {
public:
    /**
     * @brief Constructor for Queen
     * @param color The color of the queen
     * @param position Initial position of the queen
     */
    explicit Queen(Color color, Position position);
    
    /**
     * @brief Get all legal moves for this queen
     * @param board Current board state
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves(const Board& board) const override;
    
    /**
     * @brief Check if queen can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    bool canMoveTo(Position target, const Board& board) const override;
    
    /**
     * @brief Get piece symbol
     * @return 'Q' for white queen, 'q' for black queen
     */
    char getSymbol() const override;
    
    /**
     * @brief Create a copy of this queen
     * @return Unique pointer to queen copy
     */
    std::unique_ptr<Piece> clone() const override;

private:
    /**
     * @brief Get moves in a specific direction (horizontal, vertical, or diagonal)
     * @param board Current board state
     * @param rowDir Row direction (-1, 0, or 1)
     * @param colDir Column direction (-1, 0, or 1)
     * @return Vector of moves in the specified direction
     */
    std::vector<Move> getMovesInDirection(const Board& board, int rowDir, int colDir) const;
    
    /**
     * @brief Check if path is clear to target position
     * @param target Target position
     * @param board Current board state
     * @return True if path is clear
     */
    bool isPathClear(Position target, const Board& board) const;
    
    /**
     * @brief Check if move is in a straight line or diagonal
     * @param target Target position
     * @return True if move is valid queen move
     */
    bool isValidQueenMove(Position target) const;
    
    /**
     * @brief Check if move is horizontal or vertical
     * @param target Target position
     * @return True if move is horizontal or vertical
     */
    bool isStraightLine(Position target) const;
    
    /**
     * @brief Check if move is diagonal
     * @param target Target position
     * @return True if move is diagonal
     */
    bool isDiagonalMove(Position target) const;
};

#endif // CHESS_QUEEN_H