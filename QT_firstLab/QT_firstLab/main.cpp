#include<QImage>
#include<iostream>
#include "Filter.h"
using namespace std;


void main(int argc, char* argv[]) {
	string s;
	QImage img;
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-p") && (i + 1 < argc)) {
			s = argv[i + 1];
		}
	}
	img.load(QString(s.c_str()));
	img.save("C:/Images/Source.png");
	InvertFilter invert;
	invert.process(img).save("C:/Images/Invert.png");
	BlurFilter blur;
	blur.process(img).save("C:/Images/Blur.png");
}