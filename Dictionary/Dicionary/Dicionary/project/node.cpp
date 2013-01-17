#include"node.h"

Node::Node(QWidget*parent):QWidget(parent)
{
	//btna=new QPushButton("刷新");
	//btnb=new QPushButton("编辑");
	btnc=new QPushButton("删除");
	btnd=new QPushButton("保存");
	btne=new QPushButton("关闭");
	btnf=new QPushButton("退出");
	table=new QTableWidget(6,3);
	QHBoxLayout*lay2=new QHBoxLayout;
	//lay2->addWidget(btnb);
	lay2->addWidget(btnc);
	lay2->addWidget(btnd);
	//lay2->addWidget(btna);
	lay2->addWidget(btne);
	lay2->addWidget(btnf);
	QVBoxLayout*lay=new QVBoxLayout;
	lay->addWidget(table);
	lay->addLayout(lay2);
	setLayout(lay);
	table->setSelectionBehavior(QAbstractItemView::SelectRows);
	table->setColumnWidth(1,160);
	QList<QString>l;
	l.append("单词");
	l.append("解释");
	l.append("添加时间");
	table->setHorizontalHeaderLabels(l);
	setWindowTitle("生词本");
	QFile data("newword.txt");
	if(data.open(QFile::ReadOnly|QFile::Truncate))
	{
		QTextStream in(&data);
		QString line;
		QStringList m;
		int n=0;
		while(!in.atEnd())
		{
			line=in.readLine();
			m=line.split(" ");
			QTableWidgetItem*ite1=new QTableWidgetItem(m[0]);
			QTableWidgetItem*ite2=new QTableWidgetItem(m[1]);
			table->setItem(n,0,ite1);
			table->setItem(n,1,ite2);
			QString str=(QDate::currentDate()).toString("yyyy.yy.yy");
			QTableWidgetItem*ite3=new QTableWidgetItem(str);
			table->setItem(n,2,ite3);
			n++;
		}
	}
	data.close();
	//connect(btnb,SIGNAL(clicked()),this,SLOT(complie()));
	connect(btnd,SIGNAL(clicked()),this,SLOT(save()));
	connect(btnc,SIGNAL(clicked()),this,SLOT(delword()));
	connect(btne,SIGNAL(clicked()),this,SLOT(close()));
	connect(btnf,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void Node::save()
{
	QString s1,s2,s3;
	int n=0; 
	QTableWidgetItem*a1;
	a1=table->item(n,0);
		if(a1==NULL)
			return;
		s1=a1->text();
	s2=table->item(n,1)->text();
	while(1)
	{
		n++;
		s3.append(s1);
		s3.append(" ");
		s3.append(s2);
		s3.append("\n");
		a1=table->item(n,0);
		if(a1==NULL)
			break;
		s1=a1->text();
		s2=table->item(n,1)->text();
	}
	QFile data("newword.txt");
	if(data.open(QFile::WriteOnly|QFile::Truncate))
	{
		QTextStream out(&data);
		out<<s3;
	}
	data.close();
}
void Node::delword()
{
	if(!table->selectedItems().size())
	{
		QMessageBox msg(QMessageBox::Warning,"提示框","对不起，没有选中对象",QMessageBox::Ok);
		msg.exec();
		return;
	}
	int current;
	current=table->currentRow();
	table->removeRow(current);
	QString s1,s2,s3;
	int n=0;
	QMessageBox meg(QMessageBox::NoIcon,"提示框","删除成功",QMessageBox::Ok);
	QFile data("newword.txt");
	if(!data.open(QFile::WriteOnly|QFile::Truncate))
		return;
	QTableWidgetItem*a1;
	a1=table->item(n,0);
	if(a1==NULL)
	{
		QTextStream out(&data);
		out<<"";
		meg.exec();
		return;
	}
	s1=a1->text();
	s2=table->item(n,1)->text();
	while(1)
	{
		n++;
		s3.append(s1);
		s3.append(" ");
		s3.append(s2);
		s3.append("\n");
		a1=table->item(n,0);
		if(a1==NULL)
			break;
		s1=a1->text();
		s2=table->item(n,1)->text();
	}
	QTextStream out(&data);
	out<<s3;
	data.close();
	meg.exec();
}


