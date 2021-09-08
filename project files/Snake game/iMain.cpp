#define _CRT_SECURE_NO_WARNINGS
#include "igraphics.h"

void movement();
void fruit();
void tail();
void dead();
void game_ground();

double head_dx, head_dy, r = 20, q = 5;

double fruit_dx, fruit_dy;
int score;
char score_show[10];

unsigned char move;

double tail_dx[500], tail_dy[500], tail_1_dx, tail_1_dy, next_tail_dx, next_tail_dy;
int number_of_tail;

int left, right, up, down, i, key_move,game_over;
int option;

double menu_dx = 389, menu_dy = 172, m_width = 459, m_height = 115;
double red, green, blue;

void iDraw()
{
	//place your drawing codes here
	
	iClear();
	if (game_over == 1)
	{
		iShowBMP(0, 0, "pic\\gameOver.bmp");
		iText(520, 300, "Your Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 298, score_show, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (option == 0)
	{
		iShowBMP(0, 0, "pic\\homePage.bmp");

		iSetColor(red, green, blue);
		iRectangle(menu_dx, menu_dy, m_width, m_height);
		iRectangle(menu_dx - .5, menu_dy - .5, m_width + 1, m_height + 1);
		iRectangle(menu_dx - 1, menu_dy - 1, m_width + 2, m_height + 2);
		iRectangle(menu_dx - 1.5, menu_dy - 1.5, m_width + 3, m_height + 3);
		iRectangle(menu_dx - 2, menu_dy - 2, m_width + 4, m_height + 4);
		iRectangle(menu_dx - 2.5, menu_dy - 2.5, m_width + 5, m_height + 5);
		iRectangle(menu_dx - 3, menu_dy - 3, m_width + 6, m_height + 6);
	}
	else if (option == 1)
	{
		iShowBMP(0, 0, "pic\\instruction.bmp");

		iSetColor(red, green, blue);
		iRectangle(menu_dx, menu_dy, m_width, m_height);
		iRectangle(menu_dx - .5, menu_dy - .5, m_width + 1, m_height + 1);
		iRectangle(menu_dx - 1, menu_dy - 1, m_width + 2, m_height + 2);
		iRectangle(menu_dx - 1.5, menu_dy - 1.5, m_width + 3, m_height + 3);
		iRectangle(menu_dx - 2, menu_dy - 2, m_width + 4, m_height + 4);
		iRectangle(menu_dx - 2.5, menu_dy - 2.5, m_width + 5, m_height + 5);
		iRectangle(menu_dx - 3, menu_dy - 3, m_width + 6, m_height + 6);
	}
	else if (option == 2)
	{
		game_ground();
	}
}

void game_ground()
{
	_itoa(score, score_show, 10);
	iSetColor(255, 255, 255);
	iText(1020, 370, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1110, 368, score_show, GLUT_BITMAP_TIMES_ROMAN_24);
	iLine(962, 10, 962, 630);

	iSetColor(255, 14, 58);
	iPoint(fruit_dx, fruit_dy, r - q);			// fruit
	fruit();

	iSetColor(241, 252, 123);
	iPoint(head_dx, head_dy, r);				// head

	for (i = 0; i < number_of_tail - 1; i++)            // tail 
	{
		iSetColor(241, 252, 0);
		iPoint(tail_dx[i], tail_dy[i], r - 3);
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (option == 0)
		{
			if (mx > 389 && mx < 848)
			{
				if (my > 172 && my < 287)
				{
					option = 1;
					m_width = 153;
					m_height = 40;
					menu_dx = 526;
					menu_dy = 66;
				}
			}
			if (mx > 461 && mx < 776)
			{
				if (my > 33 && my < 135)
				{
					exit(0);
				}
				
			}
		}
		else if (option == 1)
		{
			if (mx > 524 && mx < 677)
			{
				if (my > 67 && my < 106)
				{
					option = 2;
				}
			}
		}
	}
}

void iPassiveMouseMove(int mx, int my)
{
	if (option == 0)
	{
		if (my > 33 && my < 135)
		{
			if (mx > 461 && mx < 776)
			{
				menu_dx = 461;
				menu_dy = 33;
				m_width = 315;
				m_height = 102;

				red = 209;
				green = 216;
				blue = 14;
			}
			else
			{
				red = 237;
				green = 43;
				blue = 26;
			}
		}
		else if (my > 172 && my < 287)
		{
			if (mx > 389 && mx < 848)
			{
				menu_dx = 389;
				menu_dy = 172;
				m_width = 459;
				m_height = 115;

				red = 209;
				green = 216;
				blue = 14;
			}
			else
			{
				red = 237;
				green = 43;
				blue = 26;
			}
		}
		else
		{
			red = 237;
			green = 43;
			blue = 26;
		}
	}
	else if (option == 1)
	{
		if (mx > 524 && mx < 677)
		{
			if (my > 67 && my < 106)
			{
				menu_dx = 526;
				menu_dy = 66;  
			
				red = 88;
				green = 13;
				blue = 216;
			}
			else
			{
				red = 237;
				green = 43;
				blue = 26;
			}
		}
		else
		{
			red = 237;
			green = 43;
			blue = 26;
		}
	}
}


void iKeyboard(unsigned char key)
{
	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/

void iSpecialKeyboard(unsigned char key)
{
	//after add tail the code is like this
	if (option == 2 && game_over == 0)
	{
		if (number_of_tail != 0)
		{
			key_move = 1;
			if ((key == GLUT_KEY_UP) && (up == 1))
			{
				left = 1;
				right = 1;
				up = 1;
				down = 0;
			}
			if ((key == GLUT_KEY_DOWN) && (down == 1))
			{
				left = 1;
				right = 1;
				up = 0;
				down = 1;
			}
			if ((key == GLUT_KEY_LEFT) && (left == 1))
			{
				left = 1;
				right = 0;
				up = 1;
				down = 1;
			}
			if ((key == GLUT_KEY_RIGHT) && (right == 1))
			{
				left = 0;
				right = 1;
				up = 1;
				down = 1;
			}
		}
		if (number_of_tail == 0)
		{
			move = key;
			key_move = 0;
		}
	}
}

void movement()
{
	if (key_move == 1)
	{
		if (up == 1)
		{
			head_dy += 40;						// up
		}
		if (down == 1)
		{
			head_dy -= 40;					 //down
		}
		if (left == 1)
		{
			head_dx -= 40;					//left
		}
		if (right == 1)
		{
			head_dx += 40;					//right
		}
	}
	if (key_move == 0)      // when no tail............
	{
		if (move == GLUT_KEY_UP)
		{
			head_dy += 40;         // up
		}
		if (move == GLUT_KEY_DOWN)
		{
			head_dy -= 40;         //down
		}
		if (move == GLUT_KEY_LEFT)
		{
			head_dx -= 40;       //left
		}
		if (move == GLUT_KEY_RIGHT)
		{
			head_dx += 40;       //right;
		}
	}

	if (head_dx > 960)
	{
		head_dx = 20;
	}
	if (head_dy > 640)
	{
		head_dy = 20;
	}
	if (head_dx < 0)
	{
		head_dx = 940;
	}
	if (head_dy < 0)
	{
		head_dy = 620;
	}
}

void fruit()
{
	
	if ((head_dx == fruit_dx) && (head_dy == fruit_dy))
	{
		fruit_dx = ((rand() % 32) * 40) + 20;
		fruit_dy = ((rand() % 18) * 40) + 20;
		score += 10;
		number_of_tail++;

		if (score == 10)
		{
			number_of_tail++;
		}
	}
	for (i = 0; i < number_of_tail; i++)
	{
		if ((tail_dx[i] == fruit_dx) && (tail_dy[i] == fruit_dy))
		{
			fruit_dx = ((rand() % 32) * 40) + 20;
			fruit_dy = ((rand() % 18) * 40) + 20;
		}
	}
	if (fruit_dx > 920 || fruit_dy>620 || fruit_dx < 0 || fruit_dy < 0)
	{
		fruit_dx = ((rand() % 32) * 40) + 20;
		fruit_dy = ((rand() % 18) * 40) + 20;
	}
}

void tail()
{
	tail_1_dx = tail_dx[0];
	tail_1_dy = tail_dy[0];

	tail_dx[0] = head_dx;
	tail_dy[0] = head_dy;

	for (i = 1 ; i < number_of_tail ; i++)
	{
		next_tail_dx = tail_dx[i];
		next_tail_dy = tail_dy[i];

		tail_dx[i] = tail_1_dx;
		tail_dy[i] = tail_1_dy;

		tail_1_dx = next_tail_dx;
		tail_1_dy = next_tail_dy;
	}
}

void dead()
{
	for (i = 0; i < number_of_tail; i++)
	{
		if ((head_dx == tail_dx[i]) && (head_dy == tail_dy[i]))
		{
			number_of_tail = 0;
			left = right = up = down = 1;
			game_over = 1;
		}
	}
}

int main()
{
	srand(time(NULL));
	fruit_dx = ((rand() % 32) * 40) + 20;
	fruit_dy = ((rand() % 18) * 40) + 20;
	fruit();

	head_dx = ((rand() % 32) * 40) + 20;
	head_dy = ((rand() % 18) * 40) + 20;

	left = right = up = down = 1;

	iSetTimer(250, movement);
	iSetTimer(250, tail);
	iSetTimer(250, dead);

	iInitialize(1240, 640, "snake game");
	return 0;
}	

//there is a bug in my game that was........when 1 tail...then....move anywhere.........