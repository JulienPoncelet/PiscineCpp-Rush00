#ifndef AOBJECT_HPP
# define AOBJECT_HPP

# include <iostream>
# include <sstream>

// # include <Map.hpp>

typedef unsigned int uint;

class AObject {

public:

	enum plan_e {
		BACKGROUND = 0, MIDDLEGROUND, FOREGROUND
	};

	AObject(void);
	AObject(uint x, uint y, uint z);
	AObject(AObject const & src);
	virtual ~AObject(void);

	AObject 				& operator=(AObject const & src);

	virtual void			move(uint x, uint y) = 0;
	virtual std::string		toString(void) const;
	
	uint					getX(void) const;
	uint					getY(void) const;
	uint					getZ(void) const;
	// Map 					* getMap(void) const;	

	void					setX(uint x);
	void					setY(uint y);
	// void					setMap(Map * map);

protected:

	uint					_x;
	uint					_y;
	uint const				_z;
	// Map						* _map;

};

std::ostream & operator<<(std::ostream & out, AObject const & src);

#endif
