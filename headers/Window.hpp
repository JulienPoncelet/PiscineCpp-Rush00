#ifndef WINDOW_CLASS
# define WINDOW_CLASS

# include <ft_retro.hpp>

class Window
{
private:
	WINDOW 			*_menuWin;
	WINDOW 			*_gameWin;
	int				_choice;
	int				_highlight;
	uint				_row; 
	uint				_col;
	int const		_menuChoices;
	std::string  	_choices[2];
	Map				*_map;
	time_t			_start;



	void _displayMenu(void);
	void _displayGame(int cd);
	void _playGame(void);
	void _initNcurses(void);
	bool _checkWindow(void);

public:

	// constructor/destructor
	Window();
	Window(Map * map);
	Window(Window const & window);
	virtual ~Window();

	// member function
	std::string const string(void) const;
	void menu(void);

	// methodes
	
	//operator overload
	Window & operator=(Window const & window);
};
// stream overload
std::ostream & operator<<(std::ostream & o, Window const & window);

#endif