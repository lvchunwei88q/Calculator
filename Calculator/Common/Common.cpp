#include "Common.h"

void ControlGlobalParameters::SetControlGlobalParameters(bool BOOL)
{
    *getGlobalParameters.GetCalculatorLoop() = BOOL;
}

void ControlGlobalParameters::SetControlGlobalUserInput()
{
    *getGlobalParameters.GetUserDecisionEnumeration() = NULL;
}

void ControlGlobalParameters::SetPrintCalculationProcess(bool BOOL)
{
    *getGlobalParameters.GetPrintCalculationProcess() = BOOL;
}

void ControlGlobalParameters::SetResult()
{
    *getGlobalParameters.GetResult() = NULL;
}

void ControlGlobalParameters::SetRecursiveCalls(int RecursiveCalls)
{
    *getGlobalParameters.GetRecursiveCalls() = RecursiveCalls;
}

void ControlGlobalParameters::SetJudgingParenthesesFormula(bool JudgingParenthesesFormula)
{
    *getGlobalParameters.GetJudgingParenthesesFormula() = JudgingParenthesesFormula;
}

void ControlGlobalParameters::SetBracketIndexValue(int BracketIndexValue)
{
    *getGlobalParameters.GetBracketIndexValue() = BracketIndexValue;
}

void ControlGlobalParameters::SetMinimumLevelParenthesis(int MinimumLevelParenthesis)
{
    *getGlobalParameters.GetMinimumLevelParenthesis() = MinimumLevelParenthesis;
}

bool* ControlGlobalParameters::GetControlGlobalParameters()
{
    return getGlobalParameters.GetCalculatorLoop();
}

void ControlGlobalParameters::ForceResetUserInput()
{
    *getGlobalParameters.GetUserDecisionEnumeration() = NULL;
}

bool* ControlGlobalParameters::GetPrintCalculationProcess()
{
    return getGlobalParameters.GetPrintCalculationProcess();
}

double* ControlGlobalParameters::GetResult()
{
    return getGlobalParameters.GetResult();
}

int* ControlGlobalParameters::GetRecursiveCalls()
{
    return getGlobalParameters.GetRecursiveCalls();
}

bool* ControlGlobalParameters::GetJudgingParenthesesFormula()
{
    return getGlobalParameters.GetJudgingParenthesesFormula();
}

int* ControlGlobalParameters::GetBracketIndexValue()
{
    return getGlobalParameters.GetBracketIndexValue();
}

int* ControlGlobalParameters::GetMinimumLevelParenthesis()
{
    return getGlobalParameters.GetMinimumLevelParenthesis();
}

UserDecision::UserDecision()
{
    USERDECISION
}

int* UserDecision::UserDecisionreturn()
{
    std::cin >> *getGlobalParameters.GetUserDecisionEnumeration();
    while (true)//循环检测用户输入是否合法
    {
        if (std::cin.fail())
        {
            ERRORINPUTNULL
            std::cin >> *getGlobalParameters.GetUserDecisionEnumeration();
        }else break;
    }
    return getGlobalParameters.GetUserDecisionEnumeration();
}

std::string* UserDecision::UserMainInputreturn()
{
    std::cin >> *getGlobalParameters.GetUserMainInput();//不可输入空格
    
    while (true)//循环检测用户输入是否合法
    {
        if (std::cin.fail())
        {
            ERRORINPUTNULL
            std::cin >> *getGlobalParameters.GetUserMainInput();
        }else break;
    }
    return getGlobalParameters.GetUserMainInput();
}
