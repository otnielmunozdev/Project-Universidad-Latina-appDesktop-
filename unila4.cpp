#include "unila4.h"
#include "ui_unila4.h"
#include "unila3.h"
#include "ui_unila3.h"
#include "unila2.h"
#include "ui_unila2.h"
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

unila4::unila4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unila4)
{
    ui->setupUi(this);
}

unila4::~unila4()
{
    delete ui;
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("departamento.db");

}

void unila4::Habilitar4()
{
    if(ui->NumSeccionlineEdit->text().length() > 0 && ui->ProfesorlineEdit->text().length() > 0 && ui->AniolineEdit->text().length() > 0 && ui->SemestrelineEdit->text().length() > 0 && ui->IdCursolineEdit->text().length() > 0)
    {
        ui->RegistrarSeccionpushButton->setEnabled(true);
    }
    else
    {
        ui->RegistrarSeccionpushButton->setEnabled(false);
    }
}

void unila4::on_NumSeccionlineEdit_textChanged(const QString &arg1)
{
    Habilitar4();
}

void unila4::on_ProfesorlineEdit_textChanged(const QString &arg1)
{
    Habilitar4();
}

void unila4::on_AniolineEdit_textChanged(const QString &arg1)
{
    Habilitar4();
}

void unila4::on_SemestrelineEdit_textChanged(const QString &arg1)
{
    Habilitar4();
}

void unila4::on_IdCursolineEdit_textChanged(const QString &arg1)
{
    Habilitar4();
}

void unila4::Habilitar4_1()
{
    if(ui->NumSeccionEMlineEdit->text().length() > 0 && ui->ProfesorEMlineEdit->text().length() > 0 && ui->AniolineEMEdit->text().length() > 0 && ui->SemestreEMlineEdit->text().length() > 0 && ui->IdCursoEMlineEdit->text().length() > 0)
    {
        ui->ModificarSeccionpushButton->setEnabled(true);
        ui->EliminarSeccionpushButton->setEnabled(true);
    }
    else
    {
        ui->ModificarSeccionpushButton->setEnabled(false);
        ui->EliminarSeccionpushButton->setEnabled(false);
    }
}

void unila4::on_NumSeccionEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar4_1();
}

void unila4::on_ProfesorEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar4_1();
}

void unila4::on_AniolineEMEdit_textChanged(const QString &arg1)
{
    Habilitar4_1();
}

void unila4::on_SemestreEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar4_1();
}

void unila4::on_IdCursoEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar4_1();
}


