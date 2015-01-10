#ifndef WINDOW_CLASS
# define WINDOW_CLASS

# include <iostream>
# include <sstream>
# include <ncurses.h>

class Window
{
private:
	WINDOW 			*_menuWin;
	WINDOW 			*_gameWin;
	int				_choice;
	int				_highlight;
	int				_row; 
	int				_col;
	int const		_menuChoices;
	std::string  	_choices[2];


	void _displayMenu(void);
	void _displayGame(int x, int y);
	void _playGame(void);

public:

	// constructor/destructor
	Window();
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