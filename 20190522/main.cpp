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

	//新建一个XMLDocument对象
	XMLDocument docXml;  

	 //调用对象的LoadFile函数加载文件，并将结果返回给errXML
	XMLError errXml = docXml.LoadFile("coolshell.xml");
	
	//如果装载成功
	if (XML_SUCCESS == errXml)
	{
		//获取XML的root节点
		XMLElement* elmtRoot = docXml.RootElement();

		//获取elementRoot节点下第一个名为"channel"的子节点
		XMLElement* channel = elmtRoot->FirstChildElement("channel");

		//获取channel节点下第一个名为"title"的子节点
		XMLElement* title = channel->FirstChildElement("title");

		//获取channel节点下第一个名为"description"的子节点
		XMLElement* description = channel->FirstChildElement("description");
		
		//获取channel节点下第一个名为"FirstChildElement"的子节点
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
	traverse(info_vec); //输出到文件
}
