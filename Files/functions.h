#define SIZE 100000
#define mil 100
#define mil_del 0.1
#define MOD_NOREPEAT 0x4000 // May be used when pressing Hotkey in function: hotkey()
void pressKeyB(char mk); // Presses a keystroke
void pressKeys(char *string); // Presses many keystrokes
char strup(char s); // Converts lowercase ascii to uppercase
void pressCkey(char s); // Presses a special key ex. enter
void show_time(void); // Prints datetime
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
void write_addition_mode(mpq_t *op_num);
void write_subtraction_mode(mpq_t *op_num);
void write_multiplication_mode(mpq_t *op_num);
void write_division_mode(mpq_t *op_num);
//void write_square_root_mode(mpq_t *op_num);
void write_expontetiation_mode(mpq_t *op_num);
void start_aloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num);
void start_sloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num);
void start_mloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num);
void start_dloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num);
//void start_srloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num);
void start_eloop_mode(double *delay, double *msg_delay, double *temp_msg_delay, char *str, mpq_t *op_num);
void hotkey_modes(char *choice3);
void hotkey_ctrl_reg(FILE *fp);
void hotkey_alt_reg(FILE *fp);
void hotkey_shift_reg(FILE *fp);
void hotkey_win_reg(FILE *fp);
void hotkey(void);
void click(double *delay, int clicks_per_sec); // Clicks
void write_hotkey_file(FILE *fp, int opt, UINT vk_code);
void read_hotkey_file(FILE *fp, int *opt, UINT *vk_code);
