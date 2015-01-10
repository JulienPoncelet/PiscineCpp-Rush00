#ifndef SHIP_HPP
# define SHIP_HPP

# include <iostream>

# include <AObject.hpp>

class AShip : public virtual AObject {

public:

	AShip(void);
	AShip(uint x, uint y, AObject::plan_e z, uint hp, uint max_hp, uint dmg);
	AShip(AShip const & src);
	virtual ~AShip(void);

	AShip 					& operator=(AShip const & src);

	virtual void			shoot(void) const = 0;
	virtual void			destroy(void) = 0;
	virtual std::string		toString(void) const;

	uint					getHp(void) const;
	uint					getMaxHp(void) const;
	uint					getDmg(void) const;

	void					setHp(uint hp);
	void					setMaxHp(uint maxHp);
	void					setDmg(uint dmg);

protected:

	uint					_hp;
	uint					_maxHp;
	uint					_dmg;

};

std::ostream 	& operator<<(std::ostream & out, AShip const & src);

#endif
