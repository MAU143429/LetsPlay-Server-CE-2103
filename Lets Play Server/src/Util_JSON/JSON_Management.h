#pragma once
#include <iostream>
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/document.h"
#include <string>


using namespace rapidjson;
using namespace std;

class JSON_Management
{
public:
	static string NewObjectToJSON();

    /**
     * @brief Method that gets the key searched from the JSON.
     * @param key the string that gets searched
     * @param jsonString  the JSON where the search is done
     * @return the string key from the JSON.
     */
    string static GetJSONString(string key, const string& jsonString) {
        rapidjson::Document document;
        document.Parse<kParseDefaultFlags>(jsonString.c_str());
        const char* searchedString;
        if (document.HasMember(key.c_str())) {
            if (document[key.c_str()].IsString()) {
                searchedString = document[key.c_str()].GetString();

            }
            return searchedString;
        }
        else {
            cout << "ERROR : KEY NOT FOUND" << endl;

        }
    }



};

