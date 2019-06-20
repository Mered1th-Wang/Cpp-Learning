#include "../include/DictProducer.h"

using namespace wd;

void changeTolittle(string & word)
{
    for(size_t idx = 0; idx != word.size(); ++idx)
    {
        if(!islower(word[idx]))
        {
            word[idx] = tolower(word[idx]);
        }
    }
}


DictProducer::DictProducer(const string& dir, const string& filepath)
    :dir_(dir),
     filepath_(filepath),
     dict_()
{
    //cout << "dir = " << dir << endl;
    //cout << "filepath = " << filepath << endl;
    DIR * d = opendir(dir.c_str());
    if(d == nullptr)
    {
        perror("opendir");
    }
    struct dirent *p;
    while((p = readdir(d)))
    {
        if(strcmp(p->d_name, ".") == 0  || strcmp(p->d_name, "..") == 0)
            continue;
        files_.push_back(p->d_name);
    }
}

void DictProducer::build_dict()
{
    for(size_t idx = 0; idx != files_.size(); ++idx)
    {
        string filepath = string("../yuliao/") + files_[idx];
        cout << filepath << endl;
        ifstream ifs(filepath);
        string word;
        while(ifs >> word)
        {
            if(!isalpha(word[0])) continue; 
            
            while(!isalpha(word[word.size() - 1]))
            {
                word.erase(word.end() - 1);
            }
            changeTolittle(word);
            dict_[word]++;
        }
    }
}

void DictProducer::store_dict()
{
    ofstream ofs;
    ofs.open(filepath_);
    for(auto iter = dict_.begin(); iter != dict_.end(); ++iter)
    {
        ofs << iter->first << " " << iter->second << endl;
    }
    ofs.close();
}

void DictProducer::show_files() const
{
    for(auto &iter : files_)
    {
        cout << iter << " ";
    }
    cout << endl;
}

void DictProducer::show_dict() const
{
    for(auto & iter : dict_)
    {
        cout << iter.first << " " << iter.second << endl;
    }
}

