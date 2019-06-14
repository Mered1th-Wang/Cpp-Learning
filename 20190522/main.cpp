#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "tinyxml2.h"
#include <regex>

using namespace std;
using namespace tinyxml2;

class information
{
public:
	information() {}
	~information() {}

public:
	string title;
	string link;
	string description;
	string content;
};

void traverse(vector<information>& _vector) {
	ofstream _ostream("result.dat", ofstream::app);

	auto _begin = _vector.begin();
	auto _end = _vector.end();
	regex re("<[^>]*>");
	++_begin;

	static int count = 1;
	
	while (_begin != _end) {
		_ostream << "<doc>" << endl;
		_ostream << "<docid>" << count++ << "</docid>" << endl;
		_ostream << "<title>" << _begin->title << "</title>" << endl;
		_ostream << "<link>" << _begin->link << "</link>" << endl;
		_ostream << "<description>" << regex_replace(_begin->description, re, "") << "</description>" << endl;
		_ostream << "<content>" << regex_replace(_begin->content, re, "") << "</content>" << endl;
		_ostream << "</doc>" << endl;
		++_begin;
	}
}

int main() {
	vector<information> info_vec;

	//�½�һ��XMLDocument����
	XMLDocument docXml;  

	 //���ö����LoadFile���������ļ�������������ظ�errXML
	XMLError errXml = docXml.LoadFile("coolshell.xml");
	
	//���װ�سɹ�
	if (XML_SUCCESS == errXml)
	{
		//��ȡXML��root�ڵ�
		XMLElement* elmtRoot = docXml.RootElement();

		//��ȡelementRoot�ڵ��µ�һ����Ϊ"channel"���ӽڵ�
		XMLElement* channel = elmtRoot->FirstChildElement("channel");

		//��ȡchannel�ڵ��µ�һ����Ϊ"title"���ӽڵ�
		XMLElement* title = channel->FirstChildElement("title");

		//��ȡchannel�ڵ��µ�һ����Ϊ"description"���ӽڵ�
		XMLElement* description = channel->FirstChildElement("description");
		
		//��ȡchannel�ڵ��µ�һ����Ϊ"FirstChildElement"���ӽڵ�
		XMLElement* item = channel->FirstChildElement("item");

		while (item) {
			information  tmp;
			XMLElement *item_child = item->FirstChildElement();
			while (item_child) {
				if (strcmp(item_child->Name(), "title") == 0) {
					tmp.title.clear();
					tmp.title.append(item_child->GetText());
				}
				else if (strcmp(item_child->Name(), "link") == 0) {
					tmp.link.clear();
					tmp.link.append(item_child->GetText());
				}
				else if (strcmp(item_child->Name(), "description") == 0) {
					tmp.description.clear();
					tmp.description.append(item_child->GetText());
				}
				else if (strncmp(item_child->Name(), "content", 7) == 0) {
					tmp.content.clear();
					tmp.content.append(item_child->GetText());
				}
				item_child = item_child->NextSiblingElement();
			}
			info_vec.push_back(tmp);
			item = item->NextSiblingElement();
		}
	}
	traverse(info_vec); //������ļ�
}
