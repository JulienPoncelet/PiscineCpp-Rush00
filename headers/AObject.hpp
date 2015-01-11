#ifndef AOBJECT_HPP
# define AOBJECT_HPP

# include <ft_retro.hpp>

class AObject {

public:

	AObject(void);
	AObject(uint x, uint y, plan_e z, Map * map);
	AObject(AObject const & src);
	virtual ~AObject(void);

	AObject 				& operator=(AObject const & src);

	virtual void			move(uint x, uint y);
	virtual std::string		toString(void) const;
	virtual void			shoot(void) const = 0;
	virtual void			destroy(void);
	
	uint					getIndex(void) const;
	objType_e				getType(void) const;
	uint					getX(void) const;
	uint					getY(void) const;
	plan_e					getZ(void) const;
	Map 					* getMap(void) const;	

	void					setIndex(uint index);
	void					setType(objType_e type);
	void					setX(uint x);
	void					setY(uint y);
	void					setMap(Map * map);

protected:

	uint					_index;
	objType_e				_type;
	uint					_x;
	uint					_y;
	plan_e const			_z;
	Map						* _map;

};

std::ostream & operator<<(std::ostream & out, AObject const & src);

#endif
