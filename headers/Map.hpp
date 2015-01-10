#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

# include <AObject.hpp>

class Map {

public:

	Map(void);
	Map(Map const & src);
	~Map(void);

	Map 					& operator=(Map const & src);

	std::string				toString(void) const;
	void					display(void) const;
	void					pushObject(AObject * newObject);
	void					popObject(uint index);

	uint					getMaxX(void) const;
	uint					getMaxY(void) const;

	void					setMaxX(uint maxX);
	void					setMaxY(uint maxY);

private:

	uint					_maxX;	
	uint					_maxY;	

};

std::ostream & operator<<(std::ostream & out, Map const & src);

#endif