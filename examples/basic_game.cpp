#include "core/Game.h"
#include "ui/ConsoleUI.h"
#include <iostream>

/**
 * @file basic_game.cpp
 * @brief Basic chess game example
 * 
 * This example demonstrates the fundamental usage of the Chess Game OOP framework.
 * It shows how to:
 * - Initialize a new game
 * - Set up players
 * - Run a basic game loop
 * - Handle user input and display output
 */

int main() {
    try {
        std::cout << "=== Chess Game OOP - Basic Example ===\n\n";
        
        // Create game instance and console UI
        Game chessGame;
        ConsoleUI ui;
        
        // Display welcome message
        ui.displayWelcome();
        ui.displayInstructions();
        
        // Get game setup from user
        std::string whiteName, blackName;
        bool whiteIsHuman, blackIsHuman;
        int timeLimit;
        
        ui.getGameSetup(whiteName, blackName, whiteIsHuman, blackIsHuman, timeLimit);
        
        // Initialize the game with user preferences
        chessGame.initializeGame(whiteName, blackName, whiteIsHuman, blackIsHuman, timeLimit);
        
        // Start the game
        chessGame.start();
        ui.displayInfo("Game started! White moves first.");
        
        // Main game loop
        while (!chessGame.isGameOver()) {
            // Clear screen for better readability
            ui.clearScreen();
            
            // Display current game state
            ui.displayBoard(chessGame.getBoard());
            ui.displayGameStatus(chessGame);
            
            // Get current player
            const Player& currentPlayer = (chessGame.getCurrentPlayer() == Color::WHITE) 
                                        ? chessGame.getWhitePlayer() 
                                        : chessGame.getBlackPlayer();
            
            // Check if current player is in check
            if (chessGame.isCurrentPlayerInCheck()) {
                ui.displayCheck(currentPlayer);
            }
            
            // Get and validate player move
            std::string moveInput;
            bool validMove = false;
            
            while (!validMove) {
                moveInput = ui.getPlayerMove(currentPlayer);
                
                // Handle special commands
                if (moveInput == "quit" || moveInput == "exit") {
                    ui.displayInfo("Game terminated by user.");
                    return 0;
                }
                
                if (moveInput == "help") {
                    ui.displayInstructions();
                    continue;
                }
                
                if (moveInput == "moves") {
                    auto legalMoves = chessGame.getLegalMoves();
                    ui.displayLegalMoves(legalMoves, currentPlayer.getName());
                    continue;
                }
                
                if (moveInput == "undo") {
                    if (chessGame.undoLastMove()) {
                        ui.displayInfo("Move undone successfully.");
                        break;  // Skip to next iteration
                    } else {
                        ui.displayError("Cannot undo move.");
                        continue;
                    }
                }
                
                if (moveInput == "resign") {
                    chessGame.resign();
                    break;  // Game over
                }
                
                // Try to make the move
                validMove = chessGame.makeMove(moveInput);
                
                if (!validMove) {
                    ui.displayError("Invalid move! Please try again.");
                    ui.displayInfo("Format: e2e4, Nf3, O-O, etc. Type 'help' for more info.");
                }
            }
            
            // Check for special game conditions after move
            if (chessGame.isCheckmate()) {
                const Player& winner = (chessGame.getCurrentPlayer() == Color::WHITE) 
                                     ? chessGame.getBlackPlayer() 
                                     : chessGame.getWhitePlayer();
                const Player& loser = (chessGame.getCurrentPlayer() == Color::WHITE) 
                                    ? chessGame.getWhitePlayer() 
                                    : chessGame.getBlackPlayer();
                ui.displayCheckmate(winner, loser);
            } else if (chessGame.isStalemate()) {
                ui.displayStalemate();
            } else if (chessGame.isDraw()) {
                ui.displayDraw("Draw by rule");
            }
        }
        
        // Game finished - display final results
        ui.clearScreen();
        ui.displayBoard(chessGame.getBoard());
        
        const Player* winner = nullptr;
        switch (chessGame.getResult()) {
            case GameResult::WHITE_WINS:
                winner = &chessGame.getWhitePlayer();
                break;
            case GameResult::BLACK_WINS:
                winner = &chessGame.getBlackPlayer();
                break;
            default:
                break;
        }
        
        ui.displayGameResult(chessGame.getResult(), winner);
        
        // Display final statistics
        ui.displayInfo("\n=== Final Statistics ===");
        ui.displayPlayerInfo(chessGame.getWhitePlayer());
        ui.displayPlayerInfo(chessGame.getBlackPlayer());
        
        // Ask if user wants to save the game
        if (ui.askYesNo("Would you like to save the game?")) {
            std::string pgn = chessGame.toPGN();
            ui.displayInfo("Game in PGN format:");
            std::cout << pgn << std::endl;
        }
        
        ui.displayInfo("Thank you for playing!");
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}