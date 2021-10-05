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
	char choice,choice2,choice3;
	double delay, msg_delay,temp_msg_delay;
	int range, random_i, i=0;
	int op_num[2];
	FILE *fp;
	while (TRUE) {
        do {
            modes(&choice);
        } while ((choice>'E'||choice<'A')&&(choice<'1'||choice>'5'));

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
                    counter_mode_modes(&choice2);
                } while ((choice2<'A'||choice2>'F')&&(choice2<'1'||choice2>'6'));
                switch(choice2) {
                    case '1':
                    case 'A':
                        do {
                            write_addition_mode(op_num);
                            timers(&delay, &msg_delay);
                        } while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
                        start_aloop_mode(&delay, &msg_delay, &temp_msg_delay, str, op_num);
                        break;
                    case '2':
                    case 'B':
                        do {
                            write_subtraction_mode(op_num);
                            timers(&delay, &msg_delay);
                        } while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
                        start_sloop_mode(&delay, &msg_delay, &temp_msg_delay, str, op_num);
                        break;
                    case '3':
                    case 'C':
                        do {
                            write_multiplication_mode(op_num);
                            timers(&delay, &msg_delay);
                        } while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
                        start_mloop_mode(&delay, &msg_delay, &temp_msg_delay, str, op_num);
                        break;
                    case '4':
                    case 'D':
                        do {
                            write_division_mode(op_num);
                            timers(&delay, &msg_delay);
                        } while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
                        start_dloop_mode(&delay, &msg_delay, &temp_msg_delay, str, op_num);
                        break;
                    case '5':
                    case 'E':
                        do {
                            write_square_root_mode(op_num);
                            timers(&delay, &msg_delay);
                        } while (op_num[0]>INT_MAX||op_num[0]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
                        start_srloop_mode(&delay, &msg_delay, &temp_msg_delay, str, op_num);

                        break;
                    case '6':
                    case 'F':
                        do {
                            write_expontetiation_mode(op_num);
                            timers(&delay, &msg_delay);
                        } while (op_num[0]>INT_MAX||op_num[1]>INT_MAX||op_num[0]<INT_MIN||op_num[1]<INT_MIN||delay>LONG_MAX||delay<LONG_MIN||msg_delay>LONG_MAX);
                        start_eloop_mode(&delay, &msg_delay, &temp_msg_delay, str, op_num);
                        break;



                    default:
                        break;
                }
                break;
            case '5':
            case 'E':
                do {
                    hotkey_modes(&choice3);
                } while((choice3>'D'||choice3<'A')&&(choice3<'1'||choice3>'4'));
                switch(choice3) {
                    case '1':
                    case 'A':
                        hotkey_ctrl_reg();
                        break;
                    case '2':
                    case 'B':
                        hotkey_alt_reg();
                        break;
                    case '3':
                    case 'C':
                        hotkey_shift_reg();
                        break;
                    case '4':
                    case 'D':
                        hotkey_win_reg();
                        break;
                    default:
                        break;
                }
                break;

            default:
                break;
        }

	}

	return EXIT_SUCCESS;
}
