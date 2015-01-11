#include <ft_retro.hpp>

AObject::AObject(void) : _z(MIDDLEGROUND) {
	setX(0);
	setY(0);
	setHp(1);
	setMap(NULL);
	return ;
}

AObject::AObject(uint x, uint y, plan_e z, uint hp, Map * map) : _z(z) {
	setX(x);
	setY(y);
	setHp(hp);
	setMap(map);
	return ;
}

AObject::AObject(AObject const & src) : _z(src.getZ()) {
	*this = src;
	return ;
}

AObject::~AObject(void) {
	return ;
}

AObject 					& AObject::operator=(AObject const & rhs) {
	setX(rhs.getX());
	setY(rhs.getY());
	setMap(rhs.getMap());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, AObject const & rhs){
	out << rhs.toString();
	return out;
}

void						AObject::move(uint x, uint y) {
	setX(x);
	setY(y);
	return ;
}

std::string 				AObject::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "AObject:" << std::endl;
	out << "\tX: " << getX() << std::endl;
	out << "\tY: " << getY() << std::endl;
	out << "\tZ: " << getZ() << std::endl;
	out << "\tMap ptr: " << getMap() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						AObject::destroy(void) {
	getMap()->getList()->removeObject(this);
	return ;
}

uint				AObject::getIndex(void) const {
	return _index;
}

objType_e			AObject::getType(void) const {
	return _type;
}

uint				AObject::getX(void) const {
	return _x;
}

uint				AObject::getY(void) const {
	return _y;
}

plan_e				AObject::getZ(void) const {
	return _z;
}

uint				AObject::getHp(void) const {
	return _hp;
}

Map 				* AObject::getMap(void) const {
	return _map;
}

void				AObject::setIndex(uint index) {
	_index = index;
	return ;
}

void				AObject::setType(objType_e type) {
	_type = type;
	return ;
}

void				AObject::setX(uint x) {
	_x = x;
	return ;
}

void				AObject::setY(uint y) {
	_y = y;
	return ;
}

void				AObject::setHp(uint hp) {
	_hp = hp;
	return ;
}

void				AObject::setMap(Map * map) {
	_map = map;
	return ;
}
