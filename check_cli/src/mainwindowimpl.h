#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H

//QT
#include <QMainWindow>
#include <QImage>
#include <QTimer>     // 设置采集数据的间隔时间

//opencv
#include <opencv2/opencv.hpp> //包含opencv库头文件

#include "ui_mainwindow.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	virtual ~MainWindowImpl();

private slots:
	void takingPictures();  // 拍照
	void checkIn();         // 签到
	void searchInfo();      // 查询
    void readShowImg();     // 读取图片并显示
	void takingPicAgain();  // 重拍
	void submitPic();       // 提交

private:
	QTimer *timer;
	QImage *imag;
    cv::VideoCapture cap;   // 视频获取结构
	cv::Mat frame;          // 存放每一帧图像

	void openCamara();      // 打开摄像头
	void closeCamara();     // 关闭摄像头。
    void showImg();         // 显示图片
	bool readFrame();       // 读取当前帧信息
};
#endif



