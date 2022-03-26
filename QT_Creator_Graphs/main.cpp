#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <vector>
#include <cmath>
#include <iostream>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;


    std::vector<float> x_coord;
    std::vector<float> y_coord;

    for(float i = -1000; i < 1000; i++)
    {
        x_coord.push_back(i/50);
    }

    for(const auto &y: x_coord)
    {
        y_coord.push_back(sin(y));
    }

    QLineSeries *series = new QLineSeries();
    for(int i = 0; i < int(y_coord.size()); i++)
    {
        series->append(x_coord[i], y_coord[i]);
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setRange(-10, 10);
    chart->axes(Qt::Vertical).back()->setRange(-1.5, 1.5);

    QPen pen(QRgb(0x26d0ff));
    pen.setWidth(7);
    series->setPen(pen);

    QFont font;
    font.setPixelSize(34);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Sin function plot");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    window.setCentralWidget(chartView);
    window.resize(1000, 1000);
    window.show();

    return a.exec();
}







