#ifndef UNILA3_H
#define UNILA3_H

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
class unila3;
}

class unila3 : public QDialog
{
    Q_OBJECT

public:
    explicit unila3(QWidget *parent = 0);
    ~unila3();
    void Habilitar3();
    void Habilitar3_1();

private slots:
    void on_UniversidadlineEdit_textChanged(const QString &arg1);

    void on_NombrelineEdit_textChanged(const QString &arg1);

    void on_NumeroOficinalineEdit_textChanged(const QString &arg1);

    void on_GuardarCursopushButton_clicked();

    void on_MostrarCursospushButton_clicked();

    void on_BuscarCursospushButton_clicked();

    void on_ModificarCursopushButton_clicked();

    void on_EliminarCursopushButton_clicked();

    void on_UniversidadEMlineEdit_textChanged(const QString &arg1);

    void on_NombreEMlineEdit_textChanged(const QString &arg1);

    void on_NumeroOficinaEMlineEdit_textChanged(const QString &arg1);

    void on_CursotableView_activated(const QModelIndex &index);

    void on_SeccionespushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::unila3 *ui;
};

#endif // UNILA3_H
