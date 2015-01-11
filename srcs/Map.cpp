#include <ft_retro.hpp>

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

void						Map::addRandomEnemy(void) {
	int						randomX = rand() % getMaxX();
	Enemy 					* enemy = new Enemy(randomX, 0, MIDDLEGROUND, this, 1, 1, 1);

	getList()->addObject(enemy);
	return ;
}


void						Map::moveAll(void) {
	CObject					* current = getList();
	AObject 				* current_obj;

	while (current) {
		current_obj = current->getObj();
		if (current_obj->getType() == ENEMY)
			current_obj->move(current_obj->getX(), current_obj->getY() + 1);
		else if (current_obj->getType() == PROJECTILE)
			current_obj->move(current_obj->getX(), current_obj->getY() - 1);
		current = current->getNext();
	}
	return ;
}

void						Map::checkColision(void) {
	CObject					* master = getList()->getFirst();
	CObject					* slave;
	AObject 				* master_obj;
	AObject 				* slave_obj;

	while (master) {
		master_obj = master->getObj();
		slave = master->getNext();
		
		while (slave) {
			slave_obj = slave->getObj();

			if (master_obj->getX() == slave_obj->getX() and master_obj->getY() == slave_obj->getY()) {
				getList()->removeObject(slave_obj);
				getList()->removeObject(master_obj);
				checkColision();
				return ;
			}		

			slave = slave->getNext();
		}
		master = master->getNext();
	}
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