#ifndef UNILA_H
#define UNILA_H

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
class Unila;
}

class Unila : public QDialog
{
    Q_OBJECT

public:
    explicit Unila(QWidget *parent = 0);
    ~Unila();
    void Habilitar();

private slots:

    void on_MostrarpushButton_clicked();

    void on_NombrelineEdit_textChanged(const QString &arg1);

    void on_NumEstudiantelineEdit_textChanged(const QString &arg1);

    void on_FechanaclineEdit_textChanged(const QString &arg1);

    void on_SexolineEdit_textChanged(const QString &arg1);

    void on_DptoMenorlineEdit_textChanged(const QString &arg1);

    void on_DptoPrincipallineEdit_textChanged(const QString &arg1);

    void on_DireccionlineEdit_textChanged(const QString &arg1);

    void on_TeleActuallineEdit_textChanged(const QString &arg1);

    void on_GradolineEdit_textChanged(const QString &arg1);

    void on_GuardarpushButton_clicked();

    void on_BuscarpushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_ModificarpushButton_clicked();

    void on_EliminarpushButton_clicked();

    void on_IdlineEdit_textChanged(const QString &arg1);

    void on_CalificacionespushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Unila *ui;
};

#endif // UNILA_H
