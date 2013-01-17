#include"main.h"
#include"node.h"

  MyWin::MyWin(QWidget*parent):QWidget(parent)
		{
			editName=new QLineEdit;
			nedit=new QTextEdit;
			btnLook=new QPushButton("查找");
			btnWord=new QPushButton("加入生词本");
			btnNode=new QPushButton("生词本");
			btnClose=new QPushButton("关闭");
			btnQuit=new QPushButton("退出");
			QHBoxLayout*hlayout=new QHBoxLayout;
			hlayout->addWidget(editName);
			hlayout->addWidget(btnLook);
			QHBoxLayout*hlayout1=new QHBoxLayout;
			hlayout1->addWidget(btnWord);
			hlayout1->addWidget(btnNode);
			hlayout1->addWidget(btnClose);
			hlayout1->addWidget(btnQuit);
			QVBoxLayout*halay=new QVBoxLayout;
			halay->addLayout(hlayout);
			halay->addWidget(nedit);
			halay->addLayout(hlayout1);
			setLayout(halay);
			setWindowTitle("词典");
			connect(btnLook,SIGNAL(clicked()),this,SLOT(myslot1()));
			connect(editName,SIGNAL(textChanged(const QString &)),this,SLOT(myslot4()));
			connect(btnWord,SIGNAL(clicked()),this,SLOT(myslot2()));
			connect(btnNode,SIGNAL(clicked()),this,SLOT(myslot3()));
			connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
			connect(btnQuit,SIGNAL(clicked()),qApp,SLOT(quit()));
		}

void MyWin:: myslot1()
{
	QFile data("word.txt");
	if(data.open(QFile::ReadOnly|QFile::Truncate))
		{
			 QTextStream stream(&data);
			 QString line,s;
			 QStringList m;
			 int i;
			 s=editName->text();
			 i=s.length();
			 while(!stream.atEnd())
			 {
				line=stream.readLine();
				m=line.split(" ");
				if(s==m[0])
				{
					nedit->setText(line);
					return;
				}
				else
				{
					nedit->setText("没有此单词");
				}
			 }
			 if(stream.atEnd())
			{
				nedit->setText("没有此单词");
			 }
		}
	data.close();
}
void MyWin:: myslot2()
{
	QString str;
	if((str=editName->text()).size()==0)
	{
		QMessageBox msg(QMessageBox::Warning,"提示框","没有加入对象",QMessageBox::Ok);
		msg.exec();
		return;
	}
	QFile data("newword.txt");
	if(!data.open(QFile::ReadOnly|QFile::Truncate))
		return;
	QTextStream in(&data);
	while(!in.atEnd())
	{
		QString line;
		QList<QString> m;
		line=in.readLine();
		m=line.split(" ");
		if(str==m[0])
		{
			QMessageBox meg(QMessageBox::Warning,"提示框","生词本中已有此单词",QMessageBox::Ok);
			meg.exec();
			data.close();
			return;
		}
	}
	QFile file("newword.txt");
	if(!file.open(QIODevice::Append))
		return;
	QTextStream out(&file);
	QString s=nedit->toPlainText();
	if(s.split(" ").size()<2)
	{
		QMessageBox mag(QMessageBox::Warning,"提示框","词库中没有此单词",QMessageBox::Ok);
		mag.exec();
		return;
	}
	out<<s<<"\n";
	QMessageBox msg(QMessageBox::NoIcon,"提示框","加入成功",QMessageBox::Ok);
	msg.exec();
	file.close();
	return;
}
void MyWin:: myslot3()
{
	newwindow=new Node;
	newwindow->show();
}
void MyWin:: myslot4()
{
	QString s=editName->text();
	//nedit->setText(s);
	QString allword;
	QFile data("word.txt");
	if(data.open(QIODevice::ReadOnly|QIODevice::Text))
	{
		QTextStream stream(&data);
		QString line,s,m;
		 int i;
		 s=editName->text();
		 i=s.length();
		 while(!stream.atEnd())
		 {
			line=stream.readLine();
			m=line.left(i);
			if(s==m)
			{
			QStringList n;
			QString f;
			n=line.split(" ");
			f=n[0];
				allword.append(f);
				allword.append("\n");
			}
		  }
	}
	data.close();
	if(!s.size())
	{
		nedit->setText(s);
		return ;
	}
	nedit->setText(allword);
	
}





int main(int argc,char*argv[])
{
	QApplication app(argc,argv);
	QTextCodec*codec=QTextCodec::codecForName("system");
	QTextCodec::setCodecForCStrings(codec);
	MyWin Win;
	Win.show();
	return app.exec();
}




