# include <ft_retro.hpp>

int					main(void) {
	AObject			* player = new Player();
	CObject			* list   = new CObject(player);
	Map				* map    = new Map(20, 40, list);

	player->move(9, 19);
	player->setMap(map);

	AObject 		* enemy = new Enemy(0, 19, MIDDLEGROUND, map, 1, 1, 1);
	map->pushObject(enemy);

	std::cout << *list << std::endl;
	std::cout << *map << std::endl;

	return 0;
}