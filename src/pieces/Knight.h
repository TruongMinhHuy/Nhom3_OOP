#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"

/**
 * @brief Represents a Knight piece in chess
 * 
 * Knights move in an L-shape: two squares in one direction and one square
 * perpendicular to that. Knights are the only pieces that can jump over
 * other pieces.
 */
class Knight : public Piece {
public:
    /**
     * @brief Constructor for Knight
     * @param color The color of the knight
     * @param position Initial position of the knight
     */
    explicit Knight(Color color, Position position);
    
    /**
     * @brief Get all legal moves for this knight
     * @param board Current board state
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves(const Board& board) const override;
    
    /**
     * @brief Check if knight can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    bool canMoveTo(Position target, const Board& board) const override;
    
    /**
     * @brief Get piece symbol
     * @return 'N' for white knight, 'n' for black knight
     */
    char getSymbol() const override;
    
    /**
     * @brief Create a copy of this knight
     * @return Unique pointer to knight copy
     */
    std::unique_ptr<Piece> clone() const override;

private:
    /**
     * @brief Check if move is a valid L-shape
     * @param target Target position
     * @return True if move forms valid L-shape
     */
    bool isValidLMove(Position target) const;
    
    /**
     * @brief Get all possible L-shaped moves from current position
     * @return Vector of all possible L-moves (may include invalid positions)
     */
    std::vector<Position> getAllPossibleLMoves() const;
};

#endif // CHESS_KNIGHT_H