void unila4::on_RegistrarSeccionpushButton_clicked()
{
    MainWindow conn;
    QString  num_seccion, profesor, anio, semestre, id_curso;
    num_seccion = ui->NumSeccionlineEdit->text();
    profesor = ui->ProfesorlineEdit->text();
    anio = ui->AniolineEdit->text();
    semestre = ui->SemestrelineEdit->text();
    id_curso = ui->IdCursolineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into secciones (num_seccion, profesor, año, semestre, id_curso) values ('"+num_seccion+"', '"+profesor+"','"+anio+"','"+semestre+"','"+id_curso+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                          Complete                        "),tr("     Se ha registrado la Seccion del Curso     "));
         ui->NumSeccionlineEdit->clear();
         ui->ProfesorlineEdit->clear();
         ui->AniolineEdit->clear();
         ui->SemestrelineEdit->clear();
         ui->IdCursolineEdit->clear();
        conn.connClose();
        on_MostrarSeccionpushButton_clicked();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila4::on_MostrarSeccionpushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from secciones");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}

void unila4::on_BuscarSeccionpushButton_clicked()
{
    QString codigo=ui->BuscarSeccionlineEdit->text();
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from secciones WHERE  num_seccion = '"+codigo+"' or profesor = '"+codigo+"' or año = '"+codigo+"' or semestre = '"+codigo+"' or id_curso = '"+codigo+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}

void unila4::on_ModificarSeccionpushButton_clicked()
{
    MainWindow conn;
    QString  id, num_seccion, profesor, anio, semestre, id_curso;
    id = ui->IDSeccionlineEdit->text();
    num_seccion = ui->NumSeccionEMlineEdit->text();
    profesor = ui->ProfesorEMlineEdit->text();
    anio = ui->AniolineEMEdit->text();
    semestre = ui->SemestreEMlineEdit->text();
    id_curso = ui->IdCursoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update secciones set num_seccion = '"+num_seccion+"', profesor = '"+profesor+"', año = '"+anio+"', semestre = '"+semestre+"', id_curso = '"+id_curso+"' where id ='"+id+"'" );

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                       Secciones               "),tr("          La Seccion se ha modificado correctamente     "));
        ui->IDSeccionlineEdit->clear();
        ui->NumSeccionEMlineEdit->clear();
        ui->ProfesorEMlineEdit->clear();
        ui->AniolineEMEdit->clear();
        ui->SemestreEMlineEdit->clear();
        ui->IdCursoEMlineEdit->clear();

        ui->NumSeccionEMlineEdit->setEnabled(false);
        ui->ProfesorEMlineEdit->setEnabled(false);
        ui->AniolineEMEdit->setEnabled(false);
        ui->SemestreEMlineEdit->setEnabled(false);
        ui->IdCursoEMlineEdit->setEnabled(false);
        ui->EliminarSeccionpushButton->setEnabled(false);
        ui->ModificarSeccionpushButton->setEnabled(false);
        conn.connClose();
        on_MostrarSeccionpushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila4::on_EliminarSeccionpushButton_clicked()
{
    MainWindow conn;
    QString  id, num_seccion, profesor, anio, semestre, id_curso;
    id = ui->IDSeccionlineEdit->text();
    num_seccion = ui->NumSeccionEMlineEdit->text();
    profesor = ui->ProfesorEMlineEdit->text();
    anio = ui->AniolineEMEdit->text();
    semestre = ui->SemestreEMlineEdit->text();
    id_curso = ui->IdCursoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from secciones where id = '"+id+"'" );

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                       Secciones               "),tr("          La Seccion del curso se ha eliminado correctamente     "));
        ui->IDSeccionlineEdit->clear();
        ui->NumSeccionEMlineEdit->clear();
        ui->ProfesorEMlineEdit->clear();
        ui->AniolineEMEdit->clear();
        ui->SemestreEMlineEdit->clear();
        ui->IdCursoEMlineEdit->clear();

        ui->NumSeccionEMlineEdit->setEnabled(false);
        ui->ProfesorEMlineEdit->setEnabled(false);
        ui->AniolineEMEdit->setEnabled(false);
        ui->SemestreEMlineEdit->setEnabled(false);
        ui->IdCursoEMlineEdit->setEnabled(false);
        ui->EliminarSeccionpushButton->setEnabled(false);
        ui->ModificarSeccionpushButton->setEnabled(false);
        conn.connClose();
        on_MostrarSeccionpushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila4::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    MainWindow conn;
    QString  id, num_seccion, profesor, anio, semestre, id_curso;
    id = ui->IDSeccionlineEdit->text();
    num_seccion = ui->NumSeccionEMlineEdit->text();
    profesor = ui->ProfesorEMlineEdit->text();
    anio = ui->AniolineEMEdit->text();
    semestre = ui->SemestreEMlineEdit->text();
    id_curso = ui->IdCursoEMlineEdit->text();


    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from secciones WHERE num_seccion = '"+val+"' ");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->IDSeccionlineEdit->setText(qry.value(0).toString());
            ui->NumSeccionEMlineEdit->setText(qry.value(1).toString());
            ui->ProfesorEMlineEdit->setText(qry.value(2).toString());
            ui->AniolineEMEdit->setText(qry.value(3).toString());
            ui->SemestreEMlineEdit->setText(qry.value(4).toString());
            ui->IdCursoEMlineEdit->setText(qry.value(5).toString());

            ui->NumSeccionEMlineEdit->setEnabled(true);
            ui->ProfesorEMlineEdit->setEnabled(true);
            ui->AniolineEMEdit->setEnabled(true);
            ui->SemestreEMlineEdit->setEnabled(true);
            ui->IdCursoEMlineEdit->setEnabled(true);
            ui->ModificarSeccionpushButton->setEnabled(true);
            ui->EliminarSeccionpushButton->setEnabled(true);
        }
        conn.connClose();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}


void unila4::on_pushButton_clicked()
{
    QMessageBox::information(this,tr("HELP"),tr("PARA ACTIVAR LAS OPCIONES MODIFICAR/ELIMINAR SELECCIONE EN LA TABLA LOS RECUADROS CON: \n\n*num_seccion   "));
}
