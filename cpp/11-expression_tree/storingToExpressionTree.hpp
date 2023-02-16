#ifndef STR_TO_TREE
#define STR_TO_TREE

#include <string>
#include <vector>
#include <assert.h>
#include "map_bild_functions.hpp"
#include "tokens/token.hpp"
#include "tokens/token-implementation/operatorToken.hpp"
#include "tokens/token-implementation/numToken.hpp"

using P_token = std::unique_ptr<tk::Token>;

bool isOperator(char op);

int extractData(std::string const& strExpr, size_t& index);

std::vector<P_token> tokenizer(std::string const& strExpr);

#endif
