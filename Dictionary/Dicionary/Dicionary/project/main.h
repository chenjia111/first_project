#ifndef _MAIN_H
#define _MAIN_H

#include<QApplication>
#include<QtGui>
#include"node.h"
class MyWin:public QWidget
{
Q_OBJECT
private:
	Node* newwindow;
	QLineEdit*editName;
	QTextEdit* nedit;
	QPushButton* btnLook;
	QPushButton* btnWord;
	QPushButton* btnNode;
	QPushButton* btnQuit;
	QPushButton* btnClose;
private slots:
	void myslot1();
	void myslot2();
	void myslot3();
	void myslot4();
public:
	MyWin(QWidget*parent=0);

};


#endif







