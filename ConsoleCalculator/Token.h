#pragma once
#include <string>

const std::string OPERATORS = "+-*/()^";

enum TokenType {
	NUMBER,
	OPERATOR,
	FUNCTION
};

class Token {
private:
	std::string content = "";
	TokenType type;

public:
	Token(TokenType toType, std::string toContent) {
		type = toType;
		content = toContent;
	}

	TokenType getType() {
		return type;
	}

	std::string getContent() {
		return content;
	}

};