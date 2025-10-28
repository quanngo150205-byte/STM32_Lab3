/*
 * software_timer.h
 *
 *  Created on: Sep 28, 2025
 *      Author: ngoqu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


#define TIMER_SIZE   10     // Số lượng timer
#define TIMER_CYCLE  10     // Chu kỳ timer tick (ms), tương ứng chu kỳ ngắt


extern int timer_counter[TIMER_SIZE];
extern int timer_flag[TIMER_SIZE];


void setTimers(int);           // Đặt cùng 1 thời gian cho tất cả timer
void setTimer(int, int); // Đặt thời gian cho 1 timer
void timer_run(void);                      // Gọi định kỳ trong ngắt timer
int  isTimerExpired(int);            // Kiểm tra timer hết hạn
void resetTimerFlag(int);            // Xóa cờ hết hạn

#endif /* INC_SOFTWARE_TIMER_H_ */
