#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainwindow1.h"
#include <mainwindow1.h>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMainWindow>

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
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase mydb; //CREAMOS EL OBJETO QUE USAREMOS PARA   LA BASE DE DATOS

    void connClose() //METODO PARA CERRAR LA BASE DE DATOS
    {
        mydb.close(); //CERRAMOS LA BASE DE DATOS
        mydb.removeDatabase(QSqlDatabase::defaultConnection); //ACTUALIZA LA BASE DE DATOS
    }

    bool connOpen() //METODO PARA ABRIR LA BASE DE DATOS
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE"); //AL OBJETO LE IMPORTAMOS LA BD CON SQLITE
        mydb.setDatabaseName("departamento.db"); //VAMOS A LA DIRECCION DONDE SE ENCUENYRA LA DB

        if(!mydb.open()) //SI NO ESTA CONECTADA LA BD AL SISTEMA
        {
            qDebug()<< ("No Conectada........");
            return false;
         }
        else{
            qDebug()<<("Conectada a la Base de Datos ......");
            return true;

        }
    }

private slots:
    void on_IngresarpushButton_clicked();

private:
    Ui::MainWindow *ui;
    void esconder();
    MainWindow1 *ventana;
};

#endif // MAINWINDOW_H
