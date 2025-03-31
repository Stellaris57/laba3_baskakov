#include <iostream>
#include <crtdbg.h>

int main() {
    for (int i = 0; i < 100; ++i) {
        int* ptr = new int(i); 
    }
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}
