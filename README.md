### CSE115 Project - First Programming Course (2020)

This repository contains three projects developed as part of the **CSE115** course, the introductory programming course in 2020. These projects demonstrate fundamental programming concepts, including dynamic memory allocation, game mechanics, and data management.

---

### 1. **Calendar Application**
- **Description**: Implements a dynamic calendar using a 3D array to represent months and dates. 
- **Features**:
  - View a specific month or the entire calendar.
  - Efficiently manages memory through dynamic allocation.
- **Snapshot**:  
  ![Calendar App](https://github.com/confusedOrca/CSE115-Project/assets/163755962/12f2293e-efd6-4434-b69b-7b681bb2c770)

---

### 2. **Moving Minefield Game**
- **Description**: A grid-based game where the player (denoted as "A") must navigate to the goal ("B") while avoiding mines ("X"). The grid dynamically shifts after each move, creating a challenging and engaging gameplay experience. 
- **Game Rules**:
  1. **Objective**: Reach "B" without depleting all lives.
  2. Collision with a mine ("X") reduces one life.
  3. After every move:
     - Odd rows rotate right.
     - Even rows rotate left.
     - The row containing "A" remains static.
  4. **Difficulty Levels**:
     - **Noob** (Press `N`): 50 moves, 5 lives, Tier Score: 1000.
     - **Pro** (Press `P`): 35 moves, 3 lives, Tier Score: 3000.
     - **Supreme** (Press `S`): 25 moves, 1 life, Tier Score: 2000.
  5. **Scoring**:
     - Each move deducts 15 points.
     - Each life lost deducts 50 points from the tier score.

- **Gameplay Demo**:  
  [![Minefield Game Demo](https://github.com/confusedOrca/CSE115-Project/assets/163755962/d1358994-34f3-43d6-b61c-3bb0d01bfadf)](https://github.com/confusedOrca/CSE115-Project/assets/163755962/d1358994-34f3-43d6-b61c-3bb0d01bfadf)

---

### 3. **Volunteer Information System**
- **Description**: A system to manage and display volunteer information.
- **Features**:
  - Add, view, and manage volunteer data.
  - A simple and intuitive interface for organizing and accessing information.
- **Snapshot**:  
  ![Volunteer Info System](https://github.com/confusedOrca/CSE115-Project/assets/163755962/9b94e9e8-006f-4e0f-afcc-a297990e85bb)
