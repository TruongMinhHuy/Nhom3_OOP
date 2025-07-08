#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

/**
 * @brief Represents a Rook piece in chess
 * 
 * Rooks move horizontally and vertically any number of squares,
 * but cannot jump over other pieces. They are also involved in castling.
 */
class Rook : public Piece {
public:
    /**
     * @brief Constructor for Rook
     * @param color The color of the rook
     * @param position Initial position of the rook
     */
    explicit Rook(Color color, Position position);
    
    /**
     * @brief Get all legal moves for this rook
     * @param board Current board state
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves(const Board& board) const override;
    
    /**
     * @brief Check if rook can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    bool canMoveTo(Position target, const Board& board) const override;
    
    /**
     * @brief Get piece symbol
     * @return 'R' for white rook, 'r' for black rook
     */
    char getSymbol() const override;
    
    /**
     * @brief Create a copy of this rook
     * @return Unique pointer to rook copy
     */
    std::unique_ptr<Piece> clone() const override;

private:
    /**
     * @brief Get moves in a specific direction
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
     * @brief Check if move is horizontal or vertical
     * @param target Target position
     * @return True if move is straight line
     */
    bool isStraightLine(Position target) const;
};

#endif // CHESS_ROOK_H