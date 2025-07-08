# Chess Game Examples

This directory contains example code and usage scenarios for the Chess Game OOP project.

## 📚 Available Examples

### Basic Usage Examples
- [basic_game.cpp](basic_game.cpp) - Simple game setup and basic moves
- [piece_movement.cpp](piece_movement.cpp) - Working with individual pieces
- [board_operations.cpp](board_operations.cpp) - Board manipulation examples

### Advanced Examples
- [custom_ui.cpp](custom_ui.cpp) - Creating custom user interfaces
- [game_analysis.cpp](game_analysis.cpp) - Analyzing game positions
- [file_operations.cpp](file_operations.cpp) - Loading/saving games (PGN, FEN)

### Integration Examples
- [console_game.cpp](console_game.cpp) - Complete console application
- [unit_test_examples.cpp](unit_test_examples.cpp) - Test case examples

## 🚀 Quick Start Example

Here's a minimal example to get you started:

```cpp
#include "core/Game.h"
#include "ui/ConsoleUI.h"

int main() {
    // Create game and UI
    Game game;
    ConsoleUI ui;
    
    // Setup game
    game.initializeGame("Player 1", "Player 2");
    game.start();
    
    // Display welcome
    ui.displayWelcome();
    
    // Main game loop
    while (!game.isGameOver()) {
        // Display current state
        ui.displayBoard(game.getBoard());
        ui.displayGameStatus(game);
        
        // Get player move
        std::string moveStr = ui.getPlayerMove(
            game.getCurrentPlayer() == Color::WHITE ? 
            game.getWhitePlayer() : game.getBlackPlayer()
        );
        
        // Make move
        if (!game.makeMove(moveStr)) {
            ui.displayError("Invalid move! Try again.");
            continue;
        }
        
        // Check for check
        if (game.isCurrentPlayerInCheck()) {
            ui.displayCheck(
                game.getCurrentPlayer() == Color::WHITE ? 
                game.getWhitePlayer() : game.getBlackPlayer()
            );
        }
    }
    
    // Display result
    ui.displayGameResult(game.getResult());
    
    return 0;
}
```

## 🔧 Building Examples

To build the examples:

```bash
# From the project root directory
cd examples
mkdir build && cd build
cmake ..
make

# Run an example
./basic_game
```

## 📝 Example Categories

### 1. Beginner Examples
Perfect for those new to the codebase:
- Basic game setup
- Simple move making
- Board display

### 2. Intermediate Examples
For developers familiar with the basics:
- Custom piece behavior
- Game state management
- Error handling

### 3. Advanced Examples
For experienced developers:
- Performance optimization
- Custom algorithms
- Integration with external systems

## 💡 Tips for Using Examples

1. **Start Simple**: Begin with `basic_game.cpp` to understand the core concepts
2. **Read Comments**: Each example is thoroughly commented
3. **Experiment**: Modify the examples to see how changes affect behavior
4. **Test**: Run the examples to see them in action

## 🤝 Contributing Examples

We welcome contributions of new examples! When adding examples:

1. Follow the existing code style
2. Include comprehensive comments
3. Add appropriate error handling
4. Update this README with your example
5. Test thoroughly before submitting

## 📞 Getting Help

If you have questions about the examples:
- Check the main [documentation](../docs/README.md)
- Review the [API documentation](../docs/api/)
- Open an issue on GitHub

---

Happy coding! ♟️