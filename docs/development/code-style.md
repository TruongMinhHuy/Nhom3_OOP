# Code Style Guide

This document defines the coding standards and conventions for the Chess Game OOP project.

## 🎯 General Principles

1. **Clarity over cleverness** - Write code that is easy to read and understand
2. **Consistency** - Follow established patterns throughout the codebase
3. **Documentation** - Document public interfaces and complex logic
4. **Testing** - Write tests for all new functionality

## 📝 Naming Conventions

### Classes
- Use `PascalCase` for class names
- Use descriptive, noun-based names

```cpp
class ChessBoard { };
class GameController { };
class PieceMovement { };
```

### Functions and Methods
- Use `camelCase` for function names
- Use verb-based names that describe what the function does

```cpp
void makeMove(const Move& move);
bool isValidPosition(Position pos);
std::vector<Move> getLegalMoves() const;
```

### Variables
- Use `camelCase` for local variables and parameters
- Use `snake_case` with trailing underscore for private member variables
- Use descriptive names, avoid abbreviations

```cpp
// Good
int moveNumber;
Position targetPosition;
std::string playerName;

// Private members
class Player {
private:
    std::string name_;
    Color color_;
    int movesPlayed_;
};
```

### Constants
- Use `UPPER_SNAKE_CASE` for constants
- Use `const` or `constexpr` as appropriate

```cpp
const int BOARD_SIZE = 8;
constexpr double PI = 3.14159265359;
static const std::string DEFAULT_PLAYER_NAME = "Player";
```

## 📁 File Organization

### Header Files
- Use `.h` extension for header files
- Include guards using `#ifndef` pattern
- One class per header file (generally)

```cpp
#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

// Header content

#endif // CHESS_PIECE_H
```

### Source Files
- Use `.cpp` extension for implementation files
- Match header file names

```
Piece.h     -> Piece.cpp
Game.h      -> Game.cpp
Player.h    -> Player.cpp
```

### Include Order
1. Corresponding header file (for .cpp files)
2. Standard library headers
3. Third-party library headers
4. Project headers

```cpp
#include "Piece.h"

#include <vector>
#include <memory>
#include <iostream>

#include "Board.h"
#include "Player.h"
```

## 🔧 Formatting Rules

### Indentation
- Use **4 spaces** for indentation (no tabs)
- Align parameters and initializer lists

```cpp
class Piece {
public:
    Piece(Color color, 
          Position position, 
          bool hasMoved = false);
};
```

### Line Length
- Maximum **100 characters** per line
- Break long lines at logical points

```cpp
// Good
std::vector<Move> moves = piece->getLegalMoves(board, 
                                               includeCaptures, 
                                               checkForCheck);

// Avoid
std::vector<Move> moves = piece->getLegalMoves(board, includeCaptures, checkForCheck, validateKingSafety);
```

### Braces
- Use K&R style bracing
- Always use braces for single-statement blocks

```cpp
// Good
if (condition) {
    doSomething();
} else {
    doSomethingElse();
}

// Also good for single statements
if (piece != nullptr) {
    piece->move(target);
}
```

### Spacing
- Space around operators
- Space after commas
- No space inside parentheses

```cpp
// Good
int result = a + b * c;
function(param1, param2, param3);

// Avoid
int result=a+b*c;
function( param1,param2,param3 );
```

## 🏗️ Class Design Guidelines

### Member Access
- Use `private` by default
- Use `protected` for inheritance hierarchies
- Use `public` for interfaces only

```cpp
class Piece {
private:
    Color color_;           // Implementation details
    Position position_;

protected:
    bool hasMoved_;         // Shared with derived classes

public:
    virtual Move getLegalMoves() const = 0;  // Interface
    Color getColor() const { return color_; }
};
```

### Constructor Guidelines
- Use member initializer lists
- Use `explicit` for single-parameter constructors
- Consider default parameters

```cpp
class Piece {
public:
    explicit Piece(Color color, Position position = Position(0, 0))
        : color_(color), position_(position), hasMoved_(false) {
    }
};
```

