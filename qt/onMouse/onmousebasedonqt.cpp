#include "onmousebasedonqt.h"

onMouseBasedOnQt::onMouseBasedOnQt(QWidget *parent)
	: QMainWindow(parent)
{
	//----Qt5解决中文乱码  
	QTextCodec *codec = QTextCodec::codecForName("GB18030");

	//---显示鼠标移动时的实时位置   
	statusLabel = new QLabel();
	statusLabel->setText(codec->toUnicode("当前位置:"));
	statusLabel->setFixedWidth(100);

	//---显示鼠标位置  
	mousePointLabel = new QLabel();
	mousePointLabel->setText("");
	mousePointLabel->setFixedWidth(100);

	//---在状态栏增加控件  
	statusBar()->addPermanentWidget(statusLabel);
	statusBar()->addPermanentWidget(mousePointLabel);

	//---设置当前窗体对鼠标追踪，默认为false，false表示不追踪  
	setMouseTracking(true);

	//----设置窗口属性  
	setWindowTitle(codec->toUnicode("鼠标事件信息"));
	//----窗口大小  
	resize(400, 150);
}

onMouseBasedOnQt::~onMouseBasedOnQt()
{

}

void onMouseBasedOnQt::mousePressEvent(QMouseEvent *e)
{
	//----Qt5解决中文乱码  
	QTextCodec *codec = QTextCodec::codecForName("GB18030");

	//----QMouseEvent类提供的x()和y()可获取鼠标相对窗口的位置  
	QString str = "(" + QString::number(e->x()) + ", " + QString::number(e->y()) + ")";

	//---点击左键  
	if (Qt::LeftButton == e->button())
	{
		statusBar()->showMessage(codec->toUnicode("左键:") + str);
	}
	//---点击左键  
	if (Qt::RightButton == e->button())
	{
		statusBar()->showMessage(codec->toUnicode("右键:") + str);
	}
	//---点击左键  
	if (Qt::MidButton == e->button())
	{
		statusBar()->showMessage(codec->toUnicode("中键:") + str);
	}
}

void onMouseBasedOnQt::mouseMoveEvent(QMouseEvent *e)
{
	mousePointLabel->setText("(" + QString::number(e->x()) + ", " + QString::number(e->y()) + ")");
}

void onMouseBasedOnQt::mouseReleaseEvent(QMouseEvent *e)
{
	//----Qt5解决中文乱码  
	QTextCodec *codec = QTextCodec::codecForName("GB18030");

	//----QMouseEvent类提供的x()和y()可获取鼠标相对窗口的位置  
	QString str = "(" + QString::number(e->x()) + ", " + QString::number(e->y()) + ")";
	statusBar()->showMessage(codec->toUnicode("鼠标位置:") + str, 3000);
}

void onMouseBasedOnQt::mouseDoubleClickEvent(QMouseEvent *e)
{

}
