#include<iostream>
using namespace std;
char origin_train[16][100] = {//lenghts=89+2*5=99
	/*0*/"                          (@@) (  ) (@)  ( )  @@    ()    @     O     @     O      @      O        ",
	/*1*/"                     (   )                                                                         ",
	/*2*/"                 (@@@@)                                                                            ",
	/*3*/"              (    )                                                                               ",
	/*4*/"                                                                                                   ",
	/*5*/"            (@@@)                                                                                  ",
	/*6*/"           ====        ________                       ___________                                  ",
	/*7*/"       _D _|  |_______/        \\__I_I_____===_________|_________|                                  ",
	/*8*/"        |(_)---  |   H\\________/ |   |               =|___ ___|      _________________             ",
	/*9*/"        /     |  |   H  |  |     |   |                ||_| |_||     _|                \\_____A      ",
	/*10*/"       |      |  |   H  |__--CHOO-CHOO-MOTHERFUCKERS--| [___] |   =|                        |      ",
	/*11*/"       | ________|___H__/__|_____/[][]~\\______________|       |   -|                        |      ",
	/*12*/"       |/ |   |-----------I_____I [][] [] _D  _______ |=======|____|________________________|_     ",
	/*13*/"     __/ =| O |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y_____Y____________|__|__________________________|_     ",
	/*14*/"      |/-=|___|=O=====O=====O=====O   |_____/~\\___/~\\___/           |_D__D__D_|  |_D__D__D_|       ",
	/*15*/"       \\_/      \\__/  \\__/  \\__/  \\__/      \\_/   \\_/                \\_/   \\_/    \\_/   \\_/        " };
char smoke_frames[8][6][83] = { {//lenghts=82
		/*0*/"              (@@) (  ) (@)  ( )  @@    ()    @     O     @     O      @      O   ",
		/*1*/"         (   )                                                                    ",
		/*2*/"     (@@@@)                                                                       ",
		/*3*/"  (    )                                                                          ",
		/*4*/"                                                                                  ",
		/*5*/"(@@@)                                                                             " },
		{	 "               (@@) (  ) (@)  ( )  @@    ()    @     O     @     O      @      O  ",
			 "          (   )                                                                   ",
			 "      (@@@@)                                                                      ",
			 "   (    )                                                                         ",
			 "                                                                                  ",
			 " (@@@)                                                                            " },
		{	 "                (@@) (  ) (@)  ( )  @@    ()    @     O     @     O      @      O ",
			 "           (   )                                                                  ",
			 "       (@@@@)                                                                     ",
			 "    (    )                                                                        ",
			 "                                                                                  ",
			 "  (@@@)                                                                           " },
		{	 "                 (@@) (  ) (@)  ( )  @@    ()    @     O     @     O      @      O",
			 "            (   )                                                                 ",
			 "        (@@@@)                                                                    ",
			 "     (    )                                                                       ",
			 "                                                                                  ",
			 "   (@@@)                                                                          " },
		{	 "              (  ) (@@) ( )  (@)  ()    @@    O     @     O     @      O      @   ",
			 "         (@@@)                                                                    ",
			 "     (    )                                                                       ",
			 "  (@@@@)                                                                          ",
			 "                                                                                  ",
			 "(   )                                                                             " },
		{	 "               (  ) (@@) ( )  (@)  ()    @@    O     @     O     @      O      @  ",
			 "          (@@@)                                                                   ",
			 "      (    )                                                                      ",
			 "   (@@@@)                                                                         ",
			 "                                                                                  ",
			 " (   )                                                                            " },
		{	 "                (  ) (@@) ( )  (@)  ()    @@    O     @     O     @      O      @ ",
			 "           (@@@)                                                                  ",
			 "       (    )                                                                     ",
			 "    (@@@@)                                                                        ",
			 "                                                                                  ",
			 "  (   )                                                                           " },
		{	 "                 (  ) (@@) ( )  (@)  ()    @@    O     @     O     @      O      @",
			 "            (@@@)                                                                 ",
			 "        (    )                                                                    ",
			 "     (@@@@)                                                                       ",
			 "                                                                                  ",
			 "   (   )                                                                          " } };
char wheels_frame[6][3][23] = { {//lenghts=22
		/*0*/"-~~\\  /~~\\  /~~\\  /~~\\",
		/*1*/"O=====O=====O=====O   ",
		/*2*/"\\__/  \\__/  \\__/  \\__/" },
		{	 "-~~\\  /~~\\  /~~\\  /~~\\",
			 "    ||    ||    ||    ",
			 "\\O=====O=====O=====O_/" },
		{	 "-~~\\  /~~\\  /~~\\  /~~\\",
			 "    ||    ||    ||    ",
			 "\\_O=====O=====O=====O/" },
		{	 "-~~\\  /~~\\  /~~\\  /~~\\",
			 "   O=====O=====O=====O",
			 "\\__/  \\__/  \\__/  \\__/" },
		{	 "-~O=====O=====O=====O\\",
			 "    ||    ||    ||    ",
			 "\\__/  \\__/  \\__/  \\__/" },
		{	 "-O=====O=====O=====O \\",
			 "    ||    ||    ||    ",
			 "\\__/  \\__/  \\__/  \\__/" } };
