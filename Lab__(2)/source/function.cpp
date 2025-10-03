#include "../header /function.h"
#include "../header /string.h"

void show_menu() {
    String s1;
    String s2;
    int choice;

    do {
        std::cout << "\n    MENU    \n";
        std::cout << "1. Input first string\n";
        std::cout << "2. Display first string\n";
        std::cout << "3. Display second string\n";
        std::cout << "4. Assign first string to second\n";
        std::cout << "5. Add second string to first\n";
        std::cout << "6. Check if strings are equal\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose point: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter first string: ";
                std::cin >> s1;
                break;
            case 2:
                std::cout << "First string: " << s1 << std::endl;
                break;
            case 3:
                std::cout << "Second string: " << s2 << std::endl;
                break;
            case 4:
                s2 = s1;
                std::cout << "Second string contains the first string.\n";
                break;
            case 5:
                s1 += s2;
                std::cout << "First string after adding second: " << s1 << std::endl;
                break;
            case 6:
                if (s1 == s2)
                    std::cout << "Strings are equal.\n";
                else
                    std::cout << "Strings are different.\n";
                break;
            case 0:
                std::cout << "Exit program.\n";
                break;
            default:
                std::cout << "ERROR. Try again.\n";
        }
    } while (choice != 0);
}