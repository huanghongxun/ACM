int isDigit(char c) {
	return '0' <= c && c <= '9';
}

int isLower(char c) {
	return 'a' <= c && c <= 'z';
}

int isUpper(char c) {
	return 'A' <= c && c <= 'Z';
}

int isAlphabit(char c) {
	return isLower(c) || isUpper(c);
}

int isAlphabitOrNumber(char c) {
	return isAlphabit(c) || isDigit(c);
}

int isSpace(char c) {
	return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

int isPrintable(char c) {
	return '!' <= c && c <= '~';
}

int isGraphical(char c) {
	return isPrintable(c) && !isSpace(c);
}

int isPunctuation(char c) {
	return isGraphical(c) && !isAlphabitOrNumber(c);
}