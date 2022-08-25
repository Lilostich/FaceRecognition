#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>

#include "mygraphicview.h"
#include "photometainfo.h"
#include "workwithapi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFileSlot();
    void openFolderSlot();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void processRequest();

private:
    Ui::MainWindow *ui_;
    MyGraphicView *image_;
    QStringList fullNames_;
    QMap<QString,PhotoMetaInfo> nameToInfo;
};
#endif // MAINWINDOW_H
