#include <iostream>
#include <string>
#include <unistd.h>
#include <cmath>
class Opts
{
private:
    // константы с пределами значений
    static constexpr int minx = -100;
    static constexpr int maxx = 100;
    static constexpr int miny = -100;
    static constexpr int maxy = 100;

    // атрибуты
    int x; // длина пароля
    int y; // количество паролей

    void usage(unsigned err);
public:
    Opts(int argc, char **argv);
    int getx()
    {
        return x;   
    }
    int gety()
    {
        return y;    
    }
};

int main(int argc, char **argv)
{
    Opts decoder(argc, argv); 
    return 0;
}

// реализация конструктора - весь разбор ПКС здесь
Opts::Opts(int argc, char **argv)
{
    int opt;
    bool flag = true;
    while ((opt = getopt(argc, argv, "e:o: ")) != -1) {
        switch (opt) {
        case 'e':	// возводит число е в степень x
            x = std::stol(optarg);
            if (x < minx || x > maxx) {	// проверка на минимум и максимум
                std::cerr << "x must be from " << minx << " to " << maxx << "\n";
                usage(1);
            }
            std::cout << "exp(" << x << ") = " << exp(x) <<  std::endl;
            break;
        case 'o': 	// возводит число х в степень у
            y = std::stol(optarg);
            if (y < miny || y > maxy) {	// проверка на минимум и максимум
                std::cerr << "y must be from " << miny << " to " << maxy << "\n";
                usage(2);
            }
            std::cout << x <<"^" << y << " = " << pow(x,y) << std::endl;
            break;

        default:	// неизвесный параметр
            std::cerr << "Unknown option\n";
            usage(4);

        }
        flag = false;
    }
    if (flag == true) {
        usage(0);
    }
}

void Opts::usage(unsigned err)
{
    std::cout << "Calculator_variant12_Tanasov\n";
    std::cout << "Usage:  [-e x] [-o y] \n";
    std::cout << "\t-e x - znachenie from -100 to 100; output: exp(x)\n";
    std::cout << "\t-o y - znachenie from -100 to 100; output x^y\n";
    exit(err);
}
