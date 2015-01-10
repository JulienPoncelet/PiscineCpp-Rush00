#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>

# include <AShip.hpp>

class Player : public virtual AShip {

public:

	Player(void);
	Player(uint x, uint y, AObject::plan_e z, uint hp, uint max_hp, uint dmg);
	Player(Player const & src);
	~Player(void);

	Player 					& operator=(Player const & src);

	virtual void			shoot(void) const;
	virtual void			destroy(void);
	virtual std::string		toString(void) const;

private:

	static uint				_amount;

};

std::ostream 	& operator<<(std::ostream & out, Player const & src);

#endif
