#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listik.h"
#include "emkost.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotTimerAlarm();

    void on_pushButton_newE_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_comboBox_E_currentIndexChanged(int index);

    void on_doubleSpinBox_M_H_valueChanged(double arg1);

    void on_doubleSpinBox_M_R_valueChanged(double arg1);

    void on_doubleSpinBox_M_P_valueChanged(double arg1);

    void on_doubleSpinBox_H_valueChanged(double arg1);

    void on_doubleSpinBox_R_valueChanged(double arg1);

    void on_doubleSpinBox_P_valueChanged(double arg1);

    void on_doubleSpinBox_P_2_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    int isUse;
    Listik ll;
    Emkost *M;
    Nasos *N;
    void updateE();
    void updateM();
    void setE();
    void setM();
    QTimer *timer;
};

#endif // MAINWINDOW_H
