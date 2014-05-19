#ifndef _TK_FACESTORAGE_H_
#define _TK_FACESTORAGE_H_
#pragma once

#include <string>
#include <vector>
using namespace std;

// face 
class Face{
private:
	int id;
	string name;
	vector<string> images;
public:
	size_t size;
	Face();
	int getId();
	void setId(int id_);
	string getName();
	void setName(string name_);
	void clearImages();
	void addImage(string img);
	void updata(int id_, string name_);
};

// facestorage
class FaceStorage{
private:
	string file;
	vector<Face> faces;
public:
	bool load(const string filename);
	bool save(const string filename);
	Face getFaceById(int id);
	Face getFaceByName(string name);
	vector<Face> getAllFaces();
	bool operator<<(Face face);

};

#include "FaceStorage_impl.h"

#endif // _TK_FACESTORAGE_H_
