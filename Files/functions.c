#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


char strup(char s) {
	if (s<'A'||s>'Z') {
		s-=32;
	}
	return s;
}
void pressKeyB(char mK)
{
    HKL kbl = GetKeyboardLayout(0);
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    if ((int)mK<65 && (int)mK>90) //for lowercase
    {
        ip.ki.wScan = 0;
        ip.ki.wVk = VkKeyScanEx( mK, kbl );
    }
    else //for uppercase
    {
        ip.ki.wScan = mK;
        ip.ki.wVk = 0;

    }
    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));
}
void pressKeys(char *string) {
	unsigned long len=0;
	len=strlen(string);
	for (int i=0; i<=len; i++) {
		pressKeyB(string[i]);
	}
}
void pressCkey(char s) {
	INPUT input;
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = s; //Enter button
	SendInput(1, &input,sizeof(INPUT));
}
