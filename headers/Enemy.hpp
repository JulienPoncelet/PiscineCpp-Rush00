#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <ft_retro.hpp>

class Enemy : public virtual AShip {

public:

	Enemy(void);
	Enemy(uint x, uint y, plan_e z, Map * map, uint hp, uint max_hp, uint dmg);
	Enemy(Enemy const & src);
	~Enemy(void);

	Enemy 					& operator=(Enemy const & src);

	virtual void			shoot(void) const;
	virtual std::string		toString(void) const;
	virtual void			destroy(void);

private:

	static uint				_amount;

};

std::ostream 				& operator<<(std::ostream & out, Enemy const & src);

#endif
