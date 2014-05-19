#include "../face/FaceStorage.h"

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
int main() {
	read_test();
	return 0;
}
