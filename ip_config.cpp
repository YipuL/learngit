//
// Created by piao on 2020/12/17.
//
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


vector<string> splitstring(string s, char sep)
{
    istringstream iss(s);
    vector<std::string> res;
    string buffer;
    while(getline(iss, buffer, sep)){
        res.push_back(buffer);
    }
    return res;
}

map<string, string> read_interface() {
    ifstream infile("network.txt");
    string line;
    map<string, string> properties; // store key-value properties
    while (getline(infile, line)){
        if (line.length() == 0 || line[0] == '#'){
            continue;
        }
        if (line.compare(0,6,"source") == 0){  //start with 'source'
            //string source, directory;
            vector<string> sv = splitstring(line,' ');
            properties["source"] = sv[1];

        }
        else if (line.compare(0,4,"auto") == 0){ // start with 'auto'
            vector<string> ifs = splitstring(line,' ');
            int num_card = ifs.size() - 1;
            if(num_card == 1){ // only have one interface card
                properties["num_card"] = "1";
                properties["card1"] = ifs[1];
            }
            else{
                properties["num_card"] = "2";
                properties["card1"] = ifs[1];
                properties["card2"] = ifs[2];

            }

        }
        else if(line.compare(0,7,"address") == 0){ // start with 'address'
            vector<string> addv = splitstring(line,' ');
            if (properties.find("address1") == properties.end()){
                properties["address1"] = addv[1];
            }
            else{
                properties["address2"] = addv[1];
            }

        }
        else if(line.compare(0,7,"netmask") == 0){ // start with 'netmask'
            vector<string> maskv = splitstring(line,' ');
            if (properties.find("netmask1") == properties.end()){
                properties["netmask1"] = maskv[1];
            }
            else{
                properties["netmask2"] = maskv[1];
            }

        }
        else if(line.compare(0,7,"network") == 0){ // start with 'network
            vector<string> netv = splitstring(line,' ');
            if (properties.find("network1") == properties.end()){
                properties["network1"] = netv[1];
            }
            else{
                properties["network2"] = netv[1];
            }

        }
        else if (line.compare(0,6,"gateway") == 0){  //start with 'gateway'
            //string source, directory;
            vector<string> gtv = splitstring(line,' ');
            properties["gateway"] = gtv[1];

        }
        else if (line.compare(0,3,"dns") == 0){ //dns server
            string dns_server = line.substr(17);
            properties["dns"] = dns_server;


        }



    }
    return properties;
//    while (getline(infile, line)) {        //load configurations
//        //read interface file line by line
//         if (line.length() > 0 && line[0] != '#') {
//            std::istringstream lineStream(line);
//            std::string key, value;
//            char delim;
//            if ((lineStream >> key >> delim >> value) && (delim == '=')) {
//                properties[key] = value;
//            }
//        }
//    }
}

int main(){
    map<string, string> interface = read_interface();
    std::map<string , string >::iterator iter;
    for (iter = read_interface().begin(); iter!=read_interface().end(); iter++)
    {
        cout<<iter->first<<iter->second<<endl;
    }


}
