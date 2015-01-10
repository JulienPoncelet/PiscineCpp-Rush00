#ifndef AOBJECT_HPP
# define AOBJECT_HPP

class AObject;

# include <sstream>

# include <Map.hpp>
# include <ft_retro.hpp>

class AObject {

public:

	enum plan_e {
		BACKGROUND = 1, MIDDLEGROUND, FOREGROUND
	};

	enum direction_e {
		UP = 1, RIGHT, DOWN, LEFT 
	};

	AObject(void);
	AObject(uint x, uint y, plan_e z);
	AObject(AObject const & src);
	virtual ~AObject(void);

	AObject 				& operator=(AObject const & src);

	void					move(uint x, uint y);
	virtual std::string		toString(void) const;
	
	uint					getIndex(void) const;
	uint					getX(void) const;
	uint					getY(void) const;
	plan_e					getZ(void) const;
	Map 					* getMap(void) const;	

	void					setIndex(uint index);
	void					setX(uint x);
	void					setY(uint y);
	void					setMap(Map * map);

protected:

	uint					_index;
	uint					_x;
	uint					_y;
	plan_e const			_z;
	Map						* _map;

};

std::ostream & operator<<(std::ostream & out, AObject const & src);

#endif
