#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
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
    void on_action_Open_triggered();

    void on_action_Undo_triggered();

    void on_action_Redo_triggered();
    void timerUpDate();

private:
    Ui::MainWindow *ui;
    QString curFile;
    QLabel *first_statusLabel; //声明两个标签对象，用于显示状态信息
    QLabel *second_statusLabel;
    QLabel *timer_statusLabel;
    void init_statusBar(); //初始化状态栏 加位置信息入一个槽函数声明
    void do_cursorChanged(); //获取光标
    void do_file_Open();
    void timerinit();
    bool do_file_Load(const QString& fileName);
};

#endif // MAINWINDOW_H
