#include <iostream>
#include <memory>

class Observer {
public:
    Observer(std::shared_ptr<int> observed) : observedPtr(observed) {}

    void check() {
        if (auto temp = observedPtr.lock()) { // получение доступа к объекту
            std::cout << "Observed value: " << *temp << std::endl;
        }
        else {
            std::cout << "Observed object no longer exists." << std::endl;
        }
    }

private:
    std::weak_ptr<int> observedPtr;
};

int main() {
    auto sharedInt = std::make_shared<int>(100);
    Observer observer(sharedInt);

    observer.check(); //вывод: 100

    sharedInt.reset(); //освобождаем наш ресурс

    observer.check(); //объект больше не существует
    return 0;
}
