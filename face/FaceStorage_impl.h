#ifndef _TK_FACESTORAGE_IMPL_H_
#define _TK_FACESTORAGE_IMPL_H_
#pragma once

#include "../ext/tinyxml/tinyxml.h"

// Impliment for class Face
Face::Face(){
	size = 0;	
}
int Face::getId(){
	return id;
}
void Face::setId(int id_){
	id = id_;
}
string Face::getName(){
	return name;
}
void Face::setName(string name_){
	name = name_;
}
void Face::clearImages(){
	images.clear();
	size = 0;
}
void Face::addImage(string img){
	bool contains = false;
	vector<string>::iterator img_it = images.begin();
	while(img_it != images.end() && !contains){
		contains = (*img_it)==img ? true : false;
		img_it++;
	}
	if(contains){
		images.push_back(img);
		size++;
	}
}
void Face::updata(int id_,string name_){
	setId(id_);
	setName(name_);
}


// Impliment for class FaceStorage
bool FaceStorage::load(const string filename){
	file = filename;

	TiXmlDocument* doc = new TiXmlDocument(file.c_str());
	doc->LoadFile();
	TiXmlElement* root = doc->RootElement();

}
bool FaceStorage::save(const string filename) {
	
	TiXmlDocument* doc = new TiXmlDocument();
	TiXmlDeclaration* declare = new TiXmlDeclaration("1.0", "UTF-8", "no");
	doc->LinkEndChild(declare);

	TiXmlElement* root = new TiXmlElement("faces");
	doc->LinkEndChild(root);

	
	for (size_t i = 0; i < faces.size(); i++) {
		TiXmlElement* face = new TiXmlElement("face");
		face->SetAttribute("id", faces[i].getId());
		face->SetAttribute("name", (faces[i].getName()).c_str());
		root->LinkEndChild(face);

		for (size_t j = 0; j < faces[i].size; j++) {

		}
	}
	bool status = doc->SaveFile(filename.c_str());
	doc->Clear(); // free memory 
	return status;
}
Face FaceStorage::getFaceById(int id){
	
}
Face FaceStorage::getFaceByName(string name){
	
}
vector<Face> FaceStorage::getAllFaces(){
	return faces; 
}
bool FaceStorage::operator<<(Face face){

}



#endif //  _TK_FACESTORAGE_IMPL_H_
