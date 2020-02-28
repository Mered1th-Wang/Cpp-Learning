#pragma  once

namespace wd
{
//前向声明(不完全类型), 可以减少头文件的依赖
class TaskQueue;

class Producer
{
public:
	void create(TaskQueue & taskque);
};

}//end of namespace wd
