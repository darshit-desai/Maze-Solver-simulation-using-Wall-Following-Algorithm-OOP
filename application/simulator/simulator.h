#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

/**
 * @file simulator.h
 * @author Darshit Desai (darshit@umd.edu) , Vamshi Kalavagunta (vamshik@umd.edu) , Vinay Bukka(vinay06@umd.edu)
 * @brief Functions to control the robot and get information on the maze.
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <string>


class Simulator {
 public:
  /**
   * @brief Compute the width of the maze.
   *
   * @return int Width of the maze.
   */
  static int mazeWidth();
  /**
   * @brief Compute the height of the maze.
   *
   * @return int Height of the maze.
   */
  static int mazeHeight();

  /**
   * @brief Check if there is a wall in front of the robot.
   *
   * @return true
   * @return false
   */
  static bool wallFront();
  /**
   * @brief Check if there is a wall to the right of the robot.
   *
   * @return true
   * @return false
   */
  static bool wallRight();
  /**
   * @brief Check if there is a wall to the left of the robot.
   *
   * @return true
   * @return false
   */
  static bool wallLeft();
  /**
   * @brief Move the robot forward.
   *
   * @param distance Distance (number of cell) to move forward.
   */
  static void moveForward(int distance = 1);
  /**
   * @brief Turn the robot right.
   *
   */
  static void turnRight();
  /**
   * @brief Turn the robot left.
   *
   */
  static void turnLeft();
  /**
   * @brief Set a wall at the given coordinates.
   *
   * @param x X coordinate of the cell.
   * @param y Y coordinate of the cell.
   * @param direction  Direction of the wall. Can be 'n', 's', 'e', 'w'.
   */
  static void setWall(int x, int y, char direction);
  /**
   * @brief Remove a wall at the given coordinates.
   *
   * @param x X coordinate of the cell.
   * @param y Y coordinate of the cell.
   * @param direction direction Direction of the wall. Can be 'n', 's', 'e',
   * 'w'.
   */
  static void clearWall(int x, int y, char direction);
  /**
   * @brief Set the color of the cell at the given coordinates.
   *
   * @param x X coordinate of the cell.
   * @param y Y coordinate of the cell.
   * @param color Color of the cell. Can be 'k' (black), 'b' (blue), 'a' (Gray),
   * 'c' (cyan), 'g' (green), 'o' (orange), 'r' (red), 'w' (white), 'y' (yellow)
   * 'B' (dark blue), 'C' (dark cyan), 'A' (dark gray), 'G' (dark green),
   * 'R' (dark green), 'Y' (dark yellow).
   */
  static void setColor(int x, int y, char color);
  /**
   * @brief Clear the color of the cell at the given coordinates.
   *
   * @return int X coordinate of the cell.
   * @return int Y coordinate of the cell.
   */
  static void clearColor(int x, int y);
  /**
   * @brief Clear the color of all cells in the maze.
   */
  static void clearAllColor();

  /**
   * @brief Set the text in a cell at the given coordinates.
   *
   * @param x X coordinate of the cell.
   * @param y Y coordinate of the cell.
   * @param text Text to display in the cell.
   */
  static void setText(int x, int y, const std::string& text);
  /**
   * @brief Clear the text in a cell at the given coordinates.
   *
   * @param x X coordinate of the cell.
   * @param y Y coordinate of the cell.
   */
  static void clearText(int x, int y);
  /**
   * @brief Clear the text in all cells of the maze.
   *
   */
  static void clearAllText();
  /**
   * @brief Check wether or not the reset button has been pressed.
   *
   * @return true
   * @return false
   */
  static bool wasReset();
  /**
   * @brief Moves the robot back to the starting position.
   */
  static void ackReset();
};

#endif
