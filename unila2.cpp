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

unila2::unila2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unila2)
{
    ui->setupUi(this);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("departamento.db");
    if(!mydb.open())
        ui->Statuslabel->setText(" No Conectada......");
    else
        ui->Statuslabel->setText("Conectada a la base de datos.....");
}

unila2::~unila2()
{
    delete ui;
}

void unila2::Habilitar2()
{
    if(ui->IDEstudiantelineEdit->text().length() > 0 && ui->SeccionlineEdit->text().length() > 0 && ui->CalificacionlineEdit->text().length() > 0 && ui->GradoNumericolineEdit->text().length() > 0 )
    {
        ui->GuardarCalificacionpushButton->setEnabled(true);

    }
    else
    {
        ui->GuardarCalificacionpushButton->setEnabled(false);

    }
}

void unila2::on_IDEstudiantelineEdit_textChanged(const QString &arg1)
{
  Habilitar2();
}

void unila2::on_SeccionlineEdit_textChanged(const QString &arg1)
{
    Habilitar2();
}

void unila2::on_CalificacionlineEdit_textChanged(const QString &arg1)
{
    Habilitar2();
}

void unila2::on_GradoNumericolineEdit_textChanged(const QString &arg1)
{
    Habilitar2();
}

void unila2::Habilitar2_1()
{
    if(ui->IDEstudianteEMlineEdit->text().length() > 0 && ui->SeccionEMlineEdit->text().length() > 0 && ui->CalificacionEMlineEdit->text().length() > 0 && ui->GradoNumericoEMlineEdit->text().length() > 0 )
    {
        ui->ModificarCalificacionpushButton->setEnabled(true);
        ui->EliminarCalificacionpushButton->setEnabled(true);

    }
    else
    {
        ui->ModificarCalificacionpushButton->setEnabled(false);
        ui->EliminarCalificacionpushButton->setEnabled(false);

    }
}

void unila2::on_IDEstudianteEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar2_1();
}

void unila2::on_SeccionEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar2_1();
}

void unila2::on_CalificacionEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar2_1();
}

void unila2::on_GradoNumericoEMlineEdit_textChanged(const QString &arg1)
{
    Habilitar2_1();
}




