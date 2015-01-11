#include <ft_retro.hpp>


// constructors /destructor
Window::Window(void) : _choice(0), _highlight(1), _menuChoices(2) {
	std::cout << "Window's constructor called"<< _highlight << _menuChoices << std::endl;
	this->_choices[0] = "Play";
	this->_choices[1] = "Exit";
	_initNcurses();
}

Window::Window(Map * map) : _choice(0), _highlight(1), _menuChoices(2), _map(map) {
	std::cout << "Window's constructor called"<< _highlight << _menuChoices << std::endl;
	this->_choices[0] = "Play";
	this->_choices[1] = "Exit";
	_initNcurses();
}

Window::Window(Window const & window) : _menuChoices(2){
	std::cout << "Window's copy constructor called" << std::endl;
	this->_choices[0] = "Play";
	this->_choices[1] = "Exit";
	*this = window;
}

Window::~Window(void) {
	std::cout << "Window's destructor called" << std::endl;
	clrtoeol();
	refresh();
	endwin();
}

// members functions
std::string const Window::string(void) const {
	std::ostringstream  out;

	out << "None";

	std::string	res (out.str());
	return res;
}

void Window::_initNcurses(void) {
	initscr();
	clear();
	cbreak();
	noecho();
	curs_set(0);
	getmaxyx(stdscr,this->_row,this->_col);
	start_color();
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

void Window::menu(void) {
	this->_menuWin = newwin(10, 30, this->_row/2-5, this->_col/2-15);
	keypad(this->_menuWin, TRUE);
	int ch;

	clear();
	this->_displayMenu();
	while(this->_choice != this->_menuChoices){
		ch = wgetch(this->_menuWin);
		if (ch == KEY_UP){
			if(this->_highlight == 1){
				this->_highlight = this->_menuChoices;
			}else{
				--this->_highlight;
			}
		}else if (ch == KEY_DOWN){
			if(this->_highlight == this->_menuChoices) {
				this->_highlight = 1;
			} else{
				++this->_highlight;
			}
		} else if (ch == 10) {
			this->_choice = this->_highlight;
			if (this->_choice == 1) {
				wclear(this->_menuWin);
				wrefresh(this->_menuWin);
				this->_playGame();
				break ;
			}else if (this->_choice == 2) {
				break ;
			}
		}
			this->_choice = 0;
			ch = 0;
		clear();
		this->_displayMenu();
	}
}

void Window::_displayMenu(void) {
	int x, y, i;

	x = 10;
	y = 10/2 - this->_menuChoices/2 - 1;
	box(this->_menuWin, 0, 0);
	for(i = 0; i < this->_menuChoices; ++i)
	{	if(this->_highlight == i + 1) /* High light the present choice */
		{
			wattron(this->_menuWin, A_REVERSE | A_BOLD);
			mvwprintw(this->_menuWin, y, x, "%s", this->_choices[i].c_str());
			wattroff(this->_menuWin, A_REVERSE | A_BOLD);
		}
		else
		{
			mvwprintw(this->_menuWin, y, x, "%s", this->_choices[i].c_str());
		}
		++y;
	}
	wrefresh(this->_menuWin);
}

void Window::_displayGame() {
	uint 		color;
	char 		obj[2] = " ";
	uint		hp;

	wclear(this->_gameWin);
	box(this->_gameWin, 0, 0);

	CObject *list = this->_map->getList()->getFirst();
	hp = 3;//list->getObj()->getHp();
	mvwprintw(this->_gameWin, 1, this->_map->getMaxX() - hp - 6, "life: ");
	while (hp) {
		obj[0] = '#';
		wattron(this->_gameWin, COLOR_PAIR(RED));
		mvwprintw(this->_gameWin, 1, this->_map->getMaxX() - hp , obj);
		wattroff(this->_gameWin, COLOR_PAIR(RED));

		hp--;
	}

	while (list) {
		if (list->getObj()->getType() == PLAYER){
			obj[0] = ' ';
			color = A_REVERSE | A_BOLD | COLOR_PAIR(GREEN);
		} else if (list->getObj()->getType() == ENEMY){
			obj[0] = 'V';
			color = COLOR_PAIR(BLUE);
		} else if (list->getObj()->getType() == PROJECTILE){
			obj[0] = '|';
			color = COLOR_PAIR(YELLOW);
		}

		wattron(this->_gameWin, color);
		mvwprintw(this->_gameWin, list->getObj()->getY() + 1, list->getObj()->getX() + 1, obj);
		wattroff(this->_gameWin, color);

		list = list->getNext();
	}

	wrefresh(this->_gameWin);
}

void Window::_playGame(void) {
	clear();
	this->_gameWin = newwin(this->_map->getMaxY() + 2, this->_map->getMaxX() + 2, 0, 0);
	keypad(this->_gameWin, TRUE);
	this->_displayGame();

	clock_t				start;
	int 				randomEnemy = 3;
	int 				input;
	clock_t				now;
	AObject				* player = this->_map->getList()->getFirst()->getObj();

	while (not this->_map->getEnd()){
		wtimeout(this->_gameWin, 10);
		start = clock();

		if (randomEnemy++ == 5) {
			this->_map->addRandomEnemy();
			randomEnemy = 0;
		}

		input = wgetch(this->_gameWin);

		if (input == KEY_LEFT)
			player->move((player->getX()!= 0 ? player->getX() - 1 : 0), player->getY());

		else if (input == KEY_RIGHT)
			player->move(player->getX() + 1,player->getY());

		else if (input == ' ')
			player->shoot();

		else if (input == 'e')
			this->_map->endGame();
		
		this->_map->checkColision();
		this->_map->moveEnemy();
		this->_map->moveProjectile();

		now = clock();
		wrefresh(this->_gameWin);

		usleep(CLOCKS_PER_SEC/FRAME_RATE - (now - start));
		this->_displayGame();
	}
	wclear(this->_gameWin);
	wrefresh(this->_gameWin);
	delwin(this->_gameWin);	
}

//operators overload
Window & Window::operator=(Window const & window) {
	std::cout << "Window's assignation constructor called" << std::endl;
	this->_choice = window._choice;
	return *this;
}

// << overload
std::ostream & operator<<(std::ostream & o, Window const & window){
	o << window.string();
	return o;
}