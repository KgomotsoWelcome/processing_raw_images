/*****************************************************************
* .cpp file for function definitions and implementations
* Author: Kgomotso Welcome
* Date: 25/02/2019
* Date completed: 17/03/2019
******************************************************************/
#include <cstdlib>
#include "Image.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>

using namespace std; 

/**
* Default constructor - set the width and height to 0. 
* 					  - intialize vector size to 0. 
**/
WLCKGO001 :: Image :: Image(){
	width = 0;
	height = 0;
	data = nullptr;
	
}
 
WLCKGO001 :: Image :: ~Image(){
	//no need to free memory as we are using unique pointers.
} 

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
