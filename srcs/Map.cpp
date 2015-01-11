#include <ft_retro.hpp>

Map::Map(void) {
	setMaxX(20);
	setMaxY(40);
	setList(NULL);
	setEnd(false);
	setScore(0);
	return ;
}

Map::Map(uint maxX, uint maxY, CObject * newList) {
	setMaxX(maxX);
	setMaxY(maxY);
	setList(newList);
	setEnd(false);
	setScore(0);
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
	setEnd(rhs.getEnd());
	setScore(rhs.getScore());
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

void						Map::moveEnemy(void) {
	CObject					* current = getList();
	AObject 				* current_obj;
	uint					x;
	uint					y;

	while (current) {
		current_obj = current->getObj();
		if (current_obj->getType() == ENEMY) {
			x = current_obj->getX();
			y = current_obj->getY();
			if (y == getMaxY() - 1)
				current_obj->destroy();
			else
				current_obj->move(x, y + 1);
		}
		current = current->getNext();
	}
	checkColision();
	return ;
}

void						Map::moveProjectile(void) {
	CObject					* current = getList();
	AObject 				* current_obj;
	uint					x;
	uint					y;	

	while (current) {
		current_obj = current->getObj();
		if (current_obj->getType() == PROJECTILE) {
			x = current_obj->getX();
			y = current_obj->getY();
			if (y == 0)
				current_obj->destroy();
			else
				current_obj->move(x, y - 1);
		}
		current = current->getNext();
	}
	checkColision();
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
				if (master_obj->getType() == PROJECTILE or slave_obj->getType() == PROJECTILE)
					setScore(getScore() + 1000);
				master_obj->destroy();				
				slave_obj->destroy();				
				checkColision();
				return ;
			}		

			slave = slave->getNext();
		}
		master = master->getNext();
	}
	return ;
}

void						Map::endGame(void) {
	setEnd(true);
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

bool						Map::getEnd(void) const {
	return _end;
}

uint						Map::getScore(void) const {
	return _score;
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
	return ;
}

void						Map::setEnd(bool end) {
	_end = end;
	return ;
}

void						Map::setScore(uint score) {
	_score = score;
	return ;
}