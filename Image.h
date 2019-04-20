/*****************************************************************
* Header file for the Imagedriver
* Author: Kgomotso Welcome
* Date: 25/02/2019
* Date completed: 17/03/2019
******************************************************************/

#ifndef _Image_H
#define _Image_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace WLCKGO001{

	class Image{
	private:  // private members
	
		int width;
		int height; 
		std::unique_ptr<unsigned char[]> data;
		
	public: // public members
	
		Image(); // default constructor - define in .cpp
		~Image(); // destructor - define in .cpp file
		Image(const Image & rhs); // Copy Constructor
		Image(Image && rhs); // Move Constructor
		// Copy and Move Assignment Operators
		Image& operator=(const Image & rhs);
		Image& operator=(Image && rhs);
	
		};


}

#endif 