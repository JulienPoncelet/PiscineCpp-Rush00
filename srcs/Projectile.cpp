#include "Projectile.hpp"

Projectile::Projectile(void) : AObject() {
	setDir(UP);
	setDmg(1);
	return ;
}

Projectile::Projectile(uint x, uint y, AObject::plan_e z, direction_e dir, uint dmg)
						: AObject(x, y, z) {
	setDir(dir);
	setDmg(dmg);
	return ;
}


Projectile::Projectile(Projectile const & src) : AObject(src) {
	*this = src;
	return ;
}

Projectile::~Projectile(void) {
	return ;
}

Projectile & Projectile::operator=(Projectile const & rhs) {
	setX(rhs.getX());
	setY(rhs.getY());
	setDir(rhs.getDir());
	setDmg(rhs.getDmg());
	return *this;
}

std::ostream & operator<<(std::ostream & out, Projectile const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				Projectile::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "Projectile:" << std::endl;
	out << "\tX: " << getX() << std::endl;
	out << "\tY: " << getY() << std::endl;
	out << "\tZ: " << getZ() << std::endl;
	// out << "\tMap ptr: " << getMap() << std::endl;
	out << "\tDirection: " << getDir() << std::endl;
	out << "\tDamage: " << getDmg() << std::endl;
	out << "\033[0m";
	return out.str();
}

AObject::direction_e		Projectile::getDir(void) const {
	return _dir;
}

uint						Projectile::getDmg(void) const {
	return _dmg;
}

void						Projectile::setDir(AObject::direction_e dir) {
	_dir = dir;
	return ;
}

void						Projectile::setDmg(uint dmg) {
	_dmg = dmg;
	return ;
}
