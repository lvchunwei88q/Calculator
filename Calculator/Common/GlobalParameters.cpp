#include "GlobalParameters.h"


bool* SetCalculatorLoop = new bool;
int* UserDecisionEnumeration = new int;
//用户输入计算公式
std::string* UserMainInput = new std::string;
//设置是否打印
bool* PrintCalculationProcess = new bool;
//结果存储
double* Result = new double;
//递归次数
int* RecursiveCalls = new int;
//判断算式是否存在括号
bool* JudgingParenthesesFormula = new bool;
//括号索引值
int* BracketIndexValue = new int;
//获取当前的最下级括号索引
int* MinimumLevelParenthesis = new int;


//GetGlobalParameters.cpp
bool* GetGlobalParameters::GetCalculatorLoop()
{
    return SetCalculatorLoop;
}

bool* GetGlobalParameters::GetPrintCalculationProcess()
{
    return PrintCalculationProcess;
}

int* GetGlobalParameters::GetUserDecisionEnumeration()
{
    return UserDecisionEnumeration;
}

int* GetGlobalParameters::GetRecursiveCalls()
{
    return UserDecisionEnumeration;
}

double* GetGlobalParameters::GetResult()
{
    return Result;
}

std::string* GetGlobalParameters::GetUserMainInput()
{
    return UserMainInput;
}

bool* GetGlobalParameters::GetJudgingParenthesesFormula()
{
    return JudgingParenthesesFormula;
}

int* GetGlobalParameters::GetBracketIndexValue()
{
    return BracketIndexValue;
}

int* GetGlobalParameters::GetMinimumLevelParenthesis()
{
    return MinimumLevelParenthesis;
}