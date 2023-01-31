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
    m_circulo->setX(centro.x());
    m_circulo->setY(centro.y());
    mPainter = new QPainter(mImagen);
    mPainter->setRenderHint(QPainter::Antialiasing);

    dibujar();
}

Juego::~Juego()
{
    delete ui;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // Dibujar la imagen
    painter.drawImage(0, 0, *mImagen);
}

//Se decidió mover de 10 en 10 px para que sea más visible su movimiento

void Juego::on_btnArriba_released()
{
    mImagen->fill(Qt::white);
    m_circulo->setposInY(m_circulo->posInY()-10);
    dibujar();
}


void Juego::on_btnAbajo_released()
{
    mImagen->fill(Qt::white);
    m_circulo->setposInY(m_circulo->posInY()+10);
    dibujar();
}


void Juego::on_btnIzqueirda_released()
{
    mImagen->fill(Qt::white);
    m_circulo->setposInX(m_circulo->posInX()-10);
    dibujar();
}


void Juego::on_btnDerecha_released()
{
    mImagen->fill(Qt::white);
    m_circulo->setposInX(m_circulo->posInX()+10);
    dibujar();
}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
        mImagen->fill(Qt::white);
        m_circulo->setTamanio(config->dimension());
        dibujar();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar(){
    QPen pincel;
    pincel.setColor(Qt::black);
    pincel.setJoinStyle(Qt::MiterJoin);
    pincel.setWidth(3);
    mPainter->setPen(pincel);
    mPainter->drawEllipse(m_circulo->posInX(), m_circulo->posInY(), m_circulo->tamanio(), m_circulo->tamanio());
    update();
}

