# Chess Game - OOP Implementation (Group 3)

A complete Object-Oriented Programming (OOP) implementation of a Chess game in C++.

## 📋 Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
- [Usage](#usage)
- [Development](#development)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Project Overview

This project implements a full-featured chess game using modern C++ and Object-Oriented Programming principles. The design emphasizes clean code, maintainability, and extensibility.

### Key Design Principles
- **Abstraction**: Abstract base classes for pieces and game components
- **Encapsulation**: Private data members with controlled access
- **Inheritance**: Piece hierarchy with shared behaviors
- **Polymorphism**: Runtime behavior based on piece types

## ✨ Features

- [ ] Complete chess piece implementation (Pawn, Rook, Knight, Bishop, Queen, King)
- [ ] Full chess rule validation
- [ ] Move generation and validation
- [ ] Check and checkmate detection
- [ ] Castling and en passant support
- [ ] Console-based user interface
- [ ] Game state persistence
- [ ] Move history tracking
- [ ] Undo/Redo functionality

## 📁 Project Structure

```
Nhom3_Chess_OOP/
├── src/                    # Source code
│   ├── pieces/            # Chess piece classes
│   │   ├── Piece.h        # Abstract base class
│   │   ├── Pawn.h         # Pawn implementation
│   │   ├── Rook.h         # Rook implementation
│   │   ├── Knight.h       # Knight implementation
│   │   ├── Bishop.h       # Bishop implementation
│   │   ├── Queen.h        # Queen implementation
│   │   └── King.h         # King implementation
│   ├── core/              # Core game logic
│   │   ├── Board.h        # Chess board representation
│   │   ├── Game.h         # Main game controller
│   │   └── Player.h       # Player management
│   └── ui/                # User interface
│       └── ConsoleUI.h    # Console interface
├── include/               # Public header files
├── tests/                 # Unit tests
├── docs/                  # Documentation
├── build/                 # Build artifacts (auto-generated)
├── assets/                # Game resources
├── examples/              # Example usage
├── CMakeLists.txt         # Build configuration
├── .gitignore            # Git ignore rules
├── CONTRIBUTING.md       # Contribution guidelines
└── LICENSE               # Project license
```

## 🛠 Building the Project

### Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10 or higher
- Make or Ninja build system

### Build Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/TruongMinhHuy/Nhom3_OOP.git
   cd Nhom3_OOP
   ```

2. **Create build directory**
   ```bash
   mkdir build && cd build
   ```

3. **Configure and build**
   ```bash
   cmake ..
   make -j$(nproc)
   ```

4. **Run the game**
   ```bash
   ./chess_game
   ```

### Alternative Build Commands

- **Debug build**:
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  make
  ```

- **Release build**:
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Release ..
  make
  ```

## 🎮 Usage

```cpp
#include "core/Game.h"
#include "ui/ConsoleUI.h"

int main() {
    Game chessGame;
    ConsoleUI ui;
    
    chessGame.start();
    ui.displayWelcome();
    
    while (!chessGame.isGameOver()) {
        ui.displayBoard(chessGame.getBoard());
        Move move = ui.getPlayerMove();
        chessGame.makeMove(move);
    }
    
    ui.displayResult(chessGame.getResult());
    return 0;
}
```

## 👥 Development

### Running Tests
```bash
cd build
ctest --verbose
```

### Code Style
- Follow Google C++ Style Guide
- Use meaningful variable and function names
- Document public interfaces
- Keep functions small and focused

### Adding New Features
1. Create feature branch: `git checkout -b feature/your-feature`
2. Implement changes with tests
3. Ensure all tests pass
4. Submit pull request

## 🤝 Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Team Members

- **Group 3 - OOP Course**
- Project maintained by: TruongMinhHuy

## 📞 Support

If you have any questions or need help, please:
1. Check the [documentation](docs/)
2. Search existing [issues](https://github.com/TruongMinhHuy/Nhom3_OOP/issues)
3. Create a new issue if needed

---

**Happy Coding! ♟️**