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
	void mousePressEvent(QMouseEvent *e);       //--��갴���¼�  
	void mouseMoveEvent(QMouseEvent *e);    //--����ƶ��¼�  
	void mouseReleaseEvent(QMouseEvent *e); //--����ͷţ��ɿ����¼�  
	void mouseDoubleClickEvent(QMouseEvent *e); //--���˫���¼�  

private:
	QLabel *statusLabel;                //---��ʾ����ƶ�ʱ��ʵʱλ��   
	QLabel *mousePointLabel;        //---��ʾ���λ��  
};

#endif // ONMOUSEBASEDONQT_H
