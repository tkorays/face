#include "../face/FaceStorage.h"
#include "../face/FaceRecog.h"

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
	FaceRecog fr;

	CvFrAdapter cvfr;
	cvfr.setFaceStorage("test.xml");

	// 当然可以直接调用cvfr的各种函数，为了能扩展，所以采用这种适配器方式
	fr.setFrClass(&cvfr);
	fr.train();
	fr.pridect(Mat());
}
int main() {
	read_test();
	return 0;
}
