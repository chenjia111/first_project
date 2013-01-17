#include"main.h"
#include"node.h"

  MyWin::MyWin(QWidget*parent):QWidget(parent)
		{
			editName=new QLineEdit;
			nedit=new QTextEdit;
			btnLook=new QPushButton("����");
			btnWord=new QPushButton("�������ʱ�");
			btnNode=new QPushButton("���ʱ�");
			btnClose=new QPushButton("�ر�");
			btnQuit=new QPushButton("�˳�");
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
			setWindowTitle("�ʵ�");
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
					nedit->setText("û�д˵���");
				}
			 }
			 if(stream.atEnd())
			{
				nedit->setText("û�д˵���");
			 }
		}
	data.close();
}
void MyWin:: myslot2()
{
	QString str;
	if((str=editName->text()).size()==0)
	{
		QMessageBox msg(QMessageBox::Warning,"��ʾ��","û�м������",QMessageBox::Ok);
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
			QMessageBox meg(QMessageBox::Warning,"��ʾ��","���ʱ������д˵���",QMessageBox::Ok);
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
		QMessageBox mag(QMessageBox::Warning,"��ʾ��","�ʿ���û�д˵���",QMessageBox::Ok);
		mag.exec();
		return;
	}
	out<<s<<"\n";
	QMessageBox msg(QMessageBox::NoIcon,"��ʾ��","����ɹ�",QMessageBox::Ok);
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




