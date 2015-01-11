#include <ft_retro.hpp>

uint						Enemy::_amount = 0;

Enemy::Enemy(void) : AObject(), AShip() {
	setIndex(_amount++);
	return ;
}

Enemy::Enemy(uint x, uint y, plan_e z, Map * map, uint hp, uint max_hp, uint dmg)
				: AObject(x, y, z, map), AShip(x, y, z, map, hp, max_hp, dmg) {
	setIndex(_amount++);
	return ;
}

Enemy::Enemy(Enemy const & src) : AObject(src), AShip(src) {
	*this = src;
	return ;
}

Enemy::~Enemy(void) {
	return ;
}

Enemy & Enemy::operator=(Enemy const & rhs) {
	setX(rhs.getX());
	setY(rhs.getY());
	setHp(rhs.getHp());
	setMaxHp(rhs.getMaxHp());
	setDmg(rhs.getDmg());	
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, Enemy const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				Enemy::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "Enemy #" << getIndex() << std::endl;
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

void			Enemy::shoot(void) const {
	// Item 		* projectile =  Projectile(DOWN, getDmg(), getX(), getY() + 1);

	// getMap().pushItem(projectile);
	return ;
}

void			Enemy::destroy(void) {
	// getMap().popItem(this);
	return ;
}
