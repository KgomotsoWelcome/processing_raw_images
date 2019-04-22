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
			Image(std::unique_ptr<unsigned char[]> data, int width, int height);
			Image(const Image & rhs); // Copy Constructor
			Image(Image && rhs); // Move Constructor
			// Copy and Move Assignment Operators
			Image& operator=(const Image & rhs);
			Image& operator=(Image && rhs);

			/*
			+ : addition of two images (I1 + I2)
			- : subtraction of two images (I1 − I2)
			! :Invert an image (!I2)
			/ :mask I1 with I2 (I1 / I2)
			*:threshold with f (int) (I1 * f)
			*/

			Image operator+(Image & rhs);
			Image operator-(Image & rhs);
			Image operator!(void);
			Image operator/(Image & rhs);
			Image operator*(Image & rhs);


		class iterator{
			private:

				friend class Image;
				unsigned char *ptr;
				// construct only via Image class (begin/end)
				iterator(u_char *p) : 
					ptr(p) {}

			public:

				//copy construct is public
				iterator(const iterator & rhs) : 
					ptr(rhs.ptr) {}
				// define overloaded ops: *, ++, --, =
				const iterator & operator = (const iterator & rhs){
					this->ptr = std::move(rhs.ptr);
        			return *this;
				}
				// other methods for iterator

				unsigned char& operator *(){
					return *ptr;
				}

				iterator & operator ++(){
				    ++ptr;
				    return *this;
				}

				iterator operator ++(int i){
				    iterator duplicate(*this);
				    (*this)++; 
				    return duplicate;
				}

				iterator & operator --(){
				    --ptr;
				    return *this;
				}

				iterator operator --(int i){
				    iterator duplicate(*this);
				    --(*this); 
				    return duplicate;
				}

				bool operator==(const iterator& rhs){
					return (this->ptr == rhs.ptr);
				}
				// checks whether Stat1 == Stat2
				bool operator!=(const iterator& rhs){
					return (this->ptr != rhs.ptr);
				}

		};
			// define begin()/end() to get iterator to start and
			// "one-past" end.
		iterator begin(void);
		iterator end(void);
			
	};


}

#endif 