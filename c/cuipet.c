#include <cdk/cdk.h>
#include <ncurses.h>
#include <string.h>
#include <pthread.h>

#include "status_bar.h"

#include "stretcher.h"
#include "screen_update.h"
#include "menu.h"


#include "sheets.h"
#include "ncurses_pthread.h"
#include "cuipet.h"



int main(int argc, char **argv)
{
	Init_Sheets();
	Init_Status_Bar();
	Init_Screen_Update();
	Init_Stretcher();
	Init_Menu();
	Params_Parser(argc,argv);
	
	Read_Properties_From_File();
	for(;;)
		;
	return 0;
}

//----------------------------------------------------------------------------------------------------
void Print_Usage(FILE *stream, int exit_code)
{
	fprintf(stream, "Usage options\n");
	fprintf(stream, 
		"  -h  --help           Display this usage information.\n"
		"  -v  --version        Print version.\n"
		"  -c  --config-file	windows organization file\n"
		"  -r  --opeation	start operation\n");
	exit(exit_code);
}
//----------------------------------------------------------------------------------------------------
void Params_Parser(int argc, char **argv)
{
	int next_option;
	const char *const short_options = "hvc:o:";
	const struct option long_options[] = {
			{ "help",		no_argument,		NULL,	'h'	},
			{ "version",		no_argument,		NULL,	'v'	},
			{ "config-file", 	required_argument,      NULL,   'c'	},
			{ "operation",		required_argument,      NULL,   'o'	},
			{ NULL,			no_argument,		NULL,	 0	}
	};
	while ( (next_option = getopt_long(argc, argv, short_options, long_options, NULL) ) != -1 ) {
		switch ( next_option ) {
			case 'h': 
				 // Print_Usage(stdout, 0);
				  break;
			case 'v': 
//				  printf("Cuipet v1.4\n");
//				  printf("Copyright (C) AR-PET\n");
				  break;
			case 'c': 
				  Change_Sheets_File(optarg);
				  break;
			case 'o': 
				  break;
			case '?': 
				//  Print_Usage(stdout, 1);
				  break;
			default : 
				Destroy_Sheets();
		}
	} 
}