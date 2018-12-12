#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include <unila.h>
#include "unila.h"
#include "unila3.h"
#include "unila2.h"
#include "unila4.h"
/*BASES DE DATOS
  Sección D02
  Calendario 2017A

EQUIPO 3
    INTEGRANTES:
    DIAZ ESCOBAR MUÑOZ VICTOR OTNIEL
    MERCADO NUÑO ALEJANDRO
    REYES SOLORIO DAVID NEFTALI
    RODRIGUEZ GOMEZ JUAN RAMON
    ROMERO ALVAREZ IVAN GERARDO

@DERECHOS RESERVADOS
*/

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_EstudiantespushButton_clicked()
{
    Unila *ventana = new Unila(this);
    //ventana->setModal(true);
    ventana->show();
}

void MainWindow1::on_pushButton_3_clicked()
{
    unila3 *ventana = new unila3(this);
    //ventana->setModal(true);
    ventana->show();
}

void MainWindow1::on_SeccionespushButton_clicked()
{
    unila4 *ventana = new unila4(this);
    //ventana->setModal(true);
    ventana->show();
}

void MainWindow1::on_CalifiacionesspushButton_clicked()
{
    unila2 *ventana = new unila2(this);
    //ventana->setModal(true);
    ventana->show();
}

void MainWindow1::on_pushButton_clicked()
{

}
