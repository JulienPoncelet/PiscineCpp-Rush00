#include <ft_retro.hpp>

CObject						* CObject::_first = NULL;
CObject						* CObject::_last = NULL;

CObject::CObject(void) {
	setObj(NULL);
	setNext(NULL);
	if (getFirst() == NULL)
		setFirst(this);
	if (getLast() == NULL)
		setLast(this);
	return ;
}

CObject::CObject(AObject * first) {
	setObj(first);
	setNext(NULL);	
	if (getFirst() == NULL)
		setFirst(this);
	if (getLast() == NULL)
		setLast(this);
	return ;
}

CObject::CObject(CObject const & src) {
	*this = src;
	return ;
}

CObject::~CObject(void) {
	return ;
}

CObject & CObject::operator=(CObject const & rhs) {
	setObj(rhs.getObj());
	setNext(rhs.getNext());
	return *this;
}

std::ostream & operator<<(std::ostream & out, CObject const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				CObject::toString(void) const {
	std::ostringstream 		out;
	CObject					* current = getFirst();
	int						i = -1;

	out << "\033[36m";
	out << "CObject:" << std::endl;
	while (current->getNext() != NULL) {
		out << "Object #" << ++i << std::endl;
		out << *(current->getObj()) << std::endl;
		current = current->getNext();
	}
	out << "Object #" << ++i << std::endl;
	out << *(current->getObj()) << std::endl;
	out << "\033[0m";
	return out.str();
}

void					CObject::addObject(AObject * obj) {
	CObject 			* last = getLast();
	CObject 			* newElem = new CObject(obj);

	last->setNext(newElem);
	setLast(newElem);
	return ;
}

void					CObject::removeObject(AObject * obj) {
	if (getFirst()->getObj() == obj)
		return removeFirst(getFirst());

	if (getLast()->getObj() == obj)
		return removeLast(getLast());

	CObject 			* current = getFirst();

	while (current != NULL and obj != current->getNext()->getObj()) {
		current = current->getNext();
	}

	current->setNext(current->getNext()->getNext());

	delete obj ;

	return ;
}

void					CObject::removeFirst(CObject * first) {
	setFirst(first->getNext());
	delete first->getObj();
	delete first;
	return ;
}

void					CObject::removeLast(CObject * last) {
	CObject 			* current = getFirst();

	while (current->getNext() != last) {
		current = current->getNext();
	}

	setLast(current);
	current->setNext(NULL);
	delete last;
	return ;
}

void					CObject::removeAll(void) {
	CObject 			* current = this;
	CObject 			* deleteMe;

	while (current) {
		deleteMe = current;

		current = current->getNext();

		delete deleteMe->getObj();
		delete deleteMe;		
	}

	return ;
}

AObject 				* CObject::getObj(void) const {
	return this->obj;
}

CObject 				* CObject::getNext(void) const {
	return this->next;
}

CObject 				* CObject::getFirst(void) const {
	return _first;
}

CObject 				* CObject::getLast(void) const {
	return _last;
}

void					CObject::setObj(AObject * obj) {
	this->obj = obj;
	return ;
}

void					CObject::setNext(CObject * next) {
	this->next = next;
	return ;
}

void					CObject::setFirst(CObject * first) {
	_first = first;
	return ;
}

void					CObject::setLast(CObject * last) {
	_last = last;
	return ;
}
