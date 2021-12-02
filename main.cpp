#include <iostream>
#include <unistd.h>
#include <getopt.h>

using namespace std;

void help();
void version(const char*);
void years(const char*);


int main(int argc, char *argv[]) {
    int rez = -1;
    int option_index;
    const char* short_options = "hv::y:";
    const struct option long_options[] = {
            {"help",no_argument,NULL,'h'},
            {"version",optional_argument,NULL,'v'},
            {"years",required_argument,NULL,'y'},
            {NULL,0,NULL,0}
    };
    int h_counter = 1;
    int v_counter = 1;
    int y_counter = 1;


    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index))  != -1) {

        switch(rez){
            case 'h': {
                if (h_counter < 1){
                    goto exitH;
                }
                h_counter--;
                help();
                exitH: break;
            }
            case 'v': {
                if (v_counter < 1){
                    goto exitV;
                }
                v_counter--;
                if (optarg!=NULL)
                    version(optarg);
                else
                    version("1.0");
                exitV: break;
            }

            case 'y': {
                if (y_counter < 1){
                    goto exitY;
                }
                y_counter--;
                years(optarg);
                exitY: break;
            }
            case '?': default: {
                printf("Unknown option\n");
                break;
            }
        }
    }
}

void help(){
    printf("\n-h, --help\n-v, --version\n-y, --years\n");
}

void version(const char* ver){
    printf("Version: %s\n", ver);
}

void years(const char* number){
    printf("U are %s years old\n", number);
}
