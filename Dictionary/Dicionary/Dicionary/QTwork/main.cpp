#include<QApplication>
#include<QtGui>
class MyWin3:public QWidget
{
	Q_OBJECT
	private:
		QLabel* lblWord;
		QLineEdit* editWord;
		QLabel* lblExplain;
		QTextEdit* editExplain;
		QPushButton* btnSave;
		QPushButton* btnCancel;	
	private slots:
		void myslots();
	public:
	MyWin3()
	{
		lblWord=new QLabel("单词");
		editWord=new QLineEdit;
		lblExplain=new QLabel("解释");
		editExplain=new QTextEdit;
		btnSave=new QPushButton("保存");
		btnCancel=new QPushButton("取消");
		
		QHBoxLayout* hlayout = new QHBoxLayout;
		hlayout->addWidget(btnSave);
		hlayout->addWidget(btnCancel);
			
		QVBoxLayout* vlayout=new QVBoxLayout;
		vlayout->addWidget(lblWord);
		vlayout->addWidget(editWord);
		vlayout->addWidget(lblExplain);
		vlayout->addWidget(editExplain);
		vlayout->addLayout(hlayout);
			
		setLayout(vlayout);
		setWindowTitle("添加");
		
		connect(btnSave,SIGNAL(clicked()),this,SLOT(myslots()));
		connect(btnCancel,SIGNAL(clicked()),this,SLOT(close()));
	}	
};
void MyWin3::myslots()
{
	QString p=editWord->text();
	QString t=editExplain->toPlainText();
	QFile file("DCP.txt");
     if (!file.open(QIODevice::Append|QIODevice::Text))
         return;

     QTextStream out(&file);
     out<<p<<"\n";
     out << t << "\n";
     out << QDate::currentDate().toString("yyyy MM dd  ")<<"\n";
     QMessageBox mes;
     mes.setText("添加成功！");
     mes.exec();	
}
class MyWin2:public QWidget
{
	Q_OBJECT
	private:
		MyWin3 win3;
		QTableWidget* editC;
		QPushButton* btnAppend;
		QPushButton* btnQuilt;
		QPushButton* btnDelete;
		QPushButton* btnRefurbish;
		QPushButton* btnSave;	
	private slots:
		void myslota();
		void myslotd();
		void myslotr();
		void myslots();
	public:
		MyWin2()
		{
		editC=new QTableWidget(this);
		editC->setRowCount(15);
    editC->setColumnCount(3);
		editC->setColumnWidth(0,100);
		editC->setColumnWidth(1,300);
		QStringList s=(QStringList()<<"单词"<<"解释"<<"添加时间");
		editC->setHorizontalHeaderLabels(s);
		btnAppend=new QPushButton("添加");
		btnAppend->setIcon(QPixmap(".\\pic\\1.jpg"));
		//btnQuilt=new QPushButton("编辑");
		//btnQuilt->setIcon(QPixmap(".\\pic\\2.jpg"));
		btnDelete=new QPushButton("删除");
		btnDelete->setIcon(QPixmap(".\\pic\\3.jpg"));
		btnRefurbish=new QPushButton("刷新");
		btnRefurbish->setIcon(QPixmap(".\\pic\\4.jpg"));
		btnSave=new QPushButton("保存");
		btnSave->setIcon(QPixmap(".\\pic\\2.jpg"));
		
		QHBoxLayout* hlayout = new QHBoxLayout;
		hlayout->addWidget(btnAppend);
		//hlayout->addWidget(btnQuilt);
		hlayout->addWidget(btnDelete);
		hlayout->addWidget(btnRefurbish);
		hlayout->addWidget(btnSave);
			
		QVBoxLayout* vlayout=new QVBoxLayout;
		vlayout->addWidget(editC);
		vlayout->addLayout(hlayout);
			
		setLayout(vlayout);	
		setWindowTitle("生词本");
		setMinimumSize(560,320);
		QIcon icon(".\\pic\\main.jpg");
		setWindowIcon (icon);
		
		connect(btnAppend,SIGNAL(clicked()),this,SLOT(myslota()));
		connect(btnDelete,SIGNAL(clicked()),this,SLOT(myslotd()));
		connect(btnRefurbish,SIGNAL(clicked()),this,SLOT(myslotr()));
		connect(btnSave,SIGNAL(clicked()),this,SLOT(myslots()));
		
		QString line;
		int i = 0;
		int j = 0;
	
		QFile file("DCP.txt");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
         return;
		QTextStream in(&file);
		QTableWidgetItem *newItem;
     		while (!in.atEnd())
		{
			for(j=0;j<3;j++)
			{
				line = in.readLine();
				newItem = new QTableWidgetItem(line);
				//newItem->setText(line); 
				editC->setItem(i,j,newItem);
			}
			i++;
     }
		}
};
void MyWin2::myslota()
{
	win3.show();
}
void MyWin2::myslotd()
{
	editC->removeRow(editC->currentRow());
}
void MyWin2::myslotr()
{
	QString line;
	int j=0,i=0;
	QFile file("DCP.txt");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
         return;
		QTextStream in(&file);
		QTableWidgetItem *newItem;
     		while (!in.atEnd())
		{
			for(j=0;j<3;j++)
			{
				line = in.readLine();
				newItem = new QTableWidgetItem(line);
				//newItem->setText(line); 
				editC->setItem(i,j,newItem);
			}
			i++;
     }
     while(i<=15)
	{
		for(j=0;j<3;j++)
		{
			newItem=new QTableWidgetItem(" ");
			editC->setItem(i,j,newItem);
		}
		i++;
	}
}
void MyWin2::myslots()
{
	int i=0,j=0;
	QString s;
	QFile file("DCP.txt");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
         return;
	QTextStream out(&file);
	while(editC->item(i,0)->text()!=" ")
	{
		for(j=0;j<3;j++)
		{
			out <<editC->item(i,j)->text()<<"\n";
		}
		i++;
	}

	QMessageBox msgBox;
 	msgBox.setText("保存成功!");
 	msgBox.exec();
}
class MyWin:public QWidget
{
	Q_OBJECT
	private:
	MyWin2 win2;
	QLineEdit* editA;
	QTextEdit* editB;
	QPushButton* btnSearch;
	QPushButton* btnInsert;
	QPushButton* btnDictionary;
	QPushButton* btnQuit;
	private slots:
	void myslot1(const QString &);
	void myslot2();
	void myslot3();
	public:
	MyWin()
	{
		editA=new QLineEdit;
		editB=new QTextEdit;
		editB->setReadOnly(TRUE);
		btnSearch=new QPushButton("查询");
		btnInsert=new QPushButton("加入生词本");
		btnDictionary=new QPushButton("生词本");
		btnQuit=new QPushButton("退出");
		
		QHBoxLayout* hlayout1 = new QHBoxLayout;
		hlayout1->addWidget(editA);
		hlayout1->addWidget(btnSearch);
		
		QHBoxLayout* hlayout2 = new QHBoxLayout;
		hlayout2->addWidget(btnInsert);
		hlayout2->addWidget(btnDictionary);
		hlayout2->addWidget(btnQuit);
			
		QVBoxLayout* vlayout=new QVBoxLayout;
		vlayout->addLayout(hlayout1);
		vlayout->addWidget(editB);
		vlayout->addLayout(hlayout2);
			
		setLayout(vlayout);	
		setWindowTitle("我的词典");
		QIcon icon(".\\pic\\ICO.ICO");
		setWindowIcon (icon);
		
		connect(btnSearch,SIGNAL(clicked()),this,SLOT(myslot1()));
		connect(editA,SIGNAL(textChanged(const QString &)),this,SLOT(myslot1(const QString &)));
		connect(btnInsert,SIGNAL(clicked()),this,SLOT(myslot2()));
		connect(btnDictionary,SIGNAL(clicked()),this,SLOT(myslot3()));
		connect(btnQuit,SIGNAL(clicked()),qApp,SLOT(quit()));
	}		
};
void MyWin::myslot1(const QString &)
{
	int index;
	QString line;
	QString s=editA->text();		
	QFile file("DC.txt");
  if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
  	return;

  QTextStream in(&file);
  while (!in.atEnd()) 
  {
  line = in.readLine();
  index=line.indexOf(s);
  if(index==0)
  	break;
  //process_line(line);
  //editB->setPlainText(line);
  }
   if(index==0)
   	editB->setPlainText(line);
   else
   	editB->setPlainText("未找到");  
}

void MyWin::myslot2()
{
	QString p=editA->text();
	QString t=editB->toPlainText();
	QFile file("DCP.txt");
     if (!file.open(QIODevice::Append|QIODevice::Text))
         return;

     QTextStream out(&file);
     out<<p<<"\n";
     out << t << "\n";
     out << QDate::currentDate().toString("yyyy MM dd  ")<<"\n";
     QMessageBox mes;
     mes.setText("添加成功！");
     mes.exec();
}

void MyWin::myslot3()
{
	win2.show();	
}
int main(int argc,char* argv[])
{
		QApplication app(argc,argv);
		QTextCodec* codec=QTextCodec::codecForName("system");
		QTextCodec::setCodecForCStrings(codec);
		MyWin win;
		win.show();
		return app.exec();
}
#include"main.moc"