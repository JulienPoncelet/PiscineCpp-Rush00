# include <ft_retro.hpp>

int					main(void) {
	AObject			* player = new Player();
	CObject			* list   = new CObject(player);
	Map				* map    = new Map(60, 30, list);

	Window			win (map);

	player->setMap(map);
	player->move(5, 29);

	AObject 		* enemy = new Enemy(5, 0, MIDDLEGROUND, map, 1, 1, 1);
	map->pushObject(enemy);

	// std::cout << *list << std::endl;
	// std::cout << *map << std::endl;

	win.menu();

	return 0;
}