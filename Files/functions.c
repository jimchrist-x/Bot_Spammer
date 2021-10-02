#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>



void show_time(void) {
	time_t t;
	struct tm *time_struct;
	time(&t);
	time_struct=localtime(&t);
	printf("%s",asctime(time_struct));
}
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
void timers(double *delay, double *msg_delay) {
	show_time();
	printf("\n");
	printf("Bot idle time before startup (seconds): ");
	scanf("%lf", delay);
	system("cls");
	fflush(stdin);
	show_time();
	printf("\n");
	printf("Delay in between the message (seconds): ");
	scanf("%lf",msg_delay);
	fflush(stdin);
	system("cls");
}
void format_path(char *path, char *formatted_path) {
	int i=0;
	while (path[i]!='\0') {
		if (path[i]=='\\') {
			formatted_path[i]=path[i];
			i++;	
			formatted_path[i]=='\\';
		}
		else {
			formatted_path[i]=path[i];
			i++;
		}
	}
}
void modes(char *choice) {
	show_time();
	printf("\n");
	printf("MODES:");
	printf("\n\tA. WRITE_LETTERS");
	printf("\n\tB. WRITE_NUMBERS");
	printf("\n\tC. WRITE_FILE");
	printf("\n\tD. CUSTOM_COUNTER_MODE");
	printf("\n\n");
	printf("\nCHOOSE MODE: ");
	fscanf(stdin,"%c",choice);
	system("cls");
	fflush(stdin);
	if ((*choice)>='a'&&(*choice)<='z') {
		*choice=strup(*choice);
	}
}
void start_letloop(double *delay, double *msg_delay, double *temp_msg_delay, char *str) {
	while ((*delay)>0) {
		printf("Starting in %.3lf...",*delay);
		(*delay)-=0.025;
		Sleep(25);
		system("cls");
	}
	(*temp_msg_delay)=(*msg_delay);
	while (TRUE) {
		pressKeys(str);
		pressCkey(VK_RETURN); // Presses the Enter btn
		(*msg_delay)=(*temp_msg_delay);	
		while ((*msg_delay)>0) {
			printf("Sending keys in %.3lf...", *msg_delay);
			Sleep(25);
			(*msg_delay)-=0.025;
			system("cls");
		}
	}
}
void start_rloop(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *random_i, int *range) {
	while ((*delay)>0) {
		printf("Starting in %.3lf...",*delay);
		(*delay)-=0.025;
		Sleep(25);
		system("cls");
	}
	*temp_msg_delay=(*msg_delay);
	srand(time(NULL));
	while (TRUE) {
		for (int i=0;i<10;i++) {
			*random_i=rand()%(*range);
			sprintf(str,"%d",*random_i);
			pressKeys(str);
			pressCkey(VK_RETURN);
			*msg_delay=(*temp_msg_delay);	
			while (*msg_delay>0) {
				printf("Sending keys in %.3lf...",*msg_delay);
				Sleep(25);
				*msg_delay-=0.025;
				system("cls");
			}
		}
		srand(time(NULL));
	}
}
void start_floop(FILE *fp, double *delay, double *msg_delay, double *temp_msg_delay, char *str, char *path) {
	int i=0;
	fp=fopen(path,"r");
	if (!fp) {
		printf("Errno : %d",errno);
		printf("\nCould not open file error!\n\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
	while ((*delay)>0) {
		printf("Starting in %.3lf...",*delay);
		*delay-=0.025;
		Sleep(25);
		system("cls");
	}
	*temp_msg_delay=(*msg_delay);	
	while (TRUE) {
		i=0;
		str[i]=fgetc(fp);
		while (str[i]!='\n'||i>=SIZE-1) {
			i++;
			str[i]=fgetc(fp);
			if (feof(fp)) {
				fseek(fp,0,SEEK_SET);
			}
		}
		str[i]='\0';
		pressKeys(str);
		pressCkey(VK_RETURN);
		*msg_delay=(*temp_msg_delay);
		while (*msg_delay>0) {
			printf("Sending keys in %.3lf...",*msg_delay);
			Sleep(25);
			*msg_delay-=0.025;
			system("cls");
		}
	}
	fclose(fp);	
}
void write_letters(char *str) {
	int i=0;
	show_time();
	printf("\n");
	printf("Type letters to send: ");
	str[i]=getchar();
	while (str[i]!='\n'||i>=SIZE-1) {
		i++;
		str[i]=getchar();
	}
	str[i]='\0';
	system("cls");
	fflush(stdin);
}
void write_numbers(int *range) {
	show_time();
	printf("\n");
	printf("Type max range of random numbers : ");
	scanf("%d",range);
	system("cls");
	fflush(stdin);
}
void write_file(char *path) {
	int i=0;
	show_time();
	printf("\n");
	printf("File path: ");
	path[i]=getchar();
	while (path[i]!='\n'||i>=SIZE-1) {
		i++;
		path[i]=getchar();
	}
	path[i]='\0';
	system("cls");
	fflush(stdin);
}
