#ifndef _NODE_H
#define _NODE_H
#include<QApplication>
#include<QtGui>
class Node:public QWidget
{
Q_OBJECT
private:
	//QPushButton* btna;
	//QPushButton* btnb;
	QPushButton* btnc;
	QPushButton* btnd;
	QPushButton* btne;
	QPushButton* btnf;
	QTableWidget*table;
private slots:
	//void complie();
	void save();
	void delword();
public:
	Node(QWidget*parent=0);
};

#endif


