#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include "functions.h"


int main() {
	char str[SIZE], path[SIZE],formatted_path[SIZE];
	char choice, choice2;
	double delay, msg_delay,temp_msg_delay;
	int range, random_i, i=0;
	int op_num[2];
	FILE *fp;
	
	do {
		printf("MODES:");
		printf("\n\tA. WRITE_LETTERS");
		printf("\n\tB. WRITE_NUMBERS");
		printf("\n\tC. WRITE_FILE");
		printf("\n\tD. CUSTOM_COUNTER_MODE");
		printf("\n\n");
		printf("\nCHOOSE MODE: ");
		fscanf(stdin,"%c",&choice);
		system("cls");
		fflush(stdin);
		if (choice>='a'&&choice<='z') {
			choice=strup(choice);
		}
	} while ((choice>'D'||choice<'A')&&(choice<'1'||choice>'4'));
	switch(choice) {
		case '1':
		case 'A':	
			do {
				printf("Type letters to send: ");
				i=0;
				str[i]=getchar();
				while (str[i]!='\n'||i>=SIZE-1) {
					i++;
					str[i]=getchar();
				}
				str[i]='\0';
				system("cls");
				fflush(stdin);
				printf("Bot idle time before startup (seconds): ");
				scanf("%lf", &delay);
				system("cls");
				fflush(stdin);
				printf("Delay in between the message (seconds): ");
				scanf("%lf",&msg_delay);
				fflush(stdin);
				system("cls");
			} while(delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
			
			while (delay>0) {
				printf("Starting in %.3lf...",delay);
				delay-=0.025;
				Sleep(25);
				system("cls");
			}
			temp_msg_delay=msg_delay;
			while (TRUE) {
				pressKeys(str);
				pressCkey(VK_RETURN); // Presses the Enter btn
				msg_delay=temp_msg_delay;	
				while (msg_delay>0) {
					printf("Sending keys in %.3lf...",msg_delay);
					Sleep(25);
					msg_delay-=0.025;
					system("cls");
				}
			}
			break;
		case '2':
		case 'B':
			do {
				printf("Type max range of random numbers : ");
				scanf("%d",&range);
				system("cls");
				fflush(stdin);
				printf("Bot idle time before startup (seconds): ");
				scanf("%lf", &delay);
				system("cls");
				fflush(stdin);
				printf("Delay in between the message (seconds): ");
				scanf("%lf",&msg_delay);
				fflush(stdin);
				system("cls");
			} while (range>INT_MAX||range<0||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
			
			while (delay>0) {
				printf("Starting in %.3lf...",delay);
				delay-=0.025;
				Sleep(25);
				system("cls");
			}
			temp_msg_delay=msg_delay;
			srand(time(NULL));
			while (TRUE) {
				for (int i=0;i<10;i++) {
					random_i=rand()%range;
					sprintf(str,"%d",random_i);
					pressKeys(str);
					pressCkey(VK_RETURN);
					msg_delay=temp_msg_delay;	
					while (msg_delay>0) {
						printf("Sending keys in %.3lf...",msg_delay);
						Sleep(25);
						msg_delay-=0.025;
						system("cls");
					}
				}
				srand(time(NULL));
			}
			break;
		case '3':
		case 'C':
			do {
				printf("File path: ");
				i=0;
				path[i]=getchar();
				while (path[i]!='\n'||i>=SIZE-1) {
					i++;
					path[i]=getchar();
				}
				path[i]='\0';
				system("cls");
				fflush(stdin);
				printf("Bot idle time before startup (seconds): ");
				scanf("%lf", &delay);
				system("cls");
				fflush(stdin);
				printf("Delay in between the message (seconds): ");
				scanf("%lf",&msg_delay);
				fflush(stdin);
				system("cls");
			} while(delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX||msg_delay<LONG_MIN);
			i=0;
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
			fp=fopen(path,"r");
			if (!fp) {
				printf("Errno : %d",errno);
				printf("\nCould not open file error!\n\n");
				system("pause");
				exit(EXIT_FAILURE);
			}
			while (delay>0) {
				printf("Starting in %.3lf...",delay);
				delay-=0.025;
				Sleep(25);
				system("cls");
			}
			temp_msg_delay=msg_delay;	
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
				msg_delay=temp_msg_delay;
				while (msg_delay>0) {
					printf("Sending keys in %.3lf...",msg_delay);
					Sleep(25);
					msg_delay-=0.025;
					system("cls");
				}
			}
			fclose(fp);
			break;
		case '4':
		case 'D':
			do {
				printf("\n\tA. ADDITION");
				printf("\n\tB. SUBTRACTION");
				printf("\n\tC. MULTIPLICATION");
				printf("\n\tD. DIVISION");
				printf("\n\tE. SQUARE_ROOT");
				printf("\n\tF. EXPONTETIATION");
				printf("\n\nChoose operation: ");
				scanf("%c",&choice2);
				fflush(stdin);
				system("cls");
				if (choice2>='a'&&choice2<='z') {
					choice2=strup(choice2);
				}
			} while ((choice2<'A'||choice2>'F')&&(choice2<'1'||choice2>'6'));
			switch(choice2) {
				case '1':
				case 'A':
					do {
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						printf("Amount to add per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.3lf...",delay);
						delay-=0.025;
						Sleep(25);
						system("cls");
					}
					temp_msg_delay=msg_delay;
					while (TRUE) {
						op_num[0] += op_num[1];
						sprintf(str,"%d",op_num[0]);
						pressKeys(str);
						pressCkey(VK_RETURN);
						msg_delay=temp_msg_delay;	
						while (msg_delay>0) {
							printf("Sending keys in %.3lf...",msg_delay);
							Sleep(25);
							msg_delay-=0.025;
							system("cls");
						}
					}
					break;
				case '2':
				case 'B':
					do {
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						printf("Amount to subtract per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.3lf...",delay);
						delay-=0.025;
						Sleep(25);
						system("cls");
					}
					temp_msg_delay=msg_delay;
					while (TRUE) {
						op_num[0] -= op_num[1];
						sprintf(str,"%d",op_num[0]);
						pressKeys(str);
						pressCkey(VK_RETURN);
						msg_delay=temp_msg_delay;	
						while (msg_delay>0) {
							printf("Sending keys in %.3lf...",msg_delay);
							Sleep(25);
							msg_delay-=0.025;
							system("cls");
						}
					}
					break;
				case '3':
				case 'C':
					do {
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						printf("Amount to multiply per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.3lf...",delay);
						delay-=0.025;
						Sleep(25);
						system("cls");
					}
					temp_msg_delay=msg_delay;
					while (TRUE) {
						op_num[0] = op_num[0] * op_num[1];
						sprintf(str,"%d",op_num[0]);
						pressKeys(str);
						pressCkey(VK_RETURN);
						msg_delay=temp_msg_delay;	
						while (msg_delay>0) {
							printf("Sending keys in %.3lf...",msg_delay);
							Sleep(25);
							msg_delay-=0.025;
							system("cls");
						}
					}
					break;
				case '4':
				case 'D':
					do {
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						printf("Amount to divide per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.3lf...",delay);
						delay-=0.025;
						Sleep(25);
						system("cls");
					}
					temp_msg_delay=msg_delay;
					while (TRUE) {
						op_num[0] = op_num[0] / op_num[1];
						sprintf(str,"%d",op_num[0]);
						pressKeys(str);
						pressCkey(VK_RETURN);
						msg_delay=temp_msg_delay;	
						while (msg_delay>0) {
							printf("Sending keys in %.3lf...",msg_delay);
							Sleep(25);
							msg_delay-=0.025;
							system("cls");
						}
					}
					break;
				case '5':
				case 'E':
					do {
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						fflush(stdin);
						system("cls");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[0]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.3lf...",delay);
						delay-=0.025;
						Sleep(25);
						system("cls");
					}
					temp_msg_delay=msg_delay;
					while (TRUE) {
						op_num[0] = sqrt(op_num[0]);
						sprintf(str,"%d",op_num[0]);
						pressKeys(str);
						pressCkey(VK_RETURN);
						msg_delay=temp_msg_delay;	
						while (msg_delay>0) {
							printf("Sending keys in %.3lf...",msg_delay);
							Sleep(25);
							msg_delay-=0.025;
							system("cls");
						}
					}
					break;
				case '6':
				case 'F':
					do {
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						printf("Amount to exponent per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.3lf...",delay);
						delay-=0.025;
						Sleep(25);
						system("cls");
					}
					temp_msg_delay=msg_delay;
					while (TRUE) {
						op_num[0] = pow(op_num[0], op_num[1]);
						sprintf(str,"%d",op_num[0]);
						pressKeys(str);
						pressCkey(VK_RETURN);
						msg_delay=temp_msg_delay;	
						while (msg_delay>0) {
							printf("Sending keys in %.3lf...",msg_delay);
							Sleep(25);
							msg_delay-=0.025;
							system("cls");
						}
					}
					break;
					
					
					
				default:
					break;
			}
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}






