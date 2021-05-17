#pragma once
#include <iostream>
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/document.h"

using namespace rapidjson;
using namespace std;

class JSON_Management
{
public:
	static string NewObjectToJSON();
};

