#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPoint>

class Circulo : public QPoint
{
private:
    int m_posInX;
    int m_posInY;
    int m_tamanio;
public:
    Circulo();
    Circulo(int xpos, int ypos, int tam);
    int posInX() const;
    void setposInX(int value);
    int posInY() const;
    void setposInY(int value);
    int tamanio() const;
    void setTamanio(int value);
};

#endif // CIRCULO_H
