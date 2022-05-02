#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(char * idProducteur,char * laSemaine, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void brochurePDF();
    QString idProducteur;
    QString semaine;
};

#endif // MAINWINDOW_H
