#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot()
{
    QVector<double> x_coord;
    QVector<double> y_coord;

    //QVector<double> x(100), y(100)
    for (float i = -1000; i < 1000; i++)
    {
        x_coord.push_back(i/50);
    }
    for(const auto &y: x_coord)
    {
        y_coord.push_back(sin(y));
    }
   ui->customPlot->addGraph();

   ui->customPlot->xAxis->setRange(-10,10);
   ui->customPlot->yAxis->setRange(-1.5,1.5);
   ui->customPlot->xAxis->setLabel("X");
   ui->customPlot->yAxis->setLabel("Y");

   //ui->customPlot->graph(0);
   ui->customPlot->graph(0)->setData(x_coord, y_coord);
   ui->customPlot->replot();

}
