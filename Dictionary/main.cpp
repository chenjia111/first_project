#include "mainWindow.h"
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QTextCodec * codec=QTextCodec::codecForName ("system");
	QTextCodec::setCodecForCStrings (codec ) ;	
	MyWin win;
	win.show();
	return app.exec();
}