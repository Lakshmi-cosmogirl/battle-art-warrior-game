# battle-art-warrior-game
A warrior battle game combining a browser-based HTML/CSS/JavaScript frontend with C++ Data Structures &amp; Algorithms, focusing on Linked Lists.
# ⚔️ BATTLE ART — Warrior Battle Game

> A warrior battle game combining a browser-based frontend with a C++ Data Structures & Algorithms implementation.

## 🎮 About the Project

**BATTLE ART** is a warrior-themed 2D battle game developed as a Data Structures & Algorithms project.

The project combines an interactive **HTML, CSS and JavaScript game interface** with a separate **C++ implementation demonstrating Data Structures and Algorithms concepts**, particularly **Linked Lists**.

The game allows the player to select warriors, fight enemies, use different weapons and abilities, manage health and lives, and achieve high scores.

---

## ✨ Features

* ⚔️ Warrior-based combat system
* 👹 Enemy and boss battles
* 🗡️ Weapon selection and customization
* ❤️ Health and life system
* 🧪 Healing potions
* 💥 Normal and charged attacks
* 🎯 Weak-point targeting
* 🔥 Special and ultimate abilities
* 🏆 High-score / leaderboard system
* 🎮 Keyboard controls
* 📱 Touch-friendly controls
* 🖥️ Browser-based game interface

---

## 🧠 Data Structures & Algorithms

The C++ implementation focuses mainly on **Linked Lists**.

### 1. Linked List for Customization

The project uses a linked-list structure to manage selected game customization options.

```text
Warrior → Enemy → Weapon → NULL
```

Each node stores information about a selected category and points to the next node.

### 2. Linked List for High Scores

A linked-list structure is also used for storing and organizing player scores.

```text
[Warrior | Boss | Score]
        ↓
[Warrior | Boss | Score]
        ↓
[Warrior | Boss | Score]
        ↓
       NULL
```

This demonstrates concepts such as:

* Nodes
* Pointers
* Dynamic memory allocation
* Linked-list traversal
* Node insertion
* Searching/accessing data

---

## 🛠️ Technologies Used

### Frontend

* HTML5
* CSS3
* JavaScript
* HTML Canvas
* Responsive design
* Keyboard and touch controls

### C++ / DSA

* C++
* Structures
* Classes
* Pointers
* Dynamic memory allocation
* Linked Lists
* Traversal
* Insertion
* Searching and data access

---

## 📁 Project Structure

```text
battle-art-warrior-game/
│
├── frontend/
│   └── battle-art.html
│
├── backend/
│   └── battle_art.cpp
│
├── README.md
└── LICENSE
```

### `frontend/`

Contains the browser-based game developed using HTML, CSS and JavaScript.

### `backend/`

Contains the C++ implementation demonstrating the game's Data Structures & Algorithms concepts.

---

## 🎮 Controls

| Key         | Action            |
| ----------- | ----------------- |
| `W A S D`   | Movement          |
| `SPACE`     | Dodge             |
| `E`         | Normal Attack     |
| `F`         | Charged Attack    |
| `Q`         | Special Skill     |
| `R`         | Ultimate          |
| `Z`         | Zoom              |
| `1 / 2 / 3` | Select Weak Point |
| `TAB`       | Target Selection  |
| `ESC`       | Close Menu        |

---

## ▶️ How to Run

### Browser Game

1. Open the `frontend` folder.
2. Open `battle-art.html`.
3. Run the file in a modern web browser.
4. Start playing.

No additional installation is required for the browser version.

### C++ Implementation

1. Open `backend/battle_art.cpp`.
2. Compile the program using a C++ compiler.
3. Run the generated executable.

Example:

```bash
g++ battle_art.cpp -o battle_art
./battle_art
```

---

## 🎯 Project Objective

The main objective of this project is to understand and demonstrate how **Data Structures & Algorithms concepts can be applied to game development**.

The project particularly focuses on understanding **Linked Lists** through a practical game-related implementation instead of using the data structure only as a theoretical example.

---

## 🚀 Future Improvements

* Connect the C++ game logic with the browser frontend
* Add more warriors, weapons and bosses
* Add advanced enemy AI
* Add sound effects and background music
* Add persistent player profiles and scores
* Add multiplayer functionality
* Expand the inventory system using Linked Lists
* Use Stack for game history / undo actions
* Use Queue for enemy attack sequences
* Improve accessibility and mobile controls

---

## 👩‍💻 Author

**Lakshmi Latheesh**

Data Science Student | Game Development & Data Structures

---

## 📚 Purpose

This project was created as an educational project to explore the combination of:

**Data Structures + C++ + Game Development + Web Technologies**

---

## 📄 License

This project is intended primarily for educational and learning purposes.
