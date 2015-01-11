#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include <ft_retro.hpp>

class Projectile : public virtual AObject {

public:

	Projectile(void);
	Projectile(uint x, uint y, plan_e z, Map * map, direction_e dir, uint dmg);
	Projectile(Projectile const & src);
	~Projectile(void);

	Projectile 				& operator=(Projectile const & src);

	virtual std::string		toString(void) const;

	direction_e				getDir(void) const;
	uint					getDmg(void) const;

	void					setDir(direction_e dir);	
	void					setDmg(uint dmg);	

private:

	direction_e				_dir;
	uint					_dmg;

};

std::ostream & operator<<(std::ostream & out, Projectile const & src);

#endif
