/* 
Computer Graphics Assignment
Group Members:
            KIDUS ASEBE     |   
			NAFYAD DACHASA  |   
		

*/

#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Window dimensions
int windowWidth = 600;
int windowHeight = 580;

// Circle parameters
int centerX = windowWidth / 2;
int centerY = windowHeight / 2;
int outerCircleRadius = 150;
int smallerCircleRadius = 120;
int additionalCircleRadius = 187; // Added radius for the new big circle
int circleWidth = 15;

int numSegments = 100;

void myInit(void) {

    glClearColor(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0, 1.0); // Dark blue background

    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
}

void drawDoubleCircle() {
    // Draw the outer circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(10.0 / 255.0, 88.0 / 255.0, 156.0 / 255.0);
    glVertex2i(centerX, centerY);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = outerCircleRadius * cos(theta);
        float y = outerCircleRadius * sin(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();

    // Draw the smaller white circle inside the inner circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glVertex2i(centerX, centerY);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = smallerCircleRadius * cos(theta);
        float y = smallerCircleRadius * sin(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();

    // Draw the new big circle with a width of 15
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(191.0 / 255.0, 37.0 / 255.0, 38.0 / 255.0);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float outerX = (additionalCircleRadius + circleWidth) * cos(theta);
        float outerY = (additionalCircleRadius + circleWidth) * sin(theta);
        float innerX = (additionalCircleRadius - circleWidth) * cos(theta);
        float innerY = (additionalCircleRadius - circleWidth) * sin(theta);
        glVertex2f(centerX + outerX, centerY + outerY);
        glVertex2f(centerX + innerX, centerY + innerY);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawDoubleCircle();

    glBegin(GL_QUADS); //left leg

    glColor3f(10.0 / 255.0, 88.0 / 255.0, 156.0 / 255.0);
    glVertex2i(335, 480); //Vertex A
    glVertex2i(380, 480); //Vertex B
    glVertex2i(200, 130); // Vertex D
    glVertex2i(150, 130); //Vertex C

    glEnd();

    glBegin(GL_QUADS); //right leg

    glColor3f(10.0 / 255.0, 88.0 / 255.0, 156.0 / 255.0);
    glVertex2i(335, 480); //Vertex A
    glVertex2i(380, 480); //Vertex B
    glVertex2i(380, 220); // Vertex D
    glVertex2i(335, 220); //Vertex C

    glEnd();

    glBegin(GL_QUADS); //Hyphen of A

    glColor3f(10.0 / 255.0, 88.0 / 255.0, 156.0 / 255.0);
    glVertex2i(239.5, 300); //Vertex A
    glVertex2i(380, 300);
    glVertex2i(380, 254.5);
    glVertex2i(218.5, 254.5);

    glEnd();

    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(341, 500); // Starting point of the line
    glVertex2f(127, 96); // Ending point of the line

    //////////////

    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(413, 317); // Starting point of the line
    glVertex2f(309.5, 200); // Ending point of the line

    //////////////////
    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(407, 248); // Starting point of the line
    glVertex2f(314.5, 345); // Ending point of the line

    ///////////////////
    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(241, 200); // Starting point of the line
    glVertex2f(186, 96); // Ending point of the line

    ///////////////////////

    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(385, 480); // Starting point of the line
    glVertex2f(385, 350); // Ending point of the line

    ///////////////   horizontal line for a left leg bottom

    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(175, 125); // Starting point of the line
    glVertex2f(200, 125); // Ending point of the line

    /////////////// horizontal line for a  left leg top

    glLineWidth(10.0);
    glColor3f(16.0 / 255.0, 43.0 / 255.0, 55.0 / 255.0);

    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(335, 485); // Starting point of the line
    glVertex2f(370, 485); // Ending point of the line

    glEnd(); // E

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Avengers LOGO");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return EXIT_SUCCESS;
}