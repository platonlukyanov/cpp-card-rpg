# Corporate Throne - Card Game
![Build and Test Status](https://github.com/platonlukyanov/cpp-card-rpg/actions/workflows/action.yml/badge.svg)

Lukyanov Platon Alexandrovich; B81
email: platon_lukyanov@vk.com

## Requirements

### Build Requirements
- g++
- make

### Development Environment
```bash
sudo apt-get install libgtest-dev build-essential clang-format
```

### Documentation Requirements
```bash
sudo apt-get install doxygen graphviz
```

## Build and Run

### Build the Project
```bash
make
```

### Run the Game
```bash
./bin/main
```

### Run Tests
```bash
make test
```

### Code Formatting
```bash
make format
```

### Documentation

#### Generate Documentation
```bash
make gen-docs
```

#### View Documentation
After generating documentation, open `docs/html/index.html` in your web browser to view the complete documentation.

The documentation includes:
- Game rules and mechanics
- System architecture
- Class diagrams
- Testing strategy
