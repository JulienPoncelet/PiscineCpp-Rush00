#include <iostream>

#include <Player.hpp>
#include <Enemy.hpp>
#include <Projectile.hpp>

int					main(void) {
	AObject			* player0 = new Player();
	AObject			* player1 = new Player(1, 2, AObject::MIDDLEGROUND, 3, 3, 2);

	std::cout << *player0 << std::endl;
	std::cout << *player1 << std::endl;

	player0->move(42, 42);
	std::cout << *player0 << std::endl;

	delete player0;
	delete player1;

	AObject			* enemy0 = new Enemy();
	AObject			* enemy1 = new Enemy(1, 2, AObject::MIDDLEGROUND, 3, 3, 2);

	std::cout << *enemy0 << std::endl;
	std::cout << *enemy1 << std::endl;

	enemy0->move(42, 42);
	std::cout << *enemy0 << std::endl;

	delete enemy0;
	delete enemy1;

	AObject			* project2 = new Projectile();
	AObject			* project3 = new Projectile(1, 2, AObject::MIDDLEGROUND, Projectile::UP, 4);

	std::cout << *project2 << std::endl;
	std::cout << *project3 << std::endl;

	project2->move(42, 42);
	std::cout << *project2 << std::endl;

	delete project2;
	delete project3;

	return 0;
}
