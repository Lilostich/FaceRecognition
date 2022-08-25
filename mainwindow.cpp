#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QWheelEvent>
#include <QtNetwork/QNetworkAccessManager>

void MainWindow::openFileSlot()
{
    QFileDialog dialog;

    QStringList files = dialog.getOpenFileNames();
    QIcon icon;
    for (auto file : files){
        ui_->listWidget->addItem(file);
        fullNames_.append(file);
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
        fullNames_.append(file.filePath()+file.fileName());
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

void addPoint(QGraphicsScene * scene, QPair<double,double> point){
    scene->addLine(point.first,point.second,
                   point.first+1,point.second+1);
}

QGraphicsScene * getFullImage(PhotoMetaInfo & info){
    QGraphicsScene * scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(QImage(info.fullFileName)));
    scene->addLine(info.rectangle.x,info.rectangle.y,
                   info.rectangle.x2(),info.rectangle.y);
    scene->addLine(info.rectangle.x,info.rectangle.y,
                   info.rectangle.x,info.rectangle.y2());
    scene->addLine(info.rectangle.x,info.rectangle.y2(),
                   info.rectangle.x2(),info.rectangle.y2());
    scene->addLine(info.rectangle.x2(),info.rectangle.y,
                   info.rectangle.x2(),info.rectangle.y2());
    for (int i = 0; i < POINT_COUNT; i++){
        addPoint(scene,info.points[i]);
    }
    return scene;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QImage img(item->text());
    QGraphicsScene * scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(img));
//    getFullImage()
    delete image_->scene();
    image_->setScene(scene);
    // После добавления рест апи
    WorkWithApi t;
    t.login();
}

void MainWindow::processRequest()
{

}

