#include <ft_retro.hpp>

AShip::AShip(void) : AObject() {
	setHp(1);
	setMaxHp(1);
	setDmg(1);
	return ;
}

AShip::AShip(uint x, uint y, plan_e z, Map * map, uint hp, uint max_hp, uint dmg)
				: AObject(x, y, z, map) {
	setHp(hp);
	setMaxHp(max_hp);
	setDmg(dmg);
	return ;
}

AShip::AShip(AShip const & src) : AObject(src) {
	*this = src;
	return ;
}

AShip::~AShip(void) {
	return ;
}

AShip & AShip::operator=(AShip const & rhs) {
	setX(rhs.getX());
	setY(rhs.getY());
	setHp(rhs.getHp());
	setMaxHp(rhs.getMaxHp());
	setDmg(rhs.getDmg());	
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, AShip const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				AShip::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "AShip:" << std::endl;
	out << "\tX: " << getX() << std::endl;
	out << "\tY: " << getY() << std::endl;
	out << "\tZ: " << getZ() << std::endl;
	// out << "\tMap ptr: " << getMap() << std::endl;
	out << "\tHP: " << getHp() << std::endl;
	out << "\tMax HP: " << getMaxHp() << std::endl;
	out << "\tDamage: " << getDmg() << std::endl;
	out << "\033[0m";
	return out.str();
}

uint			AShip::getHp(void) const {
	return _hp;
}

uint			AShip::getMaxHp(void) const {
	return _maxHp;
}

uint			AShip::getDmg(void) const {
	return _dmg;
}

void			AShip::setHp(uint hp) {
	_hp = hp;
	return ;
}

void			AShip::setMaxHp(uint maxHp) {
	_maxHp = maxHp;
	return ;
}

void			AShip::setDmg(uint dmg) {
	_dmg = dmg;
	return ;
}
