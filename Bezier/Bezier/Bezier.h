#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Bezier.h"

class Bezier : public QMainWindow
{
	Q_OBJECT

public:
	Bezier(QWidget *parent = Q_NULLPTR);

	void paintEvent(QPaintEvent *event);

protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
//	void lineInterpolation(QPoint, QPoint);

private:
	Ui::BezierClass ui;

	//�Ѿ�ȷ���ĵ�
	int pointsAmount;

	//��������ߵ�Ϳ��Ƶ�
	std::vector<QPoint> m_vecCurvePt;//��ɫ�߲��ٱ仯�����߲���
	std::vector<QPoint> m_vecCtrlPt;//��ɫ�߲��ٱ仯�����߿��Ƶ�

	//����֮����Ҫ������ĵ�
	std::vector<QPoint> m_vecClearPt;//��ɫ�߻���仯�����߲���

	//����仯�����ߵ�Ϳ��Ƶ�
	std::vector<QPoint> m_vecTempCurvePt;//��ɫ���ֱ仯������
	std::vector<QPoint> m_vecTempCtrlPt;//��ɫ���ֱ仯���ߵĿ��Ƶ�

	//�����εı���������
	void CreateBezier2();

	//�����εı���������
	void CreateBezier3();

	int isSure;
};
