#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QKeyEvent>
#include <string.h>
#include <QTextCursor>
#include <clip/clip.h>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VKeyboard)
{
    ui->setupUi(this);
    ui->textEdit->setLayoutDirection(Qt::RightToLeft);
    ui->textEdit->setAlignment(Qt::AlignRight);

    ui->textEdit->textCursor().movePosition(QTextCursor::Start);
    ui->textEdit->setFocus();

    numbers = {"ذ","١","٢","٣","٤","٥","٦","٧","٨","٩",".","-","="};
    
    arletters = {"ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ","ح", "ج", "د",
                           "ش", "س", "ي", "ب","ل", "ا", "ت", "ن", "م", "ك", "ط",
                           "ئ", "ء", "ؤ", "ر", "لا", "ى", "ة", "و", "ز", "ظ", " "};

    ui->BLang->setText("clear");
    buttons(arletters);

}




void MainWindow::buttons(QStringList letters){
        
        for(int i=0;i<letters.size();i++){
            QString Bname="b"+QString::number(i+1);
            QPushButton *button =this->findChild<QPushButton *>(Bname);
            if(button){
                disconnect(button,nullptr,this,nullptr);
                button->setText(letters[i]);
                connect(button,&QPushButton::clicked,this,[this,i,letters](){
                    QString text=ui->textEdit->toPlainText()+letters[i];
                    ui->textEdit->setText(text);
                    ui->textEdit->textCursor().movePosition(QTextCursor::Start);
                    this->setFocus();

                });
            }
        }
        
        for(int j=0;j<numbers.size();j++){
            QString Bname="testb"+QString::number(j+1);
            QPushButton *button =this->findChild<QPushButton *>(Bname);
            if(button){
                disconnect(button,nullptr,this,nullptr);
                button->setText(numbers[j]);
                connect(button,&QPushButton::clicked,this,[this,j](){
                    QString text=ui->textEdit->toPlainText()+numbers[j];
                    ui->textEdit->setText(text);
                    ui->textEdit->textCursor().movePosition(QTextCursor::Start);
                    this->setFocus();

                });
            }
        }
        
        QPushButton *button =this->findChild<QPushButton *>("testb14");
        button->setText("<=");
        connect(button,&QPushButton::clicked,[this]{
            QString t=ui->textEdit->toPlainText();
            t.chop(1);
            ui->textEdit->setText(t);
            this->setFocus();
        });

}

void MainWindow::on_copy_clicked(){
    QString t = ui->textEdit->toPlainText();
    clip::set_text(t.toStdString());
}

void MainWindow::on_BLang_clicked(){
    ui->textEdit->clear();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    QString t=ui->textEdit->toPlainText();
    if(event->key()==Qt::Key_Backspace){
        t.chop(1);
    }else if(event->key()==Qt::Key_Space){
        t = t+" ";
    }
    ui->textEdit->setText(t);
}

MainWindow::~MainWindow(){
    delete ui;
}

