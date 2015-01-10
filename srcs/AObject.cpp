#include "AObject.hpp"

AObject::AObject(void) : _z(MIDDLEGROUND) {
	setX(0);
	setY(0);
	// setMap(NULL);
	return ;
}

// ADD MAP
AObject::AObject(uint x, uint y, uint z) : _z(z) {
	setX(x);
	setY(y);
	// setMap(Map);
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
	// setMap(rhs.getMap());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, AObject const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				AObject::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "AObject:" << std::endl;
	out << "\tX: " << getX() << std::endl;
	out << "\tY: " << getY() << std::endl;
	out << "\tZ: " << getZ() << std::endl;
	// out << "\tMap ptr: " << getMap() << std::endl;
	out << "\033[0m";
	return out.str();
}

uint				AObject::getX(void) const {
	return _x;
}

uint				AObject::getY(void) const {
	return _y;
}

uint				AObject::getZ(void) const {
	return _z;
}

// Map 				AObject::getMap(void) const {
// 	return _map;
// }

void				AObject::setX(uint x) {
	_x = x;
	return ;
}

void				AObject::setY(uint y) {
	_y = y;
	return ;
}

// void			AObject::setMap(Map * map) {
// 	_map = map;
// 	return ;
// }
