#include "Lab11GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab11GUI w;
	w.show();
	return a.exec();
}
