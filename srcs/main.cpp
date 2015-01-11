# include <ft_retro.hpp>

int					main(void) {
	AShip			* player = new Player();
	CObject			* list   = new CObject(player);
	Map				* map    = new Map(20, 40, list);

	Window			win (map);

	player->setMap(map);
	player->move(5, 29);
	
	AShip	 		* enemy = new Enemy(0, 19, MIDDLEGROUND, map, 1, 1, 1);
	map->pushObject(enemy);

	win.menu();

	return 0;
}