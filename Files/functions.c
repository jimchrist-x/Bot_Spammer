#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <gmp.h>
#include "functions.h"


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
	printf("\n\tE. AUTO_CLICKER");
	printf("\n\tF. SET_HOTKEY");
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
        hotkey();
		printf("Starting in %.1lf...",*delay);
		(*delay)-=mil_del;
		Sleep(mil);
		system("cls");
	}
	(*temp_msg_delay)=(*msg_delay);
	while (TRUE) {
		pressKeys(str);
		pressCkey(VK_RETURN); // Presses the Enter btn
		(*msg_delay)=(*temp_msg_delay);
		while ((*msg_delay)>0) {
            hotkey();
			printf("Sending keys in %.1lf...", *msg_delay);
			Sleep(mil);
			(*msg_delay)-=mil_del;
			system("cls");
		}
	}
}
void start_rloop(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *random_i, int *range) {
	while ((*delay)>0) {
        hotkey();
		printf("Starting in %.1lf...",*delay);
		(*delay)-=mil_del;
		Sleep(mil);
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
			    hotkey();
				printf("Sending keys in %.1lf...",*msg_delay);
				Sleep(mil);
				*msg_delay-=mil_del;
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
        hotkey();
		printf("Starting in %.1lf...",*delay);
		*delay-=mil_del;
		Sleep(mil);
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
		    hotkey();
			printf("Sending keys in %.1lf...",*msg_delay);
			Sleep(mil);
			*msg_delay-=mil_del;
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
void counter_mode_modes(char *choice2) {
    show_time();
    printf("\n");
    printf("\n\tA. ADDITION");
    printf("\n\tB. SUBTRACTION");
    printf("\n\tC. MULTIPLICATION");
    printf("\n\tD. DIVISION");
    //printf("\n\tE. SQUARE_ROOT");
    printf("\n\tE. EXPONTETIATION");
    printf("\n\nChoose operation: ");
    scanf("%c",choice2);
    fflush(stdin);
    system("cls");
    if (*choice2>='a'&&(*choice2)<='z') {
        *choice2=strup(*choice2);
    }

}
void write_addition_mode(mpq_t *op_num) {
    show_time();
    printf("\n");
    printf("Starting number: ");
    gmp_scanf("%Qd",op_num);
    fflush(stdin);
    system("cls");
    show_time();
    printf("\n");
    printf("Amount to add per loop: ");
    gmp_scanf("%Qd",&op_num[1]);
    fflush(stdin);
    system("cls");
}
void write_subtraction_mode(mpq_t *op_num) {
    show_time();
    printf("\n");
    printf("Starting number: ");
    gmp_scanf("%Qd",op_num);
    fflush(stdin);
    system("cls");
    show_time();
    printf("\n");
    printf("Amount to subtract per loop: ");
    gmp_scanf("%Qd",&op_num[1]);
    fflush(stdin);
    system("cls");
}
void write_multiplication_mode(mpq_t *op_num) {
    show_time();
    printf("\n");
    printf("Starting number: ");
    gmp_scanf("%Qd",op_num);
    fflush(stdin);
    system("cls");
    show_time();
    printf("\n");
    printf("Amount to multiply per loop: ");
    gmp_scanf("%Qd",&op_num[1]);
    fflush(stdin);
    system("cls");
}
void write_division_mode(mpq_t *op_num) {
    show_time();
    printf("\n");
    printf("Starting number: ");
    gmp_scanf("%Qd",op_num);
    fflush(stdin);
    system("cls");
    show_time();
    printf("\n");
    printf("Amount to divide per loop: ");
    gmp_scanf("%Qd",&op_num[1]);
    fflush(stdin);
    system("cls");
}
/*void write_square_root_mode(mpq_t *op_num) {
    show_time();
    printf("\n");
    printf("Starting number: ");
    gmp_scanf("%Qd",op_num);
    fflush(stdin);
    system("cls");
}*/
void write_expontetiation_mode(mpq_t *op_num) {
    show_time();
    printf("\n");
    printf("Starting number: ");
    gmp_scanf("%Qd",op_num);
    fflush(stdin);
    system("cls");
    show_time();
    printf("\n");
    printf("Amount to exponent per loop: ");
    gmp_scanf("%Qd",&op_num[1]);
    fflush(stdin);
    system("cls");
}
void start_aloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num) {
    while ((*delay)>0) {
        hotkey();
        printf("Starting in %.1lf...",*delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    *temp_msg_delay=(*msg_delay);
    while (TRUE) {
        mpq_add(op_num[0], op_num[0], op_num[1]);
        gmp_sprintf(str, "%Qd", op_num[0]);
        pressKeys(str);
        pressCkey(VK_RETURN);
        *msg_delay=(*temp_msg_delay);
        while (*msg_delay>0) {
            hotkey();
            printf("Sending keys in %.1lf...",*msg_delay);
            Sleep(mil);
            *msg_delay-=mil_del;
            system("cls");
        }
    }
}
void start_sloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num) {
    while (*delay>0) {
        hotkey();
        printf("Starting in %.1lf...", *delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    *temp_msg_delay=(*msg_delay);
    while (TRUE) {
        mpq_sub(op_num[0], op_num[0], op_num[1]);
        gmp_sprintf(str, "%Qd", op_num[0]);
        pressKeys(str);
        pressCkey(VK_RETURN);
        *msg_delay=(*temp_msg_delay);
        while (*msg_delay>0) {
            hotkey();
            printf("Sending keys in %.1lf...", *msg_delay);
            Sleep(mil);
            *msg_delay-=mil_del;
            system("cls");
        }
    }
}
void start_mloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num) {
    while (*delay>0) {
        hotkey();
        printf("Starting in %.1lf...", *delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    *temp_msg_delay=(*msg_delay);
    while (TRUE) {
        mpq_mul(op_num[0], op_num[0], op_num[1]);
        gmp_sprintf(str, "%Qd", op_num[0]);
        pressKeys(str);
        pressCkey(VK_RETURN);
        *msg_delay=(*temp_msg_delay);
        while (*msg_delay>0) {
            hotkey();
            printf("Sending keys in %.1lf...",*msg_delay);
            Sleep(mil);
            *msg_delay-=mil_del;
            system("cls");
        }
    }
}
void start_dloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num) {
    while (*delay>0) {
        hotkey();
        printf("Starting in %.1lf...", *delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    *temp_msg_delay=(*msg_delay);
    while (TRUE) {
        mpq_div(op_num[0], op_num[0], op_num[1]);
        gmp_sprintf(str, "%Qd", op_num[0]);
        pressKeys(str);
        pressCkey(VK_RETURN);
        *msg_delay=(*temp_msg_delay);
        while (*msg_delay>0) {
            hotkey();
            printf("Sending keys in %.1lf...",*msg_delay);
            Sleep(mil);
            *msg_delay-=mil_del;
            system("cls");
        }
    }
}
/*void start_srloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num) {
    while (*delay>0) {
        hotkey();
        printf("Starting in %.1lf...", *delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    *temp_msg_delay=(*msg_delay);
    while (TRUE) {
        op_num[0] = sqrt(op_num[0]);
        gmp_sprintf(str, "%Qd", op_num[0]);
        pressKeys(str);
        pressCkey(VK_RETURN);
        *msg_delay=(*temp_msg_delay);
        while (*msg_delay>0) {
            hotkey();
            printf("Sending keys in %.1lf...", *msg_delay);
            Sleep(mil);
            *msg_delay-=mil_del;
            system("cls");
        }
    }
}*/
void start_eloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num) {
    int i;
    while (*delay>0) {
        hotkey();
        printf("Starting in %.1lf...", *delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    *temp_msg_delay=(*msg_delay);
    while (TRUE) {
        for (i=1;i<mpq_get_d(op_num[1]);i++) {
            mpq_mul(op_num[0], op_num[0], op_num[0]);
        }
        gmp_sprintf(str, "%Qd", op_num[0]);
        pressKeys(str);
        pressCkey(VK_RETURN);
        *msg_delay=(*temp_msg_delay);
        while (*msg_delay>0) {
            hotkey();
            printf("Sending keys in %.1lf...", *msg_delay);
            Sleep(mil);
            *msg_delay-=mil_del;
            system("cls");
        }
    }
}
void hotkey_modes(char *choice3) {
    show_time();
    printf("\n");
    printf("Choose first key: ");
    printf("\n\tA. CTRL");
    printf("\n\tB. ALT");
    printf("\n\tC. SHIFT");
    printf("\n\tD. WIN");
    printf("\n\n");
    printf(": ");
    scanf("%c", choice3);
    fflush(stdin);
    system("cls");
    if ((*choice3)>='a'&&(*choice3)<='z') {
		*choice3=strup(*choice3);
	}
}
void hotkey_ctrl_reg(void) {
    BOOL hotkey_val;
	char sec_hotkey;
	UINT sec_hotkey_vk_code;


    show_time();
    printf("\n");
    printf("Type secondary key: ");
    scanf("%c", &sec_hotkey);
    fflush(stdin);
    system("cls");
    sec_hotkey_vk_code=VkKeyScan(sec_hotkey);
    hotkey_val=RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_NOREPEAT, sec_hotkey_vk_code);
    if (!hotkey_val) {
        printf("Error Registering Hotkey!\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

}
void hotkey_alt_reg(void) {
    BOOL hotkey_val;
	char sec_hotkey;
	UINT sec_hotkey_vk_code;


    show_time();
    printf("\n");
    printf("Type secondary key: ");
    scanf("%c", &sec_hotkey);
    fflush(stdin);
    system("cls");
    sec_hotkey_vk_code=VkKeyScan(sec_hotkey);
    hotkey_val=RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, sec_hotkey_vk_code);
    if (!hotkey_val) {
        printf("Error Registering Hotkey!\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


}
void hotkey_shift_reg(void) {
    BOOL hotkey_val;
	char sec_hotkey;
	UINT sec_hotkey_vk_code;


    show_time();
    printf("\n");
    printf("Type secondary key: ");
    scanf("%c", &sec_hotkey);
    fflush(stdin);
    system("cls");
    sec_hotkey_vk_code=VkKeyScan(sec_hotkey);
    hotkey_val=RegisterHotKey(NULL, 1, MOD_SHIFT | MOD_NOREPEAT, sec_hotkey_vk_code);
    if (!hotkey_val) {
        printf("Error Registering Hotkey!\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

}

void hotkey_win_reg(void) {
    BOOL hotkey_val;
	char sec_hotkey;
	UINT sec_hotkey_vk_code;


    show_time();
    printf("\n");
    printf("Type secondary key: ");
    scanf("%c", &sec_hotkey);
    fflush(stdin);
    system("cls");
    sec_hotkey_vk_code=VkKeyScan(sec_hotkey);
    hotkey_val=RegisterHotKey(NULL, 1, MOD_WIN, sec_hotkey_vk_code);
    if (!hotkey_val) {
        printf("Error Registering Hotkey!\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


}
void hotkey(void) {
    MSG msg;

    if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)>0) {
        if(msg.message == WM_HOTKEY) {
            switch(msg.wParam) {
                case 1:
                    system("pause");
            }
        }
    }


}

void click (double *delay, int clicks_per_sec)
{
    show_time();
    printf("\n");
    printf("Bot idle time before startup (seconds): ");
    scanf("%lf", delay);
    system("cls");
    fflush(stdin);

    while (*delay>0) {
        hotkey();
        printf("Starting in %.1lf...", *delay);
        *delay-=mil_del;
        Sleep(mil);
        system("cls");
    }
    while (1) {
        hotkey();
        INPUT Input={0};
        Input.type = INPUT_MOUSE;
        Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
        SendInput(1,&Input,sizeof(INPUT));
        ZeroMemory(&Input,sizeof(INPUT));
        Input.type = INPUT_MOUSE;
        Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1,&Input,sizeof(INPUT));
        Sleep(1000/clicks_per_sec);
    }

}
