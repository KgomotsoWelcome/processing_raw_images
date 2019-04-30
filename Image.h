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
			Image( Image & rhs); // Copy Constructor
			Image(Image && rhs); // Move Constructor
			//Image(std::unique_ptr<unsigned char[]> data, int width, int height);
			// Copy and Move Assignment Operators
			Image& operator=(Image & rhs);
			Image& operator=(Image && rhs);

			/*
			+ : addition of two images (I1 + I2)
			- : subtraction of two images (I1 − I2)
			! :Invert an image (!I2)
			/ :mask I1 with I2 (I1 / I2)
			*:threshold with f (int) (I1 * f)
			*/

			Image& operator+(Image & rhs);
			Image& operator-(Image & rhs);
			Image& operator!(void);
			Image operator/(Image & rhs);
			//Image& operator/(Image & rhs);
			Image& operator*(int threshold);
			void load(string baseName);
			void save(string baseName);
			friend void  operator <<(ofstream & outs, const Image & rhs);
			friend void operator >>(ifstream & stream, Image & image);

		class iterator{
			
			private:
				unsigned char *ptr;
				friend class Image;
				// construct only via Image class (begin/end)
				iterator(unsigned char *p) : 
					ptr(p) {}

			public:

				//copy construct is public
				iterator(const iterator & rhs) : 
					ptr(rhs.ptr) {}

				// define overloaded ops: *, ++, --, =
				iterator & operator = (iterator & rhs){
					ptr = rhs.ptr;
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


				iterator & operator --(){
				    --ptr;
				    return *this;
				}


				 bool operator == (const iterator & rhs) {
                    return ptr == rhs.ptr;
                }

				// checks whether Stat1 == Stat2
				bool operator!=(const iterator& rhs){
					//return (ptr != rhs.ptr);
					// return !((*this) == rhs);
					return !Image::iterator::operator==(rhs);
				}

		};
			// define begin()/end() to get iterator to start and
			// "one-past" end.
		iterator begin(void){
			return data.get();
		}
		iterator end(void){
			return (data.get() + width*height);
		}
			
	};

}


#endif 