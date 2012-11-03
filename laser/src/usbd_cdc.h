/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CDC_H
#define __USBD_CDC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

#include "usbd_cdc_core.h"
#include "usbd_conf.h"
#include "usart.h" // this is for debugging (to show messages on a serial console)


#define DEFAULT_CONFIG                  0
#define OTHER_CONFIG                    1

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
/**
  * @brief  cdc_DataTx
  *         CDC received data to be send over USB IN endpoint are managed in
  *         this function.
  * @param  Buf: Buffer of data to be sent
  * @param  Len: Number of data to be sent (in bytes)
  * @retval Result of the opeartion: USBD_OK
  */
uint16_t cdc_DataTx (uint8_t* Buf, uint32_t Len);


#endif /* __USBD_CDC_VCP_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
