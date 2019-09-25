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

	//已经确定的点
	int pointsAmount;

	//不变的曲线点和控制点
	std::vector<QPoint> m_vecCurvePt;//绿色线不再变化的曲线部分
	std::vector<QPoint> m_vecCtrlPt;//绿色线不再变化的曲线控制点

	//画完之后需要清除掉的点
	std::vector<QPoint> m_vecClearPt;//绿色线还会变化的曲线部分

	//还会变化的曲线点和控制点
	std::vector<QPoint> m_vecTempCurvePt;//红色部分变化的曲线
	std::vector<QPoint> m_vecTempCtrlPt;//红色部分变化曲线的控制点

	//画二次的贝塞尔曲线
	void CreateBezier2();

	//画三次的贝塞尔曲线
	void CreateBezier3();

	int isSure;
};
