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
namespace WLCKGO001{

	/**
	* Default constructor - set the width and height to 0. 
	* 					  - intialize vector size to 0. 
	**/
	Image :: Image() : 
		width(0),
		height(0),
		data(nullptr){}
	 
	Image::~Image(){
		this->height = 0;
		   this->width = 0;
	       this->data.reset(nullptr);
	} 

	Image::Image(std::unique_ptr<unsigned char[]> data, int width, int height) : 
		width(width), 
		height(height), 
		data(move(data)) {}

	// Copy Constructor
	Image::Image(Image & rhs){
    	this->height = rhs.height;
		this->width = rhs.height;
    	this->data.reset(new unsigned char[width*height]);
    	Image :: iterator obegin =this->begin();
		Image :: iterator oender = this->end();

		Image :: iterator rbegin = rhs.begin();
		Image :: iterator render= rhs.end();
		while(obegin!=oender){
			*obegin = *rbegin;
			++obegin;
			++rbegin ;
		}
		 
	}

	// Move Constructor
	 Image::Image(Image && rhs) 
	{
		   this->height = rhs.height;
		   this->width = rhs.height;
	       this->data.reset(new unsigned char[width*height]);
	       Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();

			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();
			while(obegin != oender){
				*obegin = *rbegin;
				++obegin;
				++rbegin ;

			}
		 
		   this->height = 0;
		   this->width = 0;
	       this->data.reset(nullptr);
	}
	// Copy Assignment Operator
	Image & Image::operator = (Image & rhs){
		if(this != &rhs) {
			cout<<"copy ass called"<<endl;
			this->height = rhs.height;
			cout<<"height copied"<<endl;
			this->width = rhs.height;
			cout<<"width copied"<<endl;
	    	this->data.reset(new unsigned char[this->width*this->height]);
	    	cout<<"data has been reset"<<endl;
	        Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();
			int size =0;
			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();
			cout<<"iterators have been created"<<endl;
			
			while(obegin!=oender){
				*obegin = *rbegin;
				++obegin;
				++rbegin;
			}
			/*
			for(int i=0; rhs.width*rhs.height;i++){
				data[i] = rhs.data[i];
			}*/
			cout<<"end of while"<<endl;
		 
		}
		cout<<"copy assign done"<<endl;
		return *this;

	}

	//Move Assignment Operator
	Image & Image::operator = (Image && rhs){
		if(this != &rhs) {
			this->height = rhs.height;
			this->width = rhs.height;
	    	this->data.reset(new unsigned char[width*height]);
	    	Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();
			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();
			while(obegin!=oender){
				*obegin = *rbegin;
				++obegin;
				++rbegin ;
			}
		 
		   this->height = 0;
		   this->width = 0;
	       this->data.reset(nullptr);
		}
		return (*this);
	}

	//Adder
	Image& Image::operator+(Image & rhs){
		//check if image is same size
		if ((height*width)==(rhs.width*rhs.height)){
			Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();

			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();

			while (obegin != oender){
				int sum = (*obegin + *rbegin);
				if(sum > 255){
					sum = 255;
					*obegin = (unsigned char)sum; 
				}else{
					*obegin = (unsigned char)sum; 
				}
				++obegin;
				++rbegin ;
			}
		}else{
			cout << "operation cannot be performed on images with different size." << endl;
			exit(1);
		}

		return (*this);
	}

