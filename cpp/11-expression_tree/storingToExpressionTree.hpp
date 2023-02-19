#ifndef STR_TO_TREE
#define STR_TO_TREE

#include <string>
#include <vector>
#include "map_bild_functions.hpp"
#include "tokens/token.hpp"
#include "tokens/token-implementation/operatorToken.hpp"
#include "tokens/token-implementation/numToken.hpp"
#include "expressionTree/expressionTree.hpp"

using P_token = std::shared_ptr<tk::Token>;
using P_Vtok = std::vector<P_token>;

bool isOperator(char op);

float extractData(std::string const& strExpr, size_t& index);

std::vector<P_token> tokenizer(std::string const& strExpr);

P_Vtok makePN(P_Vtok const& tokenEper);

et::ExpressionTree perser(P_Vtok& tokenEper);

#endif
