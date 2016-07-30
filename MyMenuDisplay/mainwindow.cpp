#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
#include <QtCore>
#include<QFileDialog>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    curFile = tr("程序012");
    setWindowTitle(curFile);
    timerinit();
    init_statusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerinit()
{
    QTimer *timer = new QTimer(this); // creat new timer
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate())); //关联定时器计满信号和相应的槽函数
    timer->start(1000);//定时器开始计时，其中1000表示1000ms即1秒
}
void MainWindow::timerUpDate()
{
     QDateTime time = QDateTime::currentDateTime();
      //获取系统现在的时间
     QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
      //设置系统时间显示格式
  //  ui->label->setText(str); //在标签上显示时间

    timer_statusLabel->setText(str); //初始化内容
}

void MainWindow::do_file_Open()//
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())//如果文件名不为空
    {
        do_file_Load(fileName);
    }
    ui->textEdit->setVisible(true);//文本编辑器可见
}
bool MainWindow::do_file_Load(const QString &fileName)//读取文件
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("读取文件"),tr("无法读取文件 %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;  // 如果打开文件失败，弹出对话框，并返回
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());//讲文件中的所有内容都写到文本编辑器中
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}
void MainWindow::init_statusBar()
{
   QStatusBar *bar = ui->statusBar; //获取状态栏
   /*first_statusLabel =new QLabel;  //新建标签
   first_statusLabel->setMinimumSize(150,20); //设置最小尺寸
   first_statusLabel->setFrameShape(QFrame::Box); //设置标签形状
   first_statusLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影

   second_statusLabel = new QLabel;
   second_statusLabel->setMinimumSize(150,20);
  // second_statusLabel->s
   second_statusLabel->setFrameShape(QFrame::WinPanel);
   second_statusLabel->setFrameShadow(QFrame::Sunken);

   bar->addWidget(first_statusLabel);
   bar->addWidget(second_statusLabel);

   first_statusLabel->setText(tr("欢迎")); //初始化内容
   second_statusLabel->setText(tr("XYY制作!"));*/


   timer_statusLabel =new QLabel;  //新建标签
   timer_statusLabel->setMinimumSize(200,30); //设置最小尺寸
   timer_statusLabel->setFrameShape(QFrame::Box); //设置标签形状
   timer_statusLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影
  timer_statusLabel->setMargin(20);
   timer_statusLabel->setIndent(20);
   timer_statusLabel->setAlignment(Qt::AlignCenter);
   //timer_statusLabel->setMinimumSize(timer_statusLabel->sizeHint());
   bar->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
   bar->setSizeGripEnabled(true); //设置是否显示右边的大小控制点
   bar->addWidget(timer_statusLabel);
   //bar->set

}


/*void MainWindow::on_action_Open_triggered()
{
    do_file_Open();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_2_triggered()
{
   //    do_file_Open();
}


void MainWindow::on_action_Redo_triggered()
{
    ui->textEdit->redo();
}*/

void MainWindow::on_action_Open_triggered()
{
    do_file_Open();
}

void MainWindow::on_action_Undo_triggered()
{
     ui->textEdit->redo();
}

void MainWindow::on_action_Redo_triggered()
{
     ui->textEdit->undo();
}
