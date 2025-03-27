# 🏙️ Skyscraper Solver – 42 Berlin Piscine

This project solves the [Skyscraper puzzle](https://www.puzzlemix.com/Skyscraper) – a logic game where you must fill a grid with buildings of varying heights, following specific visibility rules from each side. You can try the puzzle [online here](https://www.interactive.onlinemathlearning.com/fun_towers.php).

## 🔧 Problem Description

Given a 4x4 grid, place numbers from 1 to 4 (representing building heights) so that:

- Each row and column contains all numbers from 1 to 4 (no duplicates).
- Side clues (given on each edge) indicate how many skyscrapers are visible from that direction.
- A taller skyscraper blocks the view of a smaller one behind it.

## 🚀 How to Run

```bash
gcc -o skyscraper ./ex00/./main.c
./skyscraper "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```
