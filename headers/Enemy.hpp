#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

# include <AShip.hpp>

class Enemy : public virtual AShip {

public:

	Enemy(void);
	Enemy(uint x, uint y, AObject::plan_e z, uint hp, uint max_hp, uint dmg);
	Enemy(Enemy const & src);
	~Enemy(void);

	Enemy 					& operator=(Enemy const & src);

	virtual void			shoot(void) const;
	virtual void			destroy(void);
	virtual std::string		toString(void) const;

private:

	static uint				_amount;

};

std::ostream 				& operator<<(std::ostream & out, Enemy const & src);

#endif
