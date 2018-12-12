#include "unila.h"
#include "ui_unila.h"
#include "unila2.h"
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

Unila::Unila(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Unila)
{
    ui->setupUi(this);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE"); // CREO EL OBJETO DE TIPO BD Y LE IMPORTO EL SQLITE
    mydb.setDatabaseName("departamento.db"); //DIRECCION DE LA BD
    if(!mydb.open())//SI ESTA DESCONECTADA LA BD DEL SISTEMA
        ui->Statuslabel->setText(" No Conectada......");
    else
        ui->Statuslabel->setText("Conectada a la base de datos.....");
}

Unila::~Unila()
{
    delete ui;
}




void Unila::Habilitar()
{
    if(ui->NombrelineEdit->text().length() > 0 && ui->NumEstudiantelineEdit->text().length() > 0 && ui->FechanaclineEdit->text().length() > 0 && ui->SexolineEdit->text().length() > 0 &&  ui->DptoMenorlineEdit->text().length() > 0 &&  ui->DptoPrincipallineEdit->text().length() > 0 && ui->DireccionlineEdit->text().length() > 0 &&  ui->TeleActuallineEdit->text().length() > 0 &&  ui->GradolineEdit->text().length() > 0 )
    {
        ui->GuardarpushButton->setEnabled(true);
    }
    else
    {
        ui->GuardarpushButton->setEnabled(false);
    }
}

void Unila::on_NombrelineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_NumEstudiantelineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_FechanaclineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_SexolineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_DptoMenorlineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_DptoPrincipallineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_DireccionlineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_TeleActuallineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_GradolineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_IdlineEdit_textChanged(const QString &arg1)
{
    Habilitar();
}

