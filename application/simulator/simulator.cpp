#include "simulator.h"
#include <cstdlib>
#include <iostream>

int Simulator::mazeWidth() {
  std::cout << "mazeWidth" << std::endl;
  std::string response;
  std::cin >> response;
  return atoi(response.c_str());
}

int Simulator::mazeHeight() {
  std::cout << "mazeHeight" << std::endl;
  std::string response;
  std::cin >> response;
  return atoi(response.c_str());
}

bool Simulator::wallFront() {
  std::cout << "wallFront" << std::endl;
  std::string response;
  std::cin >> response;
  return response == "true";
}

bool Simulator::wallRight() {
  std::cout << "wallRight" << std::endl;
  std::string response;
  std::cin >> response;
  return response == "true";
}

bool Simulator::wallLeft() {
  std::cout << "wallLeft" << std::endl;
  std::string response;
  std::cin >> response;
  return response == "true";
}

void Simulator::moveForward(int distance) {
  std::cout << "moveForward ";
  // Don't print distance argument unless explicitly specified, for
  // backwards compatibility with older versions of the simulator
  if (distance != 1) {
    std::cout << distance;
  }
  std::cout << std::endl;
  std::string response;
  std::cin >> response;
  if (response != "ack") {
    std::cerr << response << std::endl;
    throw;
  }
}

void Simulator::turnRight() {
  std::cout << "turnRight" << std::endl;
  std::string ack;
  std::cin >> ack;
}

void Simulator::turnLeft() {
  std::cout << "turnLeft" << std::endl;
  std::string ack;
  std::cin >> ack;
}

void Simulator::setWall(int x, int y, char direction) {
  std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

void Simulator::clearWall(int x, int y, char direction) {
  std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

void Simulator::setColor(int x, int y, char color) {
  std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

void Simulator::clearColor(int x, int y) {
  std::cout << "clearColor " << x << " " << y << std::endl;
}

void Simulator::clearAllColor() {
  std::cout << "clearAllColor" << std::endl;
}

void Simulator::setText(int x, int y, const std::string& text) {
  std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

void Simulator::clearText(int x, int y) {
  std::cout << "clearText " << x << " " << y << std::endl;
}

void Simulator::clearAllText() {
  std::cout << "clearAllText" << std::endl;
}

bool Simulator::wasReset() {
  std::cout << "wasReset" << std::endl;
  std::string response;
  std::cin >> response;
  return response == "true";
}

void Simulator::ackReset() {
  std::cout << "ackReset" << std::endl;
  std::string ack;
  std::cin >> ack;
}
