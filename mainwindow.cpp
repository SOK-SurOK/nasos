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
    may_change = false;
    ui->openGLWidget_E->setE(ll.getEmkost(isUse));
    Cylinder *c =dynamic_cast<Cylinder*>( ll.getEmkost(isUse));
    ui->doubleSpinBox_H->setValue(c->getH());
    ui->doubleSpinBox_R->setValue(c->getR());
    ui->doubleSpinBox_P->setValue(ll.getN1(isUse)->getPotok());
    ui->doubleSpinBox_P_2->setValue(ll.getN2(isUse)->getPotok());
    ui->openGLWidget_E->updateGL();
    may_change = true;
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
    if(may_change)
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


void MainWindow::on_pushButton_Fin_clicked()
{
    QFile file2("file2.dat");


    if(!file2.open(QIODevice::WriteOnly))
    {
        statusBar()->showMessage("Ошибка открытия для записи");
    }

    int size = ll.getSize()*5+4;
    double *mas = new double[size];

    Cylinder *c =dynamic_cast<Cylinder*>(M);
    mas[0] = c->getLitr();
    mas[1] = c->getH();
    mas[2] = c->getR();
    mas[3] = N->getPotok();

    for (int i=0, ii=4; i<ll.getSize(); i++)
    {
        Cylinder *c =dynamic_cast<Cylinder*>(ll.getEmkost(i));
        mas[ii++] = c->getLitr();
        mas[ii++] = c->getH();
        mas[ii++] = c->getR();
        mas[ii++] = ll.getN1(i)->getPotok();
        mas[ii++] = ll.getN2(i)->getPotok();
    }
    QByteArray a = QByteArray::fromRawData(reinterpret_cast<const char*>(mas), size*sizeof(double));
    file2.write(a);
    file2.close();
}

void MainWindow::on_pushButton_Fout_clicked()
{
    QFile file1("file1.dat");

    if(!file1.open(QIODevice::ReadOnly))
    {
        statusBar()->showMessage("Ошибка открытия для чтения");
    }

    int size = ll.getSize()*5+4;
    double *mas = new double[size];

    QByteArray a = file1.readAll();

    QByteArray dou(sizeof(double),0x0);
    for(int i = 0; i<size; i++)
    {
        dou = a.mid(i*sizeof(double),sizeof(double));
        mas[i] = *reinterpret_cast<const double*>(dou.data());
        dou.clear();
    }
    file1.close();
}
