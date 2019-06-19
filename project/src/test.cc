#include "../include/Configuration.h"
#include "../include/DictProducer.h"
#include "../include/IndexProduver.h"

using namespace wd;

int main()
{
    Configuration conf("/home/wj/C++/project/conf");
    
    auto confMap = conf.getConfigMap();

    DictProducer dirProducer(confMap["dir"], confMap["dict"]); 
    //dirProducer.show_files();

    dirProducer.build_dict();
    dirProducer.store_dict();
    dirProducer.show_dict();
    
    IndexProducer indexProducer(confMap["dict"], confMap["index"]);
    indexProducer.read_dict();
    indexProducer.build_index();
    //indexProducer.show_index();
    indexProducer.store_index();

    return 0;
}

