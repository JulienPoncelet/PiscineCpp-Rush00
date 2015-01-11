#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <ft_retro.hpp>

class Player : public virtual AShip {

public:

	Player(void);
	Player(uint x, uint y, plan_e z, Map * map, uint hp, uint max_hp, uint dmg);
	Player(Player const & src);
	~Player(void);

	Player 					& operator=(Player const & src);

	virtual void			move(uint x, uint y);
	virtual void			shoot(void) const;
	virtual void			destroy(void);
	virtual std::string		toString(void) const;

private:

	static uint				_amount;

};

std::ostream 	& operator<<(std::ostream & out, Player const & src);

#endif
