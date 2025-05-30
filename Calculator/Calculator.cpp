#include "Calculator.h"

int main()
{
    GlobalControl& Calculator = GlobalControl::getInstance();
    SetLoop(Calculator);
    return 0;
}

void SetLoop(GlobalControl& Calculator)
{
    Calculator.Initialization();//生成

    while (*(Calculator.GetInitialization->GetGlobalParametersLoop()))//设置循环
    {
        SystemLoop(Calculator);
    }
    Calculator.DeleeInitialization();//删除
}
