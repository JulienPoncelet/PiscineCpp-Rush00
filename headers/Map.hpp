#ifndef MAP_HPP
# define MAP_HPP

class Map;

# include <ft_retro.hpp>
# include <AObject.hpp>
# include <CObject.hpp>

class Map {

public:

	Map(uint maxX, uint maxY, CObject * newList);
	Map(Map const & src);
	~Map(void);

	Map 					& operator=(Map const & src);

	std::string				toString(void) const;
	void					display(void) const;
	void					pushObject(AObject * newObject);
	void					popObject(AObject * newObject);
	// void					checkColision(void);

	uint					getMaxX(void) const;
	uint					getMaxY(void) const;
	CObject					* getList(void) const;

	void					setMaxX(uint maxX);
	void					setMaxY(uint maxY);
	void					setList(CObject * newList);

private:

	uint					_maxX;	
	uint					_maxY;
	CObject					* _list;

	Map(void); // Don't call this bitch

};

std::ostream & operator<<(std::ostream & out, Map const & src);

#endif
