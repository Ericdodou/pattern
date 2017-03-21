#include "Maze.h"


int main() {
  MazeGame game;
  BombedMazeFactory bombedFactory;
  EnchantedMazeFactory enchantedFactory;
  game.CreateMaze(bombedFactory);

}