	//Subtractor
	Image& Image::operator-(Image & rhs){
			//check if image is same size
		if ((height*width)==(rhs.width*rhs.height)){
			Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();

			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();

			while (obegin != oender){
				int diff = ((int)*obegin - (int)*rbegin);
				if(diff < 0){
					diff = 0;
					*obegin = (unsigned char)diff;
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

		return (*this);
	}

	//Inverse
	Image& Image::operator!(void){
		
		Image :: iterator obegin = this->begin();
		Image :: iterator oender = this->end();

		while (obegin != oender){
			*obegin = 255 - *obegin;
			++obegin;
		}
		return (*this);
	}

	Image Image::operator/(Image & rhs){
		//check if image is same size
		if ((height*width)==(rhs.width*rhs.height)){
			Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();

			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();

			while (obegin != oender){
				int mask ;
				//int diff = ((int)*obegin - (int)*rbegin);
				cout<<"rbegin "<<(int)*rbegin<<endl;
				int check = (int) *rbegin;
				if(check == 255){
					mask = (int)*obegin;
					*obegin = (unsigned char)mask;
				}else{
					mask = 0;
					*obegin = (unsigned char)mask;
				}
				++obegin;
				++rbegin ;
			}

		}else{
			cout << "operation cannot be performed on images with different size." << endl;
			exit(1);
		}

		return (*this);
	}


/*
	//Mask
	Image Image::operator/(Image & rhs){
		//check if image is same size
		cout << "Inside operator /"<< endl;
		Image imageRes(move(this->data),this->width,this->height);
		cout << "created image res"<< endl;
		if ((height*width)==(rhs.width*rhs.height)){
			Image :: iterator obegin =this->begin();
			Image :: iterator oender = this->end();
			
			this->data.reset(new unsigned char[this->width*this->height]);


			Image :: iterator outputBegin = imageRes.begin();
			Image :: iterator rbegin = rhs.begin();
			Image :: iterator render= rhs.end();
			cout << "created iterators"<< endl;
			int mask;
			while (obegin != oender){
				//cout << "inside while" << endl;
				//cout << "hello "<<height<< " "<< width<< endl;
				if(*rbegin == 255){
					//cout << "inside if"<< endl;
					mask = *obegin;
					*outputBegin = (unsigned char)mask;
					
				}else{
					//cout << "inside else"<< endl;
					mask = 0;
					*outputBegin = (unsigned char)mask;
				}
				++obegin;
				++rbegin ;
				++outputBegin;
			}
			cout << "Outside while"<< endl;

		}else{
			cout << "operation cannot be performed on images with different size." << endl;
			exit(1);
		}
		cout << imageRes.width<< endl;
		cout << "Leaving operator /"<< endl;
		return (imageRes);
	}
*/
	//Threshold
	Image& Image::operator*(int threshold){

	    Image :: iterator obegin =this->begin();
		Image :: iterator oender = this->end();

		while (obegin != oender){
			if(*obegin>threshold){
				*obegin = 255;
			}else{
				*obegin = 0;
			}
			++obegin;
		}

		return (*this);
	}

	void Image::load(string baseName){
		string fileName;
		fileName = baseName + ".pgm"; //create file name
		cout << "The name of the file is "<<fileName  << endl;
		ifstream inputFile(fileName, ios::in | ios::binary);

		//Image image(std::move(nullptr),0,0);
	    inputFile >> (*this);
	    inputFile.close();
	    cout<<"Completed loading Image"<<endl;
	    //return image;
		/**vector<string> tokens;
		string fileName;
		bool ignore = false;

		fileName = baseName + ".pgm"; //create file name
		cout << "The name of the file is "<<fileName  << endl;
		ifstream file(fileName, ios::binary); // open file

		if(!file){
			cout << "Could not open " << fileName << endl;
			cout << "Make sure that " << fileName << " exists."<< endl;
		}else{
			cout << "Opened image successfully."<< endl;
			
			string line;
			while(!file.eof()){
				cout << "Inside first while loop."<< endl;
	            getline(file, line, '\n');
	            //cout << line << endl;
	            if(line == "255" || line == "P5" ){
	            	ignore = true;
	            	cout <<line << endl;

	            }
	            else if(line.at(0) == '#'){
	            	ignore = true;
	            	//cout << line << endl;
	            }
	            else{
	            	ignore = false;
	                stringstream check1(line);
					string intermediate;
					while(std::getline(check1, intermediate, ' ')){
						tokens.push_back(intermediate);
					}
	            }
	        }
	        cout << "Outside first while loop."<< endl;
	    }    
	    
		istringstream(tokens[0]) >> this->width;
		istringstream(tokens[1]) >> this->height;

		cout <<"width " <<width << " height "<< height << endl;
		
		int size = width*height;
		unsigned char * buffer = new unsigned char [size];
	    file.read((char*) buffer, size);
	    this->data = std::unique_ptr<unsigned char[]> (buffer);
	    file.close();
	    cout << endl << "-----------End of load.-----------"<< endl;
	    **/
	}

	void Image::save(string baseName){
		cout << endl << "--------This is the save method.---------"<< endl;
		string binary_file = baseName + ".pgm";
		cout << binary_file << endl;
	    ofstream output_binary(binary_file, ios::out | ios::binary | ios::app);
	    output_binary << (*this);
	   
	    cout << endl << "-----------End of save.-----------"<< endl;
	}
	//correct
	void  operator <<(ofstream & outs, const Image &rhs){
	    outs<<"P5"<<endl;
	    outs<<"#CREATOR: Kgomotso Welcome, WLCKGO001\n";
	    outs<<rhs.width << " " << rhs.height<<endl;
	    cout<<rhs.width << " " << rhs.height<<endl;
	    outs<<255<<endl;
		outs.write((char*)rhs.data.get(), rhs.width*rhs.height); 
		outs.close();   
	}
	//correct
	void operator>>(ifstream & stream, Image &image){
		cout<<"start reading"<<endl;
		string line;
		int h, w;
	    getline(stream, line); 
	    getline(stream, line); 
	    while (line.find("#") != string::npos) { 
	       getline(stream, line);
	    }

	    stringstream ss(line);
	    ss >> h;
	    ss >> w;
	   // cout<< image.width << " " << image.height << endl;
	    getline(stream, line); 
	    int size = w * h;
        cout <<w<<" "<<h<<endl;
	    
	    unique_ptr<unsigned char[]> buffer(new unsigned char[size]);
	    stream.read((char *)buffer.get(), size);
	    cout<<"done reading buffer"<<endl;
	    Image image1(move(buffer),w,h);
	    cout<<"check"<<endl;
	    stream.close();
	    image = image1;
	    cout<<"assignment constructor done"<<endl;
	    //cout << image1.data.get()<<endl;
	    cout << image.width<<endl;
	}
}

