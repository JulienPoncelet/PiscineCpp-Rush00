#include <ft_retro.hpp>

uint						Player::_amount = 0;

Player::Player(void) : AObject(), AShip() {
	setIndex(_amount++);
	return ;
}

Player::Player(uint x, uint y, plan_e z, Map * map, uint hp, uint max_hp, uint dmg)
				: AObject(x, y, z, map), AShip(x, y, z, map, hp, max_hp, dmg) {
	setIndex(_amount++);
	return ;
}

Player::Player(Player const & src) : AObject(src), AShip(src) {
	*this = src;
	return ;
}

Player::~Player(void) {
	return ;
}

Player & Player::operator=(Player const & rhs) {
	setX(rhs.getX());
	setY(rhs.getY());
	setHp(rhs.getHp());
	setMaxHp(rhs.getMaxHp());
	setDmg(rhs.getDmg());	
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, Player const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				Player::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "Player #" << getIndex() << std::endl;
	out << "\tX: " << getX() << std::endl;
	out << "\tY: " << getY() << std::endl;
	out << "\tZ: " << getZ() << std::endl;
	out << "\tMap ptr: " << getMap() << std::endl;
	out << "\tHP: " << getHp() << std::endl;
	out << "\tMax HP: " << getMaxHp() << std::endl;
	out << "\tDamage: " << getDmg() << std::endl;
	out << "\033[0m";
	return out.str();
}

void			Player::shoot(void) const {
	// Item 		* projectile =  Projectile(UP, getDmg(), getX(), getY() - 1);

	// getMap().pushItem(projectile);
	return ;
}

void			Player::destroy(void) {
	// getMap().popItem(this);
	// FINISH GAME
	return ;
}
