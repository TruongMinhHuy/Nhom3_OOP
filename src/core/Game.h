#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "Player.h"
#include <memory>
#include <vector>
#include <stack>

/**
 * @brief Game result enumeration
 */
enum class GameResult {
    ONGOING,
    WHITE_WINS,
    BLACK_WINS,
    DRAW_STALEMATE,
    DRAW_INSUFFICIENT_MATERIAL,
    DRAW_THREEFOLD_REPETITION,
    DRAW_FIFTY_MOVE_RULE,
    DRAW_AGREEMENT,
    WHITE_TIMEOUT,
    BLACK_TIMEOUT
};

/**
 * @brief Represents game state at a point in time
 */
struct GameState {
    Board board;
    Player whitePlayer;
    Player blackPlayer;
    Color currentPlayer;
    int moveNumber;
    int halfMoveClock;  // For 50-move rule
    
    GameState(const Board& b, const Player& white, const Player& black, 
              Color current, int moveNum, int halfMoves)
        : board(b), whitePlayer(white), blackPlayer(black), 
          currentPlayer(current), moveNumber(moveNum), halfMoveClock(halfMoves) {}
};

/**
 * @brief Main game controller class
 * 
 * The Game class manages the overall chess game flow, rules enforcement,
 * move validation, and game state.
 */
class Game {
private:
    Board board_;                           ///< Current board state
    std::unique_ptr<Player> whitePlayer_;   ///< White player
    std::unique_ptr<Player> blackPlayer_;   ///< Black player
    Color currentPlayer_;                   ///< Current player's turn
    GameResult result_;                     ///< Current game result
    
    int moveNumber_;                        ///< Current move number
    int halfMoveClock_;                     ///< Moves since last capture/pawn move
    
    std::vector<Move> moveHistory_;         ///< History of all moves
    std::stack<GameState> gameStates_;      ///< Stack for undo functionality
    
    bool gameStarted_;                      ///< True if game has started
    bool gameOver_;                         ///< True if game is finished
    
    // Game settings
    bool allowUndo_;                        ///< Allow undo moves
    bool timeLimitEnabled_;                 ///< Enable time control
    
public:
    /**
     * @brief Constructor
     */
    Game();
    
    /**
     * @brief Destructor
     */
    ~Game() = default;
    
    /**
     * @brief Initialize new game with players
     * @param whiteName White player name
     * @param blackName Black player name
     * @param whiteIsHuman True if white is human
     * @param blackIsHuman True if black is human
     * @param timeLimit Time limit per player in seconds
     */
    void initializeGame(const std::string& whiteName, const std::string& blackName,
                       bool whiteIsHuman = true, bool blackIsHuman = true,
                       int timeLimit = 1800);
    
    /**
     * @brief Start the game
     */
    void start();
    
    /**
     * @brief Make a move
     * @param move Move to execute
     * @return True if move was successful
     */
    bool makeMove(const Move& move);
    
    /**
     * @brief Make a move using algebraic notation
     * @param moveStr Move in algebraic notation (e.g., "e4", "Nf3")
     * @return True if move was successful
     */
    bool makeMove(const std::string& moveStr);
    
    /**
     * @brief Undo last move
     * @return True if undo was successful
     */
    bool undoLastMove();
    
    /**
     * @brief Check if game is over
     * @return True if game has ended
     */
    bool isGameOver() const { return gameOver_; }
    
    /**
     * @brief Get current game result
     * @return Game result
     */
    GameResult getResult() const { return result_; }
    
    /**
     * @brief Get current board state
     * @return Reference to board
     */
    const Board& getBoard() const { return board_; }
    
    /**
     * @brief Get current player
     * @return Current player color
     */
    Color getCurrentPlayer() const { return currentPlayer_; }
    
    /**
     * @brief Get white player
     * @return Reference to white player
     */
    const Player& getWhitePlayer() const { return *whitePlayer_; }
    
    /**
     * @brief Get black player
     * @return Reference to black player
     */
    const Player& getBlackPlayer() const { return *blackPlayer_; }
    
    /**
     * @brief Get current move number
     * @return Move number
     */
    int getMoveNumber() const { return moveNumber_; }
    
    /**
     * @brief Get move history
     * @return Vector of all moves played
     */
    const std::vector<Move>& getMoveHistory() const { return moveHistory_; }
    
    /**
     * @brief Get all legal moves for current player
     * @return Vector of legal moves
     */
    std::vector<Move> getLegalMoves() const;
    
    /**
     * @brief Check if current player is in check
     * @return True if in check
     */
    bool isCurrentPlayerInCheck() const;
    
    /**
     * @brief Check if current player is in checkmate
     * @return True if in checkmate
     */
    bool isCheckmate() const;
    
    /**
     * @brief Check if game is in stalemate
     * @return True if stalemate
     */
    bool isStalemate() const;
    
    /**
     * @brief Check for draw conditions
     * @return True if game should be drawn
     */
    bool isDraw() const;
    
    /**
     * @brief Offer draw to opponent
     * @return True if draw was accepted
     */
    bool offerDraw();
    
    /**
     * @brief Resign current player
     */
    void resign();
    
    /**
     * @brief Convert move to algebraic notation
     * @param move Move to convert
     * @return Algebraic notation string
     */
    std::string moveToAlgebraic(const Move& move) const;
    
    /**
     * @brief Parse algebraic notation to move
     * @param algebraic Algebraic notation string
     * @return Parsed move
     */
    Move parseAlgebraicNotation(const std::string& algebraic) const;
    
    /**
     * @brief Get game state as FEN string
     * @return FEN notation string
     */
    std::string getFEN() const;
    
    /**
     * @brief Load game state from FEN string
     * @param fen FEN notation string
     * @return True if loading was successful
     */
    bool loadFromFEN(const std::string& fen);
    
    /**
     * @brief Save game to PGN format
     * @return PGN string
     */
    std::string toPGN() const;
    
    /**
     * @brief Load game from PGN format
     * @param pgn PGN string
     * @return True if loading was successful
     */
    bool loadFromPGN(const std::string& pgn);
    
    /**
     * @brief Enable/disable undo functionality
     * @param allow True to allow undo
     */
    void setAllowUndo(bool allow) { allowUndo_ = allow; }
    
    /**
     * @brief Enable/disable time control
     * @param enable True to enable time control
     */
    void setTimeControl(bool enable) { timeLimitEnabled_ = enable; }

private:
    /**
     * @brief Switch to next player's turn
     */
    void switchPlayer();
    
    /**
     * @brief Update game state after move
     * @param move Move that was made
     */
    void updateGameState(const Move& move);
    
    /**
     * @brief Check for game end conditions
     */
    void checkGameEnd();
    
    /**
     * @brief Save current game state for undo
     */
    void saveGameState();
    
    /**
     * @brief Check for threefold repetition
     * @return True if position has occurred three times
     */
    bool isThreefoldRepetition() const;
    
    /**
     * @brief Check for insufficient material
     * @return True if insufficient material to checkmate
     */
    bool isInsufficientMaterial() const;
    
    /**
     * @brief Check fifty-move rule
     * @return True if fifty moves without capture or pawn move
     */
    bool isFiftyMoveRule() const;
    
    /**
     * @brief Get current player object
     * @return Reference to current player
     */
    Player& getCurrentPlayerObj();
    
    /**
     * @brief Get opponent player object
     * @return Reference to opponent player
     */
    Player& getOpponentPlayerObj();
};

#endif // CHESS_GAME_H