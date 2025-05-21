#pragma once
#include "../Include/Include.h"
#include <vector>
#include <cctype>
#include <stdexcept>
#include <algorithm>

class GetGlobalParameters
{
    public://变量索引
    GetGlobalParameters(){}
    ~GetGlobalParameters(){}
    bool* GetCalculatorLoop();
    bool* GetPrintCalculationProcess();
    int* GetUserDecisionEnumeration();
    int* GetRecursiveCalls();
    double* GetResult();
    std::string* GetUserMainInput();
    bool* GetJudgingParenthesesFormula();
    int* GetBracketIndexValue();
    int* GetMinimumLevelParenthesis();
};

struct Token {
    enum Type { NUMBER, OPERATOR };
    Type type;
    std::string value;
    int index;
};

class ExpressionParser {
private:
    std::vector<Token> tokens;
    int currentIndex = 0;
    GetGlobalParameters getGlobalParameters;

public:
    void parse(const std::string& input) {
        tokens.clear();
        currentIndex = 0;
        std::string buffer;

        for (size_t i = 0; i < input.size(); ++i) {
            char c = input[i];

            if (std::isdigit(c)) {
                buffer += c;
            } else {
                if (!buffer.empty()) {
                    addToken(Token::NUMBER, buffer);
                    buffer.clear();
                }
                if (isOperator(c)) {
                    addToken(Token::OPERATOR, std::string(1, c));
                }
            }
        }

        if (!buffer.empty()) {
            addToken(Token::NUMBER, buffer);
        }
    }

    const std::vector<Token>& getTokens() const {
        return tokens;
    }

    // 事务性修改方法（删除指定范围的 Token，并插入新 Token）
    bool transactionalUpdate(size_t startIndex, size_t deleteCount, const std::vector<Token>& newTokens) {
        // 1. 备份原数据
        auto backup = tokens;
        int backupIndex = currentIndex;

        try {
            // 2. 检查范围合法性
            if (startIndex >= tokens.size() || startIndex + deleteCount > tokens.size()) {
                throw std::out_of_range("The deletion range exceeds the container size.");
            }

            // 3. 删除旧数据
            tokens.erase(tokens.begin() + startIndex, tokens.begin() + startIndex + deleteCount);

            // 4. 插入新数据（无需设置 index，后续会重建）
            for (const auto& token : newTokens) {
                if (token.type != Token::NUMBER && token.type != Token::OPERATOR) {
                    throw std::invalid_argument("Invalid token type");
                }
                tokens.insert(tokens.begin() + startIndex, token);
                startIndex++;
            }

            // 5. 重建索引
            rebuildIndexes();

            // 6. 验证数据
            if (!validateTokens()) {
                throw std::runtime_error("The modified token sequence is invalid.");
            }

            return true; // 修改成功
        } catch (const std::exception& e) {
            // 回滚到备份
            tokens = backup;
            currentIndex = backupIndex;
            std::cerr << "Transactional modification failed: " << e.what() << std::endl;
            return false;
        }
    }

private:
    // 重建索引（确保连续）
    void rebuildIndexes() {
        currentIndex = 0;
        for (auto& token : tokens) {
            token.index = currentIndex++;
        }
    }

    // 验证 Token 序列的合法性
    bool validateTokens() {
        if (tokens.empty()) return true;

        // 首个 Token 必须是数字有括号除外
        if (tokens[0].type != Token::NUMBER && !*getGlobalParameters.GetJudgingParenthesesFormula()) {//!*getGlobalParameters.GetJudgingParenthesesFormula()判断括号
            return false;
        }

        // 后续必须交替为运算符和数字有括号除外
        for (size_t i = 1; i < tokens.size(); ++i) {
            if ((i % 2 == 1 && tokens[i].type != Token::OPERATOR) &&
                !*getGlobalParameters.GetJudgingParenthesesFormula() ||//!*getGlobalParameters.GetJudgingParenthesesFormula()判断括号
                (i % 2 == 0 && tokens[i].type != Token::NUMBER) &&
                !*getGlobalParameters.GetJudgingParenthesesFormula()) {//!*getGlobalParameters.GetJudgingParenthesesFormula()判断括号
                return false;
            }
        }

        return true;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';//添加扩号
    }

    void addToken(Token::Type type, const std::string& value) {
        tokens.push_back({type, value, currentIndex++});
    }
};