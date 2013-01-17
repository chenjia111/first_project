#include"menu1.h"

MyMain::MyMain(QWidget* parent):QWidget(parent)
{	
		i=0;
		win1=NULL;
		linefirst=" ";
		
		editword = new QLineEdit;
		editword->setStyleSheet("font-size : 20px");
		/////////设置字体大小
		
		lblpic=new QLabel;
		
		btnsearch = new QPushButton("查询");
		
		edittext = new QTextEdit;
		edittext->setReadOnly(true);
		edittext->setStyleSheet("font-size : 20px");

		btninsert = new QPushButton("加入生词库");
		btnku = new QPushButton("生词库");
		btnquit = new QPushButton("退出");

		QHBoxLayout* hlayout1 = new QHBoxLayout;
		hlayout1->addWidget(editword);
		hlayout1->addWidget(btnsearch);
		
		QHBoxLayout* hlayout2 = new QHBoxLayout;
		hlayout2->addWidget(edittext);
		
		QHBoxLayout* hlayout4 = new QHBoxLayout;
		hlayout4->addWidget(lblpic);
		
		QHBoxLayout* hlayout3 = new QHBoxLayout;
		hlayout3->addWidget(btninsert);
		hlayout3->addWidget(btnku);
		hlayout3->addWidget(btnquit);

		QVBoxLayout* vlayout = new QVBoxLayout;
		vlayout->addLayout(hlayout1);
		vlayout->addLayout(hlayout2);
		vlayout->addLayout(hlayout4);
		vlayout->addLayout(hlayout3);
		
		//设置窗体的布局
		setLayout(vlayout);
		//设置窗体的标题
		
		setMinimumSize(550,400);//设置窗口大小（宽，高）
		
		setWindowTitle("my qt");
		//设置icon
		QIcon icon(".\\system\\qt.ico");
		setWindowIcon (icon);
		//设置背景图片
		 //QPalette   palette;
		// QPixmap pixmap("E:\\qtprogram\\qt.png");
 		//palette.setBrush(backgroundRole(),QBrush(pixmap));
		// setPalette(palette);
		//setGeometry(10,10,300,200);
		
		connect(btnquit,SIGNAL(clicked()),qApp,SLOT(quit()));
		connect(btnsearch,SIGNAL(clicked()),this,SLOT(btnsearchfun()));
		connect(btninsert,SIGNAL(clicked()),this,SLOT(insert()));
		connect(btnku,SIGNAL(clicked()),this,SLOT(myku()));
		connect(editword,SIGNAL(textChanged(const QString &)),this,SLOT(editwordfun(const QString &)));
		connect(edittext,SIGNAL(selectionChanged()),this,SLOT(edittextfun()));
}

void MyMain::myslot()///////// 输入就有变化、、显示<n个
{
	lblpic->setPixmap(QPixmap(" "));
	QString word=editword->text();
	int siz=word.size();
	//qDebug()<<"word="<<siz<<endl;
	
	QFile file(".\\system\\大学英语四级词汇.txt");
	if (!file.open(QFile::ReadOnly | QFile::Text))
        return;
	QTextStream in(&file);
	
	int index;
	int count=0;
	QString lineall,line1,line2;
	while (!in.atEnd())
	{
		line1 = in.readLine();
        index=line1.indexOf(word,0);
        if(index==0) ///在开头位置0说明找到了(输入为空--单词的确找到了)
        {
			  line2 = in.readLine();
			//line2=line1+'\n'+line2;
			  if(siz!=0 && count<12)	//输入不为空且count<10
				{
				count++;
				if(count==1) linefirst=line1+'\n'+line2+'\n';//保持第一个；
				lineall=lineall+line1+' '+line2+'\n';
				edittext->setPlainText(lineall);
			}
			else     //输入的是空白或count>12
			{
				if(siz==0)
				{
					lineall=" ";
					linefirst=" ";
					edittext->setPlainText(lineall);
					return;
				}
				else return;
			}
        }
		else
		{
			line2 = in.readLine();
		}
	}
	//////////////////
	//输入不为空 && index不为0 && 找到个数为0
	if(siz!=0 && index!=0 && count==0) 
	{
		edittext->setPlainText("未找到！");
		linefirst=" ";
	}
	
}

void MyMain::editwordfun(const QString &text)
{
	myslot();
}

void MyMain::btnsearchfun()/////////////点击查询按钮、、只显示第一个
{
	lblpic->setPixmap(QPixmap(" "));
	QString word=editword->text();
	int siz=word.size();	
	
	QFile file(".\\system\\大学英语四级词汇.txt");
	if (!file.open(QFile::ReadOnly | QFile::Text))
        return;
	QTextStream in(&file);
	
	int index;
	QString line1,line2;
	while (!in.atEnd())
	{
		line1 = in.readLine();
        index=line1.indexOf(word,0);
        if(index==0) 
        {
			line2 = in.readLine();
			break;	
        }
		else in.readLine();
	}
	if(index==0 && siz!=0)	
	{
		if(word=="dog") 
		{
			lblpic->setPixmap(QPixmap(".\\system\\gou.jpg"));
		}
		else if(word=="cat")
		{
			lblpic->setPixmap(QPixmap(".\\system\\cat.jpg"));
		}
		linefirst=line1+'\n'+line2+'\n';
		edittext->setPlainText(linefirst);
	}
	else 
	{
			linefirst=" ";
			if(siz!=0)
			{
				edittext->setPlainText("未找到！");
			}
			else 
			{
				edittext->setPlainText(linefirst);
			}
	}	
}

void MyMain::edittextfun()
{		
		qDebug()<<"---";
	}

void MyMain::insert()
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("对话框");
	QIcon icon(".\\system\\qt.ico");
	msgBox.setWindowIcon (icon);
	//QIcon icon(".\\system\\qt.ico");
	if(linefirst[0]!=' ')
	{
		QFile file(".\\system\\生单词.txt");
		if (!file.open(QFile::Append))
         return;

		QTextStream out(&file);
		
		QDate qdate;
		qdate=QDate::currentDate();
		QString sdate;
		sdate=qdate.toString("yyyy-M-d");
		
		out << linefirst<<sdate<<'\n';
		//qDebug()<<sdate<<endl;
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setText("   添加成功！\n");
		msgBox.exec();
		
	}
	else 
	{
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setText("   添加失败！\n");  
		msgBox.exec();
	}
	
	if(win1!=NULL) win1->refurbish();
	
	
}

void MyMain::myku()
{
	
		if(i==0)
		{
			i=1;
			win1=new MyKu;
		}
		win1->show();
		//editword->setStyleSheet("font-size : 20px");
		
}

