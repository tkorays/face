#include "../face/FaceStorage.h"

int main(int argc, char** argv) {
	string dir = "E:/BigData/face_data/";
	FaceStorage fs;
	Face face;
	face.addImage(dir + "xuzhibo/small/" + "1.jpg");
	face.addImage(dir + "xuzhibo/small/" + "2.jpg");
	face.addImage(dir + "xuzhibo/small/" + "3.jpg");
	face.addImage(dir + "xuzhibo/small/" + "4.jpg");
	face.addImage(dir + "xuzhibo/small/" + "5.jpg");
	face.updata(1, "–Ï÷æ≤©");
	fs << face;

	face.clearImages();
	face.addImage(dir + "lyq/small/" + "1.jpg");
	face.addImage(dir + "lyq/small/" + "2.jpg");
	face.addImage(dir + "lyq/small/" + "3.jpg");
	face.addImage(dir + "lyq/small/" + "4.jpg");
	face.addImage(dir + "lyq/small/" + "5.jpg");
	face.updata(2, "¡Ë”¿«Â");
	fs << face;

	face.clearImages();
	face.addImage(dir + "xujian/small/" + "1.jpg");
	face.addImage(dir + "xujian/small/" + "2.jpg");
	face.addImage(dir + "xujian/small/" + "3.jpg");
	face.addImage(dir + "xujian/small/" + "4.jpg");
	face.addImage(dir + "xujian/small/" + "5.jpg");
	face.updata(3, "–ÌΩ£");
	fs << face;

	fs.save(dir + "face_list.xml");

	return 0;
}