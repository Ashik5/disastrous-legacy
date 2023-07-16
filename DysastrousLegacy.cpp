# include "iGraphics.h"
#include "bitmap_loader.h"
#include <Windows.h>
#include <GLFW/glfw3.h>

int totalOpt = 3;
int screenWidth,screenHeight;
int playerOneHealth=50;
int screen = 1;
int opt = 1;
bool firstStart = true;
int position = 1;
int charOnePosX = screenWidth*0.5;
int animationIndex = 0;
bool joyStick = false;

void iDraw()
{
	//place your drawing codes here

	iClear();

	iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("images/bg2.png"));
	glColor4f(0, 0, 0, 0.5);
	iFilledRectangle(0,0,screenWidth, screenHeight);
	//player -one 
	iShowImage(46, screenHeight - 134,108,108, iLoadImage("images/char_one_ring.png"));
	iShowImage(50, screenHeight - 130, 100, 100, iLoadImage("images/char_one.png"));


	//top health - player one
	iSetColor(0, 0, 0);
	iFilledRectangle(170, screenHeight - 80, 500, 5);
	iSetColor(153, 153, 255);
	iFilledRectangle(170, screenHeight - 80, 5*playerOneHealth, 5);
	//bottom health - player one
	iSetColor(0, 0, 0);
	iFilledRectangle(170, screenHeight - 90, 400, 5);
	iSetColor(255, 255, 255);
	iFilledRectangle(170, screenHeight - 90, 4*playerOneHealth, 5);


	//player - two 
	iShowImage(screenWidth - 46, screenHeight - 134, -108, 108, iLoadImage("images/char_two_ring.png"));
	iShowImage(screenWidth - 50, screenHeight - 130, -100, 100, iLoadImage("images/char_one.png"));

	//top health - player two
	iSetColor(0, 0, 0);
	iFilledRectangle(screenWidth - 170, screenHeight - 80, -500, 5);
	iSetColor(153, 255, 153);
	iFilledRectangle(screenWidth - 170, screenHeight - 80, -5 * playerOneHealth, 5);
	//bottom health - player two
	iSetColor(0, 0, 0);
	iFilledRectangle(screenWidth - 170, screenHeight - 90, -400, 5);
	iSetColor(255, 255, 255);
	iFilledRectangle(screenWidth - 170, screenHeight - 90, -4 * playerOneHealth, 5);

	//bootom instraction text
	

	//bottom fighting surface
	iSetColor(0, 0, 0);
	iFilledRectangle(0,0,screenWidth,screenHeight/10);



	//char-1
	if (position == 1){
		int idle[6] = { iLoadImage("images/char-1/idle/idle 1.png"),
			iLoadImage("images/char-1/idle/idle 2.png"),
			iLoadImage("images/char-1/idle/idle 3.png"),
			iLoadImage("images/char-1/idle/idle 4.png"),
			iLoadImage("images/char-1/idle/idle 5.png"),
			iLoadImage("images/char-1/idle/idle 6.png")
		}
		;
		if (animationIndex >= 5)
			animationIndex=1;
		animationIndex++;
		iShowImage(charOnePosX, screenHeight / 10, 100, 220, idle[animationIndex]);
		iDelayMS(100);
	}
	if (position == 2){
		int walk[9] = { iLoadImage("images/char-1/walk/Walk 1.png"),
			iLoadImage("images/char-1/walk/Walk 2.png"),
			iLoadImage("images/char-1/walk/Walk 3.png"),
			iLoadImage("images/char-1/walk/Walk 4.png"),
			iLoadImage("images/char-1/walk/Walk 5.png"),
			iLoadImage("images/char-1/walk/Walk 6.png"),
			iLoadImage("images/char-1/walk/Walk 7.png"),
			iLoadImage("images/char-1/walk/Walk 8.png"),
			iLoadImage("images/char-1/walk/Walk 9.png"),
		}
		;
		if (animationIndex >= 8)
			animationIndex = 1;
		animationIndex++;
		iShowImage(charOnePosX, screenHeight / 10, 100, 220,walk[animationIndex] );
		position = 1;
	}
	if (position == 3){
		int jump[9] = { iLoadImage("images/char-1/jump/Jump 1.png"),
			iLoadImage("images/char-1/jump/Jump 2.png"),
			iLoadImage("images/char-1/jump/Jump 3.png"),
			iLoadImage("images/char-1/jump/Jump 4.png"),
			iLoadImage("images/char-1/jump/Jump 5.png"),
			iLoadImage("images/char-1/jump/Jump 6.png"),
			iLoadImage("images/char-1/jump/Jump 7.png"),
			iLoadImage("images/char-1/jump/Jump 8.png"),
			iLoadImage("images/char-1/jump/Jump 9.png"),
		}
		;
		if (animationIndex >= 8)
			animationIndex = 1;
		animationIndex++;
		iShowImage(charOnePosX, screenHeight / 10, 56, 128, jump[animationIndex]);
		position = 1;
	}
	glColor4f(255, 255, 255, 0.5);
	if (joyStick){
		iText(screenHeight / 2, screenWidth / 2, "Joystick connected");
	}
	else{
		iText(screenHeight / 2, screenWidth / 2, "Joystick not connected");
	}
	// menu screen -1
	if (screen==1){
		glColor4f(0, 0, 0, 0.7);
		iFilledRectangle(0, 0, screenWidth, screenHeight);
		//option 1
		if (opt==1){
			glColor3f(255, 255, 255);
		}
		else{
			glColor4f(255, 255, 255, 0.5);
		}
		if (firstStart){
			iText(screenWidth / 2 - 15, screenHeight / 2, "Start", GLUT_BITMAP_9_BY_15);
		}
		else{
			iText(screenWidth / 2 - 15, screenHeight / 2, "Resume", GLUT_BITMAP_9_BY_15);
		}
		//option 2
		if (opt==2){
			glColor3f(255, 255, 255);
		}
		else{
			glColor4f(255, 255, 255, 0.5);
		}
		iText(screenWidth / 2 - 12, screenHeight / 2 - 20, "Choose Character", GLUT_BITMAP_9_BY_15);
		//option 3
		if (opt == 3){
			glColor3f(255, 255, 255);
		}
		else{
			glColor4f(255, 255, 255, 0.5);
		}
		iText(screenWidth / 2 - 12, screenHeight / 2 - 40, "Exit", GLUT_BITMAP_9_BY_15);
		glColor3f(255,255,255);
		//menubar instraction
		iText(screenWidth / 2 - 55, 70, "Use arrow to move", GLUT_BITMAP_9_BY_15);
		iText(screenWidth / 2 - 88, 50, "Please press 'A' to select", GLUT_BITMAP_9_BY_15);
	}


	// character screen - 2
	if (screen == 2){
		glColor4f(0, 0, 0, 0.7);
		iFilledRectangle(0, 0, screenWidth, screenHeight);
		glColor4f(0, 0, 0, 0.3);
		iFilledRectangle(0, 0, screenWidth *0.3, screenHeight);
		int idle[6] = { iLoadImage("images/char-1/idle/idle 1.png"),
			iLoadImage("images/char-1/idle/idle 2.png"),
			iLoadImage("images/char-1/idle/idle 3.png"),
			iLoadImage("images/char-1/idle/idle 4.png"),
			iLoadImage("images/char-1/idle/idle 5.png"),
			iLoadImage("images/char-1/idle/idle 6.png")
		}
		;
		if (animationIndex >= 5)
			animationIndex = 1;
		animationIndex++;
		iShowImage(screenWidth/2, screenHeight / 2, 70, 128, idle[animationIndex]);
		iDelayMS(100);
	}

}
void iMouseMove(int mx, int my)
{
}
void iPassiveMouse(int mx, int my)
{
}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}
void iKeyboard(unsigned char key)
{
	if(key == 'a'|| key == 'A')
	{
		//screen - one 
		if (screen==1){
			if (opt==1){
				screen = 0;
				firstStart = false;
			}
			else if (opt == 2){
				screen = 2;
			}
			else{
				exit(0);
			}
		}
	}
	if (key == 'x' || key == 'X')
	{
		switch (screen)
		{
		case 0:
			screen = 1;
			break;
		case 1:
			screen = 0;
			break;
		case 2:
			screen = 1;
			break;
		}
	}
	if (key == 'w' || key == 'W')
	{
		position = 2;
		charOnePosX += 10;
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_LEFT)
	{
		if (screen==0){
			position = 2;
			charOnePosX -= 10;
		}
		
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if (screen == 0){
			charOnePosX += 3;
			if (position = 2){
				position = 1;
			}
		}
	}
	if (key == GLUT_KEY_UP)
	{
		// screen - one
		if (screen == 1){
			if (opt == 1){
				opt=3;
			}
			else{
				opt--;
			}
		}
		else if(screen == 0){
				position = 3;
				charOnePosX += 10;
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		//screen - one
		if (screen == 1){
			if (opt == totalOpt){
				opt=1;
			}
			else{
				opt++;
			}
		}
	}
}
void glfwJoystickCallback(int jid, int event)
{
	if (event == GLFW_CONNECTED)
	{
		
	}
	else if (event == GLFW_DISCONNECTED)
	{
		
	}
}
int main()
{
	//place your own initialization codes here.
	HWND desktopHandle = GetDesktopWindow();
	if (!glfwInit()){
		return -1;
		}
	// Get the screen dimensions
	RECT desktopRect;
	GetClientRect(desktopHandle, &desktopRect);
	// Calculate the width and height
	screenWidth = desktopRect.right;
	screenHeight = desktopRect.bottom;
	iInitialize(screenWidth, screenHeight, "Disastrous Legacy");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	iStart();
	return 0;
}
