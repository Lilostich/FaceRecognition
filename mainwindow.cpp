#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QWheelEvent>

void MainWindow::openFileSlot()
{
    QFileDialog dialog;

    QStringList files = dialog.getOpenFileNames();
    QIcon icon;
    for (auto file : files){
        ui_->listWidget->addItem(file);
    }
    ui_->listWidget->sortItems();

}

void MainWindow::openFolderSlot()
{
    QFileDialog dialog;

    QDir dir(dialog.getExistingDirectory());

    QIcon icon;
    QFileInfoList dirContent = dir.entryInfoList(QStringList()
            << "*.jpg",
            QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

    for (auto file : dirContent){
        ui_->listWidget->addItem(file.filePath()+file.fileName());
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
//    QSC
    image_ = new MyGraphicView();
    QGraphicsView* test = new QGraphicsView;
//    image_->show();
    ui_->setupUi(this);
    connect(ui_->actionOpen,&QAction::triggered,this,&MainWindow::openFileSlot);
    connect(ui_->actionOpen_folder,&QAction::triggered,this,&MainWindow::openFolderSlot);
    ui_->horizLayout->addWidget(image_);
}

MainWindow::~MainWindow()
{
    delete ui_;
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QImage img(item->text());
    QGraphicsScene * scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(img));
    delete image_->scene();
    image_->setScene(scene);
}

