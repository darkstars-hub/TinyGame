//! 
//! @file Clock.h
//! @brief ���C�u�������ł̎��v
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_CLOCK_CLOCK_H
#define LIBRARY_CLOCK_CLOCK_H


#include "../Common/Common.h"

#include <deque>


namespace library::clock {
class Clock {
private:
    //! ����
    float _delta_time;
    //! ����
    float _previous_time;
    //! ���z�I��FPS
    float _ideal_fps;
    //! ���݂�FPS
    float _now_fps;
    //! �W�{��
    const int _sample_count;
    //! �f���^�^�C���̍��v�l
    float _delta_times_sum;
    //! �W�{
    std::deque<float> _delta_times;
    /// <summary>
    /// FPS�Z�o
    /// </summary>
    /// <param name=""></param>
    void CalculateFPS(void);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Clock();
    /// <summary>
    /// �f���X�g���N�^
    /// </summary>
    ~Clock();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    float GetFrameSecond(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>���z�I��FPS</returns>
    float GetIdealFPS(void) const noexcept;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>���݂�FPS</returns>
    float GetFPS(void) const noexcept;
    /// <summary>
    /// �P�ʎ��Ԃɓ��B���������肷��
    /// </summary>
    /// <param name=""></param>
    /// <returns>���Ă���Ȃ�true��Ԃ�</returns>
    bool IsFull(void);
    /// <summary>
    /// �P�ʎ��ԂɂȂ�܂ő҂�
    /// </summary>
    /// <param name=""></param>
    void Wait(void);
    /// <summary>
    /// ���Ԃ�i�߂�
    /// </summary>
    /// <param name=""></param>
    void Tick(void);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    void Update(void);
};
}
#endif // !LIBRARY_CLOCK_CLOCK_H