void Unila::on_GuardarpushButton_clicked()
{
    MainWindow conn;
    QString  nombre, fechaNac, sexo, dpto_menor, dpto_principal, num_estudiante, direccion, tele_actual , grado;
    nombre = ui->NombrelineEdit->text();
    num_estudiante = ui->NumEstudiantelineEdit->text();
    fechaNac = ui->FechanaclineEdit->text();
    sexo = ui->SexolineEdit->text();
    dpto_menor = ui->DptoMenorlineEdit->text();
    dpto_principal = ui->DptoPrincipallineEdit->text();
    direccion = ui->DireccionlineEdit->text();
    tele_actual = ui->TeleActuallineEdit->text();
    grado = ui->GradolineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into estudiante (nombre, num_estudiante, fechaNac, sexo, dpto_menor, dpto_principal, direccion, tele_actual, grado) values ('"+nombre+"', '"+num_estudiante+"','"+fechaNac+"','"+sexo+"','"+dpto_menor+"','"+dpto_principal+"','"+direccion+"','"+tele_actual+"','"+grado+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr(".......................Save...................!!"),tr("     !!Los datos se guardaron!!     "));
         ui->NombrelineEdit->clear();
         ui->NumEstudiantelineEdit->clear();
         ui->FechanaclineEdit->clear();
         ui->SexolineEdit->clear();
         ui->DptoMenorlineEdit->clear();
         ui->DptoPrincipallineEdit->clear();
         ui->DireccionlineEdit->clear();
         ui->TeleActuallineEdit->clear();
         ui->GradolineEdit->clear();
        conn.connClose();
        on_MostrarpushButton_clicked();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}


void Unila::on_MostrarpushButton_clicked()
{
    MainWindow conn; //CREO UN OBJETO DE LA CLASE MAINWINDOWS DONDE TENDRE EL CONTROL PARA LLAMR LOS METODOS
    QSqlQueryModel * modal = new QSqlQueryModel(); //hará referencia a las distintas columnas por el nombre del role establecido en el modelo.

    conn.connOpen();//ABRO LA BD
    QSqlQuery * qry=new QSqlQuery(conn.mydb);//CREO UN NUEVO QRY DONDE LO CONECTARE CON MY DB Y SELECCIONO LA INFORMACION DE LA BD

    qry->prepare("SELECT * from estudiante");

    qry->exec();
    modal->setQuery(*qry);//METO A LA TABLA TODO LO QUE HAY EN QRY
    ui->tableView->setModel(modal);//ACOMODARA COMO TABLA SIN NECESIDAD DE UN SIZE
    ui->CalificacionespushButton->setEnabled(true);
    //ui->IDEstudiantecomboBox->setModel(modal);
    conn.connClose();//CIERRO MI BD

    qDebug() << (modal->rowCount());//MUESTRA EN CONSOLA EL NUMERO DE COLUMNAS
}



void Unila::on_BuscarpushButton_clicked()
{
    QString codigo=ui->BuscarlineEdit->text();
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * from estudiante WHERE id  ='"+codigo+"' or num_estudiante = '"+codigo+"' or nombre = '"+codigo+"' or fechaNac = '"+codigo+"' or  sexo = '"+codigo+"' or  dpto_menor = '"+codigo+"' or  dpto_principal = '"+codigo+"' or  direccion = '"+codigo+"' or  tele_actual = '"+codigo+"' or  grado = '"+codigo+"'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();

    qDebug() << (modal->rowCount());
}

void Unila::on_CalificacionespushButton_clicked()
{
        QString codigo=ui->BuscarlineEdit->text();
        MainWindow conn;
        QSqlQueryModel * modal = new QSqlQueryModel();
        conn.connOpen();
        QSqlQuery * qry=new QSqlQuery(conn.mydb);

        qry->prepare("SELECT * from informe_calificaciones WHERE id='"+codigo+"' or num_estudiante = '"+codigo+"' or nombre = '"+codigo+"' or fechaNac = '"+codigo+"' or  sexo = '"+codigo+"' or  dpto_menor = '"+codigo+"' or  dpto_principal = '"+codigo+"' or  direccion = '"+codigo+"' or  tele_actual = '"+codigo+"' or  grado = '"+codigo+"'");

        qry->exec();
        unila2 *ventana = new unila2(this);
        ventana->show();


}

void Unila::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    MainWindow conn;
    QString  nombre, id, fechaNac, sexo, dpto_menor, dpto_principal, num_estudiante, direccion, tele_actual , grado; //GUARDARE LA INFORMACION QUE INSERTE EN LOS LINE EDIT
    nombre = ui->NombrelineEMEdit->text();
    id = ui->IdlineEdit->text();
    num_estudiante = ui->NumEstudianteEMlineEdit->text();
    fechaNac = ui->FechanacEMlineEdit->text();
    sexo = ui->SexoEMlineEdit->text();
    dpto_menor = ui->DptoMenorEMlineEdit->text();
    dpto_principal = ui->DptoPrincipalEMlineEdit->text();
    direccion = ui->DireccionEMlineEdit->text();
    tele_actual = ui->TeleActualEMlineEdit->text();
    grado = ui->GradoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from estudiante WHERE id = '"+val+"' or nombre = '"+val+"' or num_estudiante = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->IdlineEdit->setText(qry.value(0).toString());
            ui->NombrelineEMEdit->setText(qry.value(1).toString());
            ui->NumEstudianteEMlineEdit->setText(qry.value(2).toString());
            ui->FechanacEMlineEdit->setText(qry.value(3).toString());
            ui->SexoEMlineEdit->setText(qry.value(4).toString());
            ui->DptoMenorEMlineEdit->setText(qry.value(5).toString());
            ui->DptoPrincipalEMlineEdit->setText(qry.value(6).toString());
            ui->DireccionEMlineEdit->setText(qry.value(7).toString());
            ui->TeleActualEMlineEdit->setText(qry.value(8).toString());
            ui->GradoEMlineEdit->setText(qry.value(9).toString());

            ui->NombrelineEMEdit->setEnabled(true);
            ui->NumEstudianteEMlineEdit->setEnabled(true);
            ui->FechanacEMlineEdit->setEnabled(true);
            ui->SexoEMlineEdit->setEnabled(true);
            ui->DptoMenorEMlineEdit->setEnabled(true);
            ui->DptoPrincipalEMlineEdit->setEnabled(true);
            ui->DireccionEMlineEdit->setEnabled(true);
            ui->TeleActualEMlineEdit->setEnabled(true);
            ui->GradoEMlineEdit->setEnabled(true);
            ui->ModificarpushButton->setEnabled(true);
            ui->EliminarpushButton->setEnabled(true);
            ui->GuardarpushButton->setEnabled(false);
        }
        conn.connClose();
     }
     else

            QMessageBox::critical(this,tr("error::"),qry.lastError().text());

}

