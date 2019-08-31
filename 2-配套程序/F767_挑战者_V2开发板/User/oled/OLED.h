/*********************************************************************************
*
* 1. void OLED_WrDat(unsigned char dat) -- 向OLED写数据
* 2. void OLED_WrCmd(unsigned char cmd) -- 向OLED写命令
* 3. void OLED_SetPos(unsigned char x, unsigned char y) -- 设置起始点坐标
* 4. void OLED_Fill(unsigned char bmp_dat) -- 全屏填充(0x00可以用于清屏，0xff可以用于全屏点亮)
* 5. void OLED_CLS(void) -- 清屏
* 6. void OLED_Init(void) -- OLED显示屏初始化
* 7. void OLED_6x8Str(unsigned char x, y,unsigned char ch[]) -- 显示6x8的ASCII字符
* 8. void OLED_8x16Str(unsigned char x, y,unsigned char ch[]) -- 显示8x16的ASCII字符
* 9. void OLED_16x16CN(unsigned char x, y, N) -- 显示16x16中文汉字,汉字要先在取模软件中取模
* 10.void OLED_BMP(unsigned char x0, y0,x1, y1,unsigned char BMP[]) -- 全屏显示128*64的BMP图片
*
* 
*************************************************************************************/

#ifndef __OLED_H
#define __OLED_H
#include "stm32f7xx.h"


#define X_WIDTH 		128
#define Y_WIDTH 		64

//引脚定义
/*******************************************************/
/*CS引脚*/
#define OLED_CS_PIN                  GPIO_PIN_2               
#define OLED_CS_GPIO_PORT            GPIOC                 
#define OLED_CS_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()

/*DC引脚*/
#define OLED_DC_PIN                  GPIO_PIN_3                 
#define OLED_DC_GPIO_PORT            GPIOI                      
#define OLED_DC_GPIO_CLK_ENABLE()    __GPIOI_CLK_ENABLE()

/*MOSI引脚*/
#define OLED_SDA_PIN                  GPIO_PIN_6                 
#define OLED_SDA_GPIO_PORT            GPIOC                       
#define OLED_SDA_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()

/*CLK引脚*/
#define OLED_CLK_PIN                  GPIO_PIN_7                 
#define OLED_CLK_GPIO_PORT            GPIOC                       
#define OLED_CLK_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()
/************************************************************/

#define OLED_CS_0() HAL_GPIO_WritePin(OLED_CS_GPIO_PORT,OLED_CS_PIN,GPIO_PIN_RESET)
#define OLED_CS_1() HAL_GPIO_WritePin(OLED_CS_GPIO_PORT,OLED_CS_PIN,GPIO_PIN_SET)    //接OLED模块CS

#define OLED_DC_0() HAL_GPIO_WritePin(OLED_DC_GPIO_PORT,OLED_DC_PIN,GPIO_PIN_RESET)
#define OLED_DC_1() HAL_GPIO_WritePin(OLED_DC_GPIO_PORT,OLED_DC_PIN,GPIO_PIN_SET)     //接OLED模块D/C

#define OLED_SDA_0() HAL_GPIO_WritePin(OLED_SDA_GPIO_PORT,OLED_SDA_PIN,GPIO_PIN_RESET)
#define OLED_SDA_1() HAL_GPIO_WritePin(OLED_SDA_GPIO_PORT,OLED_SDA_PIN,GPIO_PIN_SET)    //接OLED模块MOSI

#define OLED_CLK_0() HAL_GPIO_WritePin(OLED_CLK_GPIO_PORT,OLED_CLK_PIN,GPIO_PIN_RESET)
#define OLED_CLK_1() HAL_GPIO_WritePin(OLED_CLK_GPIO_PORT,OLED_CLK_PIN,GPIO_PIN_SET)    //接OLED模块的CLK




//OLED控制用函数
void OLED_GPIO_Config(void);
void OLED_WrDat(unsigned char dat);//写数据
void OLED_WrCmd(unsigned char cmd);//写命令
void OLED_SetPos(unsigned char x, unsigned char y);//设置起始点坐标
void OLED_Fill(unsigned char bmp_dat);//全屏填充
void OLED_CLS(void);//清屏
void OLED_Init(void);//初始化
void OLED_6x8Str(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_8x16Str(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_16x16CN(unsigned char x, unsigned char y, unsigned char N);
void OLED_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);

#endif
