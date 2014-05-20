#ifndef _TK_FACERECOG_H_
#define _TK_FACERECOG_H_
#pragma once
#include <string>
using namespace std;

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\contrib\contrib.hpp>
using namespace cv;

#include "FaceStorage.h"

// 适配器的接口
class FrAdapter {
public:
	virtual void init();
	virtual bool train();
	virtual int pridect(Mat img);
};

// 使用opencv的人脸识别
class CvFrAdapter : public FrAdapter {
private:
	string face_storage_file; // 用于保存图片
	string trained_file; // 训练好的参数
	Ptr<FaceRecognizer> Fr;
	FaceStorage fs;
public:
	CvFrAdapter();
	void init();
	bool train();
	int pridect(Mat img);

	void setFaceStorage(string fn);
	void loadTrainedFile(string fn);
};


class FaceRecog {
private:
	FrAdapter* Fr;
public:
	FaceRecog();
	void setFrClass(FrAdapter* fr);
	bool train();
	int pridect(Mat img);

};

#include "FaceRecog_impl.h"

#endif // _TK_FACERECOG_H_