### Virtual Functions
- Use `virtual` keyword for base class virtual functions
- Use `override` keyword for derived class overrides
- Use `= 0` for pure virtual functions

```cpp
class Piece {
public:
    virtual ~Piece() = default;
    virtual std::vector<Move> getLegalMoves() const = 0;
};

class Pawn : public Piece {
public:
    std::vector<Move> getLegalMoves() const override;
};
```

## 📚 Documentation Standards

### Class Documentation
```cpp
/**
 * @brief Represents a chess piece on the board
 * 
 * The Piece class is an abstract base class that defines the common
 * interface for all chess pieces. Each specific piece type inherits
 * from this class and implements its own movement logic.
 */
class Piece {
    // Class implementation
};
```

### Function Documentation
```cpp
/**
 * @brief Get all legal moves for this piece
 * 
 * @param board Current state of the chess board
 * @param checkForCheck Whether to verify moves don't put king in check
 * @return Vector of legal moves available to this piece
 * 
 * @throws std::invalid_argument if board is in invalid state
 */
virtual std::vector<Move> getLegalMoves(const Board& board, 
                                       bool checkForCheck = true) const = 0;
```

## ✅ Best Practices

### Modern C++ Features
- Use `auto` for type deduction when type is obvious
- Use smart pointers instead of raw pointers
- Use range-based for loops when possible
- Use `nullptr` instead of `NULL`

```cpp
// Good
auto piece = std::make_unique<Pawn>(Color::WHITE, position);
for (const auto& move : legalMoves) {
    // Process move
}

// Avoid
Pawn* piece = new Pawn(Color::WHITE, position);  // Memory leak risk
for (int i = 0; i < legalMoves.size(); ++i) {
    // Process legalMoves[i]
}
```

### Error Handling
- Use exceptions for exceptional conditions
- Use return values for expected failures
- Validate input parameters

```cpp
bool Game::makeMove(const Move& move) {
    if (!isValidMove(move)) {
        return false;  // Expected failure
    }
    
    if (board_.isEmpty()) {
        throw std::runtime_error("Board not initialized");  // Programming error
    }
    
    // Execute move
    return true;
}
```

### Performance Considerations
- Pass large objects by const reference
- Use move semantics for temporary objects
- Reserve vector capacity when size is known

```cpp
// Good
void processMove(const Move& move);           // Pass by const reference
std::vector<Move> moves = generateMoves();   // Move semantics

// Avoid
void processMove(Move move);                  // Unnecessary copy
```

## 🧪 Testing Standards

### Test Naming
- Use descriptive test names
- Follow pattern: `TestClass_Method_Condition_ExpectedResult`

```cpp
TEST(PawnTest, GetLegalMoves_FromStartingPosition_ReturnsTwoMoves) {
    // Test implementation
}

TEST(KingTest, CanMoveTo_AdjacentSquare_ReturnsTrue) {
    // Test implementation
}
```

### Test Structure
- Use Arrange-Act-Assert pattern
- One assertion per test when possible
- Use setup and teardown methods for common initialization

```cpp
TEST_F(BoardTest, MovePiece_ValidMove_UpdatesPosition) {
    // Arrange
    Board board;
    board.setupInitialPosition();
    Position from(1, 0);
    Position to(3, 0);
    
    // Act
    bool result = board.movePiece(from, to);
    
    // Assert
    EXPECT_TRUE(result);
    EXPECT_EQ(board.getPieceAt(to)->getPosition(), to);
    EXPECT_EQ(board.getPieceAt(from), nullptr);
}
```

## 🚫 Common Pitfalls to Avoid

1. **Memory leaks** - Always use smart pointers
2. **Magic numbers** - Use named constants
3. **Deep nesting** - Extract methods to reduce complexity
4. **Long functions** - Keep functions focused and short
5. **Global variables** - Use proper encapsulation
6. **Inconsistent naming** - Follow established conventions

---

Following these guidelines ensures consistent, maintainable, and professional code quality throughout the project.