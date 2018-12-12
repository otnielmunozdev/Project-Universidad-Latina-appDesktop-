#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ventana = new MainWindow1();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::esconder()
{
    this->setVisible(true);
    ventana->setVisible(false);
    QObject::connect(ventana, SIGNAL(back()), this, SLOT(esconder()));
}

void MainWindow::on_IngresarpushButton_clicked()
{
    QString x = "administrador";
    QString y = "UTF-8";
    QString a = "actor";
    QString b = "pontetrucha";

    if(ui->UserNamelineEdit->text()  == x && ui->PasswordlineEdit->text()== y||ui->UserNamelineEdit->text()  == a && ui->PasswordlineEdit->text()== b)
    {
        QMessageBox::information(this,tr("..........................BIENVENIDO........................!!"),tr("     !!Accediendo al sistema de base de datos de la Universidad Latina !!     "));
        this->setVisible(false);
        ventana->setVisible(true);

    }
    else
    {
        QMessageBox::critical(this,tr(".......................ERROR...................!!"),tr("     !!INTRODUZCA DATOS CORRECTOS!!     "));

    }
}
