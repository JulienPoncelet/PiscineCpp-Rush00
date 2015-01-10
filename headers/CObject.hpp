#ifndef COBJECT_HPP
# define COBJECT_HPP

# include <iostream>

# include <AObject.hpp>

class CObject {

public:

	CObject(AObject * first);
	CObject(CObject const & src);
	~CObject(void);

	CObject 				& operator=(CObject const & src);

	std::string				toString(void) const;

	void					addObject(AObject * obj);
	void					removeObject(AObject * obj);
	void					removeFirst(CObject * first);
	void					removeLast(CObject * last);
	void					removeAll(void);

	AObject 				* getObj(void) const;
	CObject 				* getNext(void) const;
	CObject 				* getFirst(void) const;
	CObject 				* getLast(void) const;

	void					setObj(AObject * obj);
	void					setNext(CObject * next);
	void					setFirst(CObject * first);
	void					setLast(CObject * last);

	AObject					* obj;
	CObject 				* next;

private:

	CObject(void); // Don't call this

	static CObject 			* _first;
	static CObject 			* _last;

};

std::ostream				& operator<<(std::ostream & out, CObject const & src);

#endif