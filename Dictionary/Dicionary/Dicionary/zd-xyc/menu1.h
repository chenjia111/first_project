#ifndef _MENU1_H
#define _MENU1_H

#include"common.h"
#include"menu2.h"
class MyMain :public QWidget
{
Q_OBJECT
	
private:
	
	QLineEdit* editword;
	QPushButton* btnsearch;
	
	QTextEdit* edittext;
	QLabel* lblpic;
	QPushButton* btninsert;
	QPushButton* btnku;
	
	QPushButton* btnquit;
	QString linefirst;//��ѯ���ĵ�һ��(��������'\n'����)
	int i;
private slots:
	
	void myslot();
	void editwordfun(const QString &text);
	void btnsearchfun();
	void edittextfun();
	
	void insert();
	void myku();
	
public:   
	MyKu* win1;
	MyMain(QWidget* parent=0);
};

#endif