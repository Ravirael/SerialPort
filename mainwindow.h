#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>
#include "serialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionRefresh_ports_triggered();

    void on_terminatorASCIIEdit_textEdited(const QString &arg1);

    void on_terminatorHexEdit_textEdited(const QString &arg1);

    void on_terminatorCB_currentIndexChanged(int index);

    void on_sendButton_clicked();

private:
    void setupComboBoxes();

    Ui::MainWindow *ui;
    SerialPort serialPort;

    QRegExpValidator hexValidator;
    QIntValidator intValidator;

};

#endif // MAINWINDOW_H
