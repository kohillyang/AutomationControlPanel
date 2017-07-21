#include <stdint.h>
extern const unsigned char CRC8_INIT;
extern unsigned char Get_CRC8_Check_Sum(unsigned char *pchMessage,unsigned int dwLength,unsigned
char ucCRC8);
inline void fast_GET_CRC8(unsigned char *pchMessage){
    uint8_t d = Get_CRC8_Check_Sum(pchMessage,31,CRC8_INIT);
    pchMessage[32 - 1] = d;  
}
typedef uint8_t U8;
#define __FALSE 0