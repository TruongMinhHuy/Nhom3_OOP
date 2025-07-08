#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include "pieces/Piece.h"
#include <string>
#include <chrono>

/**
 * @brief Represents a chess player
 * 
 * The Player class manages player information, timing, and statistics.
 */
class Player {
private:
    std::string name_;              ///< Player name
    Color color_;                   ///< Player color (WHITE or BLACK)
    std::chrono::seconds timeLeft_; ///< Remaining time for player
    int movesPlayed_;              ///< Number of moves played
    bool isHuman_;                 ///< True if human player, false if AI
    
    // Game statistics
    int capturedPieces_;           ///< Number of pieces captured
    int checksGiven_;              ///< Number of checks given to opponent
    bool isInCheck_;               ///< Current check status

public:
    /**
     * @brief Constructor for Player
     * @param name Player name
     * @param color Player color
     * @param isHuman True if human player
     * @param timeLimit Initial time limit in seconds
     */
    explicit Player(const std::string& name, Color color, bool isHuman = true, 
                   int timeLimit = 1800); // 30 minutes default
    
    /**
     * @brief Get player name
     * @return Player name
     */
    const std::string& getName() const { return name_; }
    
    /**
     * @brief Get player color
     * @return Player color
     */
    Color getColor() const { return color_; }
    
    /**
     * @brief Check if player is human
     * @return True if human player
     */
    bool isHuman() const { return isHuman_; }
    
    /**
     * @brief Get remaining time
     * @return Time left in seconds
     */
    std::chrono::seconds getTimeLeft() const { return timeLeft_; }
    
    /**
     * @brief Get number of moves played
     * @return Move count
     */
    int getMovesPlayed() const { return movesPlayed_; }
    
    /**
     * @brief Get number of pieces captured
     * @return Captured pieces count
     */
    int getCapturedPieces() const { return capturedPieces_; }
    
    /**
     * @brief Get number of checks given
     * @return Checks given count
     */
    int getChecksGiven() const { return checksGiven_; }
    
    /**
     * @brief Check if player is currently in check
     * @return True if in check
     */
    bool isCurrentlyInCheck() const { return isInCheck_; }
    
    /**
     * @brief Set player name
     * @param name New player name
     */
    void setName(const std::string& name) { name_ = name; }
    
    /**
     * @brief Set human/AI status
     * @param isHuman True for human, false for AI
     */
    void setHumanStatus(bool isHuman) { isHuman_ = isHuman; }
    
    /**
     * @brief Add time to player's clock
     * @param seconds Time to add
     */
    void addTime(int seconds) { timeLeft_ += std::chrono::seconds(seconds); }
    
    /**
     * @brief Subtract time from player's clock
     * @param seconds Time to subtract
     */
    void subtractTime(int seconds) { 
        timeLeft_ -= std::chrono::seconds(seconds);
        if (timeLeft_ < std::chrono::seconds(0)) {
            timeLeft_ = std::chrono::seconds(0);
        }
    }
    
    /**
     * @brief Set remaining time
     * @param seconds New time limit
     */
    void setTimeLeft(int seconds) { timeLeft_ = std::chrono::seconds(seconds); }
    
    /**
     * @brief Increment move counter
     */
    void incrementMoves() { movesPlayed_++; }
    
    /**
     * @brief Increment captured pieces counter
     */
    void incrementCaptured() { capturedPieces_++; }
    
    /**
     * @brief Increment checks given counter
     */
    void incrementChecks() { checksGiven_++; }
    
    /**
     * @brief Set check status
     * @param inCheck True if player is in check
     */
    void setCheckStatus(bool inCheck) { isInCheck_ = inCheck; }
    
    /**
     * @brief Check if player has time left
     * @return True if time remaining
     */
    bool hasTimeLeft() const { return timeLeft_ > std::chrono::seconds(0); }
    
    /**
     * @brief Get formatted time string
     * @return Time in MM:SS format
     */
    std::string getFormattedTime() const;
    
    /**
     * @brief Get player statistics summary
     * @return Formatted statistics string
     */
    std::string getStatistics() const;
    
    /**
     * @brief Reset player statistics
     */
    void resetStatistics();
    
    /**
     * @brief Get player color as string
     * @return "White" or "Black"
     */
    std::string getColorString() const;
    
    /**
     * @brief Check if two players are equal
     * @param other Other player to compare
     * @return True if players are the same
     */
    bool operator==(const Player& other) const;
    
    /**
     * @brief Check if two players are different
     * @param other Other player to compare
     * @return True if players are different
     */
    bool operator!=(const Player& other) const;
};

#endif // CHESS_PLAYER_H