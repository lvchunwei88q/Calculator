#include "Value.h"
#include "Timer.h"

void GlobalControl::Initialization()
{
    //初始化SetInitializationClass
    SetInitialization* setInitialization = new SetInitialization();
    GetInitialization = setInitialization;
}

void GlobalControl::DeleeInitialization()
{
    //删除SetInitializationClass
    delete GetInitialization;

    std::cout << "CalculatorEnd!" << std::endl;
}

void SetInitialization::SetGlobal(bool ControlGlobalParameters,bool PrintCalculationProcess)//初始化函数
{   //初始化列表
    GetGlobalParameters->SetControlGlobalParameters(ControlGlobalParameters);
    GetGlobalParameters->SetControlGlobalUserInput();
    GetGlobalParameters->SetPrintCalculationProcess(PrintCalculationProcess);
    GetGlobalParameters->SetResult();
    GetGlobalParameters->SetRecursiveCalls(0);//初始化为0
    GetGlobalParameters->SetBracketIndexValue(0);//初始化为0
    GetGlobalParameters->SetJudgingParenthesesFormula(false);//初始化为false因为默认就是没有括号
    GetGlobalParameters->SetMinimumLevelParenthesis(NULL);//初始化为NULL因为默认就是没有括号
}

void SetInitialization::SetGlobalParametersLoop(bool BOOL)
{
    GetGlobalParameters->SetControlGlobalParameters(BOOL);
}

void SetInitialization::SetPrintCalculationProcess()
{
    bool SetPrintCalculationProcess;
    std::cout << "Please enter whether to print the calculation process.(0 or 1)" << std::endl;
    std::cin >> SetPrintCalculationProcess;
    while (true)//循环检测用户输入是否合法
    {
        if (std::cin.fail())
        {
            ERRORINPUTNULL
            std::cin >> SetPrintCalculationProcess;
        }else break;
    }
    GetGlobalParameters->SetPrintCalculationProcess(SetPrintCalculationProcess);
    if (*GetGlobalParameters->GetPrintCalculationProcess())std::cout << "Start Printing!" << std::endl;
    else std::cout << "Turn off Printing!" << std::endl;//提醒用户是否开启打印
}

bool* SetInitialization::GetGlobalParametersLoop()
{
    return GetGlobalParameters->GetControlGlobalParameters();
}

int* SetInitialization::GetUserDecision()
{
    UserDecision* userdecision = new UserDecision();//这个不会被一直保留
    UserDecisions = userdecision;
    return userdecision->UserDecisionreturn();
}

bool* SetInitialization::GetPrintCalculationProcess()
{
    return GetGlobalParameters->GetPrintCalculationProcess();
}

void SetInitialization::MainCalculation()
{
    std::cout << "Please enter the formula to be calculated." << std::endl;
    std::string* UserMainInput = UserDecisions->UserMainInputreturn();
    delete UserDecisions;//删除UserDecision
    Timer CurrentTime;//计时器
    
    ExpressionParser parser;//这里是在栈上创建的，不要在堆上
    parser.parse(*UserMainInput);
    if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
    {
        //这会耗费一定的性能
        PRINTOPERATIONINDEX
    }
    
    //这里计算有括号的算式
    while (true)
    {
        ParenthesisCalculations(parser);//GetMinimumLevelParenthesis
        if (!*GetGlobalParameters->GetJudgingParenthesesFormula())break;//这里判断是否有括号
        CalculateWeightFormula(parser);
    }
    //这里计算没有括号的算式
    *GetGlobalParameters->GetResult() = Maincalculate(parser);//计算结果
    
    std::cout << "\n" << "\n" << "Result: " << *GetGlobalParameters->GetResult() << std::endl;//打印结果
    //耗时 S - MS
    std::cout << "Time-consuming: " << CurrentTime.elapsed() << " MS\n";
    std::cout << "Time-consuming: " << CurrentTime.elapsedSeconds() << " S\n";
    //打印回调多少次2
    std::cout << "RecursiveCalls: " << *GetGlobalParameters->GetRecursiveCalls() << "\n";
}

