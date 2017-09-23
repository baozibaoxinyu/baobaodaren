#ifndef BOX_H
#define BOX_H
class Box {
private:
	double length{ 1 };
	double width{ 1 };
	double height{ 1 };
public:
	Box(double theLength, double theWidth, double theHeight) :
		length{ theLength }, width{ theWidth }, height{ theHeight } {}
	/*
	Box(Box& box) {
		length = box.length;
		width = box.width;
		height = box.height;
	}
	*/
	Box() {};
	double volumn() const {
		return length*width*height;
	}
};
#endif