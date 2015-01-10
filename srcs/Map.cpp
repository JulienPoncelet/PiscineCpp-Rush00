#include "Map.hpp"

Map::Map(void) {
	setMaxX(20);
	setMaxY(40);
	setList(NULL);
	return ;
}

Map::Map(uint maxX, uint maxY, CObject * newList) {
	setMaxX(maxX);
	setMaxY(maxY);
	setList(newList);
	return ;
}

Map::Map(Map const & src) {
	*this = src;
	return ;
}

Map::~Map(void) {
	return ;
}

Map & Map::operator=(Map const & rhs) {
	setMaxX(rhs.getMaxX());
	setMaxY(rhs.getMaxY());
	setList(rhs.getList());
	return *this;
}

std::ostream & operator<<(std::ostream & out, Map const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				Map::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "Map:" << std::endl;
	out << "\tMax X: " << getMaxX() << std::endl;
	out << "\tMax Y: " << getMaxY() << std::endl;
	out << "\tList: " << getList() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						Map::display(void) const {
	std::cout << "Je display" << std::endl;
	return ;
}

void						Map::pushObject(AObject * newObject) {
	getList()->addObject(newObject);	
	return ;
}

void						Map::popObject(AObject * newObject) {
	getList()->removeObject(newObject);	
	return ;
}

uint						Map::getMaxX(void) const {
	return _maxX;
}

uint						Map::getMaxY(void) const {
	return _maxY;
}

CObject						* Map::getList(void) const {
	return _list;
}

void						Map::setMaxX(uint maxX) {
	_maxX = maxX;
	return ;
}

void						Map::setMaxY(uint maxY) {
	_maxY = maxY;
	return ;
}

void						Map::setList(CObject * newList) {
	_list = newList;
}