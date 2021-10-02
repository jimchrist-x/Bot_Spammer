#define SIZE 100000


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
