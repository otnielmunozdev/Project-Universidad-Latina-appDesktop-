#ifndef UNILA4_H
#define UNILA4_H

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
class unila4;
}

class unila4 : public QDialog
{
    Q_OBJECT

public:
    explicit unila4(QWidget *parent = 0);
    ~unila4();
    void Habilitar4();
    void Habilitar4_1();

private slots:
    void on_NumSeccionlineEdit_textChanged(const QString &arg1);

    void on_ProfesorlineEdit_textChanged(const QString &arg1);

    void on_AniolineEdit_textChanged(const QString &arg1);

    void on_SemestrelineEdit_textChanged(const QString &arg1);

    void on_IdCursolineEdit_textChanged(const QString &arg1);

    void on_RegistrarSeccionpushButton_clicked();

    void on_MostrarSeccionpushButton_clicked();

    void on_BuscarSeccionpushButton_clicked();

    void on_ModificarSeccionpushButton_clicked();

    void on_EliminarSeccionpushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_NumSeccionEMlineEdit_textChanged(const QString &arg1);

    void on_ProfesorEMlineEdit_textChanged(const QString &arg1);

    void on_AniolineEMEdit_textChanged(const QString &arg1);

    void on_SemestreEMlineEdit_textChanged(const QString &arg1);

    void on_IdCursoEMlineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::unila4 *ui;
};

#endif // UNILA4_H
