#pragma once
#include <iostream>
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/document.h"
#include "../DataStructures/SimplyList.h"
#include "../DataStructures/Random_Box.h"
#include "TypeMessage.h"
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
                return searchedString;
            }
        }
        else {
            cout << "ERROR : KEY NOT FOUND" << endl;
            return " ";

        }
    }
    /*
    * @brief Method that serializes a TypeMessage.h method to a JSON string
    * @param typemessageObject is the TypeMessage.h object that contains all the information 
    * @return the serialized object into a JSON string 
    */
    static string TypeMessageToJSON(TypeMessage* typemessageObject) {
        Document json_document;
        StringBuffer stringbuffer;
        SimplyLinkedList<Random_Box*> *jsonPlayerList = typemessageObject->getPlayerlist();
        int list_lenght = typemessageObject->getPlayerlist()->getLen();

        json_document.SetArray();
        Document::AllocatorType& allocator = json_document.GetAllocator();

        Writer<rapidjson::StringBuffer> writer(stringbuffer);

        writer.StartObject();

        writer.Key("Game");
        writer.String(typemessageObject->getGame().c_str());
        writer.Key("Gamemode");
        writer.String(typemessageObject->getGamemode().c_str());
        writer.Key("Player");
        writer.String(typemessageObject->getPlayer().c_str());
        writer.Key("Totalplayers");
        writer.String(typemessageObject->getTotalplayers().c_str());
        writer.Key("Currentposx");
        writer.String(typemessageObject->getCurrentposx().c_str());
        writer.Key("Currentposy");
        writer.String(typemessageObject->getCurrentposy().c_str());
        writer.Key("Initmode");
        writer.String(typemessageObject->getInitmode().c_str());
        writer.Key("isAi");
        writer.String(typemessageObject->getInitmode().c_str());
        

        writer.Key("Playerlist");
        writer.StartArray();
        for (int i = 0; i < list_lenght; i++)
        {
            Random_Box* object = jsonPlayerList->get(i);
            SerializeRandomBoxToJSON(&writer, object);
        }
        writer.EndArray();
        writer.EndObject();

        return stringbuffer.GetString();
    }
    /*
    * @brief Method that serializes a singly list that contains Random_Box objects to a JSON array 
    * @param boxList the list that contains the Random_box objects
    * @return the JSON using a string 
    */
    static string PosObjectListToJSON(SimplyLinkedList<Random_Box*>* boxList) {
        Document json_document;
        StringBuffer stringbuffer;
        int cont = 0;

        json_document.SetArray();
        Document::AllocatorType& allocator = json_document.GetAllocator();

        Writer<rapidjson::StringBuffer> writer(stringbuffer);

        writer.StartArray();
        while (cont < boxList->getLen())
        {
            Random_Box* object = boxList->get(cont);
            SerializeRandomBoxToJSON(&writer , object);
            cont++;
        }
        writer.EndArray();
        

        return stringbuffer.GetString();
   
    }

    /*
    * @brief Method that serializes a Random_Box.h object using a writer object
    * @param writer object used for serializing object and boxObject is the Random_Box.h object
    */
    static void SerializeRandomBoxToJSON(rapidjson::Writer<rapidjson::StringBuffer> *writer, Random_Box* boxObject){
        writer->StartObject();
        writer->Key("posx");
        writer->Int(boxObject->getPosx());
        writer->Key("posy");
        writer->Int(boxObject->getPosy());

        writer->EndObject();
    }


};

