#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <math.h>
float p=0;
static float	tx	=  0.0;
static float	ty	=  0.0;
float i=0;
float k=0;
int flag=0;
float mv1=0;
//float p=-2.3;
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = rx * cosf(theta);//calculate the x component
        float y = ry * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void init()
{
    glClearColor(0.0f,1.0f,1.0f,1.0f);
    glOrtho(-100,100,-100,150,-100,100);
    PlaySound("evilwelcome2.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //background ->


    glBegin(GL_QUADS);
    glColor3ub(0,0,220);
    glVertex3d(100.0,0.0,0.0);
    glColor3ub(0,0,100);
    glVertex3d(-100.0,0.0,0.0);
    glColor3ub(0,0,100);
    glVertex3d(-100.0,150.0,0.0);
    glColor3ub(0,0,80);
    glVertex3d(100.0,150.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,220);
    glVertex3d(100.0,0.0,0.0);
    glColor3ub(0,0,100);
    glVertex3d(100.0,-100.0,0.0);
    glColor3ub(0,0,100);
    glVertex3d(-100.0,-100.0,0.0);
    glColor3ub(0,0,100);
    glVertex3d(-100.0,0.0,0.0);
    glEnd();

    //background finished

    //main shape ->
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(60.0,85.0,0.0);
    glVertex3d(60.0,67.0,0.0);
    glVertex3d(-60.0,67.0,0.0);
    glVertex3d(-60.0,85.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(60.0,67.0,0.0);
    glVertex3d(59.0,65.0,0.0);
    glVertex3d(-59.0,65.0,0.0);
    glVertex3d(-60.0,67.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(59.0,65.0,0.0);
    glVertex3d(35.0,45.0,0.0);
    glVertex3d(-35.0,45.0,0.0);
    glVertex3d(-59.0,65.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(35.0,45.0,0.0);
    glVertex3d(60.0,35.0,0.0);
    glVertex3d(-60.0,35.0,0.0);
    glVertex3d(-35.0,45.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(60.0,35.0,0.0);
    glVertex3d(60.0,15.0,0.0);
    glVertex3d(-60.0,15.0,0.0);
    glVertex3d(-60.0,35.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(45.0,15.0,0.0);
    glVertex3d(30.0,12.0,0.0);
    glVertex3d(-30.0,12.0,0.0);
    glVertex3d(-45.0,15.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(30.0,12.0,0.0);
    glVertex3d(25.0,9.0,0.0);
    glVertex3d(-25.0,9.0,0.0);
    glVertex3d(-30.0,12.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(25.0,9.0,0.0);
    glVertex3d(23.0,6.0,0.0);
    glVertex3d(-23.0,6.0,0.0);
    glVertex3d(-25.0,9.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3d(23.0,6.0,0.0);
    glVertex3d(22.0,-2.0,0.0);
    glVertex3d(-22.0,-2.0,0.0);
    glVertex3d(-23.0,6.0,0.0);
    glEnd();

    //hair ->

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(-60.0,85.0,0.0);
    glVertex3d(-55.0,90.0,0.0);
    glVertex3d(-50.0,85.0,0.0);
    glVertex3d(-45.0,90.0,0.0);
    glVertex3d(-40.0,85.0,0.0);
    glVertex3d(-35.0,90.0,0.0);
    glVertex3d(-30.0,85.0,0.0);
    glVertex3d(-30.0,85.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(-30.0,85.0,0.0);
    glVertex3d(-25.0,90.0,0.0);
    glVertex3d(-20.0,85.0,0.0);
    glVertex3d(-15.0,90.0,0.0);
    glVertex3d(-10.0,85.0,0.0);
    glVertex3d(-5.0,90.0,0.0);
    glVertex3d(0.0,85.0,0.0);
    glVertex3d(0.0,85.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(0.0,85.0,0.0);
    glVertex3d(5.0,90.0,0.0);
    glVertex3d(10.0,85.0,0.0);
    glVertex3d(15.0,90.0,0.0);
    glVertex3d(20.0,85.0,0.0);
    glVertex3d(25.0,90.0,0.0);
    glVertex3d(30.0,85.0,0.0);
    glVertex3d(30.0,85.0,0.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(30.0,85.0,0.0);
    glVertex3d(35.0,90.0,0.0);
    glVertex3d(40.0,85.0,0.0);
    glVertex3d(45.0,90.0,0.0);
    glVertex3d(50.0,85.0,0.0);
    glVertex3d(55.0,90.0,0.0);
    glVertex3d(60.0,85.0,0.0);
    glVertex3d(60.0,85.0,0.0);
    glEnd();

    // main shape finished

    //nose ->


    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(5.0,4.0-1,0.0);
    glVertex3d(22.0,0.0-1,0.0);
    glVertex3d(9.0,-4.0-1,0.0);
    glVertex3d(0.0,-10.0-1,0.0);
    glVertex3d(-9.0,-4.0-1,0.0);
    glVertex3d(-22.0,0.0-1,0.0);
    glVertex3d(-5.0,4.0-1,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3d(0.0,30.0-1,0.0);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex3d(1.0,0.0+4,0.0);
    glVertex3d(2.0,-1.0+4,0.0);
    glVertex3d(2.0,-2.0+4,0.0);
    glVertex3d(0.0,-1.0+4,0.0);
    glVertex3d(0.0,-1.0+4,0.0);
    glVertex3d(-2.0,-2.0+4,0.0);
    glVertex3d(-2.0,-1.0+4,0.0);
    glVertex3d(-1.0,0.0+4,0.0);
    glEnd();

    //nose finished

    //eyes ->

    if (i<255)
        i+=15;
    else
        i=0;
    glutPostRedisplay();

    glBegin(GL_POLYGON);
    glColor3ub(255,i,0);
    glVertex3d(5.0+20,4.0+42,0.0);
    glVertex3d(15.0+20,0.0+42,0.0);
    glVertex3d(5.0+20,-4.0+42,0.0);
    glVertex3d(0.0+20,-20.0+42,0.0);
    glVertex3d(-5.0+20,-4.0+42,0.0);
    glVertex3d(-15.0+20,0.0+42,0.0);
    glVertex3d(-5.0+20,4.0+42,0.0);
    glVertex3d(0.0+20,10.0+42,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3d(5.0-20,4.0+42,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(15.0-20,0.0+42,0.0);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3d(5.0-20,-4.0+42,0.0);
    glVertex3d(0.0-20,-5.0+42,0.0);
    glVertex3d(-5.0-20,-4.0+42,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(-15.0-20,0.0+42,0.0);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3d(-5.0-20,4.0+42,0.0);
    glVertex3d(0.0-20,5.0+42,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0-20,0.0+42,0.0);
    glVertex3d(1.5-20,-2.0+42,0.0);
    glVertex3d(1.0-20,-4.0+42,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3d(0.0-20,-5.0+42,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-1.0-20,-4.0+42,0.0);
    glVertex3d(-1.5-20,-2.0+42,0.0);
    glVertex3d(-2.0-20,0.0+42,0.0);
    glVertex3d(-2.0-20,2.0+42,0.0);
    glVertex3d(-1.0-20,4.0+42,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3d(0.0-20,5.0+42,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(1.0-20,4.0+42,0.0);
    glVertex3d(2.0-20,2.0+42,0.0);
    glEnd();

    //eyes finished

    //tooth ->


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0,0.0-11,0.0);
    glVertex3d(3.0,-2.0-11,0.0);
    glVertex3d(3.0,-3.0-11,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0,-10.0-11,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0,-3.0-11,0.0);
    glVertex3d(-3.0,-2.0-11,0.0);
    glVertex3d(-2.0,0.0-11,0.0);
    glVertex3d(0.0,1.0-11,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0+5,0.0-11,0.0);
    glVertex3d(3.0+5,-2.0-11,0.0);
    glVertex3d(3.0+5,-3.0-11,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0+5,-10.0-11,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0+5,-3.0-11,0.0);
    glVertex3d(-3.0+5,-2.0-11,0.0);
    glVertex3d(-2.0+5,0.0-11,0.0);
    glVertex3d(0.0+5,1.0-11,0.0);
    glEnd();

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0-5,0.0-11,0.0);
    glVertex3d(3.0-5,-2.0-11,0.0);
    glVertex3d(3.0-5,-3.0-11,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0-5,-10.0-11,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0-5,-3.0-11,0.0);
    glVertex3d(-3.0-5,-2.0-11,0.0);
    glVertex3d(-2.0-5,0.0-11,0.0);
    glVertex3d(0.0-5,1.0-11,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0+10,0.0-11.5,0.0);
    glVertex3d(3.0+10,-2.0-11.5,0.0);
    glVertex3d(3.0+10,-3.0-11.5,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0+10,-10.0-11.5,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0+10,-3.0-11.5,0.0);
    glVertex3d(-3.0+10,-2.0-11.5,0.0);
    glVertex3d(-2.0+10,0.0-11.5,0.0);
    glVertex3d(0.0+10,1.0-11.5,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0-10,0.0-11.5,0.0);
    glVertex3d(3.0-10,-2.0-11.5,0.0);
    glVertex3d(3.0-10,-3.0-11.5,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0-10,-10.0-11.5,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0-10,-3.0-11.5,0.0);
    glVertex3d(-3.0-10,-2.0-11.5,0.0);
    glVertex3d(-2.0-10,0.0-11.5,0.0);
    glVertex3d(0.0-10,1.0-11.5,0.0);
    glEnd();

    //big tooth ->
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(2.5+15,0.0-11,0.0);
    glVertex3d(3.5+15,-2.0-11,0.0);
    glVertex3d(3.5+15,-3.0-11,0.0);
    glColor3ub(0,0,0);
    glVertex3d(0.0+15,-20.0-11,0.0);
        glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(-3.5+15,-3.0-11,0.0);
    glVertex3d(-3.5+15,-2.0-11,0.0);
    glVertex3d(-2.5+15,0.0-11,0.0);
    glVertex3d(0.0+15,1.0-11,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(2.5-15,0.0-11,0.0);
    glVertex3d(3.5-15,-2.0-11,0.0);
    glVertex3d(3.5-15,-3.0-11,0.0);
    glColor3ub(0,0,0);
    glVertex3d(0.0-15,-20.0-11,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(-3.5-15,-3.0-11,0.0);
    glVertex3d(-3.5-15,-2.0-11,0.0);
    glVertex3d(-2.5-15,0.0-11,0.0);
    glVertex3d(0.0-15,1.0-11,0.0);
    glEnd();

    //big tooth finished


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0+20,0.0-12,0.0);
    glVertex3d(3.0+20,-2.0-12,0.0);
    glVertex3d(3.0+20,-3.0-12,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0+20,-10.0-12,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0+20,-3.0-12,0.0);
    glVertex3d(-3.0+20,-2.0-12,0.0);
    glVertex3d(-2.0+20,0.0-12,0.0);
    glVertex3d(0.0+20,1.0-12,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0-20,0.0-12,0.0);
    glVertex3d(3.0-20,-2.0-12,0.0);
    glVertex3d(3.0-20,-3.0-12,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0-20,-10.0-12,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0-20,-3.0-12,0.0);
    glVertex3d(-3.0-20,-2.0-12,0.0);
    glVertex3d(-2.0-20,0.0-12,0.0);
    glVertex3d(0.0-20,1.0-12,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0-25,0.0-13,0.0);
    glVertex3d(3.0-25,-2.0-13,0.0);
    glVertex3d(3.0-25,-3.0-13,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0-25,-10.0-13,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0-25,-3.0-13,0.0);
    glVertex3d(-3.0-25,-2.0-13,0.0);
    glVertex3d(-2.0-25,0.0-13,0.0);
    glVertex3d(0.0-25,1.0-13,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(2.0+25,0.0-13,0.0);
    glVertex3d(3.0+25,-2.0-13,0.0);
    glVertex3d(3.0+25,-3.0-13,0.0);
     glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(0.0+25,-10.0-13,0.0);
     glColor3f(1.0f,1.0f,1.0f);
    glVertex3d(-3.0+25,-3.0-13,0.0);
    glVertex3d(-3.0+25,-2.0-13,0.0);
    glVertex3d(-2.0+25,0.0-13,0.0);
    glVertex3d(0.0+25,1.0-13,0.0);
    glEnd();

    //tooth finished

    //goof ->


    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    glVertex3d(0.5,-10.0+6,0.0);
    glVertex3d(3.0,-7.0+6,0.0);
    glVertex3d(20.0,-7.0+6,0.0);
    glVertex3d(25.0,-8.0+6,0.0);
    glVertex3d(25.0,-16.5+6,0.0);
    glVertex3d(20.0,-16.5+6,0.0);
    glVertex3d(3.0,-16.0+6,0.0);
    glVertex3d(0.5,-13.0+6,0.0);
    glEnd();

    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    glVertex3d(25.0,-8.0+6,0.0);
    glVertex3d(28.0,-9.0+6,0.0);
    glVertex3d(31.0,-11.0+6,0.0);
    glVertex3d(34.0,-15.0+6,0.0);
    glVertex3d(31.0,-21.0+6,0.0);
    glVertex3d(29.0,-18.0+6,0.0);
    glVertex3d(27.0,-17.0+6,0.0);
    glVertex3d(25,-16.5+6,0.0);
    glEnd();

    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    glVertex3d(34.0,-15.0+6,0.0);
    glVertex3d(36.0,-20.0+6,0.0);
    glVertex3d(36.0,-22.0+6,0.0);
    glVertex3d(37.0,-40.0+6,0.0);
    glVertex3d(33.0,-40.0+6,0.0);
    glVertex3d(31.0,-25.0+6,0.0);
    glVertex3d(31.0,-25.0+6,0.0);
    glVertex3d(31.0,-21.0+6,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex3d(37.0,-40.0+6,0.0);
    glVertex3d(37.0,-42.0+6,0.0);
    glVertex3d(40.0,-44.0+6,0.0);
    glColor3ub(255,0,0);
    glVertex3d(45.0,-45.0+6,0.0);
    glVertex3d(45.0,-46.0+6,0.0);
    glColor3ub(255,215,0);
    glVertex3d(40.0,-45.0+6,0.0);
    glVertex3d(35.0,-43.0+6,0.0);
    glVertex3d(33.0,-40.0+6,0.0);
    glEnd();

    //goof right finished

    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    glVertex3d(-0.5,-10.0+6,0.0);
    glVertex3d(-3.0,-7.0+6,0.0);
    glVertex3d(-20.0,-7.0+6,0.0);
    glVertex3d(-25.0,-8.0+6,0.0);
    glVertex3d(-25.0,-16.5+6,0.0);
    glVertex3d(-20.0,-16.5+6,0.0);
    glVertex3d(-3.0,-16.0+6,0.0);
    glVertex3d(-0.5,-13.0+6,0.0);
    glEnd();

    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    glVertex3d(-25.0,-8.0+6,0.0);
    glVertex3d(-28.0,-9.0+6,0.0);
    glVertex3d(-31.0,-11.0+6,0.0);
    glVertex3d(-34.0,-15.0+6,0.0);
    glVertex3d(-31.0,-21.0+6,0.0);
    glVertex3d(-29.0,-18.0+6,0.0);
    glVertex3d(-27.0,-17.0+6,0.0);
    glVertex3d(-25,-16.5+6,0.0);
    glEnd();

    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    glVertex3d(-34.0,-15.0+6,0.0);
    glVertex3d(-36.0,-20.0+6,0.0);
    glVertex3d(-36.0,-22.0+6,0.0);
    glVertex3d(-37.0,-40.0+6,0.0);
    glVertex3d(-33.0,-40.0+6,0.0);
    glVertex3d(-31.0,-25.0+6,0.0);
    glVertex3d(-31.0,-25.0+6,0.0);
    glVertex3d(-31.0,-21.0+6,0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex3d(-37.0,-40.0+6,0.0);
    glVertex3d(-37.0,-42.0+6,0.0);
    glVertex3d(-40.0,-44.0+6,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3d(-45.0,-45.0+6,0.0);
    glVertex3d(-45.0,-46.0+6,0.0);
    glColor3ub(255,215,0);
    glVertex3d(-40.0,-45.0+6,0.0);
    glVertex3d(-35.0,-43.0+6,0.0);
    glVertex3d(-33.0,-40.0+6,0.0);
    glEnd();

    //goof left finished

    //cross ->

    if(k<=9)
        k+=.1;
    else
        k=0;
    glutPostRedisplay();

        /*
        if(flag=0)
        {
            k+=.5;
            if(k==9)
                flag=1;
        }
        else
        {
            k-=.5;
            if(k==0)
                flag=0;
        }
        */
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3d(5.0,68.0+k,0.0);
    glVertex3d(5.0,65.0+k,0.0);
    glColor3ub(205,133,0);
    glVertex3d(-5.0,65.0+k,0.0);
    glVertex3d(-5.0,68.0+k,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3d(1.5,72.0+k,0.0);
    glVertex3d(1.5,50.0+k,0.0);
    glColor3ub(205,133,0);
    glVertex3d(-1.5,50.0+k,0.0);
    glVertex3d(-1.5,72.0+k,0.0);
    glEnd();

    //cross finished

    //tattoo ->

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(60.0,85.0,0.0);
    glVertex3d(60.0,75.0,0.0);
    glVertex3d(45.0,71.0,0.0);
    glVertex3d(40.0,68.0,0.0);
    glVertex3d(39.0,69.0,0.0);
    glVertex3d(45.0,75.0,0.0);
    glVertex3d(60.0,77.0,0.0);
    glVertex3d(60.0,85.0,0.0);
    glEnd();

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(-60.0,85.0,0.0);
    glVertex3d(-60.0,75.0,0.0);
    glVertex3d(-45.0,71.0,0.0);
    glVertex3d(-40.0,68.0,0.0);
    glVertex3d(-39.0,69.0,0.0);
    glVertex3d(-45.0,75.0,0.0);
    glVertex3d(-60.0,77.0,0.0);
    glVertex3d(-60.0,85.0,0.0);
    glEnd();

    //tattoo finished

    //tongue ->

    glColor3ub(139,35,35);
    glBegin(GL_POLYGON);
    glVertex3d(-13.0,-25.0,0.0);
    glVertex3d(-12.0,-30.0,0.0);
    glVertex3d(-10.0,-35.0,0.0);
    glVertex3d(-6.0,-40.0,0.0);
    glVertex3d(20.0,-43.0,0.0);
    glVertex3d(15.0,-37.0,0.0);
    glVertex3d(14.0,-31.0,0.0);
    glVertex3d(13.0,-25.0,0.0);
    glEnd();

    glColor3ub(205,51,51);
    glBegin(GL_POLYGON);
    glVertex3d(20.0,-43.0,0.0);
    glVertex3d(25.0,-50.0,0.0);
    glVertex3d(30.0,-55.0,0.0);
    glVertex3d(30.0,-60.0,0.0);
    glVertex3d(16.0,-60.0,0.0);
    glVertex3d(15.0,-57.0,0.0);
    glVertex3d(10.0,-52.0,0.0);
    glVertex3d(-6.0,-40.0,0.0);
    glEnd();

    glColor3ub(238,59,59);
    glBegin(GL_POLYGON);
    glVertex3d(30.0,-60.0,0.0);
    glVertex3d(30.0,-65.0,0.0);
    glVertex3d(29.0,-67.0,0.0);
    glVertex3d(28.0,-69.0,0.0);
    glVertex3d(26.0,-70.0,0.0);
    glVertex3d(22.0,-67.0,0.0);
    glVertex3d(18.0,-65.0,0.0);
    glVertex3d(16.0,-60.0,0.0);

    glEnd();

    /*glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3d(27.0,-70.5,0.0);
        glVertex3d(15.0,-72.5,0.0);
        glVertex3d(0.1,2.0,0.0);
        glVertex3d(0.1,-3.0,0.0);
    glEnd();*/
/*
int k=0;
    if (i<200)
    {
        i+=.05;
        k+=5;
    }
    else
    {
        i=0;
        k=0;
    }
    glutPostRedisplay();
    glPushMatrix();
    glColor3ub(199, i+50, 45);
    DrawCircle(0,0,k+i,k+i,1000);
    glPopMatrix();

*/
    //tongue finished

    ///tusharpat->
      ///snow
glPushMatrix();
glTranslated(-100,0,0);
glScaled(2,2,1);
   if(mv1<50)
    mv1+=.5;
   else mv1=-50;


     glColor3f(1,1,1);
    glPushMatrix();
    glTranslated(0,70-mv1,0);
         glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+73);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+71);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+80);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+75);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+81);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+72);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+70);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+77);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+5,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+90);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+70,sin(2*3.14159*i/1000.0)*1+89);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+40,sin(2*3.14159*i/1000.0)*1+99);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+85,sin(2*3.14159*i/1000.0)*1+95);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+60,sin(2*3.14159*i/1000.0)*1+98);
    glEnd();
    //////
 glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+50);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+40);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+61);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+58);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
   glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+21,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslated(0,-mv1,0);
         glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+73);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+71);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+80);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+75);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+81);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+72);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+70);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+77);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+5,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+90);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+70,sin(2*3.14159*i/1000.0)*1+89);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+40,sin(2*3.14159*i/1000.0)*1+99);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+85,sin(2*3.14159*i/1000.0)*1+95);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+60,sin(2*3.14159*i/1000.0)*1+98);
    glEnd();
    //////
 glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+50);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+40);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+61);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+58);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
   glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+21,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-70-mv1,0);
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+73);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+71);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+80);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+75);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+81);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+72);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+70);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+77);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+5,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+90);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+70,sin(2*3.14159*i/1000.0)*1+89);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+40,sin(2*3.14159*i/1000.0)*1+99);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+85,sin(2*3.14159*i/1000.0)*1+95);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+60,sin(2*3.14159*i/1000.0)*1+98);
    glEnd();
    //////
 glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+50);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+40);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+61);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+58);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
   glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+21,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-140-mv1,0);
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+73);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+71);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+80);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+75);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+81);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+72);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+85);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+70);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+77);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+5,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+90);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+88);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+70,sin(2*3.14159*i/1000.0)*1+89);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+40,sin(2*3.14159*i/1000.0)*1+99);
    glEnd();
glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+85,sin(2*3.14159*i/1000.0)*1+95);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+60,sin(2*3.14159*i/1000.0)*1+98);
    glEnd();
    //////
 glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+6,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+20.5,sin(2*3.14159*i/1000.0)*1+50);
    glEnd();
      glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+30,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+39,sin(2*3.14159*i/1000.0)*1+40);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+50,sin(2*3.14159*i/1000.0)*1+61);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+59,sin(2*3.14159*i/1000.0)*1+58);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+67,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+79,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+89,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
     glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+98.5,sin(2*3.14159*i/1000.0)*1+55);
    glEnd();
   glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+21,sin(2*3.14159*i/1000.0)*1+60);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<1000;++i)
    glVertex2f(cos(2*3.14159*i/1000.0)*1+15,sin(2*3.14159*i/1000.0)*1+48);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    ///tusharpat end

    glFlush();
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(780,780);
    glutInitWindowPosition(450,50);
    glutCreateWindow("Mask");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
