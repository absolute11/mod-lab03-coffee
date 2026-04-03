// Copyright 2026 Gitelman Denis
#include <iostream>
#include "Automata.h"

int main() {
    Automata a;

    a.on();
    std::cout << "Состояние после включения: " << a.getState() << std::endl;

    a.coin(35);
    std::cout << "Баланс: " << a.cash << std::endl;

    a.choice(1);
    std::cout << "Состояние после выбора: " << a.getState() << std::endl;

    if (a.check()) {
        a.cook();
        std::cout << "Состояние после приготовления: ";
        std::cout << a.getState() << std::endl;
        a.finish();
        std::cout << "Состояние после завершения: ";
        std::cout << a.getState() << std::endl;
    } else {
        a.cancel();
        std::cout << "Недостаточно средств, отмена" << std::endl;
    }

    a.off();
    std::cout << "Состояние после выключения: ";
    std::cout << a.getState() << std::endl;
    return 0;
}
