#include "solution.hpp"
#include <iostream>
#include <vector>
#include <utility>

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {

    // Check bounds
    if (x >= maze.size() || y >= maze[0].size())
        return false;

    // Wall or already visited
    if (maze[x][y] == '#' || visited[x][y])
        return false;

    // Mark cell as visited and add to path
    visited[x][y] = true;
    path.push_back({x, y});

    // Check for exit
    if (maze[x][y] == 'X')
        return true;

    // Explore directions in order: South, North, East, West
    if (SolveMazeRecursive(maze, x + 1, y, path, visited)) return true; // South
    if (x > 0 && SolveMazeRecursive(maze, x - 1, y, path, visited)) return true; // North
    if (SolveMazeRecursive(maze, x, y + 1, path, visited)) return true; // East
    if (y > 0 && SolveMazeRecursive(maze, x, y - 1, path, visited)) return true; // West

    // Backtrack if no path found
    path.pop_back();
    return false;
}

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {

    std::vector<std::pair<unsigned int, unsigned int>> path;
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));

    SolveMazeRecursive(maze, start_x, start_y, path, visited);
    return path;
}
