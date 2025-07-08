#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

/**
 * @brief Represents a Pawn piece in chess
 * 
 * Pawns have special movement rules:
 * - Move forward one square normally
 * - Can move forward two squares on first move
 * - Capture diagonally forward
 * - En passant capture
 * - Promotion when reaching end of board
 */
class Pawn : public Piece {
private:
    bool canPromote_;       ///< True if pawn can be promoted

public:
    /**
     * @brief Constructor for Pawn
     * @param color The color of the pawn
     * @param position Initial position of the pawn
     */
    explicit Pawn(Color color, Position position);
    
    /**
     * @brief Get all legal moves for this pawn
     * @param board Current board state
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves(const Board& board) const override;
    
    /**
     * @brief Check if pawn can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    bool canMoveTo(Position target, const Board& board) const override;
    
    /**
     * @brief Get piece symbol
     * @return 'P' for white pawn, 'p' for black pawn
     */
    char getSymbol() const override;
    
    /**
     * @brief Create a copy of this pawn
     * @return Unique pointer to pawn copy
     */
    std::unique_ptr<Piece> clone() const override;
    
    /**
     * @brief Check if pawn can be promoted
     * @return True if promotion is possible
     */
    bool canBePromoted() const { return canPromote_; }
    
    /**
     * @brief Check if move is a double move (first move)
     * @param target Target position
     * @return True if it's a double move
     */
    bool isDoubleMove(Position target) const;
    
    /**
     * @brief Check if move is an en passant capture
     * @param target Target position
     * @param board Current board state
     * @return True if it's en passant
     */
    bool isEnPassant(Position target, const Board& board) const;

private:
    /**
     * @brief Get forward direction based on piece color
     * @return +1 for white (moving up), -1 for black (moving down)
     */
    int getForwardDirection() const;
    
    /**
     * @brief Check if pawn is at starting position
     * @return True if at starting position
     */
    bool isAtStartingPosition() const;
    
    /**
     * @brief Check if pawn can capture at target position
     * @param target Target position
     * @param board Current board state
     * @return True if capture is possible
     */
    bool canCaptureAt(Position target, const Board& board) const;
};

#endif // CHESS_PAWN_H