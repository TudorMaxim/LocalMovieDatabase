
#include <QtWidgets/QApplication>
#include "tester.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tester t;
	t.TestDomain();
	/*t.TestRepository();
	t.TestController();*/
	try {
		MovieValidator validator;
		Repository dataBase("movies.csv");
		FileWatchList* watchList;
		string fileName;
		
		QWidget* wg = new QWidget();
		QString s = QInputDialog::getText(wg, "Watch List", "What type of file would you like to use? (HTML/CSV)");
		if (s.toStdString() == "CSV") {
			fileName = "watchlist.csv";
			watchList = new CSVWatchList(fileName);
		}
		else {
			fileName = "watchlist.html";
			watchList = new HTMLWatchList(fileName);
		}
		Controller ctrl(dataBase, watchList, validator);
		MainWindow window(ctrl);
		window.show();
		a.exec();
		delete watchList;
		delete wg;
	}
	catch (FileException& ex) {
		QMessageBox mess;
		mess.setText(QString(ex.what()));
		mess.exec();
		return 1;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
