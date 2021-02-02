#include "stdafx.h"
#include "inputbox.h"

InputBox::InputBox(QString title, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(title);

	//Qt::NonModal ���ô��ڲ���ģ̬���������������������������Ϣ��
	//Qt::WindowModal���ô�����һ�����Բ�ε�ģ̬���ڣ����������ĸ����ڡ��游���ں͸����ֵܴ��ڽ���������Ϣ��
	//Qt::ApplicationModal���ô�����Ӧ��ģ̬���ڣ����������д��ڽ���������Ϣ��

	//qDebug() << (0x1001 &~ 0x0001);
	//qDebug() << (0x1000 | 0x0001);
	setWindowFlags(windowFlags() &~ Qt::WindowContextHelpButtonHint);
	//setAttribute(Qt::WA_DeleteOnClose, true);

	exec();
}

InputBox::~InputBox()
{
}

void InputBox::on_inputPushButton_clicked()
{
	m_input = ui.inputLineEdit->text().trimmed();
	emit inputed(m_input);
	
	close();
}

QString InputBox::GetInput()
{
	return m_input;
}