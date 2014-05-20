#include "../face/FaceStorage.h"
#include "../face/FaceRecog.h"
#include "../face/CvFrAdapter.h"
#include "../ext/cxxlib/cv_lib.h"

#pragma comment(lib,cvLIB("core"))
#pragma comment(lib,cvLIB("contrib"))
#pragma comment(lib,cvLIB("highgui"))
//#pragma comment(lib,cvLIB("core"))

#include <iostream>
using namespace std;

int write_test() {
	FaceStorage fs;
	
	Face face;
	face.addImage("1.jpg");
	face.addImage("2.jpg");
	face.addImage("3.jpg");

	face.updata(1, "xujian");
	fs << face;

	face.updata(2, "xuzhibo");
	fs << face;

	face.updata(3, "lingyongqing");
	fs << face;

	fs.save("test.xml");
	return 0;
}
int read_test() {
	FaceStorage fs;
	fs.load("test.xml");
	cout << fs.faces.size() << endl;

	for (size_t i = 0; i < fs.size(); i++) {
		cout << "id:" << fs.faces[i].getId() << endl;
		cout << "name:" << fs.faces[i].getName() << endl;
		for (size_t j = 0; j < fs.faces[i].images.size(); j++) {
			cout << "\t" << fs.faces[i].images[j] << endl;
		}
	}
	cout << fs.getNameById(2) << endl;
	return 0;
}
void fr_test() {
	string dir = "E:/BigData/face_data/";
	FaceRecog fr; // 人脸识别类

	// 设置用于识别的类,以及做好该类的初始化
	CvFrAdapter cvfr;
	cvfr.setFaceStorage(dir+"face_list.xml");

	// 当然可以直接调用cvfr的各种函数，为了能扩展，所以采用这种适配器方式
	fr.setFrClass(&cvfr);

	cout << "training..." << endl;
	bool status =  fr.train();
	if (!status) {
		cout << "train failed!" << endl;
		return ;
	}
	cout << "load img:" << dir + "xuzhibo/small/6.jpg" << endl;
	// 识别
	int rt = fr.pridect(imread(dir+"xuzhibo/small/6.jpg",CV_LOAD_IMAGE_GRAYSCALE));
	// CvFrAdapter的FaceStorage是public的，可以使用其读取name
	cout << "这个人是：" << cvfr.fs.getNameById(rt) << endl;
}

void generate_xml_file() {
	string dir = "E:/BigData/face_data/";
	FaceStorage fs;
	Face face;
	face.addImage(dir + "xuzhibo/small/" + "1.jpg");
	face.addImage(dir + "xuzhibo/small/" + "2.jpg");
	face.addImage(dir + "xuzhibo/small/" + "3.jpg");
	face.addImage(dir + "xuzhibo/small/" + "4.jpg");
	face.addImage(dir + "xuzhibo/small/" + "5.jpg");
	face.updata(1, "徐志博");
	fs << face;

	face.clearImages();
	face.addImage(dir + "lyq/small/" + "1.jpg");
	face.addImage(dir + "lyq/small/" + "2.jpg");
	face.addImage(dir + "lyq/small/" + "3.jpg");
	face.addImage(dir + "lyq/small/" + "4.jpg");
	face.addImage(dir + "lyq/small/" + "5.jpg");
	face.updata(2, "凌永清");
	fs << face;

	face.clearImages();
	face.addImage(dir + "xujian/small/" + "1.jpg");
	face.addImage(dir + "xujian/small/" + "2.jpg");
	face.addImage(dir + "xujian/small/" + "3.jpg");
	face.addImage(dir + "xujian/small/" + "4.jpg");
	face.addImage(dir + "xujian/small/" + "5.jpg");
	face.updata(2, "许剑");
	fs << face;

	fs.save(dir + "face_list.xml");
}
int main() {
	fr_test();
	//generate_xml_file();
	return 0;
}
