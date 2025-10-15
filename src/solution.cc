#include "solution.hpp"

// Recursive helper function that explores the maze using backtracking
bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {

  // Check if current cell is out of bounds
  if (x >= maze.size() || y >= maze[0].size()) {
    return false;
  }

  // Check if current cell is a wall or already visited
  if (maze[x][y] == '#' || visited[x][y]) {
    return false;
  }

  // Mark as visited and add to the current path
  visited[x][y] = true;
  path.push_back({x, y});

  // Check for exit
  if (maze[x][y] == 'X') {
    return true;
  }

  // Explore directions: Down, Up, Right, Left
  if (SolveMazeRecursive(maze, x + 1, y, path, visited)) return true; // Down
  if (x > 0 && SolveMazeRecursive(maze, x - 1, y, path, visited)) return true; // Up
  if (SolveMazeRecursive(maze, x, y + 1, path, visited)) return true; // Right
  if (y > 0 && SolveMazeRecursive(maze, x, y - 1, path, visited)) return true; // Left

  // Backtrack: remove current cell if it leads to a dead end
  path.pop_back();
  return false;
}

// Main function that initializes visited matrix and starts recursion
std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {

  std::vector<std::pair<unsigned int, unsigned int>> path;

  // Edge case: empty maze
  if (maze.empty() || maze[0].empty()) {
    return path;
  }

  // Initialize visited grid
  std::vector<std::vector<bool>> visited(
      maze.size(), std::vector<bool>(maze[0].size(), false));

  // Begin solving recursively
  SolveMazeRecursive(maze, start_x, start_y, path, visited);

  return path;
}