char train[16][100];
char temp[16][100];
char temp_2[16][100];
int i, j, k;
int mem_wheels, limit_j_wheels;
int mem_smoke, limit_j_smoke;
int twenty_one, eighty_one;
int count_smoke;
int count_shift;
bool found_wheels = false;
bool found_smoke = false;
bool hyphen = false;
bool backslash = false;
bool left_round_bracket = false;
bool o_or_at_sign = false;
void find_column_wheels() {
	if (hyphen) {
		for (i = 0; i < 99; i++) {
			if (train[13][i] == '-') {
				found_wheels = true;
				mem_wheels = i;
				break;
			}
			else found_wheels = false;
		}
	}
	else if (backslash) {
		for (i = 98; i >= 0; i--) {
			if (train[13][i] == '\\') {
				found_wheels = true;
				mem_wheels = i;
				break;
			}
			else found_wheels = false;
		}
	}
}
void find_column_smoke() {
	if (left_round_bracket) {
		for (i = 0; i < 99; i++) {
			if (train[5][i] == '(') {
				found_smoke = true;
				mem_smoke = i;
				count_smoke++;
				break;
			}
			else found_smoke = false;
		}
	}
	else if (o_or_at_sign) {
		for (i = 98; i >= 0; i--) {
			if (train[0][i] == 'O' || train[0][i] == '@') {
				found_smoke = true;
				mem_smoke = i + 3;
				count_smoke++;
				break;
			}
			else found_smoke = false;
		}
	}
}
void add_moving_whells(int frame) {
	if (hyphen) {
		find_column_wheels();
		if (found_wheels) {
			limit_j_wheels = mem_wheels + 21;
			if (limit_j_wheels > 91)limit_j_wheels = 98;
			for (i = 13; i < 16; i++) {
				for (j = mem_wheels; j < limit_j_wheels; j++) {
					temp[i][j] = train[i][j];
					train[i][j] = wheels_frame[frame][i - 13][j - mem_wheels];
				}
			}
		}
	}
	else if (backslash) {
		find_column_wheels();
		if (found_wheels) {
			if (mem_wheels > 21) limit_j_wheels = mem_wheels - 21;
			else limit_j_wheels = 0;
			for (i = 13; i < 16; i++) {
				twenty_one = 21;
				for (j = mem_wheels; j >= limit_j_wheels; j--) {
					temp[i][j] = train[i][j];
					train[i][j] = wheels_frame[frame][i - 13][twenty_one--];
				}
			}
		}

	}
}
void drop_moving_wheels() {
	if (found_wheels) {
		if (hyphen) {
			for (i = 13; i < 16; i++) {
				for (j = mem_wheels; j < limit_j_wheels; j++) {
					train[i][j] = temp[i][j];
				}
			}
			limit_j_wheels = mem_wheels = 0;
		}
		else if (backslash) {
			for (i = 13; i < 16; i++) {
				for (j = mem_wheels; j >= limit_j_wheels; j--) {
					train[i][j] = temp[i][j];
				}
			}
			limit_j_wheels = mem_wheels = 0;
		}
	}
}
void smoke(int frame) {
	if (left_round_bracket) {
		find_column_smoke();
		if (found_smoke) {
			limit_j_smoke = mem_smoke + 81;
			if (limit_j_smoke > 91)limit_j_smoke = 98;
			for (i = 0; i < 6; i++) {
				for (j = mem_smoke; j < limit_j_smoke; j++) {
					temp_2[i][j] = train[i][j];
					train[i][j] = smoke_frames[frame][i][j - mem_smoke];
				}
			}
		}
	}
	else if (o_or_at_sign) {
		find_column_smoke();
		if (found_smoke) {
			if (mem_smoke > 81) limit_j_smoke = mem_smoke - 81;
			else limit_j_smoke = 0;
			for (i = 0; i < 6; i++) {
				eighty_one = 81;
				for (j = mem_smoke; j >= limit_j_smoke; j--) {
					temp_2[i][j] = train[i][j];
					train[i][j] = smoke_frames[frame][i][eighty_one--];
				}
			}
		}

	}
}
void clean_smoke() {
	if (found_smoke) {
		if (left_round_bracket) {
			for (i = 0; i < 6; i++) {
				for (j = mem_smoke; j < limit_j_smoke; j++) {
					train[i][j] = temp_2[i][j];
				}
			}
			limit_j_smoke = mem_smoke = 0;
		}
		else if (o_or_at_sign) {
			for (i = 0; i < 6; i++) {
				for (j = mem_smoke; j >= limit_j_smoke; j--) {
					train[i][j] = temp_2[i][j];
				}
			}
			limit_j_smoke = mem_smoke = 0;
		}
	}
}
void install_proto_train() {
	for (i = 0; i < 16; i++) {
		for (k = 0; k < 98; k++) {
			train[i][k] = ' ';
		}
	}
}
void show_train() {
	for (int l = 0; l < 16; l++) {
		cout << train[l] << endl;
	}
}
void shift_left() {
	for (i = 0; i < 16; i++) {
		for (k = 1; k < 99; k++) {
			train[i][k - 1] = train[i][k];
		}
	}
}
void install_train() {
	install_proto_train();
	count_shift = 98;
	count_smoke = 1;
	hyphen = true;
	backslash = false;
	left_round_bracket = true;
	o_or_at_sign = false;
	while (count_shift) {
		if (count_shift != 98)shift_left();
		for (i = 0; i < 16; i++) {
			train[i][98] = origin_train[i][0 + (98 - count_shift)];
		}
		add_moving_whells(6 - count_shift % 6);
		smoke(count_smoke % 8);
		show_train();
		clean_smoke();
		drop_moving_wheels();
		count_shift -= 1;
		system("cls");
	}
}
void delete_train() {
	count_shift = 98;
	hyphen = false;
	backslash = true;
	left_round_bracket = false;
	o_or_at_sign = true;
	while (count_shift) {
		shift_left();
		add_moving_whells(6 - count_shift % 6);
		smoke(count_smoke % 8);
		show_train();
		clean_smoke();
		drop_moving_wheels();
		count_shift -= 1;
		if (count_shift)system("cls");
	}
}
void moving_train() {
	install_train();
	delete_train();
}
int main() {
	moving_train();
	return 0;
}
