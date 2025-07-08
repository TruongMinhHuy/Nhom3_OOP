#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

/**
 * @brief Represents a King piece in chess
 * 
 * The King is the most important piece. It can move one square in any
 * direction (horizontal, vertical, or diagonal). The King is also involved
 * in the special move called castling.
 */
class King : public Piece {
public:
    /**
     * @brief Constructor for King
     * @param color The color of the king
     * @param position Initial position of the king
     */
    explicit King(Color color, Position position);
    
    /**
     * @brief Get all legal moves for this king
     * @param board Current board state
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves(const Board& board) const override;
    
    /**
     * @brief Check if king can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    bool canMoveTo(Position target, const Board& board) const override;
    
    /**
     * @brief Get piece symbol
     * @return 'K' for white king, 'k' for black king
     */
    char getSymbol() const override;
    
    /**
     * @brief Create a copy of this king
     * @return Unique pointer to king copy
     */
    std::unique_ptr<Piece> clone() const override;
    
    /**
     * @brief Check if king is currently in check
     * @param board Current board state
     * @return True if king is in check
     */
    bool isInCheck(const Board& board) const;
    
    /**
     * @brief Check if king would be in check after moving to target
     * @param target Target position
     * @param board Current board state
     * @return True if move would put king in check
     */
    bool wouldBeInCheckAt(Position target, const Board& board) const;
    
    /**
     * @brief Check if castling is possible
     * @param board Current board state
     * @param kingSide True for kingside castling, false for queenside
     * @return True if castling is legal
     */
    bool canCastle(const Board& board, bool kingSide) const;

private:
    /**
     * @brief Get all positions one square away from current position
     * @return Vector of adjacent positions (may include invalid ones)
     */
    std::vector<Position> getAdjacentPositions() const;
    
    /**
     * @brief Check if move is exactly one square away
     * @param target Target position
     * @return True if move is one square in any direction
     */
    bool isOneSquareMove(Position target) const;
    
    /**
     * @brief Check if position is under attack by enemy pieces
     * @param position Position to check
     * @param board Current board state
     * @return True if position is under attack
     */
    bool isPositionUnderAttack(Position position, const Board& board) const;
    
    /**
     * @brief Get the castling rook position
     * @param kingSide True for kingside, false for queenside
     * @return Position of the rook involved in castling
     */
    Position getCastlingRookPosition(bool kingSide) const;
    
    /**
     * @brief Check if castling path is clear and safe
     * @param board Current board state
     * @param kingSide True for kingside, false for queenside
     * @return True if castling path is valid
     */
    bool isCastlingPathValid(const Board& board, bool kingSide) const;
};

#endif // CHESS_KING_H