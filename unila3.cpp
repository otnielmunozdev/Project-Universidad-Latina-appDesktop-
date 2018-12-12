#include "unila3.h"
#include "ui_unila3.h"
#include "unila2.h"
#include "ui_unila2.h"
#include "unila4.h"
#include "unila.h"
#include <unila.h>
#include <mainwindow.h>
#include <QtSql>
#include <QFileInfo>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtWidgets>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <stdio.h>
#include <QToolBar>

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

unila3::unila3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unila3)
{
    ui->setupUi(this);
}

unila3::~unila3()
{
    delete ui;
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("departamento.db");

}

void unila3::Habilitar3()
{
    if(ui->UniversidadlineEdit->text().length() > 0 && ui->NombreCursolineEdit->text().length() > 0 && ui->NumeroOficinalineEdit->text().length() > 0)
    {
        ui->GuardarCursopushButton->setEnabled(true);
    }
    else
    {
        ui->GuardarCursopushButton->setEnabled(false);
    }
}

void unila3::Habilitar3_1()
{
    if(ui->UniversidadEMlineEdit->text().length() > 0 && ui->NombreEMlineEdit->text().length() > 0 && ui->NumeroOficinaEMlineEdit->text().length() > 0)
    {
        ui->ModificarCursopushButton->setEnabled(true);
        ui->EliminarCursopushButton->setEnabled(true);
    }
    else
    {
        ui->ModificarCursopushButton->setEnabled(false);
        ui->EliminarCursopushButton->setEnabled(false);
    }
}

void unila3::on_UniversidadEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar3_1();
}

void unila3::on_NombreEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar3_1();
}

void unila3::on_NumeroOficinaEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar3_1();
}


void unila3::on_UniversidadlineEdit_textChanged(const QString &arg1)
{
    Habilitar3();
}

void unila3::on_NombrelineEdit_textChanged(const QString &arg1)
{
    Habilitar3();
}

void unila3::on_NumeroOficinalineEdit_textChanged(const QString &arg1)
{
    Habilitar3();
}

void unila3::on_GuardarCursopushButton_clicked()
{
    MainWindow conn;
    QString  universidad, nombre, num_oficina;
    universidad = ui->UniversidadlineEdit->text();
    nombre = ui->NombreCursolineEdit->text();
    num_oficina = ui->NumeroOficinalineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into cursos (universidad, nombre, num_oficina) values ('"+universidad+"', '"+nombre+"','"+num_oficina+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                          Complete                        "),tr("     Se ha registrado el Curso     "));
         ui->UniversidadlineEdit->clear();
         ui->NombreCursolineEdit->clear();
         ui->NumeroOficinalineEdit->clear();
        conn.connClose();
        on_MostrarCursospushButton_clicked();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila3::on_MostrarCursospushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from cursos");

    qry->exec();
    modal->setQuery(*qry);
    ui->CursotableView->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}

void unila3::on_BuscarCursospushButton_clicked()
{
    QString codigo=ui->BuscarCursolineEdit->text();
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from cursos WHERE id='"+codigo+"' or nombre = '"+codigo+"' or num_oficina = '"+codigo+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->CursotableView->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}

void unila3::on_ModificarCursopushButton_clicked()
{
    MainWindow conn;
    QString  id, universidad, nombre, num_oficina;
    id = ui->IDCursoslineEdit->text();
    universidad = ui->UniversidadEMlineEdit->text();
    nombre = ui->NombreEMlineEdit->text();
    num_oficina = ui->NumeroOficinaEMlineEdit->text();


    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update cursos set universidad = '"+universidad+"', nombre = '"+nombre+"', num_oficina = '"+num_oficina+"' where id ='"+id+"'" );

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                       Cursos               "),tr("          El curso se ha modificado correctamente     "));
        ui->IDCursoslineEdit->clear();
        ui->UniversidadEMlineEdit->clear();
        ui->NombreEMlineEdit->clear();
        ui->NumeroOficinaEMlineEdit->clear();

        ui->UniversidadEMlineEdit->setEnabled(false);
        ui->NombreEMlineEdit->setEnabled(false);
        ui->NumeroOficinaEMlineEdit->setEnabled(false);
        ui->EliminarCursopushButton->setEnabled(false);
        ui->ModificarCursopushButton->setEnabled(false);
        conn.connClose();
        on_MostrarCursospushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila3::on_EliminarCursopushButton_clicked()
{
    MainWindow conn;
    QString  id, universidad, nombre, num_oficina;
    id = ui->IDCursoslineEdit->text();
    universidad = ui->UniversidadEMlineEdit->text();
    nombre = ui->NombreEMlineEdit->text();
    num_oficina = ui->NumeroOficinaEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry, qry2;
    qry.prepare("Delete from cursos where id = '"+id+"'" );
    qry2.prepare("Delete from secciones where id_curso = '"+id+"'");

    if(qry.exec() && qry2.exec())
    {
        QMessageBox::information(this,tr("                       Cursos               "),tr("          El curso se ha elimino junto con las secciones correctamente     "));
        ui->IDCursoslineEdit->clear();
        ui->UniversidadEMlineEdit->clear();
        ui->NombreEMlineEdit->clear();
        ui->NumeroOficinaEMlineEdit->clear();

        ui->UniversidadEMlineEdit->setEnabled(false);
        ui->NombreEMlineEdit->setEnabled(false);
        ui->NumeroOficinaEMlineEdit->setEnabled(false);
        ui->EliminarCursopushButton->setEnabled(false);
        ui->ModificarCursopushButton->setEnabled(false);
        conn.connClose();
        on_MostrarCursospushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}


void unila3::on_CursotableView_activated(const QModelIndex &index)
{
    QString val = ui->CursotableView->model()->data(index).toString();

    MainWindow conn;
    QString  id, universidad, nombre, num_oficina;
    id = ui->IDCursoslineEdit->text();
    universidad = ui->UniversidadEMlineEdit->text();
    nombre = ui->NombreEMlineEdit->text();
    num_oficina = ui->NumeroOficinaEMlineEdit->text();


    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from cursos WHERE id = '"+val+"'  or nombre = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->IDCursoslineEdit->setText(qry.value(0).toString());
            ui->UniversidadEMlineEdit->setText(qry.value(1).toString());
            ui->NombreEMlineEdit->setText(qry.value(2).toString());
            ui->NumeroOficinaEMlineEdit->setText(qry.value(3).toString());

            ui->UniversidadEMlineEdit->setEnabled(true);
            ui->NombreEMlineEdit->setEnabled(true);
            ui->NumeroOficinaEMlineEdit->setEnabled(true);
            ui->ModificarCursopushButton->setEnabled(true);
            ui->EliminarCursopushButton->setEnabled(true);
        }
        conn.connClose();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila3::on_SeccionespushButton_clicked()
{
    unila4 *ventana = new unila4(this);
    //ventana->setModal(true);
    ventana->show();
}

void unila3::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("HELP"),tr("PARA ACTIVAR LAS OPCIONES MODIFICAR/ELIMINAR SELECCIONE EN LA TABLA LOS RECUADROS CON: \n\n*id \n *nombre  "));
}
