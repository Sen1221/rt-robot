#ifndef __ANO_H__
#define	__ANO_H__

#include <rtthread.h>

struct ano_callback
{
    void (*acc_calibrate)(void);
    void (*gyro_calibrate)(void);
    void (*mag_calibrate)(void);
    void (*request_pid_param_info)(void);
    void (*request_version_info)(void);
    void (*reset_param)(void);
    void (*set_pid_group1)(float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
    void (*set_pid_group2)(float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
    void (*set_pid_group3)(float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
    void (*set_pid_group4)(float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
    void (*set_pid_group5)(float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
    void (*set_pid_group6)(float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
};

typedef struct ano_callback *ano_callback_t;

int ano_send_version(uint8_t hardware_type, uint16_t hardware_ver, uint16_t software_ver, uint16_t protocol_ver, uint16_t bootloader_ver);
int ano_send_status(float angle_rol, float angle_pit, float angle_yaw, int32_t alt, uint8_t fly_model, uint8_t armed);
int ano_send_senser(int16_t a_x, int16_t a_y, int16_t a_z, int16_t g_x, int16_t g_y, int16_t g_z, int16_t m_x, int16_t m_y, int16_t m_z, int32_t bar);
int ano_send_rcdata(uint16_t thr, uint16_t yaw, uint16_t rol, uint16_t pit, uint16_t aux1, uint16_t aux2, uint16_t aux3, uint16_t aux4, uint16_t aux5, uint16_t aux6);
int ano_send_power(uint16_t votage, uint16_t current);
int ano_send_motorpwm(uint16_t m_1, uint16_t m_2, uint16_t m_3, uint16_t m_4, uint16_t m_5, uint16_t m_6, uint16_t m_7, uint16_t m_8);
int ano_send_pid(uint8_t group, float k1_p, float k1_i, float k1_d, float k2_p, float k2_i, float k2_d, float k3_p, float k3_i, float k3_d);
int ano_send_user_data(uint8_t number, float d0, float d1, float d2, float d3, float d4, float d5, int16_t d6, int16_t d7, int16_t d8);
int ano_set_device(const char *device_name);
int ano_set_callback(ano_callback_t cb);
int ano_get_callback(ano_callback_t cb);
int ano_init(void *param, ano_callback_t cb);

#endif
