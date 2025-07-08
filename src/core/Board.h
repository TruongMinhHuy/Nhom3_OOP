#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "pieces/Piece.h"
#include <array>
#include <memory>
#include <vector>

/**
 * @brief Represents the chess board and manages piece positions
 * 
 * The Board class handles the 8x8 chess board, piece placement,
 * move validation, and game state queries.
 */
class Board {
private:
    /// 8x8 grid of pieces (nullptr for empty squares)
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board_;
    
    /// Track last move for en passant
    Move lastMove_;
    bool hasLastMove_;
    
    /// Castle rights tracking
    bool whiteKingSideCastle_;
    bool whiteQueenSideCastle_;
    bool blackKingSideCastle_;
    bool blackQueenSideCastle_;

public:
    /**
     * @brief Constructor - initializes empty board
     */
    Board();
    
    /**
     * @brief Copy constructor
     */
    Board(const Board& other);
    
    /**
     * @brief Assignment operator
     */
    Board& operator=(const Board& other);
    
    /**
     * @brief Destructor
     */
    ~Board() = default;
    
    /**
     * @brief Initialize board with starting chess position
     */
    void setupInitialPosition();
    
    /**
     * @brief Get piece at specific position
     * @param position Board position
     * @return Pointer to piece or nullptr if empty
     */
    Piece* getPieceAt(Position position) const;
    
    /**
     * @brief Place piece at specific position
     * @param piece Unique pointer to piece
     * @param position Target position
     */
    void setPieceAt(std::unique_ptr<Piece> piece, Position position);
    
    /**
     * @brief Remove piece from position
     * @param position Position to clear
     * @return Unique pointer to removed piece
     */
    std::unique_ptr<Piece> removePieceAt(Position position);
    
    /**
     * @brief Move piece from one position to another
     * @param from Source position
     * @param to Destination position
     * @return True if move was successful
     */
    bool movePiece(Position from, Position to);
    
    /**
     * @brief Check if position is empty
     * @param position Position to check
     * @return True if no piece at position
     */
    bool isEmpty(Position position) const;
    
    /**
     * @brief Check if position contains piece of specific color
     * @param position Position to check
     * @param color Color to check for
     * @return True if piece of specified color is at position
     */
    bool hasPieceOfColor(Position position, Color color) const;
    
    /**
     * @brief Find king of specified color
     * @param color King color to find
     * @return Position of king
     */
    Position findKing(Color color) const;
    
    /**
     * @brief Get all pieces of specified color
     * @param color Piece color
     * @return Vector of positions with pieces of specified color
     */
    std::vector<Position> getPiecesOfColor(Color color) const;
    
    /**
     * @brief Check if king of specified color is in check
     * @param color King color
     * @return True if king is in check
     */
    bool isKingInCheck(Color color) const;
    
    /**
     * @brief Check if position is under attack by specified color
     * @param position Position to check
     * @param attackingColor Color of attacking pieces
     * @return True if position is under attack
     */
    bool isPositionUnderAttack(Position position, Color attackingColor) const;
    
    /**
     * @brief Get all legal moves for specified color
     * @param color Player color
     * @return Vector of all legal moves
     */
    std::vector<Move> getAllLegalMoves(Color color) const;
    
    /**
     * @brief Check if move is legal
     * @param move Move to validate
     * @return True if move is legal
     */
    bool isMoveLegal(const Move& move) const;
    
    /**
     * @brief Make a temporary move and check resulting board state
     * @param move Move to test
     * @return Board state after move
     */
    Board makeTemporaryMove(const Move& move) const;
    
    /**
     * @brief Get last move made (for en passant)
     * @return Last move or invalid move if none
     */
    Move getLastMove() const { return hasLastMove_ ? lastMove_ : Move(Position(-1, -1), Position(-1, -1)); }
    
    /**
     * @brief Check if there was a last move
     * @return True if last move exists
     */
    bool hasLastMove() const { return hasLastMove_; }
    
    /**
     * @brief Set last move (for en passant tracking)
     * @param move Last move made
     */
    void setLastMove(const Move& move) { lastMove_ = move; hasLastMove_ = true; }
    
    /**
     * @brief Check castling rights
     * @param color Player color
     * @param kingSide True for kingside, false for queenside
     * @return True if castling is still possible
     */
    bool canCastle(Color color, bool kingSide) const;
    
    /**
     * @brief Update castling rights after piece move
     * @param from Source position
     * @param to Destination position
     */
    void updateCastlingRights(Position from, Position to);
    
    /**
     * @brief Display board state (for debugging)
     */
    void printBoard() const;

private:
    /**
     * @brief Create piece of specified type
     * @param type Piece type character
     * @param color Piece color
     * @param position Piece position
     * @return Unique pointer to created piece
     */
    std::unique_ptr<Piece> createPiece(char type, Color color, Position position) const;
    
    /**
     * @brief Check if position is within board bounds
     * @param position Position to validate
     * @return True if position is valid
     */
    bool isValidPosition(Position position) const;
    
    /**
     * @brief Deep copy board state
     * @param other Board to copy from
     */
    void copyBoard(const Board& other);
};

#endif // CHESS_BOARD_H