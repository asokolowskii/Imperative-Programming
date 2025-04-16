# 🐜 Langton’s Ant – Task

Langton's Ant is a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior.  
The task is to simulate the movement of the ant according to the following logic:
- At a white square, turn 90° right, flip the color of the square, move forward one unit.
- At a black square, turn 90° left, flip the color of the square, move forward one unit.

---

## 📄 Task Description (Scans)

Below are all pages of the original task description:

![Langton's Ant – Page 1](https://raw.githubusercontent.com/asokolowskii/Imperative-Programming/main/img/ant_task_page1.png)

![Langton's Ant – Page 2](https://raw.githubusercontent.com/asokolowskii/Imperative-Programming/main/img/ant_task_page2.png)

---

## 🧠 Goals

- Understand how a simple state machine can generate complex behavior
- Practice working with 2D arrays, state tracking, and visualization in C
- Learn how to model direction, movement, and toggling states

---

## 💡 Sample Ideas

- Represent the board as a 2D array of `bool` or `char` (`0` = white, `1` = black)
- Use a `struct` to represent the ant: position (x, y) + direction (N/E/S/W)
- Implement step-by-step updates: turn → flip color → move
- Optionally print the grid every N steps to observe the pattern

---

## 🛠️ Tools

- Language: `C`
- Compile with: `gcc -std=c17 -O2 -Wall ant.c -o ant`
- Optional: visual output using console characters (`#`, `.`)

---

## 📬 Contact

[github.com/asokolowskii](https://github.com/asokolowskii)

