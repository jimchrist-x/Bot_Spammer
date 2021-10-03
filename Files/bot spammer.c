#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <gmp.h>
#include "functions.h"


int main() {
	char str[SIZE], path[SIZE],formatted_path[SIZE];
	char choice, choice2;
	double delay, msg_delay,temp_msg_delay;
	int range, random_i, i=0;
	int op_num[2];
	FILE *fp;
	do {
		modes(&choice);
	} while ((choice>'D'||choice<'A')&&(choice<'1'||choice>'4'));


	switch(choice) {
		case '1':
		case 'A':
			do {
				write_letters(str);
				timers(&delay, &msg_delay);
			} while(delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
			start_letloop(&delay, &msg_delay, &temp_msg_delay, str);
			break;
		case '2':
		case 'B':
			do {
				write_numbers(&range);
				timers(&delay, &msg_delay);
			} while (range>INT_MAX||range<0||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
			start_rloop(&delay, &msg_delay, &temp_msg_delay, str, &random_i, &range);
			break;
		case '3':
		case 'C':
			do {
				write_file(path);
				timers(&delay, &msg_delay);
			} while(delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX||msg_delay<LONG_MIN);
			format_path(path, formatted_path);
			start_floop(fp, &delay, &msg_delay, &temp_msg_delay, str, path);
			break;
		case '4':
		case 'D':
			do {
				show_time();
				printf("\n");
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
						show_time();
						printf("\n");
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Amount to add per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						show_time();
						printf("\n");
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.1lf...",delay);
						delay-=mil_del;
						Sleep(mil);
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
							printf("Sending keys in %.1lf...",msg_delay);
							Sleep(mil);
							msg_delay-=mil_del;
							system("cls");
						}
					}
					break;
				case '2':
				case 'B':
					do {
						show_time();
						printf("\n");
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Amount to subtract per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						show_time();
						printf("\n");
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.1lf...",delay);
						delay-=mil_del;
						Sleep(mil);
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
							printf("Sending keys in %.1lf...",msg_delay);
							Sleep(mil);
							msg_delay-=mil_del;
							system("cls");
						}
					}
					break;
				case '3':
				case 'C':
					do {
						show_time();
						printf("\n");
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Amount to multiply per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						show_time();
						printf("\n");
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.1lf...",delay);
						delay-=mil_del;
						Sleep(mil);
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
							printf("Sending keys in %.1lf...",msg_delay);
							Sleep(mil);
							msg_delay-=mil_del;
							system("cls");
						}
					}
					break;
				case '4':
				case 'D':
					do {
						show_time();
						printf("\n");
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Amount to divide per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						show_time();
						printf("\n");
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.1lf...",delay);
						delay-=mil_del;
						Sleep(mil);
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
							printf("Sending keys in %.1lf...",msg_delay);
							Sleep(mil);
							msg_delay-=mil_del;
							system("cls");
						}
					}
					break;
				case '5':
				case 'E':
					do {
						show_time();
						printf("\n");
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						show_time();
						printf("\n");
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[0]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.1lf...",delay);
						delay-=mil_del;
						Sleep(mil);
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
							printf("Sending keys in %.1lf...",msg_delay);
							Sleep(mil);
							msg_delay-=mil_del;
							system("cls");
						}
					}
					break;
				case '6':
				case 'F':
					do {
						show_time();
						printf("\n");
						printf("Starting number: ");
						scanf("%d",op_num);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Amount to exponent per loop: ");
						scanf("%d",&op_num[1]);
						fflush(stdin);
						system("cls");
						show_time();
						printf("\n");
						printf("Bot idle time before startup (seconds): ");
						scanf("%lf", &delay);
						system("cls");
						fflush(stdin);
						show_time();
						printf("\n");
						printf("Delay in between the message (seconds): ");
						scanf("%lf",&msg_delay);
						fflush(stdin);
						system("cls");
					} while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
					while (delay>0) {
						printf("Starting in %.1lf...",delay);
						delay-=mil_del;
						Sleep(mil);
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
							printf("Sending keys in %.1lf...",msg_delay);
							Sleep(mil);
							msg_delay-=mil_del;
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
