# Chess Game Documentation

Welcome to the Chess Game OOP documentation. This directory contains comprehensive documentation for the chess game implementation.

## 📚 Documentation Structure

### API Documentation
- [Core Classes](api/core.md) - Board, Game, Player classes
- [Piece Classes](api/pieces.md) - All chess piece implementations
- [UI Classes](api/ui.md) - User interface components

### Development Guides
- [Code Style Guide](development/code-style.md) - Coding standards and conventions
- [Architecture Overview](development/architecture.md) - System design and structure
- [Build Instructions](development/build.md) - Detailed build and compilation guide
- [Testing Guide](development/testing.md) - Unit testing framework and guidelines

### Game Rules
- [Chess Rules](rules/chess-rules.md) - Complete chess rules implementation
- [Special Moves](rules/special-moves.md) - Castling, en passant, promotion
- [Game Endings](rules/game-endings.md) - Checkmate, stalemate, draw conditions

### Examples
- [Basic Usage](examples/basic-usage.md) - Simple game setup and play
- [Advanced Features](examples/advanced-features.md) - Time control, move history
- [Customization](examples/customization.md) - Extending and modifying the game

### Technical Specifications
- [File Formats](technical/file-formats.md) - FEN, PGN format support
- [Performance](technical/performance.md) - Optimization and benchmarks
- [Memory Management](technical/memory.md) - Resource management strategies

## 🚀 Quick Start

1. **Building the Project**
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

2. **Running the Game**
   ```bash
   ./chess_game
   ```

3. **Running Tests**
   ```bash
   ctest --verbose
   ```

## 📖 API Reference

### Core Classes

#### Game Class
The main game controller that manages game flow, rules, and state.

```cpp
Game game;
game.initializeGame("Player 1", "Player 2");
game.start();
```

#### Board Class
Represents the chess board and manages piece positions.

```cpp
Board board;
board.setupInitialPosition();
bool moved = board.movePiece(Position(1, 0), Position(3, 0));
```

#### Piece Hierarchy
Abstract base class `Piece` with implementations for all chess pieces.

```cpp
auto pawn = std::make_unique<Pawn>(Color::WHITE, Position(1, 0));
auto moves = pawn->getLegalMoves(board);
```

## 🔧 Configuration

### Build Options
```cmake
# Debug build
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Release build
cmake -DCMAKE_BUILD_TYPE=Release ..

# With tests
cmake -DENABLE_TESTING=ON ..
```

### Compiler Support
- GCC 7.0+ 
- Clang 5.0+
- MSVC 2017+
- C++17 standard required

## 📝 Contributing

Please read our [Contributing Guide](../CONTRIBUTING.md) for development guidelines and coding standards.

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/TruongMinhHuy/Nhom3_OOP/issues)
- **Documentation**: This docs folder
- **Discussions**: [GitHub Discussions](https://github.com/TruongMinhHuy/Nhom3_OOP/discussions)

---

Last updated: 2024