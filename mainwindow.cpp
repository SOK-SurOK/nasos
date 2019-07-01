#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    M = new Cylinder();
    N = new Nasos();
    N->setInE(M);
    isUse = ui->comboBox_E->currentIndex();

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

    ui->openGLWidget_E->show();
    ui->openGLWidget_M->show();
}

void MainWindow::slotTimerAlarm()
{
    N->Do();
    for (int i =0; i<ll.getSize(); i++)
    {
        ll.getN1(i)->Do();
        ll.getN2(i)->Do();
    }
    ui->openGLWidget_E->updateGL();
    ui->openGLWidget_M->updateGL();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_newE_clicked()
{
    ll.Add();
    isUse = ll.getSize() - 1;
    ll.getN1(isUse)->setInE(M);
    ll.getN1(isUse)->setOutE(ll.getEmkost(isUse));
    ll.getN2(isUse)->setOutE(ll.getEmkost(isUse));
    ui->comboBox_E->addItem(QString::number(isUse)+" Элемент");
    //updateE();
    ui->comboBox_E->setCurrentIndex(isUse);
}

void MainWindow::updateE()
{
    ui->openGLWidget_E->setE(ll.getEmkost(isUse));
    Cylinder *c =dynamic_cast<Cylinder*>( ll.getEmkost(isUse));
    ui->doubleSpinBox_H->setValue(c->getH());
    ui->doubleSpinBox_R->setValue(c->getR());
    ui->doubleSpinBox_P->setValue(ll.getN1(isUse)->getPotok());
    ui->doubleSpinBox_P_2->setValue(ll.getN2(isUse)->getPotok());
    ui->openGLWidget_E->updateGL();
}

void MainWindow::updateM()
{
    ui->openGLWidget_M->setE(M);
    Cylinder *c =dynamic_cast<Cylinder*>(M);
    ui->doubleSpinBox_M_H->setValue(c->getH());
    ui->doubleSpinBox_M_R->setValue(c->getR());
    ui->doubleSpinBox_M_P->setValue(N->getPotok());
    ui->openGLWidget_M->updateGL();
}

void MainWindow::setE()
{
    try
    {
    Cylinder *c = dynamic_cast<Cylinder *>(ll.getEmkost(isUse));
    c->setRH(ui->doubleSpinBox_R->value(),ui->doubleSpinBox_H->value());
    ll.getN1(isUse)->setPotok(ui->doubleSpinBox_P->value());
    ll.getN2(isUse)->setPotok(ui->doubleSpinBox_P_2->value());
    updateE();
    }
    catch (QString str)
    {
        statusBar()->showMessage(str);
    }
}

void MainWindow::setM()
{
    Cylinder *c = dynamic_cast<Cylinder *>(M);
    c->setRH(ui->doubleSpinBox_M_R->value(),ui->doubleSpinBox_M_H->value());
    N->setPotok(ui->doubleSpinBox_M_P->value());
    updateM();
}

void MainWindow::on_pushButton_start_clicked()
{
    timer->start(1000);
}

void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();
}

void MainWindow::on_comboBox_E_currentIndexChanged(int index)
{
    isUse = index;
    updateE();
}

void MainWindow::on_doubleSpinBox_M_H_valueChanged(double arg1)
{
    setM();
}

void MainWindow::on_doubleSpinBox_M_R_valueChanged(double arg1)
{
    setM();
}

void MainWindow::on_doubleSpinBox_M_P_valueChanged(double arg1)
{
    setM();
}

void MainWindow::on_doubleSpinBox_H_valueChanged(double arg1)
{
    setE();
}

void MainWindow::on_doubleSpinBox_R_valueChanged(double arg1)
{
    setE();
}

void MainWindow::on_doubleSpinBox_P_valueChanged(double arg1)
{
    setE();
}

void MainWindow::on_doubleSpinBox_P_2_valueChanged(double arg1)
{
    setE();
}

