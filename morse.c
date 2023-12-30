#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <wiringPi.h>

#define ledPin 0

int getMillisecondsForMorseTime(void);
void getTextToConvertToMorseCode(char *str);
void dot(int morseTime);
void dash(int morseTime);
void displayMorseCode(char *str, int morseTime);

int main(void) {
	int morseTime = getMillisecondsForMorseTime();
	char input[256];
	getTextToConvertToMorseCode(input);
	wiringPiSetup();
	pinMode(ledPin, OUTPUT);
	displayMorseCode(input, morseTime);
	return 0;
}

int getMillisecondsForMorseTime(void) {
	int morseTime;
	printf("Enter the milliseconds for a morse code time unit: ");
	scanf("%d", &morseTime);
	return morseTime;
}

void getTextToConvertToMorseCode(char *str) {
	printf("Enter text: ");
	scanf(" %[^\n]100s", str);
}

void dot(int t) {
	digitalWrite(ledPin, HIGH); delay(t); digitalWrite(ledPin, LOW); delay(t);
}

void dash(int t) {
	digitalWrite(ledPin, HIGH); delay(t*3); digitalWrite(ledPin, LOW); delay(t);
}

void displayMorseCode(char *str, int t) {
	for (int i = 0; i < strlen(str); i++) {
		printf("Current char = %c\n", str[i]);
		if (str[i] == ' ') {
			delay(t*3);
		} else {
			switch (tolower(str[i])) {
				case 'a':
					dot(t); dash(t);
					break;
				case 'b':
					dash(t); dot(t); dot(t); dot(t);
					break;
				case 'c':
					dash(t); dot(t); dash(t); dot(t);
					break;
				case 'd':
					dash(t); dot(t); dot(t);
					break;
				case 'e':
					dot(t);
					break;
				case 'f':
					dot(t); dot(t); dash(t); dot(t);
					break;
				case 'g':
					dash(t); dash(t); dot(t);
					break;
				case 'h':
					dot(t); dot(t); dot(t); dot(t); 
					break;
				case 'i':
					dot(t); dot(t);
					break;
				case 'j':
					dot(t); dash(t); dash(t); dash(t);
					break;
				case 'k':
					dash(t); dot(t); dash(t);
					break;
				case 'l':
					dot(t); dash(t); dot(t); dot(t);
					break;
				case 'm':
					dash(t); dash(t);
					break;
				case 'n':
					dash(t); dot(t);
					break;
				case 'o':
					dash(t); dash(t); dash(t);
					break;
				case 'p':
					dot(t); dash(t); dash(t); dot(t);					
					break;
				case 'q':
					dash(t); dash(t); dot(t); dash(t);
					break;
				case 'r':
					dot(t); dash(t); dot(t);
					break;
				case 's':
					dot(t); dot(t); dot(t);
					break;
				case 't':
					dash(t);
					break;
				case 'u':
					dot(t); dot(t); dash(t);
					break;
				case 'v':
					dot(t); dot(t); dot(t); dash(t);
					break;
				case 'w':
					dot(t); dash(t); dash(t);
					break;
				case 'x':
					dash(t); dot(t); dot(t); dash(t);
					break;
				case 'y':
					dash(t); dot(t); dash(t); dash(t);
					break;
				case 'z':
					dash(t); dash(t); dot(t); dot(t);
					break;
				default:
					printf("Character not implemented\n");
					break;
			}
			delay(t*2);
		}
	}
}