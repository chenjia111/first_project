#include"menu2.h"
MyKu::MyKu(QWidget* parent):QWidget(parent)
{		
		i=0;
		table = new QTableWidget(0,3);
		table->setColumnWidth(0,100);
		table->setColumnWidth(1,300);
		table->setColumnWidth(2,100);
		table->setStyleSheet("font-size : 18px");
		//table->QAbstractItemView::NoSelection;
		//edittext->SelectionMode(NoSelection);
		//QItemSelectionModel abc;
		//table->setSelectionModel(2);
		
		QStringList s=(QStringList() <<"单词"<<"解释"<<"添加时间");
		table->setHorizontalHeaderLabels(s);
		//////设置table的选择行为///
		table->setSelectionBehavior(QAbstractItemView::SelectRows);
		append =new QPushButton("添加");
		append->setIcon(QPixmap(".\\system\\add.ico"));
		del =new QPushButton("删除");
		del->setIcon(QPixmap(".\\system\\minus.ico"));
		reload =new QPushButton("刷新");
		reload->setIcon(QPixmap(".\\system\\refresh.ico"));
		save =new QPushButton("保存");
		save->setIcon(QPixmap(".\\system\\save.ico"));
		btnclose=new QPushButton("关闭");
		btnclose->setIcon(QPixmap(".\\system\\close.ico"));
		

			
		QHBoxLayout* hlayout1 = new QHBoxLayout;
		hlayout1->addWidget(table);
			
		QHBoxLayout* hlayout2 = new QHBoxLayout;
		hlayout2->addWidget(append);
		hlayout2->addWidget(del);
		hlayout2->addWidget(reload);
		hlayout2->addWidget(save);
		hlayout2->addWidget(btnclose);
			
		QVBoxLayout* vlayout = new QVBoxLayout;
		vlayout->addLayout(hlayout1);
		vlayout->addLayout(hlayout2);
			
		setLayout(vlayout);
		setWindowTitle("生词库");
		setMinimumSize(550,400);//设置窗口大小（宽，高）
		QIcon icon(".\\system\\qt.ico");
		setWindowIcon (icon);
		refurbish();
		connect(append,SIGNAL(clicked()),this,SLOT(appendfun()));
		connect(del,SIGNAL(clicked()),this,SLOT(delfun()));
		connect(reload,SIGNAL(clicked()),this,SLOT(reloadfun()));
		connect(save,SIGNAL(clicked()),this,SLOT(savefun()));
		connect(btnclose,SIGNAL(clicked()),this,SLOT(close()));
	}

void MyKu::appendfun()
{
		if(i==0)
		{
			i=1;
			kuadd=new KuAdd;
		}
		kuadd->show();
}

void MyKu::reloadfun()
{
		refurbish();
	}
	
void MyKu::delfun()
{
		int crow;
		crow=table->currentRow();
		table->removeRow(crow);
		//table->insertRow(99);
		savetofile();
	}

void MyKu::savefun()
{
		savetofile();
	}


void MyKu::refurbish()
{
		
		QFile file(".\\system\\生单词.txt");
		if (!file.open(QFile::ReadOnly | QFile::Text))
		{
			qDebug()<<"return";
			return;
		}
		QTextStream in(&file);
		QString line1,line2,linedate;
		int i=0,j=0;
		while (!in.atEnd())
		{
			int r=table->rowCount();
			if(i>=r) table->insertRow(i);
			QTableWidgetItem* item1=new QTableWidgetItem; 
			line1 = in.readLine();		
			item1->setText(line1);
			table->setItem(i,j++,item1);
			
			QTableWidgetItem* item2=new QTableWidgetItem; 
			line2 = in.readLine();
			item2->setText(line2);
			table->setItem(i,j++,item2);
			QTableWidgetItem* itemdate=new QTableWidgetItem; 
			linedate= in.readLine();
			itemdate->setText(linedate);
			table->setItem(i,j++,itemdate);	
			if(j>=3) j=0;
			i++;
		}
		//delete(item);
}

void MyKu::savetofile()
{
		QFile file(".\\system\\生单词.txt");
		if (!file.open(QFile::WriteOnly))////?????
         return;
		QTextStream out(&file);		
		QTableWidgetItem* item;
		QString s;
		item=new QTableWidgetItem;
		int i=0,j=0;
		while(i<100)
		{
			item=table->item(i,j);
			if(item==0) break;			
			s=item->text();
			out <<s<<'\n';
			j++;
			if(j>=3)
			{
				j=0;
				i++;
			}
		}
	}
	
