#include "Value.h"

void SystemLoop(GlobalControl& Calculator)
{
    switch (*Calculator.GetInitialization->GetUserDecision())
    {
        case ContinueCalculating:Calculator.GetInitialization->MainCalculation();
            break;
        case PrintCalculationProcess:Calculator.GetInitialization->SetPrintCalculationProcess();
            break;
        case Leave:Calculator.GetInitialization->SetGlobalParametersLoop(false);
            break;
        default:std::cout << "Error! User Input is Null!" << std::endl;
            Calculator.GetInitialization->GetGlobalParameters->ForceResetUserInput();//强制清除用户输入数据
            break;
    }
    //分割线
    std::cout << '\n' << "<---------------------------------------------------->" << '\n';
}
