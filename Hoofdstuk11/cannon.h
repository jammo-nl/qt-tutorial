#ifndef CANNON_H
#define CANNON_H

#include <qwidget.h>

class CannonField : public QWidget
{
	Q_OBJECT
public:
	CannonField(QWidget *parent=0, const char *name=0);

	QSizePolicy sizePolicy() const;

	int angle() const { return ang; }
	int force() const { return f; }
public slots:
	void setAngle(int degrees);
	void setForce(int newton);
	void shoot();
private slots:
	void moveShot();
signals:
	void angleChanged(int);
	void forceChanged(int);
protected:
	void paintEvent(QPaintEvent*);
private:
	void paintShot(QPainter*);
	void paintCannon(QPainter*);
	QRect cannonRect() const;
	QRect shotRect() const;

	int ang;
	int f;

	int timerCount;
	QTimer *autoShootTimer;
	float shoot_ang;
	float shoot_f;
};
#endif
