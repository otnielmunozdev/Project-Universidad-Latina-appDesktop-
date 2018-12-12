#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

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
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = 0);
    ~MainWindow1();
    void Habilitar();

signals:
    void back();

private slots:
    void on_EstudiantespushButton_clicked();

    void on_pushButton_3_clicked();

    void on_SeccionespushButton_clicked();

    void on_CalifiacionesspushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow1 *ui;
};

#endif // MAINWINDOW1_H
