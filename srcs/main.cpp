# include <ft_retro.hpp>

int					main(void) {
	srand(time(NULL));

	AShip			* player = new Player();
	CObject			* list   = new CObject(player);
	Map				* map    = new Map(80, 50, list);

	Window			* win 	 = new Window(map);

	player->setMap(map);
	player->move(39, 49);
	player->setHp(3);

	win->menu();
	delete win;

	return 0;
}