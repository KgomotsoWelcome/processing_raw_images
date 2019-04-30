/*****************************************************************
* Basic driver file
* Author: Kgomotso Welcome
* Date started: 19/02/2019
* Date completed: 24/02/2019
******************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "Image.h"

using namespace WLCKGO001;
using namespace std;


Image image(std::move(nullptr),0,0);
Image image1(std::move(nullptr),0,0);
Image image2(std::move(nullptr),0,0);

int main(int argc, char* argv[]){
 	cout << "THIS IS THE DRIVER FILE." << endl;

    if (argc == 2){
        cout << "Insert the correct commands." << endl;
        
    }

    else if(argc == 3){
        string executable = argv[0];
        string operation = argv[1];
        string firstImage = argv[2];

        cout << "0 : "<< executable << endl;

        cout << "1 : "<< operation << endl;

        cout << "2 : "<< firstImage << endl;
        if (string(argv[1]) == "-i"){
            //testing inverse
            image.load(firstImage);
            !image;
            image.save("inverse");
        }
    }

    else if(argc == 4){
        string executable = argv[0];
        string operation = argv[1];
        string firstImage = argv[2];
        string secondImage = argv[3];

        cout << "0 : "<< executable << endl;

        cout << "1 : "<< operation << endl;

        cout << "2 : "<< firstImage << endl;

        cout << "3 : "<< secondImage << endl;
        if (string(argv[1]) == "-a"){
            //testing addition
            image1.load(firstImage);
            image2.load(secondImage);
            Image result = image1+image2;
            result.save("addition");
        }

        else if (string(argv[1]) == "-s"){
            //testing subtraction
            image1.load(firstImage);
            image2.load(secondImage);
            Image result = image1-image2;
            result.save("subtraction");
        }

        else if (string(argv[1]) == "-l"){
            //testing mask
            image1.load(firstImage);
            image2.load(secondImage);
            Image result = image1/image2;
            result.save("mask");
        }

        else if (string(argv[1]) == "-t"){
            //testing threshold
            image.load(firstImage);
            image*45;
            image.save("threshold");
        }

    }

/*
    //testing addition
    Image first = image1.load(firstImage);
    Image second = image2.load(secondImage);
    Image result = first+second;
    result.save("addition");

    //testing subtraction
    Image first = image1.load(firstImage);
    Image second = image2.load(secondImage);
    Image result = first-second;
    result.save("subtraction");

    //testing inverse
    Image test = image.load(firstImage);
    !test;
    test.save("inverse");

    //testing mask
    Image first = image1.load(firstImage);
    Image second = image2.load(secondImage);
    Image result = first/second;
    result.save("mask");

/*
    //testing threshold
    Image test = image.load(firstImage);
    test*45;
    test.save("threshold");
*/
	return 0;
}
