#ifndef ONMOUSEBASEDONQT_H
#define ONMOUSEBASEDONQT_H

#include <QtWidgets/QMainWindow>
#include <qt_all.h>
#include "ui_onmousebasedonqt.h" 



class onMouseBasedOnQt : public QMainWindow
{
	Q_OBJECT

public:
	onMouseBasedOnQt(QWidget *parent = 0);
	~onMouseBasedOnQt();

private:
	Ui::onMouseBasedOnQtClass ui;
protected:
	void mousePressEvent(QMouseEvent *e);       //--鼠标按下事件  
	void mouseMoveEvent(QMouseEvent *e);    //--鼠标移动事件  
	void mouseReleaseEvent(QMouseEvent *e); //--鼠标释放（松开）事件  
	void mouseDoubleClickEvent(QMouseEvent *e); //--鼠标双击事件  

private:
	QLabel *statusLabel;                //---显示鼠标移动时的实时位置   
	QLabel *mousePointLabel;        //---显示鼠标位置  
};

#endif // ONMOUSEBASEDONQT_H
