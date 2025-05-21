#pragma once
#include "GlobalParameters.h"
#include "../Include/Include.h"
#define USERDECISION     std::cout << "UserDecision" << std::endl;\
                         std::cout << "Input(1)->ContinueCalculating" << std::endl;\
                         std::cout << "Input(2)->PrintCalculationProcess" << std::endl;\
                         std::cout << "Input(3)->Leave" << std::endl;

#define ERRORINPUTNULL   std::cout << "Error! User Input is Null!" << std::endl;\
                         std::cin.clear();\
                         std::cin.ignore(1000, '\n');

class ControlGlobalParameters
{
    public:
    GetGlobalParameters getGlobalParameters;//GetGlobalParameters
    ControlGlobalParameters(){}
    ~ControlGlobalParameters(){}

    void SetControlGlobalParameters(bool BOOL);
    void SetControlGlobalUserInput();
    void SetPrintCalculationProcess(bool BOOL);
    void SetResult();
    void SetRecursiveCalls(int RecursiveCalls);
    //括号计算变量
    void SetJudgingParenthesesFormula(bool JudgingParenthesesFormula);
    void SetBracketIndexValue(int BracketIndexValue);
    void SetMinimumLevelParenthesis(int MinimumLevelParenthesis);
    //-------------------
    bool* GetControlGlobalParameters();
    void ForceResetUserInput();
    bool* GetPrintCalculationProcess();
    double* GetResult();
    int* GetRecursiveCalls();
    //括号计算变量
    bool* GetJudgingParenthesesFormula();
    int* GetBracketIndexValue();
    int* GetMinimumLevelParenthesis();
};

class UserDecision
{
    public:
    GetGlobalParameters getGlobalParameters;//GetGlobalParameters
    UserDecision();
    int* UserDecisionreturn();
    std::string* UserMainInputreturn();
    ~UserDecision(){}
};

enum UserDecisionType
{
    Null,//占位符
    ContinueCalculating,
    PrintCalculationProcess,
    Leave,
};