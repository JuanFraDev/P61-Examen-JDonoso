#include "configuracion.h"
#include "ui_configuracion.h"

bool Configuracion::dimFlag() const
{
    return m_dimFlag;
}

void Configuracion::setDimFlag(bool newDimFlag)
{
    m_dimFlag = newDimFlag;
}

bool Configuracion::colorFlag() const
{
    return m_colorFlag;
}

void Configuracion::setColorFlag(bool newColorFlag)
{
    m_colorFlag = newColorFlag;
}

void Configuracion::setPositionBarra(int value)
{
    ui->inDimension->setSliderPosition(value);
}

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
    m_color = Qt::black;
    setWidgetColor(m_color);
    m_dimension = 100;
    m_dimFlag = false;
    m_colorFlag = false;
    ui->inDimension->setSliderPosition(100);
}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::on_btnColor_released()
{

}

void Configuracion::setColor(const QColor &newColor)
{
    m_color = newColor;
}

void Configuracion::setDimension(int newDimension)
{
    m_dimension = newDimension;
}

void Configuracion::setWidgetColor(const QColor &newColor)
{
    int r = newColor.red();
    int g = newColor.green();
    int b = newColor.blue();
    QString style = "background-color: rgb(" + QString::number(r) + ", " + QString::number(g) + ", " + QString::number(b) + ")";
    ui->wigetColor->setStyleSheet(style);
}

const QColor &Configuracion::color() const
{
    return m_color;
}

int Configuracion::dimension() const
{
    return m_dimension;
}

void Configuracion::on_inDimension_sliderMoved(int position)
{
    m_dimension = ui->inDimension->value();
    m_dimFlag = true;
}

void Configuracion::on_btnColor_clicked()
{
    m_color = QColorDialog::getColor(m_color,
                                    this,
                                    "Color de la circunferencia");
    setWidgetColor(m_color);
    m_colorFlag = true;
}


