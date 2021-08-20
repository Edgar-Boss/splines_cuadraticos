#include <iostream>
#include "glut.h"
#include <math.h> 

int i, x = 1000, y = 1000;  // ventana  1cm =50 pix

void pintar(float x, float y, float r, float g, float b) {

    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2f(x, y);
    glEnd();
    glutSwapBuffers();
}

void Funcion() {
    float v, v1, v2, v3;
    //  funcion G(x)
    for (float i = -10; i < 10; i += 0.03) {
        
        v = (-0.0115*(i*i))-(0.0463*i)+0.6765;
        pintar(i * 50, v * 50, 0.7, 0.7, 0);
    }

}

void plano() {
    for (int i = -x / 2; i < x / 2; i++) {
        pintar(i, 0, 1, 1, 1);
    }
    for (int i = -y / 2; i < y / 2; i++) {
        pintar(0, i, 1, 1, 1);
    }
    Funcion();
}

void cordenadas() {
    int x = 0, y = 0;
    plano();

    pintar(x, y, 0, 0, 0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(x, y);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dibujar Función");
    gluOrtho2D(-x / 2, x / 2, -y / 2, y / 2);
    glutDisplayFunc(cordenadas);
    glutMainLoop();


}