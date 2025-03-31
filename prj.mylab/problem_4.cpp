#include <iostream>
#include <memory>

class SharedResource {
public:
    SharedResource(int value) : value(value) {}
    void display() const { std::cout << "Value: " << value << std::endl; }
private:
    int value;
};

int main() {
    std::shared_ptr<SharedResource> resource = std::make_shared<SharedResource>(100); //наш ресурс

    {
        std::shared_ptr<SharedResource> resource1 = resource; // второй указатель на ресурс
        resource1->display();
        std::cout << "Reference count: " << resource.use_count() << std::endl; //вывод: 2
    } //resource1 имеет локальную область видимости

    resource->display();
    std::cout << "Reference count: " << resource.use_count() << std::endl; //вывод: 1
    return 0;
}
