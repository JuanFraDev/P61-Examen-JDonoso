#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>
#include <QColorDialog>
#include "circulo.h"

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT
private:
    Ui::Configuracion *ui;
    QColor m_color;
    int m_dimension;
    bool m_dimFlag;
    bool m_colorFlag;

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion();

    const QColor &color() const;
    int dimension() const;

    void setColor(const QColor &newColor);
    void setDimension(int newDimension);
    void setWidgetColor(const QColor &newColor);

    bool dimFlag() const;

    void setDimFlag(bool newDimFlag);

    bool colorFlag() const;
    void setColorFlag(bool newColorFlag);

    void setPositionBarra(int value);

private slots:
    void on_btnColor_released();

    void on_inDimension_sliderMoved(int position);
    void on_btnColor_clicked();
};

#endif // CONFIGURACION_H
