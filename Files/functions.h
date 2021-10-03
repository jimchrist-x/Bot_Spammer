#define SIZE 100000
#define mil 100
#define mil_del 0.1
void pressKeyB(char mk);
void pressKeys(char *string);
char strup(char s);
void pressCkey(char s);
void show_time(void);
void format_path(char *path, char *formatted_path);
void timers(double *delay, double *msg_delay);
void modes(char *choice);
void start_letloop(double *delay, double *msg_delay, double *temp_msg_delay, char *str);
void start_rloop(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *random_i, int *range);
void start_floop(FILE *fp, double *delay, double *msg_delay, double *temp_msg_delay, char *str, char *path);
void write_letters(char *str);
void write_numbers(int *range);
void write_file(char *path);
void counter_mode_modes(char *choice2);
void write_addition_mode(int *op_num);
void write_subtraction_mode(int *op_num);
void write_multiplication_mode(int *op_num);
void write_division_mode(int *op_num);
void write_square_root_mode(int *op_num);
void write_expontetiation_mode(int *op_num);
void start_aloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *op_num);
void start_sloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *op_num);
void start_mloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *op_num);
void start_dloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *op_num);
void start_srloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *op_num);
void start_eloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, int *op_num);


