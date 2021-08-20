// Examen Diagnostico

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Nums {
private:
    std::vector<int> nums;
public:
    Nums() {};

    Nums(std::string str) {
        std::stringstream ss(str);
        std::string num;
        while (ss >> num) {
            this->checkNum(num);
            this->nums.push_back(std::stoi(num));
        }

        if (this->nums.size() < 1) {
            throw "La lista esta vacia";
        }
    };

    void checkNum(std::string num) {
        for (auto& dig : num) {
            if (!std::isdigit(dig) && dig != '-' ) throw "Ingresaste un valor no numerico";
        }
    }

    void sortNums() {
        for (int i = 1; i < this->nums.size(); i++) {
            for (int j = 0; j < this->nums.size() - 1; j++) {
                if (this->nums[i] < this->nums[j]) {
                    std::swap(this->nums[j], this->nums[i]);
                }
            }
        }
    }

    void printNums() {
        std::cout << "Lista: ";
        for (int i = 0; i < this->nums.size(); i++) {
            if (i == (nums.size() - 1)) {
                std::cout << this->nums[i];
                continue;
            }
            std::cout << this->nums[i] << ", ";
        }
        std::cout << std::endl;
    }
};

char tryAgain() {
    char opt;

    do {
        std::cout << "\nQuiere volver a intentarlo? (y/n): ";
        std::cin >> opt;
        opt = tolower(opt);
        if (opt != 'y' && opt != 'n') {
            std::cout << "Entrada no valida. Ingrese un valor correcto.\n";
        }
        else {
            std::cin.ignore();
            break;
        }
    } while (true);

    return opt;
}

int main()
{
    std::string str;
    char opt;
    Nums nums;

    do{
        system("cls");
        std::cout << "Ingresa la lista de numeros separado por espacios:";
        std::getline(std::cin, str);

        try
        {
            nums = Nums(str);
            nums.sortNums();
            nums.printNums();
        }
        catch (const char* err)
        {
            std::cout << err << '\n';
        }

        opt = tryAgain();
        
    } while (opt != 'n');

    std::cout << "\nGracias por su estadia :)\n";
    system("pause");
    return 0;
}
