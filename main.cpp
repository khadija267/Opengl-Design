/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;
float ypos = 0.0f;
float angle = 50.0f;
float armPos = 2.0f;
float rightRun = 0.0f;
float leftRun = 0.0f;
float move_unit = 0.2f;
float posX=0.01f, posY=0.01f, posZ;
/* GLUT callback Handlers */
void astronaut(){
    // Create body

   glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(0, 0, 0);
    glColor3f(.5,.5,.5);
    glScalef(2.5, 4.5, 0);
    glutSolidSphere(.5,100,100);
    glPopMatrix();

       glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(0, 0, 0);
    glColor3f(0,0,0);
    glScalef(2.5, 4.5, 0);
    glutSolidCube(1);
    glPopMatrix();

    // Create head
    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(1, 3.5, 0);
    glColor3f(.5,.5,.5);
    glScalef(.7, .5, 4);
    glutSolidSphere(.4,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(1, 3, 0);
    glColor3f(.5,.5,.5);
    glScalef(0.1, 1, 1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(0, 2, 0);
    glColor3f(.5,.5,.5);
    glScalef(2, 1.5, 1);
    glutSolidCube(1);
    glPopMatrix();
        glPushMatrix();
        glTranslated(posX,posY,0);
    glTranslatef(0, 2, 0);
    glColor3f(0,0,0);
    glScalef(.7, .5, 4);
    glutSolidSphere(.9,100,100);
    glPopMatrix();
    // Create right leg

    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(-1, -2.5, 0);
    glRotatef(rightRun, 1.0f, 0, 0);
    glColor3f(.5,.5,.5);
    glScalef(1, 3, 2);
    glutSolidSphere(.4,100,100);
    glPopMatrix();

    // Create left leg
    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(1, -2.5, 0);
    glRotatef(leftRun, 1.0f, 0, 0);
    glColor3f(.5,.5,.5);
    glScalef(1, 3, 2);
    glutSolidSphere(.4,100,100);
    glPopMatrix();

    // Right arm
    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(-armPos, 1, 0);
    glRotatef(-angle, 0, 0, 1.0f);
    glColor3f(.5,.5,.5);
    glScalef(1, 3, 2);
    glutSolidSphere(.4,100,100);
    glPopMatrix();

    // Left arm
    glPushMatrix();
    glTranslated(posX,posY,0);
    glTranslatef(armPos, 1, 0);
    //glRotatef(rightRun, 1.0f, 0, 0);
    glRotatef(angle, 0, 0, 1.0f);
    glColor3f(.5,.5,.5);
    glScalef(1, 3, 2);
    glutSolidSphere(.4,100,100);
    glPopMatrix();
}
void keyboardown(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        posX += move_unit;
        break;
    case GLUT_KEY_LEFT:
        posX -= move_unit;
        break;
    case GLUT_KEY_UP:
        posY += move_unit;
        break;
    case GLUT_KEY_DOWN:
        posY -= move_unit;
        break;
    default:
        break;
    }
glutPostRedisplay();
}
void createRobot() {



}
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-10,10,-10,10,-10,10);
astronaut();
//earth
glPushMatrix();
glColor3d(.1,.1,1);
glScaled(.5,.5,1);
glTranslated(-9,15,3);
glutSolidSphere(3,100,100);
glPopMatrix();
//moon
glPushMatrix();
glColor3d(1,1,1);
glScaled(4,2,1);
glRotated(60,1,0,0);
glTranslated(0,-5,0);
glutSolidSphere(3,100,100);
glPopMatrix();
/////////////////////
glPushMatrix();
glColor3d(0,1,1);
glScaled(.2,.2,0);
glRotated(60,1,0,0);
glTranslated(1,80,1);
glutSolidSphere(3,100,100);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,1);
glRotated(30,1,0,0);
glRotated(a,0,1,0);
glTranslated(1,9.5,2);
glScaled(2,2,2);
glutSolidSphere(.2,100,100);
glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutSpecialFunc(keyboardown);
    glutMainLoop();

    return EXIT_SUCCESS;
}
