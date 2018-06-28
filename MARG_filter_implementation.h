//=====================================================================================================
// MARG_filter_implementation.h
//=====================================================================================================
#ifndef MARG_filter_implementation_h
#define MMARG_filter_implementation_h

// System constants
#define deltat 0.001f // sampling period in seconds (shown as 1 ms)
#define gyroMeasError 3.14159265358979 * (5.0f / 180.0f) // gyroscope measurement error in rad/s (shown as 5 deg/s)
#define gyroMeasDrift 3.14159265358979 * (0.2f / 180.0f) // gyroscope measurement error in rad/s/s (shown as 0.2f deg/s/s)
#define beta invSqrt(3.0f / 4.0f) * gyroMeasError // compute beta
#define zeta invSqrt(3.0f / 4.0f) * gyroMeasDrift // compute zeta
// Global system variables
float a_x, a_y, a_z; // accelerometer measurements
float w_x, w_y, w_z; // gyroscope measurements in rad/s
float m_x, m_y, m_z; // magnetometer measurements
float SEq_1 = 1, SEq_2 = 0, SEq_3 = 0, SEq_4 = 0; // estimated orientation quaternion elements with initial conditions
float b_x = 1, b_z = 0; // reference direction of flux in earth frame
float w_bx = 0, w_by = 0, w_bz = 0; // estimate gyroscope biases error

//---------------------------------------------------------------------------------------------------
// Function declarations

float invSqrt(float x);
void filterUpdate(float w_x, float w_y, float w_z, float a_x, float a_y, float a_z, float m_x, float m_y, float m_z);

//---------------------------------------------------------------------------------------------------

#endif
//=====================================================================================================
// End of file
//=====================================================================================================
