#include "solution.hpp"
#include <iostream>

// Recursive helper: explores the maze using backtracking
bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {

  // Check bounds
  if (x >= maze.size() || y >= maze[0].size()) {
    return false;
  }

  // Check for walls or previously visited cells
  if (maze[x][y] == '#' || visited[x][y]) {
    return false;
  }

  // Mark current cell as visited
  visited[x][y] = true;

  // Add current cell to the path
  path.push_back({x, y});

  // Check if this cell is the exit
  if (maze[x][y] == 'X') {
    return true;
  }

  // Explore directions: Down, Up, Right, Left
  if (SolveMazeRecursive(maze, x + 1, y, path, visited)) return true; // Down
  if (x > 0 && SolveMazeRecursive(maze, x - 1, y, path, visited)) return true; // Up
  if (SolveMazeRecursive(maze, x, y + 1, path, visited)) return true; // Right
  if (y > 0 && SolveMazeRecursive(maze, x, y - 1, path, visited)) return true; // Left

  // Backtrack: remove current cell if no path found
  path.pop_back();
  return false;
}

// Sets up visited matrix and initiates recursion
std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {

  std::vector<std::pair<unsigned int, unsigned int>> path;

  if (maze.empty() || maze[0].empty()) {
    return path; // Empty maze, nothing to solve
  }

  // Create visited matrix initialized to false
  std::vector<std::vector<bool>> visited(
      maze.size(), std::vector<bool>(maze[0].size(), false));

  // Start recursive search from the starting point
  SolveMazeRecursive(maze, start_x, start_y, path, visited);

  return path;
}
