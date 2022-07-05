#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qlineedit.h>

class MyWidget : public QWidget
{
	public:
		MyWidget(QWidget *parent=0, const char *name=0);
};

MyWidget::MyWidget(QWidget *parent, const char *name)
		:QWidget(parent,name)
{
	setMinimumSize(200,120);
	setMaximumSize(200,120);
	QPushButton *quit = new QPushButton("Quit", this, "quit");
	quit->setGeometry(62,40,75,30);
	quit->setFont(QFont("Times",18,QFont::Bold));
	QLineEdit *line = new QLineEdit("", this, "line");
	line->setGeometry(0,20,100,20);

	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

int main(int argc, char **argv)
{

	QApplication a(argc, argv);

	MyWidget w;
	w.setGeometry(100,100,200,120);
	a.setMainWidget(&w);
	w.show();
	return a.exec();
}
