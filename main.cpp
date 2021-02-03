#include "mainwindow.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	srand((unsigned)time(nullptr));
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
