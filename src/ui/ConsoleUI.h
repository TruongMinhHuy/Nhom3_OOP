#ifndef CHESS_CONSOLE_UI_H
#define CHESS_CONSOLE_UI_H

#include "core/Game.h"
#include "core/Board.h"
#include "core/Player.h"
#include <string>
#include <iostream>

/**
 * @brief Console-based user interface for the chess game
 * 
 * The ConsoleUI class provides a text-based interface for playing chess,
 * displaying the board, getting user input, and showing game information.
 */
class ConsoleUI {
private:
    bool useUnicodeChess_;    ///< Use Unicode chess symbols
    bool showCoordinates_;    ///< Show board coordinates
    bool colorOutput_;        ///< Use colored output (ANSI codes)
    
    // ANSI color codes
    static const std::string RESET;
    static const std::string BOLD;
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string BLUE;
    static const std::string MAGENTA;
    static const std::string CYAN;
    static const std::string WHITE;
    static const std::string BG_WHITE;
    static const std::string BG_BLACK;

public:
    /**
     * @brief Constructor
     * @param useUnicode Use Unicode chess symbols
     * @param showCoords Show board coordinates
     * @param useColor Use colored output
     */
    explicit ConsoleUI(bool useUnicode = true, bool showCoords = true, bool useColor = true);
    
    /**
     * @brief Display welcome message and game title
     */
    void displayWelcome() const;
    
    /**
     * @brief Display game rules and instructions
     */
    void displayInstructions() const;
    
    /**
     * @brief Display the chess board
     * @param board Board to display
     * @param highlightMoves Optional vector of moves to highlight
     */
    void displayBoard(const Board& board, const std::vector<Move>& highlightMoves = {}) const;
    
    /**
     * @brief Display current game status
     * @param game Current game state
     */
    void displayGameStatus(const Game& game) const;
    
    /**
     * @brief Display player information
     * @param player Player to display
     * @param isCurrentPlayer True if this is the current player
     */
    void displayPlayerInfo(const Player& player, bool isCurrentPlayer = false) const;
    
    /**
     * @brief Display move history
     * @param moves Vector of moves to display
     * @param currentMove Current move number (-1 for all)
     */
    void displayMoveHistory(const std::vector<Move>& moves, int currentMove = -1) const;
    
    /**
     * @brief Get player move input
     * @param player Current player
     * @return Move string entered by player
     */
    std::string getPlayerMove(const Player& player) const;
    
    /**
     * @brief Get player name input
     * @param color Player color
     * @return Player name
     */
    std::string getPlayerName(Color color) const;
    
    /**
     * @brief Get game setup options from user
     * @param whiteName Output parameter for white player name
     * @param blackName Output parameter for black player name
     * @param whiteIsHuman Output parameter for white player type
     * @param blackIsHuman Output parameter for black player type
     * @param timeLimit Output parameter for time limit
     */
    void getGameSetup(std::string& whiteName, std::string& blackName,
                     bool& whiteIsHuman, bool& blackIsHuman, int& timeLimit) const;
    
    /**
     * @brief Display game result
     * @param result Game result
     * @param winner Winner player (if applicable)
     */
    void displayGameResult(GameResult result, const Player* winner = nullptr) const;
    
    /**
     * @brief Display check notification
     * @param player Player in check
     */
    void displayCheck(const Player& player) const;
    
    /**
     * @brief Display checkmate notification
     * @param winner Winning player
     * @param loser Losing player
     */
    void displayCheckmate(const Player& winner, const Player& loser) const;
    
    /**
     * @brief Display stalemate notification
     */
    void displayStalemate() const;
    
    /**
     * @brief Display draw notification
     * @param reason Draw reason
     */
    void displayDraw(const std::string& reason) const;
    
    /**
     * @brief Display error message
     * @param message Error message
     */
    void displayError(const std::string& message) const;
    
    /**
     * @brief Display information message
     * @param message Information message
     */
    void displayInfo(const std::string& message) const;
    
    /**
     * @brief Display legal moves for a piece
     * @param moves Vector of legal moves
     * @param piece Piece name/type
     */
    void displayLegalMoves(const std::vector<Move>& moves, const std::string& piece) const;
    
    /**
     * @brief Ask yes/no question
     * @param question Question to ask
     * @return True if yes, false if no
     */
    bool askYesNo(const std::string& question) const;
    
    /**
     * @brief Ask user to choose from options
     * @param question Question to ask
     * @param options Vector of options
     * @return Index of chosen option
     */
    int askChoice(const std::string& question, const std::vector<std::string>& options) const;
    
    /**
     * @brief Wait for user to press Enter
     * @param message Optional message to display
     */
    void waitForEnter(const std::string& message = "Press Enter to continue...") const;
    
    /**
     * @brief Clear the console screen
     */
    void clearScreen() const;
    
    /**
     * @brief Set Unicode chess symbols usage
     * @param use True to use Unicode symbols
     */
    void setUnicodeChess(bool use) { useUnicodeChess_ = use; }
    
    /**
     * @brief Set coordinate display
     * @param show True to show coordinates
     */
    void setShowCoordinates(bool show) { showCoordinates_ = show; }
    
    /**
     * @brief Set colored output
     * @param use True to use colors
     */
    void setColorOutput(bool use) { colorOutput_ = use; }
    
    /**
     * @brief Convert position to chess notation (e.g., a1, h8)
     * @param pos Position to convert
     * @return Chess notation string
     */
    static std::string positionToChessNotation(Position pos);
    
    /**
     * @brief Parse chess notation to position
     * @param notation Chess notation (e.g., "a1", "h8")
     * @return Position object
     */
    static Position parseChessNotation(const std::string& notation);

private:
    /**
     * @brief Get piece symbol for display
     * @param piece Piece to get symbol for
     * @return Display symbol
     */
    std::string getPieceSymbol(const Piece* piece) const;
    
    /**
     * @brief Get colored text
     * @param text Text to color
     * @param color Color code
     * @return Colored text string
     */
    std::string getColoredText(const std::string& text, const std::string& color) const;
    
    /**
     * @brief Check if position should be highlighted
     * @param pos Position to check
     * @param highlightMoves Moves to highlight
     * @return True if position should be highlighted
     */
    bool shouldHighlight(Position pos, const std::vector<Move>& highlightMoves) const;
    
    /**
     * @brief Get square color for display
     * @param row Board row
     * @param col Board column
     * @param isHighlighted True if square is highlighted
     * @return Background color string
     */
    std::string getSquareColor(int row, int col, bool isHighlighted = false) const;
    
    /**
     * @brief Display board header with column labels
     */
    void displayBoardHeader() const;
    
    /**
     * @brief Display board footer with column labels
     */
    void displayBoardFooter() const;
    
    /**
     * @brief Display a single board row
     * @param board Board to display
     * @param row Row number
     * @param highlightMoves Moves to highlight
     */
    void displayBoardRow(const Board& board, int row, const std::vector<Move>& highlightMoves) const;
    
    /**
     * @brief Get user input with prompt
     * @param prompt Prompt message
     * @return User input string
     */
    std::string getUserInput(const std::string& prompt) const;
    
    /**
     * @brief Validate move input format
     * @param input Move input string
     * @return True if format is valid
     */
    bool isValidMoveFormat(const std::string& input) const;
    
    /**
     * @brief Format time for display
     * @param seconds Time in seconds
     * @return Formatted time string
     */
    std::string formatTime(int seconds) const;
};

#endif // CHESS_CONSOLE_UI_H