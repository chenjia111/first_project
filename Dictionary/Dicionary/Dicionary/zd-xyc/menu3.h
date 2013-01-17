#ifndef _MENU3_H
#define _MENU3_H

#include"common.h"
class KuAdd:public QWidget
{
Q_OBJECT

private:
	QLabel* lblword;
	QLineEdit* editword;
	QLabel* lblexplain;
	QLineEdit* editexplain;
	QPushButton* btnsave;
	QPushButton* btncancel;
private slots:
	void savefun();
public:
	KuAdd(QWidget* parent=0);
};


#endif