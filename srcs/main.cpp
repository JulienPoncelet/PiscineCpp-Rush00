# include <ft_retro.hpp>

int					main(void) {
	srand(time(NULL));

	AShip			* player = new Player();
	CObject			* list   = new CObject(player);
	Map				* map    = new Map(40, 40, list);

	Window			win (map);

	player->setMap(map);
	player->move(19, 39);
	player->setHp(3);

	win.menu();

	return 0;
}