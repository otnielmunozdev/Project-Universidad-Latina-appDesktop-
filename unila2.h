#ifndef UNILA2_H
#define UNILA2_H
#include "unila.h"

#include <QDialog>

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
class unila2;
}

class unila2 : public QDialog
{
    Q_OBJECT

public:
    explicit unila2(QWidget *parent = 0);
    ~unila2();
    void Habilitar2();
    void Habilitar2_1();

private slots:


    void on_GuardarCalificacionpushButton_clicked();

    void on_MostrarCalifiacionpushButton_clicked();

    void on_BuscarCalifiacionpushButton_clicked();

    void on_ModificarCalificacionpushButton_clicked();

    void on_tableView2_activated(const QModelIndex &index);

    void on_EliminarCalificacionpushButton_clicked();



    void on_IDEstudiantelineEdit_textChanged(const QString &arg1);

    void on_SeccionlineEdit_textChanged(const QString &arg1);

    void on_CalificacionlineEdit_textChanged(const QString &arg1);

    void on_GradoNumericolineEdit_textChanged(const QString &arg1);

    void on_IDEstudianteEMlineEdit_textChanged(const QString &arg1);

    void on_SeccionEMlineEdit_textChanged(const QString &arg1);

    void on_CalificacionEMlineEdit_textChanged(const QString &arg1);

    void on_GradoNumericoEMlineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::unila2 *ui;
};

#endif // UNILA2_H