void Unila::on_ModificarpushButton_clicked()
{
    MainWindow conn;
    QString  nombre, id, fechaNac, sexo, dpto_menor, dpto_principal, num_estudiante, direccion, tele_actual , grado;
    nombre = ui->NombrelineEMEdit->text();
    id = ui->IdlineEdit->text();
    num_estudiante = ui->NumEstudianteEMlineEdit->text();
    fechaNac = ui->FechanacEMlineEdit->text();
    sexo = ui->SexoEMlineEdit->text();
    dpto_menor = ui->DptoMenorEMlineEdit->text();
    dpto_principal = ui->DptoPrincipalEMlineEdit->text();
    direccion = ui->DireccionEMlineEdit->text();
    tele_actual = ui->TeleActualEMlineEdit->text();
    grado = ui->GradoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update estudiante set nombre = '"+nombre+"', num_estudiante = '"+num_estudiante+"', fechaNac = '"+fechaNac+"', sexo = '"+sexo+"', dpto_menor = '"+dpto_menor+"', dpto_principal = '"+dpto_principal+"', direccion = '"+direccion+"', tele_actual = '"+tele_actual+"', grado = '"+grado+"' where id ='"+id+"'" );

    if(qry.exec())
    {
        QMessageBox::information(this,tr(".......................Editado...................!!"),tr("     !!Los datos se editaron correctamente!!     "));
         ui->NombrelineEMEdit->clear();
         ui->IdlineEdit->clear();
         ui->NumEstudianteEMlineEdit->clear();
         ui->FechanacEMlineEdit->clear();
         ui->SexoEMlineEdit->clear();
         ui->DptoMenorEMlineEdit->clear();
         ui->DptoPrincipalEMlineEdit->clear();
         ui->DireccionEMlineEdit->clear();
         ui->TeleActualEMlineEdit->clear();
         ui->GradoEMlineEdit->clear();

         ui->IdlineEdit->setEnabled(false);
         ui->NombrelineEMEdit->setEnabled(false);
         ui->NumEstudianteEMlineEdit->setEnabled(false);
         ui->FechanacEMlineEdit->setEnabled(false);
         ui->SexoEMlineEdit->setEnabled(false);
         ui->DptoMenorEMlineEdit->setEnabled(false);
         ui->DptoPrincipalEMlineEdit->setEnabled(false);
         ui->DireccionEMlineEdit->setEnabled(false);
         ui->TeleActualEMlineEdit->setEnabled(false);
         ui->GradoEMlineEdit->setEnabled(false);
         ui->EliminarpushButton->setEnabled(false);
         ui->ModificarpushButton->setEnabled(false);
        conn.connClose();
        on_MostrarpushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());

}

void Unila::on_EliminarpushButton_clicked()
{
    MainWindow conn;
    QString  nombre, id, fechaNac, sexo, dpto_menor, dpto_principal, num_estudiante, direccion, tele_actual , grado;
    nombre = ui->NombrelineEMEdit->text();
    id = ui->IdlineEdit->text();
    num_estudiante = ui->NumEstudianteEMlineEdit->text();
    fechaNac = ui->FechanacEMlineEdit->text();
    sexo = ui->SexoEMlineEdit->text();
    dpto_menor = ui->DptoMenorEMlineEdit->text();
    dpto_principal = ui->DptoPrincipalEMlineEdit->text();
    direccion = ui->DireccionEMlineEdit->text();
    tele_actual = ui->TeleActualEMlineEdit->text();
    grado = ui->GradoEMlineEdit->text();

    conn.connOpen();
    QSqlQuery qry ,qry2;
    qry.prepare("Delete from estudiante  where id = '"+id+"'" );
    qry2.prepare("Delete from informe_calificaciones where id_estudiante = '"+id+"'");

    if(qry.exec() && qry2.exec())
    {
        QMessageBox::information(this,tr(".......................Eliminado...................!!"),tr("     !!Los datos se eliminaron correctamente!!     "));
        ui->NombrelineEMEdit->clear();
        ui->IdlineEdit->clear();
        ui->NumEstudianteEMlineEdit->clear();
        ui->FechanacEMlineEdit->clear();
        ui->SexoEMlineEdit->clear();
        ui->DptoMenorEMlineEdit->clear();
        ui->DptoPrincipalEMlineEdit->clear();
        ui->DireccionEMlineEdit->clear();
        ui->TeleActualEMlineEdit->clear();
        ui->GradoEMlineEdit->clear();

        ui->IdlineEdit->setEnabled(false);
        ui->NombrelineEMEdit->setEnabled(false);
        ui->NumEstudianteEMlineEdit->setEnabled(false);
        ui->FechanacEMlineEdit->setEnabled(false);
        ui->SexoEMlineEdit->setEnabled(false);
        ui->DptoMenorEMlineEdit->setEnabled(false);
        ui->DptoPrincipalEMlineEdit->setEnabled(false);
        ui->DireccionEMlineEdit->setEnabled(false);
        ui->TeleActualEMlineEdit->setEnabled(false);
        ui->GradoEMlineEdit->setEnabled(false);
        ui->EliminarpushButton->setEnabled(false);
        ui->ModificarpushButton->setEnabled(false);
        conn.connClose();
        on_MostrarpushButton_clicked();
     }
     else
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());

}



void Unila::on_pushButton_3_clicked()
{
    QMessageBox::information(this,tr("HELP"),tr("PARA ACTIVAR LAS OPCIONES MODIFICAR/ELIMINAR SELECCIONE EN LA TABLA LOS RECUADROS CON: \n\n*id \n *nombre \n *num_estudiante   "));

}
