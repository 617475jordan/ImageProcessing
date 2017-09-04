#include "onmousebasedonqt.h"

onMouseBasedOnQt::onMouseBasedOnQt(QWidget *parent)
	: QMainWindow(parent)
{
	//----Qt5�����������  
	QTextCodec *codec = QTextCodec::codecForName("GB18030");

	//---��ʾ����ƶ�ʱ��ʵʱλ��   
	statusLabel = new QLabel();
	statusLabel->setText(codec->toUnicode("��ǰλ��:"));
	statusLabel->setFixedWidth(100);

	//---��ʾ���λ��  
	mousePointLabel = new QLabel();
	mousePointLabel->setText("");
	mousePointLabel->setFixedWidth(100);

	//---��״̬�����ӿؼ�  
	statusBar()->addPermanentWidget(statusLabel);
	statusBar()->addPermanentWidget(mousePointLabel);

	//---���õ�ǰ��������׷�٣�Ĭ��Ϊfalse��false��ʾ��׷��  
	setMouseTracking(true);

	//----���ô�������  
	setWindowTitle(codec->toUnicode("����¼���Ϣ"));
	//----���ڴ�С  
	resize(400, 150);
}

onMouseBasedOnQt::~onMouseBasedOnQt()
{

}

void onMouseBasedOnQt::mousePressEvent(QMouseEvent *e)
{
	//----Qt5�����������  
	QTextCodec *codec = QTextCodec::codecForName("GB18030");

	//----QMouseEvent���ṩ��x()��y()�ɻ�ȡ�����Դ��ڵ�λ��  
	QString str = "(" + QString::number(e->x()) + ", " + QString::number(e->y()) + ")";

	//---������  
	if (Qt::LeftButton == e->button())
	{
		statusBar()->showMessage(codec->toUnicode("���:") + str);
	}
	//---������  
	if (Qt::RightButton == e->button())
	{
		statusBar()->showMessage(codec->toUnicode("�Ҽ�:") + str);
	}
	//---������  
	if (Qt::MidButton == e->button())
	{
		statusBar()->showMessage(codec->toUnicode("�м�:") + str);
	}
}

void onMouseBasedOnQt::mouseMoveEvent(QMouseEvent *e)
{
	mousePointLabel->setText("(" + QString::number(e->x()) + ", " + QString::number(e->y()) + ")");
}

void onMouseBasedOnQt::mouseReleaseEvent(QMouseEvent *e)
{
	//----Qt5�����������  
	QTextCodec *codec = QTextCodec::codecForName("GB18030");

	//----QMouseEvent���ṩ��x()��y()�ɻ�ȡ�����Դ��ڵ�λ��  
	QString str = "(" + QString::number(e->x()) + ", " + QString::number(e->y()) + ")";
	statusBar()->showMessage(codec->toUnicode("���λ��:") + str, 3000);
}

void onMouseBasedOnQt::mouseDoubleClickEvent(QMouseEvent *e)
{

}
