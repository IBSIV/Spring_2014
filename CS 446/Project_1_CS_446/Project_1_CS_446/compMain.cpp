#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>


HGLRC	hRC=NULL;
HDC		hDC=NULL;
HWND	hWnd=NUll;
HINSTANCE	hInstance;

bool keys[256];
bool active=TRUE;
bool fullscreen=FALSE;
LRESULT CALLBACK WindProc(HWND, UNIT, WPARAM, LPARAM); //Declaration of WndProc


GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
	if(height==0)
	{
		height=1;
	}
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity;
	

}