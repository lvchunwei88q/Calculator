#pragma once
#include "../Include/Include.h"
#include "../Common/Common.h"

#define PRINTOPERATIONINDEX     std::cout << "\nAnalysisResults:" << std::endl;\
                                for (const auto& token : parser.getTokens()) {\
                                std::cout << "Index " << token.index << ":"\
                                << (token.type == Token::NUMBER ? "Number" : "Operator")\
                                << " [" << token.value << "]" << std::endl;}

#define ChecktheGeneratedIndexValue   if (token.index == 0 || token.index == tokens.size() - 1) {\
        std::cerr << "Operator position error!" << std::endl;\
        return 1;}\
        double Temp = 0.0;\
        double OneNumBer = std::stod(tokens[token.index - 1].value);\
        double TwoNumBer = std::stod(tokens[token.index + 1].value);\
        if (*GetGlobalParameters->GetPrintCalculationProcess())\
            std::cout << "Index: " << token.index << "[OneNumBer:" << OneNumBer << ",TwoNumBer:" << TwoNumBer << "]" << '\n';\


class SetInitialization
{
    public:
    ControlGlobalParameters* GetGlobalParameters = new ControlGlobalParameters();
    UserDecision* UserDecisions = nullptr;
    
    SetInitialization()
    {
        std::cout << "HI!GET-C++->Calculator" << '\n';
        SetGlobal(true,true);
    }
    //Set
    void SetGlobal(bool ControlGlobalParameters,bool PrintCalculationProcess);//初始化函数
    void SetGlobalParametersLoop(bool BOOL);
    void SetPrintCalculationProcess();
    //Get
    bool* GetGlobalParametersLoop();
    int* GetUserDecision();
    bool* GetPrintCalculationProcess();
    //Main
    void MainCalculation();
    double Maincalculate(ExpressionParser& parser);
    void ParenthesisCalculations(ExpressionParser& parser);
    void CalculateWeightFormula(ExpressionParser& parser);
    
    ~SetInitialization()
    {
        delete GetGlobalParameters;   
    }
};

class GlobalControl {
public:
    SetInitialization* GetInitialization;
    // 删除拷贝构造函数和赋值操作符，确保单例
    GlobalControl(const GlobalControl&) = delete;
    GlobalControl& operator=(const GlobalControl&) = delete;

    // 获取单例实例的静态方法
    static GlobalControl& getInstance() {
        // 使用局部静态变量实现线程安全的单例 (C++11保证)
        static GlobalControl instance;
        return instance;
    }
    void Initialization();
    void DeleeInitialization();

private:
    // 私有构造函数，防止外部实例化
    GlobalControl() = default;
    
    // 私有析构函数
    ~GlobalControl() = default;
};

void SystemLoop(GlobalControl& Calculator);