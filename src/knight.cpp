#include "knight.h"
#include <algorithm>
#include <cmath>

/* -------- minKnightMoves -------- */
int minKnightMoves(const Pos& start, const Pos& target) {
    if (start == target) return 0;

    vector<pair<int, int>> directions = {
        {+2, +1}, {+2, -1}, {-2, +1}, {-2, -1},
        {+1, +2}, {+1, -2}, {-1, +2}, {-1, -2}
    };

    queue<pair<Pos, int>> q;
    unordered_set<Pos, PosHash> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();

        for (auto [dr, dc] : directions) {
            Pos next{current.row + dr, current.col + dc};
            if (next == target) return dist + 1;

            if (visited.count(next) == 0) {
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }
    }

    return -1; // Should never be reached on infinite board
}

/* -------- getKnightPath -------- */
vector<Pos> getKnightPath(const Pos& start, const Pos& target) {
    if (start == target) return {start};

    vector<pair<int, int>> directions = {
        {+2, +1}, {+2, -1}, {-2, +1}, {-2, -1},
        {+1, +2}, {+1, -2}, {-1, +2}, {-1, -2}
    };

    queue<Pos> q;
    unordered_map<Pos, Pos, PosHash> parent;
    unordered_set<Pos, PosHash> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Pos current = q.front();
        q.pop();

        for (auto [dr, dc] : directions) {
            Pos next{current.row + dr, current.col + dc};
            if (visited.count(next)) continue;

            parent[next] = current;
            if (next == target) {
                // Reconstruct path
                vector<Pos> path;
                for (Pos p = target; ; p = parent[p]) {
                    path.push_back(p);
                    if (p == start) break;
                }
                reverse(path.begin(), path.end());
                return path;
            }

            visited.insert(next);
            q.push(next);
        }
    }

    return {}; // Should not happen
}

/* -------- isValidPosition -------- */
bool isValidPosition(const Pos& pos, int boardSize) {
    if (boardSize == -1) {
        return true; // Infinite board
    }

    return pos.row >= 0 && pos.row < boardSize &&
           pos.col >= 0 && pos.col < boardSize;
}
