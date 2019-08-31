/*********************************************************************************
*
* 1. void OLED_WrDat(unsigned char dat) -- ��OLEDд����
* 2. void OLED_WrCmd(unsigned char cmd) -- ��OLEDд����
* 3. void OLED_SetPos(unsigned char x, unsigned char y) -- ������ʼ������
* 4. void OLED_Fill(unsigned char bmp_dat) -- ȫ�����(0x00��������������0xff��������ȫ������)
* 5. void OLED_CLS(void) -- ����
* 6. void OLED_Init(void) -- OLED��ʾ����ʼ��
* 7. void OLED_6x8Str(unsigned char x, y,unsigned char ch[]) -- ��ʾ6x8��ASCII�ַ�
* 8. void OLED_8x16Str(unsigned char x, y,unsigned char ch[]) -- ��ʾ8x16��ASCII�ַ�
* 9. void OLED_16x16CN(unsigned char x, y, N) -- ��ʾ16x16���ĺ���,����Ҫ����ȡģ�����ȡģ
* 10.void OLED_BMP(unsigned char x0, y0,x1, y1,unsigned char BMP[]) -- ȫ����ʾ128*64��BMPͼƬ
*
* 
*************************************************************************************/

#ifndef __OLED_H
#define __OLED_H
#include "stm32f7xx.h"


#define X_WIDTH 		128
#define Y_WIDTH 		64

//���Ŷ���
/*******************************************************/
/*CS����*/
#define OLED_CS_PIN                  GPIO_PIN_2               
#define OLED_CS_GPIO_PORT            GPIOC                 
#define OLED_CS_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()

/*DC����*/
#define OLED_DC_PIN                  GPIO_PIN_3                 
#define OLED_DC_GPIO_PORT            GPIOI                      
#define OLED_DC_GPIO_CLK_ENABLE()    __GPIOI_CLK_ENABLE()

/*MOSI����*/
#define OLED_SDA_PIN                  GPIO_PIN_6                 
#define OLED_SDA_GPIO_PORT            GPIOC                       
#define OLED_SDA_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()

/*CLK����*/
#define OLED_CLK_PIN                  GPIO_PIN_7                 
#define OLED_CLK_GPIO_PORT            GPIOC                       
#define OLED_CLK_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()
/************************************************************/

#define OLED_CS_0() HAL_GPIO_WritePin(OLED_CS_GPIO_PORT,OLED_CS_PIN,GPIO_PIN_RESET)
#define OLED_CS_1() HAL_GPIO_WritePin(OLED_CS_GPIO_PORT,OLED_CS_PIN,GPIO_PIN_SET)    //��OLEDģ��CS

#define OLED_DC_0() HAL_GPIO_WritePin(OLED_DC_GPIO_PORT,OLED_DC_PIN,GPIO_PIN_RESET)
#define OLED_DC_1() HAL_GPIO_WritePin(OLED_DC_GPIO_PORT,OLED_DC_PIN,GPIO_PIN_SET)     //��OLEDģ��D/C

#define OLED_SDA_0() HAL_GPIO_WritePin(OLED_SDA_GPIO_PORT,OLED_SDA_PIN,GPIO_PIN_RESET)
#define OLED_SDA_1() HAL_GPIO_WritePin(OLED_SDA_GPIO_PORT,OLED_SDA_PIN,GPIO_PIN_SET)    //��OLEDģ��MOSI

#define OLED_CLK_0() HAL_GPIO_WritePin(OLED_CLK_GPIO_PORT,OLED_CLK_PIN,GPIO_PIN_RESET)
#define OLED_CLK_1() HAL_GPIO_WritePin(OLED_CLK_GPIO_PORT,OLED_CLK_PIN,GPIO_PIN_SET)    //��OLEDģ���CLK




//OLED�����ú���
void OLED_GPIO_Config(void);
void OLED_WrDat(unsigned char dat);//д����
void OLED_WrCmd(unsigned char cmd);//д����
void OLED_SetPos(unsigned char x, unsigned char y);//������ʼ������
void OLED_Fill(unsigned char bmp_dat);//ȫ�����
void OLED_CLS(void);//����
void OLED_Init(void);//��ʼ��
void OLED_6x8Str(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_8x16Str(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_16x16CN(unsigned char x, unsigned char y, unsigned char N);
void OLED_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);

#endif
