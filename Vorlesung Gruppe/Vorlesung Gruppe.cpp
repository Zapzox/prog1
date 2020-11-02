#include <iostream>

int main()
{
    float e1 = 0.0;
    for (float i = 1.0; i <= 10.0; i++) {
        e1 = e1 + (1 / i);
     }
    
    std::cout << e1 << std::endl;

    float e2 = 0;
    float j = 1;

    while (j<=10) {
        e2 = e2 + (1 / j);
        j++;
    }

    std::cout << e2;

}
