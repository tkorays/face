/*
 * =====================================================================================
 *
 *       Filename:  fr.cpp
 *
 *    Description:  face recognition
 *
 *        Version:  1.0
 *        Created:  2014年05月23日 13时32分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  tkorays (tk), tkorays@hotmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
//#include <opencv/core/core.h>
//#include <opencv/highgui.h>
//#include <opencv/contrib/contrib.h>
//using namespace cv;

#include "../face/FaceRecog.h"
#include "../face/CvFrAdapter.h"

#include <iostream>
using namespace std;

void check_status(bool status,string msg){
	if(!status){
		cout<<msg<<endl;
		exit(0);
	}
}

int main(int argc,char** argv){
	string dir_prefix = "/home/tkorays/pic/face_data/";
	FaceRecog fr;

	CvFrAdapter cvfr;
	cvfr.setFaceStorage(dir_prefix+"face_list.xml");
	fr.setFrClass(&cvfr);

	bool status = fr.train();
	check_status(status,"Train failed...");

	int ret = fr.pridect(imread(dir_prefix+"xujian/small/9.jpg",CV_LOAD_IMAGE_GRAYSCALE));
	cout<<"The guy is: "+fr.getNameById(ret)<<endl;

	return 0;
}
