#ifndef _TK_FACERECOG_IMPL_H_
#define _TK_FACERECOG_IMPL_H_
#pragma once

#include "FaceRecog.h"

// CvFrAdapter的实现
CvFrAdapter::CvFrAdapter() {

}
void CvFrAdapter::init() {
	Fr = createEigenFaceRecognizer(20);
}
bool CvFrAdapter::train() {
	if (face_storage_file.empty()) {
		return false;
	} // else face_storage_file not empty 
	fs.load(face_storage_file);
	vector<Face> allface = fs.getAllFaces();
	vector<Face>::iterator allface_it = allface.begin();
	vector<Mat> faces;
	vector<int> labels;
	while (allface_it!=allface.end()) {
		vector<string>::iterator img_it = (*allface_it).images.begin();
		while (img_it != (*allface_it).images.end()) {
			Mat gray_img = imread((*img_it), CV_LOAD_IMAGE_GRAYSCALE);
			faces.push_back(gray_img);
			labels.push_back((*allface_it).getId());
		}
	}
	Fr->train(faces, labels);
	return true;
}
int CvFrAdapter::pridect(Mat img) {
	return Fr->predict(img);
}
void CvFrAdapter::setFaceStorage(string fn) {
	face_storage_file = fn;
}
void CvFrAdapter::loadTrainedFile(string fn) {
	trained_file = fn;
}


// FaceRecog的实现
FaceRecog::FaceRecog() {
	Fr = 0;
}
void FaceRecog::setFrClass(FrAdapter* fr) {
	Fr = fr;
}
bool FaceRecog::train() {
	return Fr->train();
}
int FaceRecog::pridect(Mat img) {
	return Fr->pridect(img);
}

#endif // _TK_FACERECOG_IMPL_H_