#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <vector>
#include <memory>

/**
 * @brief Represents piece colors in chess
 */
enum class Color {
    WHITE,
    BLACK
};

/**
 * @brief Represents a position on the chess board
 */
struct Position {
    int row;    ///< Row index (0-7)
    int col;    ///< Column index (0-7)
    
    Position(int r = 0, int c = 0) : row(r), col(c) {}
    
    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
    
    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
    
    /**
     * @brief Check if position is within board bounds
     */
    bool isValid() const {
        return row >= 0 && row < 8 && col >= 0 && col < 8;
    }
};

/**
 * @brief Represents a chess move
 */
struct Move {
    Position from;  ///< Source position
    Position to;    ///< Destination position
    
    Move(Position f, Position t) : from(f), to(t) {}
    
    bool operator==(const Move& other) const {
        return from == other.from && to == other.to;
    }
};

// Forward declarations
class Board;

/**
 * @brief Abstract base class for all chess pieces
 * 
 * This class defines the common interface and behavior for all chess pieces.
 * Each specific piece type inherits from this class and implements its own
 * movement logic.
 */
class Piece {
protected:
    Color color_;           ///< Piece color (WHITE or BLACK)
    Position position_;     ///< Current position on board
    bool hasMoved_;        ///< Track if piece has moved (for castling, pawn double move, etc.)

public:
    /**
     * @brief Constructor for Piece
     * @param color The color of the piece
     * @param position Initial position of the piece
     */
    explicit Piece(Color color, Position position);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Piece() = default;
    
    /**
     * @brief Get all legal moves for this piece
     * @param board Current board state
     * @return Vector of legal moves
     */
    virtual std::vector<Move> getLegalMoves(const Board& board) const = 0;
    
    /**
     * @brief Check if piece can move to target position
     * @param target Target position
     * @param board Current board state
     * @return True if move is legal
     */
    virtual bool canMoveTo(Position target, const Board& board) const = 0;
    
    /**
     * @brief Get piece type as character (for display)
     * @return Character representing piece type
     */
    virtual char getSymbol() const = 0;
    
    /**
     * @brief Create a copy of this piece
     * @return Unique pointer to piece copy
     */
    virtual std::unique_ptr<Piece> clone() const = 0;
    
    // Getters
    Color getColor() const { return color_; }
    Position getPosition() const { return position_; }
    bool hasMovedBefore() const { return hasMoved_; }
    
    // Setters
    void setPosition(Position newPosition) { position_ = newPosition; }
    void markAsMoved() { hasMoved_ = true; }
    
protected:
    /**
     * @brief Check if target position is occupied by enemy piece
     * @param target Target position
     * @param board Current board state
     * @return True if occupied by enemy
     */
    bool isEnemyAt(Position target, const Board& board) const;
    
    /**
     * @brief Check if target position is occupied by friendly piece
     * @param target Target position
     * @param board Current board state
     * @return True if occupied by friendly piece
     */
    bool isFriendlyAt(Position target, const Board& board) const;
    
    /**
     * @brief Check if target position is empty
     * @param target Target position
     * @param board Current board state
     * @return True if position is empty
     */
    bool isEmpty(Position target, const Board& board) const;
};

#endif // CHESS_PIECE_H