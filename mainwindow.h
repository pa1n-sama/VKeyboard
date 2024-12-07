#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class VKeyboard;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent *event);
    void buttons(QStringList letters);
    void on_copy_clicked();
    void on_BLang_clicked();

private:
    Ui::VKeyboard *ui;
    QStringList numbers;
    QStringList arletters;
};

#endif
