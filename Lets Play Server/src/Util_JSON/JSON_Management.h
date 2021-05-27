#pragma once
#include <iostream>
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/document.h"
#include "../DataStructures/SimplyList.h"
#include "../DataStructures/Random_Box.h"
#include <string>


using namespace rapidjson;
using namespace std;

class JSON_Management
{
public:
    /**
     * @brief Method that gets the key searched from the JSON.
     * @param key the string that gets searched
     * @param jsonString  the JSON where the search is done
     * @return the string key from the JSON.
     */
    static string GetJSONString(string key, const string& jsonString) {
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


    /*
    * @brief Method that serializes a singly list that contains Random_Box objects to a JSON array 
    * @param boxList the list that contains the Random_box objects
    * @return the JSON using a string 
    */
    static string PosObjectListToJSON(SimplyLinkedList<Random_Box*>* boxList) {
        Document json_document;
        StringBuffer strbuf;
        int cont = 0;

        json_document.SetArray();
        Document::AllocatorType& allocator = json_document.GetAllocator();

        Writer<rapidjson::StringBuffer> writer(strbuf);

        writer.StartArray();
        while (cont < boxList->getLen())
        {
            Random_Box* object = boxList->get(cont);
            SerializeRandomBoxToJSON(&writer , object);
            cont++;
        }
        writer.EndArray();

        return strbuf.GetString();
   
    }

    /*
    * @brief Method that serializes a Random_Box.h object using a writer object
    * @param writer object used for serializing object and boxObject is the Random_Box.h object
    */
    static void SerializeRandomBoxToJSON(rapidjson::Writer<rapidjson::StringBuffer> *writer, Random_Box* boxObject){
        writer->StartObject();

        writer->String("posx");
        writer->Int(boxObject->getPosx());
        writer->String("posy");
        writer->Int(boxObject->getPosy());

        writer->EndObject();
    }


};

