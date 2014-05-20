#ifndef _TK_FACERECOG_IMPL_H_
#define _TK_FACERECOG_IMPL_H_
#pragma once

#include "FaceRecog.h"


// FaceRecogµÄÊµÏÖ
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