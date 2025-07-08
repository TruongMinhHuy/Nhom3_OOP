# Contributing to Chess Game OOP

We welcome contributions to our Chess Game project! This document provides guidelines for contributing.

## 🚀 Getting Started

1. **Fork the repository** on GitHub
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/Nhom3_OOP.git
   cd Nhom3_OOP
   ```
3. **Create a feature branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```

## 📋 Code Style Guidelines

### C++ Style
- Follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- Use **4 spaces** for indentation (no tabs)
- Maximum line length: **100 characters**
- Use `PascalCase` for class names
- Use `camelCase` for function and variable names
- Use `UPPER_SNAKE_CASE` for constants

### File Organization
- Header files use `.h` extension
- Implementation files use `.cpp` extension
- One class per header file
- Include guards in all header files

### Example Code Style
```cpp
#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <vector>
#include <memory>

class Piece {
private:
    Color color_;
    Position position_;
    
public:
    explicit Piece(Color color, Position position);
    virtual ~Piece() = default;
    
    virtual std::vector<Move> getLegalMoves(const Board& board) const = 0;
    virtual bool canMoveTo(Position target, const Board& board) const;
    
    // Getters
    Color getColor() const { return color_; }
    Position getPosition() const { return position_; }
    
    // Setters
    void setPosition(Position newPosition) { position_ = newPosition; }
};

#endif // CHESS_PIECE_H
```

## 🏗️ Development Workflow

### Before Starting
1. Check existing issues and pull requests
2. Create or comment on an issue describing your planned changes
3. Ensure your development environment is set up correctly

### Development Process
1. **Write tests first** (Test-Driven Development)
2. **Implement the feature** with clean, readable code
3. **Test thoroughly** - all tests must pass
4. **Document your changes** in code comments and README if needed
5. **Follow commit message conventions**

### Commit Message Format
Use clear, descriptive commit messages:
```
type(scope): brief description

Detailed explanation if needed.

Fixes #issue_number
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code formatting changes
- `refactor`: Code refactoring
- `test`: Adding or modifying tests
- `build`: Build system changes

Examples:
```
feat(pieces): implement Knight movement logic

Add Knight class with L-shaped movement validation
and collision detection.

Fixes #15
```

## 🧪 Testing Requirements

### Unit Tests
- Write unit tests for all new functionality
- Maintain or improve test coverage
- Tests should be isolated and deterministic
- Use descriptive test names

### Test Structure
```cpp
#include <gtest/gtest.h>
#include "pieces/Knight.h"

class KnightTest : public ::testing::Test {
protected:
    void SetUp() override {
        board = std::make_unique<Board>();
        knight = std::make_unique<Knight>(Color::WHITE, Position(4, 4));
    }
    
    std::unique_ptr<Board> board;
    std::unique_ptr<Knight> knight;
};

TEST_F(KnightTest, ValidLShapedMoves) {
    auto moves = knight->getLegalMoves(*board);
    EXPECT_TRUE(containsMove(moves, Position(6, 5)));
    EXPECT_TRUE(containsMove(moves, Position(2, 3)));
}
```

### Running Tests
```bash
cd build
cmake ..
make
ctest --verbose
```

## 🔧 Build Requirements

### Prerequisites
- C++17 compatible compiler
- CMake 3.10+
- Git

### Build Commands
```bash
# Debug build
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$(nproc)

# Release build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
```

## 📝 Documentation

### Code Documentation
- Document all public interfaces
- Use Doxygen-style comments
- Explain complex algorithms
- Include usage examples

### Example Documentation
```cpp
/**
 * @brief Calculates all legal moves for this piece
 * 
 * This method considers the current board state, piece position,
 * and chess rules to generate all valid moves.
 * 
 * @param board Current state of the chess board
 * @return Vector of legal moves for this piece
 * 
 * @throws std::invalid_argument if board is in invalid state
 * 
 * @example
 * ```cpp
 * Board board;
 * Knight knight(Color::WHITE, Position(4, 4));
 * auto moves = knight.getLegalMoves(board);
 * ```
 */
virtual std::vector<Move> getLegalMoves(const Board& board) const = 0;
```

## 🚫 What Not to Contribute

- Code that doesn't follow our style guidelines
- Features without corresponding tests
- Breaking changes without discussion
- Large refactoring without prior approval
- Code with security vulnerabilities
- Plagiarized or copyrighted code

## 🆘 Getting Help

- **Documentation**: Check the `/docs` folder
- **Issues**: Browse existing GitHub issues
- **Discussions**: Start a GitHub discussion for questions
- **Code Review**: Request review from maintainers

## 🎯 Areas Needing Contribution

### High Priority
- [ ] Complete piece movement implementations
- [ ] Add check/checkmate detection
- [ ] Implement special moves (castling, en passant)
- [ ] Add comprehensive unit tests

### Medium Priority
- [ ] Improve user interface
- [ ] Add game state persistence
- [ ] Implement move history
- [ ] Add performance optimizations

### Low Priority
- [ ] Add different UI themes
- [ ] Implement AI opponent
- [ ] Add network multiplayer
- [ ] Create game replay system

## 📋 Pull Request Process

1. **Ensure all tests pass** locally
2. **Update documentation** if needed
3. **Create descriptive PR title** and description
4. **Link related issues** in PR description
5. **Request review** from maintainers
6. **Address feedback** promptly
7. **Squash commits** if requested

### PR Template
```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Breaking change
- [ ] Documentation update

## Testing
- [ ] Unit tests added/updated
- [ ] All tests pass
- [ ] Manual testing completed

## Checklist
- [ ] Code follows style guidelines
- [ ] Self-review completed
- [ ] Documentation updated
- [ ] No breaking changes (or documented)
```

## 🏆 Recognition

Contributors will be recognized in:
- README.md contributors section
- Release notes for significant contributions
- GitHub contributor graphs

Thank you for helping make this project better! 🎉