#ifndef _MENU2_H
#define _MENU2_H

#include"common.h"
#include"menu3.h"

class MyKu:public QWidget
{

Q_OBJECT
friend class KuAdd;
private:
	KuAdd* kuadd;
	QTableWidget* table;
	QPushButton* append;
	QPushButton* del;
	QPushButton* reload;
	QPushButton* save;
	QPushButton* btnclose;
	int i;
private slots:
	void appendfun();
	void reloadfun();
	void delfun();
	void savefun();
public:
	
	MyKu(QWidget* parent=0);
	void refurbish();
	void savetofile();	
};


#endif