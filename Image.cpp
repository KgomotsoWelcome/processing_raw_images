/*****************************************************************
* .cpp file for function definitions and implementations
* Author: Kgomotso Welcome
* Date: 25/02/2019
* Date completed: 17/03/2019
******************************************************************/

#include "Image.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>

using namespace std; 

/**
* Default constructor - set the width and height to 0. 
* 					  - intialize vector size to 0. 
**/
WLCKGO001 :: Image :: Image() : 
	width(0),
	height(0),
	data(nullptr){}
 
WLCKGO001 :: Image :: ~Image(){
	//no need to free memory as we are using unique pointers.
} 

WLCKGO001::Image::Image(std::unique_ptr<unsigned char[]> data, int width, int height) : 
	width(width), 
	height(height), 
	data(move(data)) {}

// Copy Constructor
WLCKGO001 :: Image :: Image(const Image & rhs) : 
	width(rhs.width),
    height(rhs.height){
    //unique pointer not copyable, thus not accounted for in copy constructor
}

// Move Constructor
WLCKGO001 :: Image :: Image(Image && rhs) :
	width (rhs.width),
	height (rhs.height),
	data(std::move(rhs.data)){
		 rhs.width = -1;
   		 rhs.height = -1;
	
}
// Copy Assignment Operator
WLCKGO001 :: Image & WLCKGO001 :: Image :: operator = (const Image & rhs){
	if(this != &rhs) {
		width = rhs.width;
		height = rhs.height;
		//unique pointer not copyable, thus not accounted for in copy assignment operator
	}
	return *this;
}

//Move Assignment Operator
WLCKGO001 :: Image & WLCKGO001 :: Image :: operator = (Image && rhs){
	if(this != &rhs) {
		width = rhs.width;
		height = rhs.height;
		data = std::move(rhs.data);
	}
	return *this;
}


WLCKGO001 :: Image :: iterator WLCKGO001 :: Image :: begin(void){ 
	return iterator(data.get());
}

WLCKGO001 :: Image :: iterator WLCKGO001 :: Image :: end(void){ 
	int sizeOfData = height*width;
	return iterator(data.get()+sizeOfData-1);
}

WLCKGO001 :: Image WLCKGO001 :: Image:: operator+(Image & rhs){
	//check if image is same size
	Image duplicate = Image(*this);//copy constructor
	if (height == rhs.height && width == rhs.height){
		Image :: iterator obegin = duplicate.begin();
		Image :: iterator oender = duplicate.end();

		Image :: iterator rbegin = rhs.begin();
		Image :: iterator render = rhs.end();

		while (obegin != oender){
			int sum = ((int)*obegin + (int)*rbegin);
			if(sum > 255){
				sum = 255;
			}else{
				*obegin = (unsigned char)sum; 
			}
			++obegin;
			++rbegin;
		}

	}else{
		cout << "operation cannot be performed on images with different size." << endl;
		exit(1);
	}

	return duplicate;
}

WLCKGO001 :: Image WLCKGO001 :: Image:: operator-(Image & rhs){
		//check if image is same size
	Image duplicate = Image(*this);//copy constructor
	if (height == rhs.height && width == rhs.height){
		Image :: iterator obegin = duplicate.begin();
		Image :: iterator oender = duplicate.end();

		Image :: iterator rbegin = rhs.begin();
		Image :: iterator render = rhs.end();

		while (obegin != oender){
			int diff = ((int)*obegin - (int)*rbegin);
			if(diff < 0){
				diff = 0;
			}else{
				*obegin = (unsigned char)diff;
			}
			++obegin;
			++rbegin;
		}

	}else{
		cout << "operation cannot be performed on images with different size." << endl;
		exit(1);
	}

	return duplicate;
}

WLCKGO001 :: Image WLCKGO001 :: Image:: operator!(void){
	Image duplicate = Image(*this);//copy constructor
	Image :: iterator obegin = duplicate.begin();
	Image :: iterator oender = duplicate.end();

	while (obegin != oender){
		
		*obegin = 255 - *obegin;
		++obegin;
	}

	return duplicate;
}

WLCKGO001 :: Image WLCKGO001 :: Image:: operator/(Image & rhs){
	//check if image is same size
	Image duplicate = Image(*this);//copy constructor
	if (height == rhs.height && width == rhs.height){
		Image :: iterator obegin = duplicate.begin();
		Image :: iterator oender = duplicate.end();

		bool check = true;

		if (*obegin == 255){
			check = true;
		}else{
			check = false;
		}

		while (obegin != oender){
			if(check == false){
				*obegin = 0;
			}
			++obegin;
			++oender;	
		}

	}else{
		cout << "operation cannot be performed on images with different size." << endl;
		exit(1);
	}

	return duplicate;
}

WLCKGO001 :: Image WLCKGO001 :: Image:: operator*(int threshold){

	Image duplicate = Image(*this);//copy constructor
	Image :: iterator obegin = duplicate.begin();
	Image :: iterator oender = duplicate.end();

	while (obegin != oender){
		
		while (obegin != oender){
			if(*obegin>threshold){
				*obegin = 255;
			}else{
				*obegin = 0;
			}
			++obegin;
			++oender;	
		}
	}

	return duplicate;
}

