// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <conio.h>
#include <locale>

#define MAX_LENGTH 		255

void clearText(char *string_text);
void processingText(char *text);

int main() {
	system("chcp 1251");
	system("cls");

	char string_text[MAX_LENGTH];
	clearText(string_text);

	printf("Введите ваш текст: ");
	fgets(string_text, MAX_LENGTH, stdin);

	processingText(string_text);

	printf("%s", string_text);

	_getch();
	return 0;
}

void processingText(char *text) {
	int	length = strlen(text),
		position_space_left = -1;

	for (int i = 0; i < length; i++) {
		if (text[i] == ' ' || text[i] == '\n') {
			text[position_space_left + 1] = text[i - 1];
			position_space_left = i;
		}
	}
}

void clearText(char *string_text) {
	for (int i = 0; i < MAX_LENGTH; i++)
		string_text[i] = '\0';
}