#include <iostream>

#include <Player.hpp>

int					main(void) {
	AObject			* obj0 = new Player();
	AObject			* obj1 = new Player(1, 2, AObject::MIDDLEGROUND, 3, 3, 2);

	std::cout << *obj0 << std::endl;
	std::cout << *obj1 << std::endl;

	obj0->move(42, 42);
	std::cout << *obj0 << std::endl;

	delete obj0;
	delete obj1;

	return 0;
}
