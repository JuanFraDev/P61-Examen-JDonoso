#include "circulo.h"

Circulo::Circulo()
    :QPoint(0,0)
{
    m_posInY = 50;
    m_posInX = 20;
    m_tamanio = 100;
}

Circulo::Circulo(int xpos, int ypos, int tam)
    :m_posInX(xpos), m_posInY(ypos), m_tamanio(tam)
{

}

int Circulo::posInX() const
{
    return m_posInX;
}

void Circulo::setposInX(int value)
{
    m_posInX = value;
}

int Circulo::posInY() const
{
    return m_posInY;
}

void Circulo::setposInY(int value)
{
    m_posInY = value;
}

int Circulo::tamanio() const
{
    return m_tamanio;
}

void Circulo::setTamanio(int value)
{
    m_tamanio = value;
}
