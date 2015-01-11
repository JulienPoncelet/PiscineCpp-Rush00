#ifndef MAP_HPP
# define MAP_HPP

# include <ft_retro.hpp>

class Map {

public:

	Map(uint maxX, uint maxY, CObject * newList);
	Map(Map const & src);
	~Map(void);

	Map 					& operator=(Map const & src);

	std::string				toString(void) const;

	void					pushObject(AObject * newObject);
	void					popObject(AObject * newObject);

	void					addRandomEnemy(void);
	void					moveEnemy(void);
	void					moveProjectile(void);
	void					checkColision(void);

	void					endGame(void);

	uint					getMaxX(void) const;
	uint					getMaxY(void) const;
	CObject					* getList(void) const;
	bool					getEnd(void) const;

	void					setMaxX(uint maxX);
	void					setMaxY(uint maxY);
	void					setList(CObject * newList);
	void					setEnd(bool end);

private:

	uint					_maxX;	
	uint					_maxY;
	CObject					* _list;
	bool					_end;

	Map(void); // Don't call this bitch

};

std::ostream & operator<<(std::ostream & out, Map const & src);

#endif
