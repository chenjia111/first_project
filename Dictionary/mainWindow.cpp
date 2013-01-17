#include"mainWindow.h"

MyWin::MyWin(QWidget* parent):QWidget(parent)
{
	word_input=new QLineEdit;
	translate=new QTextEdit;
	check_word=new QPushButton("����");
	unknown_text=new QPushButton("���ʱ�");
	add_word=new QPushButton("�������ʱ�");
	exit_button=new QPushButton("�˳�");
	//���򲼾�
	QHBoxLayout* hlayout1 =new QHBoxLayout;
	hlayout1->addWidget(word_input);
	hlayout1->addWidget(check_word);
	QHBoxLayout* hlayout2 = new QHBoxLayout;
	hlayout2->addWidget(translate);
	QHBoxLayout* hlayout3 = new QHBoxLayout;
	hlayout3->addWidget(unknown_text);
	hlayout3->addWidget(add_word);
	hlayout3->addWidget(exit_button);
	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->addLayout(hlayout1);
	vlayout->addLayout(hlayout2);
	vlayout->addLayout(hlayout3);
	setLayout(vlayout);
	setWindowTitle("���Ӵʵ�");
	connect(exit_button,SIGNAL(clicked()),qApp,SLOT(quit()));
	connect(check_word,SIGNAL(clicked()),this,SLOT(seek_word()));
	connect(word_input,SIGNAL(textChanged(const QString&)),this,SLOT(seek_word(const QString&)));
	connect(add_word,SIGNAL(clicked()),this,SLOT(add_text()));
	connect(unknown_text,SIGNAL(clicked()),this,SLOT(unkonwn_fun()));
}
void MyWin::seek_word()
{
		 QString str = word_input->text();
		 if(str=="\0")
		 	return;
	   QFile file("lib.txt"); 
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        	 return;
     QTextStream out(&file);
     QString line1=out.readLine();
     QString dis="\0";
     int i;
     while(!line1.isNull())
      {
         	i=line1.indexOf(str,0);
         	if(i==0)
         	{
         		QString line2=out.readLine();
					  dis=line1+"\n"+line2+"\n";
					  translate->setPlainText(dis);
					  break;
       		}
       		else
       		{
       			line1=out.readLine();
        	}
 					line1=out.readLine();
     	}
     	if(dis=="\0")
     	{
     		dis="Sorry��δ�ҵ��˵���";
     		translate->setPlainText(dis);
     	}
     	file.close();
}
void MyWin::seek_word(const QString&a)
	{
		 QString str = word_input->text();
		 if(str=="\0")
		 	return;
	   QFile file("lib.txt"); 
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        	 return;
     QTextStream out(&file);
     QString line1=out.readLine();
     QString dis="\0";
     int i;
     while(!line1.isNull())
      {
         	i=line1.indexOf(str,0);
         	if(i==0)
         	{
         		QString line2=out.readLine();
					  dis=dis+line1+"\n"+line2+"\n";
       		}
       		else
       		{
       			line1=out.readLine();
        	}
 					line1=out.readLine();
     	}
     	if(dis=="\0")
     	{
     		dis="Sorry��δ�ҵ��˵���";
     	}
     	translate->setPlainText(dis);
     	file.close();
	}
void MyWin::add_text()
{
	QFile file1("study.txt"); 
	QMessageBox msgBox;
  if (!file1.open(QFile::Append))
  {
 		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setText("   ���ʧ�ܣ�\n");  
		msgBox.exec();
    return;
  }
  QTextStream in(&file1);
  QString str=translate->	toPlainText ();
  if(str.isEmpty())
  {
  	msgBox.setIcon(QMessageBox::Critical);
		msgBox.setText("   ���ʧ�ܣ�\n");  
		msgBox.exec();
  	return;
  }
  int i=str.indexOf("\n",0);
  QString writeBuf=str.left(i+1);
  in<<writeBuf;
 	str=str.right(str.size()-i-1);
	i=str.indexOf("\n",0);
	writeBuf=str.left(i+1);
	QDate qdate;
	qdate=QDate::currentDate();
	QString sdate;
	sdate=qdate.toString("yyyy-M-d");
	sdate=sdate+"\n";
  in<<writeBuf<<sdate;
  file1.close();
  msgBox.setIcon(QMessageBox::Information);
	msgBox.setText("   ��ӳɹ���\n");
	msgBox.exec();
}
void MyWin::unkonwn_fun()
{
	text_menu=new TextWin;
	text_menu->show();
}