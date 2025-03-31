#include <iostream>
#include <crtdbg.h>

int main() {
    for (int i = 0; i < 100; ++i) {
        std::unique_ptr<int> ptr(new int(i)); 
    }
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}
