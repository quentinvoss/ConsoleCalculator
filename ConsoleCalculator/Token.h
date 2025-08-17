#pragma once
#include <string>
enum TokenType {
	NUMBER,
	OPERATOR
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