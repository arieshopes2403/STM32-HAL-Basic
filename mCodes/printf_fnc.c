#include <stdio.h>
#include <stdarg.h>

char buffer[104];

void mPrint(const char*format, ...)
{
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    // UART Transmit
    //HAL_UART_Transmit(&huart1, (uint8_t*)buffer, 104, 1000); 
}

int main() {
    // Write C code here
    mPrint("x= %d\n", 12);

    printf("%s", buffer);

    return 0;
}