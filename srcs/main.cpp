# include <ft_retro.hpp>

int					main(void) {
	srand(time(NULL));

	AShip			* player = new Player();
	CObject			* list   = new CObject(player);
	Map				* map    = new Map(40, 20, list);

	Window			win (map);

	player->setMap(map);
	player->move(19, 19);

	win.menu();

	return 0;
}