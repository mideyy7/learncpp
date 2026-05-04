# Tic Tac Toe
### Clarify requirements
- Ask questions to uncover hidden assumptions, clarify ambiguities and define the system's scope
-Example:
1. Should the game support various board sizes like 4x4, 5x5
2. Should the game support both player v player and player v computer modes
3. what should happen if the player tries to make an invalide move?
4. Should the system maintain a scoreboard across multiple games?
5. how should input be handled? from console or hardcode a simple game sequence?
6. should the system track history or moves to allow undo or replay?


### Functional Requirements
* The game is played on a 3x3 grid
* Two players take alternate turns identified by markers 'X and 'O'
* The game should detect and announce the winner
* The game should declare a draw if all cells are filled and no player has won
* The game should reject invalid moves and inform the player
* The system should maintain a scoreboard across multiple games
* Moves can be hardcoded into a driver classs to simulate gameplay

### Non Functional Requirements
* The design should follow object oriented principles with clear responsibility and separation of concerns
* The system should be modular and extensible to support future features
* The game logic should be testable and easy to maintain
* The system should provide clear console output that reflects the currrent state of the game board

### Identifying Core Entities
*KEY: Look through the functional requirements and identify the nouns*
1. Board
2. Cell
3. Player
4. Symbol
5. Game
6. GameStatus
7. ScoreBoard
8. TicTacToeSystem

### Class Definitions
**Enum**: Enums define fixed set of values that provide type safety. They prevent invalid states at compile time rather than runtime
**Symbol**: Represents the value that a cell can contain
- X, O, EMPTY
- Use characters to display -> 'X', 'O', '-'
**GameStatus***: Defines the possible states of the game
- IN_PROGRESS, WINNER_X, WINNER_O, DRAW
- Once game starts it triggeres state IN_PROGRESS then it could end at the other 3 terminal states


**Data Classes**: These are simple containers that hodl data with minimal behaviour
**Player**: Hold player information -> name and symbol
**Cell**: Hold current value of a board position and isEmpty()

**Interfaces**: Interfaces define contracts for interchangeable behaviour
**WinningStrategy**: defines a contract for winning detection algorithms
**GameObserver**: defines a contract for listeming to game end events

**Core Classes** contains the actiual game logic
**Board**: contains the grid and handles all board related operations
**Game**: brings all components together and manages gameplay
**ScoreBoard**: tracks  wins across multiple games
**TicTacToe System**: is the public facing facade that hides internal complexity

### Key Design Patterns
1. Strategy pattern (used for win detection)
2. Observer pattern (used in score updates)
3. Singleton pattern (used in the TicTacToe system)






