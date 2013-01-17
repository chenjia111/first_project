#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QApplication>
#include<QtGui>
#include "textWindow.h"
class MyWin: public QWidget
{
Q_OBJECT
private:
	QLineEdit* word_input;
	QTextEdit* translate;
	QPushButton* check_word;
	QPushButton* unknown_text;
	QPushButton* exit_button;
	QPushButton* add_word;
private slots:
	void seek_word(const QString&a);
	void seek_word();
	void unkonwn_fun();
	void add_text();
public:
	MyWin(QWidget* parent=0);
	TextWin* text_menu;
	
};
#endif