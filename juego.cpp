#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    mImagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    mImagen->fill(Qt::white);
    QPoint centro = ui->marco->geometry().center();
    m_circulo = new Circulo();
    m_circulo->setposInX(centro.x()-40);
    m_circulo->setposInY(centro.y()-40);
    mPainter = new QPainter(mImagen);
    mPainter->setRenderHint(QPainter::Antialiasing);
    m_color = Qt::black;
    dibujar();
}

Juego::~Juego()
{
    delete ui;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *mImagen);
}

//Se decidió mover de 5 en 5 px para que sea más visible su movimiento

void Juego::on_btnArriba_released()
{
    if(m_circulo->posInY() < 35){
        QMessageBox::warning(this,"Aviso de excedencia","No puede revasar el limite superior");
    } else {
        mImagen->fill(Qt::white);
        m_circulo->setposInY(m_circulo->posInY()-5);
        dibujar();
    }
}


void Juego::on_btnAbajo_released()
{
    if((m_circulo->posInY() + m_circulo->tamanio()/2) > 375){
        QMessageBox::warning(this,"Aviso de excedencia","No puede revasar el limite inferior");
    } else {
        mImagen->fill(Qt::white);
        m_circulo->setposInY(m_circulo->posInY()+5);
        dibujar();
    }
}


void Juego::on_btnIzqueirda_released()
{
    if(m_circulo->posInX() < 15){
        QMessageBox::warning(this,"Aviso de excedencia","No puede revasar el limite izquierdo");
    } else {
    mImagen->fill(Qt::white);
    m_circulo->setposInX(m_circulo->posInX()-5);
    dibujar();
    }
}


void Juego::on_btnDerecha_released()
{
    if((m_circulo->posInX() + m_circulo->tamanio()/2) > 450){
        QMessageBox::warning(this,"Aviso de excedencia","No puede revasar el limite derecho");
    } else {
    mImagen->fill(Qt::white);
    m_circulo->setposInX(m_circulo->posInX()+5);
    dibujar();
    }
}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    config->setWidgetColor(m_circulo->colorCir());//Para que cuando se abra la configuración muestre los valores actuales del circulo
    config->setPositionBarra(m_circulo->tamanio());
    int respuesta = config->exec();
    if (respuesta){
        if(config->colorFlag()){//Para que el circulo no vuelva a su color inicial en caso de que no se lo cambie
            mImagen->fill(Qt::white);
            m_color = config->color().name();
            config->setColor(m_color);
            m_circulo->setColorCir(m_color);
            dibujar();
        }
        if(config->dimFlag()){ //Para que el circulo no vuelva a su tamaño inicial en caso de que no se mueva el slider
            mImagen->fill(Qt::white);
            m_circulo->setTamanio(config->dimension());
            dibujar();
        }
        config->setDimFlag(false);
        config->setColorFlag(false);
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar(){
    QPen pincel;
    pincel.setColor(m_color);
    pincel.setJoinStyle(Qt::MiterJoin);
    pincel.setWidth(3);
    mPainter->setPen(pincel);
    mPainter->drawEllipse(m_circulo->posInX(), m_circulo->posInY(), m_circulo->tamanio(), m_circulo->tamanio());
    update();
}

