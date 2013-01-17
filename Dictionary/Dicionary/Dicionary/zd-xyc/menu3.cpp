#include"menu1.h"
#include"menu2.h"
#include"menu3.h"
extern MyMain* win;
void KuAdd::savefun()
{
		QString sword,sexplain;
		sword=editword->text();
		sexplain=editexplain->text();
		
		QMessageBox msgBox;
		msgBox.setWindowTitle("�Ի���");
		QIcon icon(".\\system\\qt.ico");
		msgBox.setWindowIcon (icon);
		if(sword.size()==0 || sexplain.size()==0) 
		{
			msgBox.setIcon(QMessageBox::Critical);
			msgBox.setText("   ����ʧ�ܣ�\n");
			msgBox.exec();
			//close();
			//return;			
		}
		else 
		{
			/////write////
			QFile file(".\\system\\������.txt");
			if (!file.open(QFile::Append))
				return;

			QTextStream out(&file);
		
			QDate qdate;
			qdate=QDate::currentDate();
			QString sdate;
			sdate=qdate.toString("yyyy-M-d");
		
			out << sword<<'\n'<<sexplain<<'\n'<<sdate<<'\n';
			
			msgBox.setIcon(QMessageBox::Information);
			msgBox.setText("   ����ɹ���\n"); 
			msgBox.exec();
			
			close();
			
		}
		win->win1->refurbish();
		///���
		editword->setText("");
		editexplain->setText("");
		
	}

KuAdd::KuAdd(QWidget* parent):QWidget(parent)
{
		lblword=new QLabel("����");
		editword=new QLineEdit;
		editword->setStyleSheet("font-size : 20px");
		lblexplain=new QLabel("����");
		editexplain=new QLineEdit;
		editexplain->setStyleSheet("font-size : 30px");
		btnsave=new QPushButton("����");
		btncancel=new QPushButton("ȡ��");
		
		QHBoxLayout* hlayout1 = new QHBoxLayout;
		hlayout1->addWidget(lblword);
		hlayout1->addWidget(editword);
		//hlayout1->heightForWidth(40);
		
		QHBoxLayout* hlayout2 = new QHBoxLayout;
		hlayout2->addWidget(lblexplain);
		hlayout2->addWidget(editexplain);
		
		QHBoxLayout* hlayout3 = new QHBoxLayout;
		hlayout3->addWidget(btnsave);
		hlayout3->addWidget(btncancel);
		
		QVBoxLayout* vlayout = new QVBoxLayout;
		vlayout->addLayout(hlayout1);
		vlayout->addLayout(hlayout2);
		vlayout->addLayout(hlayout3);
		
		setLayout(vlayout);
		setMinimumSize(300,150);//���ô��ڴ�С�����ߣ�
		QIcon icon(".\\system\\qt.ico");
		setWindowIcon (icon);
		setWindowTitle("���/�༭ ���ʿ�");
		connect(btnsave,SIGNAL(clicked()),this,SLOT(savefun()));
		connect(btncancel,SIGNAL(clicked()),this,SLOT(close()));
}
