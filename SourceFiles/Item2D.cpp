#include "stdafx.h"
#include <iosfwd>
#include <sstream>

using namespace std;

Item2D::Item2D():Shape2D(), Item() {

}

Item2D::Item2D(const Item& orig):Shape2D() {
}

Item2D::~Item2D() {
}



void Item2D::encodeAsJSON(stringstream &jsonStr)
{


    jsonStr << "{";

    jsonStr << "\"item_size\": \"" << origSize() << "\",";
    jsonStr << "\"user_id\": \"" << id() << "\",";
    jsonStr << "\"prog_id\": \"" << myID << "\",";
//    jsonStr << "\"size_1\": " << origSide1()->size() << ",";
//    jsonStr << "\"size_2\": " << origSide2()->size() << ",";
	jsonStr << "\"constraints\": " << constraints() << ",";
	jsonStr << "\"bin\": " << getBin() << ",";
	if( getSpinLocation() )
        jsonStr << "\"rotation\" : \"yes\",";
        else
           jsonStr << "\"rotation\" : \"no\",";
	jsonStr << "\"W\": " << getWLocation() << ",";
	jsonStr << "\"H\": " << getHLocation();

    jsonStr << "}";



}

