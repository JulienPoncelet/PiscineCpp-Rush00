#include "Window.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <ncurses.h>

// constructors /destructor
Window::Window(void) : _choice(0), _highlight(1), _menuChoices(2) {
	std::cout << "Window's constructor called"<< _highlight << _menuChoices << std::endl;
	this->_choices[0] = "Play";
	this->_choices[1] = "Exit";
	initscr();
	clear();
	cbreak();
	noecho();
	curs_set(0);
	getmaxyx(stdscr,this->_row,this->_col);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
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
				std::cerr << "playgame" << std::endl;
				this->_playGame();
			}else if (this->_choice == 2) {
				break;
			}
			this->_choice = 0;
			ch = 0;
		}
		clear();
		this->_displayMenu();
	}
}

void Window::_displayMenu(void) {
	int x, y, i;
	x = 12;
	y = 4;
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

void Window::_displayGame(int x, int y) {
	box(this->_gameWin, 0, 0);

	mvwprintw(this->_gameWin, y-1, x, " ");
	mvwprintw(this->_gameWin, y+1, x, " ");
	mvwprintw(this->_gameWin, y, x-1, " ");
	mvwprintw(this->_gameWin, y, x+1, " ");
	wattron(this->_gameWin, A_REVERSE | A_BOLD);
	mvwprintw(this->_gameWin, y, x, "@");
	wattroff(this->_gameWin, A_REVERSE | A_BOLD);

	wrefresh(this->_gameWin);
}

void Window::_playGame(void) {
	this->_gameWin = newwin(this->_row, this->_col, 0, 0);
	int ch;
	int x, y;
	keypad(this->_gameWin, TRUE);
	x = this->_col / 2;
	y = this->_row / 2;
	clear();
	halfdelay(255);
	this->_displayGame(x, y);
	while (42){
		ch = wgetch(this->_gameWin);
		if (ch == KEY_UP){
			y--;
		}else if (ch == KEY_DOWN){
			y++;
		}else if (ch == KEY_LEFT){
			x--;
		}else if (ch == KEY_RIGHT){
			x++;
		}else if (ch == 'e') {
			wborder(this->_gameWin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
			wrefresh(this->_gameWin);
			delwin(this->_gameWin);
			nocbreak();
			cbreak();
			return;
		}
		this->_displayGame(x, y);
	}
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