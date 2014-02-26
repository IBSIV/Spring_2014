// CS_446_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Sample code for CS446 Project 1 Part2
 *
 * Instructor: Qi Li
 *
 */

#include <stdio.h>
#include <math.h>
#include <gl/glut.h>


void keyboard (unsigned char key, int x, int y);
void mouse (int button, int state, int x, int y);
void init (void);
void display(void);
void menu(int id);

// Fill your code to declare a number of global variables to
// store the geometry information, including position, orientation, and scaling
// ...

int main(int argc, char** argv)
{
    int subMenu_Translation;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Interactive 2D Transformation");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    // create sub menu for translation
    subMenu_Translation = glutCreateMenu(menu);
    // The second parameter of glutAddMenuEntry() is the ID that will be used in menu()
    glutAddMenuEntry("Horizontal increment", 1);
    // Fill your code here to add rest menu entries for translation
    // ...

    // Fill your code here to creat sub menu for scaling and its menu entries
    // ...

    // Fill your code here to creat sub menu for rotation and its menu entries
    // ...


    // create main "right click" menu
    glutCreateMenu(menu);
    glutAddSubMenu("Translation", subMenu_Translation);
    // Fill your code here to add submenus of scaling and rotation
    // ...
    glutAddMenuEntry("Quit", 'q');
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    init ();
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}

void keyboard (unsigned char key, int x, int y)
{ int i;

  switch (key)
    {
    case 'q':
      exit (0);
      break;
    case 'c':
      glClear (GL_COLOR_BUFFER_BIT);
      break;
    default:
      break;
    }
}


void mouse (int button, int state, int x, int y)
{
  int i;

  switch (button)
    {
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN) {
	// Fill your code to initialize the position of an object, i.e., the save the (x,y)
	// of a left click
	// ...

	glutPostRedisplay();
      }
      break;
    default:
      break;
    }
}

void init (void)
{
  /*  select clearing (background) color       */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  /*  initialize viewing values  */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(void)
{

  /*  clear all pixels  */
  glClear (GL_COLOR_BUFFER_BIT);

  glColor3f (1.0, 1.0, 1.0);
  // Fill your code to draw an object (you can choose your favorate object)
  // under an interactive 2D transformation
  // ...

  // Fill your code to reset some variables if necessary
  // ...


  /*  don't wait!
   *  start processing buffered OpenGL routines
   */
  glFlush ();
}

void menu(int id)
{
	  switch(id) {
  case 1:  // 1 is the ID (chosed by a programmar, refer to main()) for horizontal translation
    // Fill your code to update the variable associated with horizontal translation
    // ...
    glutPostRedisplay();
    break;

  // Fill your code to handle the other transformation
  // ...

  case 'q':
    exit(0);
  }
}


