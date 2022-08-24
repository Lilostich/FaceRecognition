#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "mygraphicview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


//slots:


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFileSlot();
    void openFolderSlot();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);


private:
    Ui::MainWindow *ui_;
    MyGraphicView *image_;
};
#endif // MAINWINDOW_H