void unila2::on_GuardarCalificacionpushButton_clicked()
{
    MainWindow conn;
    QString  id_estudiante, seccion, calificacion, grado_numerico;
    id_estudiante = ui->IDEstudiantelineEdit->text();
    seccion = ui->SeccionlineEdit->text();
    calificacion = ui->CalificacionlineEdit->text();
    grado_numerico = ui->GradoNumericolineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into informe_calificaciones (id_estudiante, seccion, calificacion, grado_numerico) values ('"+id_estudiante+"', '"+seccion+"','"+calificacion+"','"+grado_numerico+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                          Complete                        "),tr("     Se asigno la calificacion al estudiante     "));
         ui->IDEstudiantelineEdit->clear();
         ui->SeccionlineEdit->clear();
         ui->CalificacionlineEdit->clear();
         ui->GradoNumericolineEdit->clear();
        conn.connClose();
        on_MostrarCalifiacionpushButton_clicked();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

void unila2::on_MostrarCalifiacionpushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from informe_calificaciones");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView2->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}

void unila2::on_BuscarCalifiacionpushButton_clicked()
{
    QString codigo=ui->BuscarCalificacionlineEdit->text();
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from informe_calificaciones WHERE id_estudiante = '"+codigo+"' or seccion = '"+codigo+"' or calificacion = '"+codigo+"' or grado_numerico = '"+codigo+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView2->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}


void unila2::on_tableView2_activated(const QModelIndex &index)
{
    QString val = ui->tableView2->model()->data(index).toString();

    MainWindow conn;
    QString  id, id_estudiante, seccion, calificacion, grado_numerico;
    id = ui->IdCalificacionlineEdit->text();
    id_estudiante = ui->IDEstudianteEMlineEdit->text();
    seccion = ui->SeccionEMlineEdit->text();
    calificacion = ui->CalificacionEMlineEdit->text();
    grado_numerico = ui->GradoNumericoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * from informe_calificaciones WHERE id = '"+val+"'  or id_estudiante = '"+val+"' or seccion = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->IdCalificacionlineEdit->setText(qry.value(0).toString());
            ui->IDEstudianteEMlineEdit->setText(qry.value(1).toString());
            ui->SeccionEMlineEdit->setText(qry.value(2).toString());
            ui->CalificacionEMlineEdit->setText(qry.value(3).toString());
            ui->GradoNumericoEMlineEdit->setText(qry.value(4).toString());

            ui->IDEstudianteEMlineEdit->setEnabled(true);
            ui->SeccionEMlineEdit->setEnabled(true);
            ui->CalificacionEMlineEdit->setEnabled(true);
            ui->GradoNumericoEMlineEdit->setEnabled(true);
            ui->ModificarCalificacionpushButton->setEnabled(true);
            ui->EliminarCalificacionpushButton->setEnabled(true);
        }
        conn.connClose();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());

}

void unila2::on_ModificarCalificacionpushButton_clicked()
{
    MainWindow conn;
    QString  id, id_estudiante, seccion, calificacion, grado_numerico;
    id = ui->IdCalificacionlineEdit->text();
    id_estudiante = ui->IDEstudianteEMlineEdit->text();
    seccion = ui->SeccionEMlineEdit->text();
    calificacion = ui->CalificacionEMlineEdit->text();
    grado_numerico = ui->GradoNumericoEMlineEdit->text();


    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update informe_calificaciones set id_estudiante = '"+id_estudiante+"', seccion = '"+seccion+"', calificacion = '"+calificacion+"', grado_numerico = '"+grado_numerico+"' where id ='"+id+"'" );

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                       Calificacion               "),tr("          El informe de calificacion se  edito correctamente     "));
        ui->IdCalificacionlineEdit->clear();
        ui->IDEstudianteEMlineEdit->clear();
        ui->SeccionEMlineEdit->clear();
        ui->CalificacionEMlineEdit->clear();
        ui->GradoNumericoEMlineEdit->clear();

        ui->IDEstudianteEMlineEdit->setEnabled(false);
        ui->SeccionEMlineEdit->setEnabled(false);
        ui->CalificacionEMlineEdit->setEnabled(false);
        ui->GradoNumericoEMlineEdit->setEnabled(false);
        ui->EliminarCalificacionpushButton->setEnabled(false);
        ui->ModificarCalificacionpushButton->setEnabled(false);
        conn.connClose();
        on_MostrarCalifiacionpushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}


void unila2::on_EliminarCalificacionpushButton_clicked()
{
    MainWindow conn;
    QString  id, id_estudiante, seccion, calificacion, grado_numerico;
    id = ui->IdCalificacionlineEdit->text();
    id_estudiante = ui->IDEstudianteEMlineEdit->text();
    seccion = ui->SeccionEMlineEdit->text();
    calificacion = ui->CalificacionEMlineEdit->text();
    grado_numerico = ui->GradoNumericoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from informe_calificaciones where id = '"+id+"'" );

    if(qry.exec())
    {
        QMessageBox::information(this,tr("                      Eliminado                   "),tr("       La calificacion se elimina correctamente     "));
        ui->IdCalificacionlineEdit->clear();
        ui->IDEstudianteEMlineEdit->clear();
        ui->SeccionEMlineEdit->clear();
        ui->CalificacionEMlineEdit->clear();
        ui->GradoNumericoEMlineEdit->clear();

        ui->IDEstudianteEMlineEdit->setEnabled(false);
        ui->SeccionEMlineEdit->setEnabled(false);
        ui->CalificacionEMlineEdit->setEnabled(false);
        ui->GradoNumericoEMlineEdit->setEnabled(false);
        ui->EliminarCalificacionpushButton->setEnabled(false);
        ui->ModificarCalificacionpushButton->setEnabled(false);
        conn.connClose();
        on_MostrarCalifiacionpushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}



void unila2::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("HELP"),tr("PARA ACTIVAR LAS OPCIONES MODIFICAR/ELIMINAR SELECCIONE EN LA TABLA LOS RECUADROS CON: \n\n*id \n *id_estudiante \n *seccion   "));
}