double SetInitialization::Maincalculate(ExpressionParser& parser)
{
    GetGlobalParameters->SetRecursiveCalls(*GetGlobalParameters->GetRecursiveCalls()+1);
    const std::vector<Token>& tokens = parser.getTokens();//Gettokens
    if (tokens.empty()) return 0.0;//检测

    for (const auto& token : tokens)//这个数组判断乘除
    {
        if (token.type == Token::NUMBER)continue;
        if (token.type == Token::OPERATOR)
        {
            if (token.value == "*" || token.value == "/")
            {
                //检测生成Index索引值
                ChecktheGeneratedIndexValue

                if (token.value == "*")
                    Temp = OneNumBer * TwoNumBer;
                else if(token.value == "/")
                    Temp = OneNumBer / TwoNumBer;
                else {std::cout << "\n[Maincalculate:]Error! Invalid Operator!" << std::endl;break;}
                
                if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
                std::cout << "TempResults: " << Temp << '\n';
                std::vector<Token> newTokens = {
                    {Token::NUMBER, std::to_string(Temp), 0}  // index 会被 rebuildIndexes() 覆盖
                };
                // 删除位置：token.index - 1 到 token.index + 1
                bool success = parser.transactionalUpdate(token.index - 1, 3, newTokens);
                
                if (success) {
                    if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
                    {
                        std::cout << "\nAfterModificationTokens:" << '\n';
                        for (const auto& token : parser.getTokens()) {
                            std::cout << token.index << ": " << token.value << '\n';
                        }
                    }
                    return Maincalculate(parser);  // 递归处理新 Token 列表
                }else
                {
                    std::cout << "\n[Maincalculate:]Error! Invalid Operator!" << std::endl;
                    break;
                }
            }
        }
    }
    for (const auto& token : tokens)//这个数组判断加减
    {
        if (token.type == Token::NUMBER)continue;
        if (token.type == Token::OPERATOR)
        {
            if (token.value == "+" || token.value == "-")
            {
                //检测生成Index索引值
                ChecktheGeneratedIndexValue
                
                if (token.value == "+")
                    Temp = OneNumBer + TwoNumBer;
                else if(token.value == "-")
                    Temp = OneNumBer - TwoNumBer;
                else {std::cout << "\n[Maincalculate:]Error! Invalid Operator!" << std::endl;break;}
                
                if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
                    std::cout << "TempResults: " << Temp << '\n';

                std::vector<Token> newTokens = {
                    {Token::NUMBER, std::to_string(Temp), 0}  // index 会被 rebuildIndexes() 覆盖
                };

                // 删除位置：token.index - 1 到 token.index + 1
                bool success = parser.transactionalUpdate(token.index - 1, 3, newTokens);
                if (success) {
                    if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
                    {
                        std::cout << "\nAfterModificationTokens:" << '\n';
                        for (const auto& token : parser.getTokens()) {
                            std::cout << token.index << ": " << token.value << '\n';
                        }
                    }
                    return Maincalculate(parser);  // 递归处理新 Token 列表
                }else
                {
                    std::cout << "\n[Maincalculate:]Error! Invalid Operator!" << std::endl;
                    break;
                }
            }
        }
    }
    return std::stod(tokens[0].value);//返回结果
}

void SetInitialization::ParenthesisCalculations(ExpressionParser& parser)
{
    GetGlobalParameters->SetRecursiveCalls(*GetGlobalParameters->GetRecursiveCalls()+1);//把记录的也加上
    GetGlobalParameters->SetBracketIndexValue(0);//初始化为0
    const std::vector<Token>& tokens = parser.getTokens();//Gettokens
    int index = 0;//这个记录最小级的括号
    bool TempJudgingParenthesesFormula = false;
    if (!tokens.empty())//检查过了才会执行
    {
        for (const auto& token : tokens)//这个数组判断括号
        {
            if (token.type == Token::NUMBER)continue;
            if (token.type == Token::OPERATOR)
            {
                if (token.value == "(")
                {
                    if (token.index == 1 || token.index == tokens.size())//这个不要去-1与+1
                    {
                        std::cerr << "[ParenthesisCalculations:]Operator position error!" << std::endl;
                        return;
                    }
                    GetGlobalParameters->SetBracketIndexValue(*GetGlobalParameters->GetBracketIndexValue() + 1);//有一个就加一次
                    
                    TempJudgingParenthesesFormula = true;//有一个就加一次
                    index = token.index;//当为最小级时就不在更新
                    if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
                        std::cout << "MinimumLevelParenthesis: " << index << '\n';
                }
                if (token.value == ")")
                {
                    if (*GetGlobalParameters->GetBracketIndexValue() == 0)//说明没有正确判断
                    {
                        std::cerr << "[ParenthesisCalculations:]Operator position error!" << std::endl;
                        return;
                    }
                    GetGlobalParameters->SetMinimumLevelParenthesis(index);//这里是最小的(
                }
            }
        }
        GetGlobalParameters->SetJudgingParenthesesFormula(TempJudgingParenthesesFormula);
    }
}

void SetInitialization::CalculateWeightFormula(ExpressionParser& parser)
{
    GetGlobalParameters->SetRecursiveCalls(*GetGlobalParameters->GetRecursiveCalls()+1);//把记录的也加上
    const std::vector<Token>& tokens = parser.getTokens();//Gettokens
    int index = *GetGlobalParameters->GetMinimumLevelParenthesis();//获取index
    int EndIndex = 0;
    std::string Temp;
    
    if (tokens.empty())//检查过了才会执行-用于检查容器是否为空
    {
        std::cerr << "[CalculateWeightFormulaEmpty:]Operator position error!" << std::endl;
        return;
    }
    for (const auto& token : tokens)
    {
        if (token.index >= index)//在Index之前的都跳过
        {
            if (token.value == ")")
            {
                EndIndex = token.index;//最小结束的Index
                break;
            }
            if (token.value == "(")continue;//确保没有括号
            Temp += token.value;
        }
    }
    
    ExpressionParser TempParser;//这里是在栈上创建的，不要在堆上
    TempParser.parse(Temp);
    double TempResult = Maincalculate(TempParser);//计算结果
    
    std::vector<Token> newTokens = {
        {Token::NUMBER, std::to_string(TempResult), 0}  // index 会被 rebuildIndexes() 覆盖
    };
    int TempIndex = EndIndex - index + 1;
    // 删除位置：index 到 EndIndex
    bool success = parser.transactionalUpdate(index, TempIndex, newTokens);
                
    if (success) {
        if (*GetGlobalParameters->GetPrintCalculationProcess())//检测是否要打印计算过程
        {
            std::cout << "\nAfterModificationTokens:" << '\n';
            for (const auto& token : parser.getTokens()) {
                std::cout << token.index << ": " << token.value << '\n';
            }
        }
    }else
    {
        std::cout << "\n[CalculateWeightFormula:]Error! Invalid Operator!" << std::endl;
        return;
    }
}