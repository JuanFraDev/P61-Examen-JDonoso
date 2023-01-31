/************************
 * Nombre: Juan Donoso  *
 * Cedula: 1723514335   *
 * **********************/

#include "juego.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();
    return a.exec();
}
