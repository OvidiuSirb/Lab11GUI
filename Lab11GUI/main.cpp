#include "Lab11GUI.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab11GUI w;
	QLabel l("da");
	l.show();
	w.show();
	return a.exec();
}
