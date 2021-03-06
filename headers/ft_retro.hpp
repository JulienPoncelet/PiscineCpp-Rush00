#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include <iostream>
# include <sstream>
# include <ncurses.h>
# include <unistd.h>
# include <ctime>
# include <stdlib.h>

# define FRAME_RATE 24

typedef unsigned int uint;

enum plan_e {
	BACKGROUND = 1, MIDDLEGROUND, FOREGROUND
};

enum direction_e {
	UP = 1, RIGHT, DOWN, LEFT 
};

enum objType_e {
	PLAYER = 1, ENEMY, PROJECTILE 
};
enum color_e {
	RED = 1, BLUE, GREEN, WHITE, YELLOW, MAGENTA
};

class Map;
class AObject;
class CObject;

class AShip;
class Enemy;
class Player;
class Projectile;

class Window;

# include <Map.hpp>
# include <AObject.hpp>
# include <CObject.hpp>
# include <AShip.hpp>
# include <Enemy.hpp>
# include <Player.hpp>
# include <Projectile.hpp>
# include <Window.hpp>

#endif
