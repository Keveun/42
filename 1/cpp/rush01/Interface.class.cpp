#include "Interface.class.hpp"
#include ""
#include <curses.h>

#define ESCAPE 27
#define MOD1	49
#define MOD2	50
#define MOD3	51
#define MOD4	52
#define MOD5	53
#define MOD6	54

Interface::Interface(void) : _y(0)
{
	return ;
}

Interface::~Interface(void)
{
	endwin();
	return ;
}

void	Interface::init_ncurse(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_GREEN, COLOR_GREEN);
	init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_GREEN, COLOR_BLACK);
	init_color(12, 300, 300, 300);
	init_pair(13, 12, COLOR_BLACK);
	init_pair(14, COLOR_CYAN, COLOR_BLACK);
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
}

int		Interface::getKey(void)
{
	int		key = 0;

	switch ((key = getch()))
	{
		case MOD1:
			this->_module |= 0 << 1;
			(this->_module & (0 << 1)) ? this->_y += ram->getHeigh() : ;
			break ;
		/*case MOD2:
			this->_module |= 1 << 1;
			(this->_module & (1 << 1)) ? this->_y += ram->getHeigh() : ;
			break ;
		case MOD3:
			this->_module |= 2 << 1;
			(this->_module & (2 << 1)) ? this->_y += ram->getHeigh() : ;
			break ;
		case MOD4:
			this->_module |= 3 << 1;
			(this->_module & (3 << 1)) ? this->_y += ram->getHeigh() : ;
			break ;
		case MOD5:
			this->_module |= 4 << 1;
			(this->_module & (4 << 1)) ? this->_y += ram->getHeigh() :  ;
			break ;
		case MOD6: this->_module |= 5 << 1;
			(this->_module & (5 << 1)) ? this->_y += ram->getHeigh() : ;
			break ;
		default: mvprintw(0, 0, "key: %d", key);*/
	}
	return (key);
}

void	Interface::start(void)
{
	int		key;
	CPU		cpu;
	//Ram		ram;

	this->init_ncurse();
	while ((key = this->getKey()) != ESCAPE)
	{
		if (this->_module & (0 << 1))
			cpu.display(this->_y);
		/*if (this->module & (1 << 1))
			
		if (this->module & (2 << 1))
			
		if (this->module & (3 << 1))
			
		if (this->module & (4 << 1))
			
		if (this->module & (5 << 1))*/
			
	}
}
