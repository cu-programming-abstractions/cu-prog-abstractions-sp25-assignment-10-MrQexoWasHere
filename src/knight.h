/*
 * 
 * This file defines the data structures and functions for solving the knight moves problem:
 * 
 * 1. Position Structure:
 *    - row: integer representing the row coordinate (0-based)
 *    - col: integer representing the column coordinate (0-based)
 *    - operator==: comparison operator for position equality
 * 
 * 2. Knight Movement Functions:
 *    - minKnightMoves(): Find minimum moves for knight to reach target
 *    - getKnightPath(): Get the actual path of moves
 *    - Helper functions for BFS implementation
 * 
 * 3. Algorithm:
 *    - Uses BFS (Breadth-First Search) to find shortest path
 *    - Knight moves in L-shape: 2 squares in one direction, 1 in perpendicular
 *    - 8 possible moves from any position
 */

#pragma once
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;
// Very interesting task!
struct Pos {
    int row, col;
    
    bool operator==(const Pos& other) const {
        return row == other.row && col == other.col;
    }
    
    bool operator!=(const Pos& other) const {
        return !(*this == other);
    }
};

// Hash function for Pos to use in unordered_set/map
struct PosHash {
    size_t operator()(const Pos& p) const {
        return hash<int>()(p.row) ^ (hash<int>()(p.col) << 1);
    }
};

/* Find minimum number of moves for knight to reach target from start position.
   Returns -1 if target is unreachable (shouldn't happen on infinite board). */
int minKnightMoves(const Pos& start, const Pos& target);

/* Get the actual path of positions from start to target.
   Returns vector of positions including start and target. */
vector<Pos> getKnightPath(const Pos& start, const Pos& target);

/* Check if a position is valid on the board (helper function).
   For infinite board, this always returns true.
   For bounded board, check if position is within bounds. */
bool isValidPosition(const Pos& pos, int boardSize = -1);
