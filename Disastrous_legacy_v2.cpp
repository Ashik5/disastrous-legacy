# include "iGraphics.h"
#include "bitmap_loader.h"
#include <Windows.h>
#include <GLFW/glfw3.h>
int screenWidth,screenHeight;
int playerOneHealth=50;
int charOnePosX = 99;
int charOneWidth = 150;
int changeOnMovement = 30;

void iDraw()
{
	//place your drawing codes here

	iClear();

	iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("images/bg2.png"));
	glColor4f(0, 0, 0, 0.5);
	iFilledRectangle(0,0,screenWidth, screenHeight);
	//player -one 
	iShowImage(50, screenHeight - 130, 100, 100, iLoadImage("images/avatar.png"));


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
	iShowImage(screenWidth - 50, screenHeight - 130, -100, 100, iLoadImage("images/avatar.png"));

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
	iShowImage(charOnePosX, screenHeight / 10,charOneWidth, 276, iLoadImage("images/char-1/idle/Idle 1.png"));
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
	}
	if (key == 'x' || key == 'X')
	{
	}
	if (key == 'w' || key == 'W')
	{
	}
}
void charMoveLeft(){
	if (charOneWidth < 0){
		if (charOnePosX - 150 > 0){
			charOnePosX -= changeOnMovement;
		}
		else
		{
			charOnePosX = charOneWidth*-1;
		}
		
	}
	else{
		charOnePosX = charOnePosX+charOneWidth;
		charOneWidth = charOneWidth*-1;
	}
}
void charMoveRight(){
	if (charOneWidth > 0){
		if (charOnePosX + 150 < screenWidth){
			charOnePosX += changeOnMovement;
		}
		else
		{
			charOnePosX = screenWidth-charOneWidth;
		}

	}
	else{
		charOneWidth = charOneWidth*-1;
		charOnePosX = charOnePosX - charOneWidth;
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_LEFT)
	{
		charMoveLeft();
	}
	if(key == GLUT_KEY_RIGHT)
	{
		charMoveRight();
	}
	if (key == GLUT_KEY_UP)
	{
	}
	if (key == GLUT_KEY_DOWN)
	{
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
	screenHeight = desktopRect.bottom-98;
	iInitialize(screenWidth, screenHeight, "Disastrous Legacy");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	iStart();
	return 0;
}
