#include <iostream>
#include <cstdlib>
#include <getopt.h>
#include <cmath>
#include <iomanip>
using namespace std;

void print_help();
bool compareStrings(const char *str1); //compareStrings(optarg)

int main(int argc, char* argv[])
{
    int opt;
    double base = 0.0, exponent = 0.0;
    bool calculate_exponent = false, calculate_power = false, flag = true;

    while ((opt = getopt(argc, argv, "e:p:")) != -1) {
        switch (opt) {
        case 'e':
            flag = false;
            if(compareStrings(optarg)) {
                calculate_exponent = true;
                exponent = atof(optarg);
            } else {
                cerr << "Error: Known option, but unknown argument.\n";
            }
            break;
        case 'p':
            flag = false;
            if(compareStrings(optarg)) {
                calculate_power = true;
                base = atof(optarg);
                if (optind < argc) {
                    exponent = atof(argv[optind]);
                } else {
                    cerr << "Error: Missing exponent value for -p option.\n";
                    return 1;
                }
            } else {
                cerr << "Error: Known option, but unknown argument.\n";
            }
            break;
        case '?':
            cerr << "Error: Unknown option or missing argument.\n";
            print_help();
            return 1;
        default:
            cerr << "Unknown option\n";
            break;
        }
    }
    if (calculate_exponent) {
        double result = exp(exponent);
        cout << "e^" << exponent << " = " << setprecision(6) << result << endl;
    }
    if (calculate_power) {
        double result = pow(base, exponent);
        cout << base << "^" << exponent << " = " << setprecision(6) << result << endl;
    }
    if (flag == true) print_help();
    return 0;
}
void print_help()
{
    cout << "Variant12_Tanasov\n";
    cout << "Usage: calculator [OPTIONS]\n";
    cout << "Options:\n";
    cout << "  -e, --exponent VALUE    Calculate e^VALUE\n";
    cout << "  -p, --power BASE POWER    Calculate BASE^POWER\n";
}
bool compareStrings(const char *str1) //compareStrings(optarg, size)
{
    bool flag = false;
    const char digits [] = "0123456789.";
    int size_digits = 10;
    if (*str1 && digits) {
        if (flag == true) return flag;
        for(int j = 1; j <= size_digits; j++) {
            if(*str1==digits[j]) {
                flag = true;
                break;
            }
        }
    }
    return flag;
}
