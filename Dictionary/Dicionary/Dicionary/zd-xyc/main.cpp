#include"main.h"
#include"menu1.h"
#include"menu2.h"
#include"menu3.h"
MyMain* win;
int main(int argc,char* argv[])
{
//////////////////////////////////
////////�������ĵ�����////
	QTextCodec * codec=QTextCodec::codecForName("system");
	QTextCodec::setCodecForCStrings(codec);
/////////////////////////////////
	QApplication app(argc,argv);
	win = new MyMain;
	win->show();
	return app.exec();
}
//#include"main.moc"//����Ҫ���ļ���һ��
