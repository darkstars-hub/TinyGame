//! 
//! @file GameApplication.h
//! @brief game application
//! @author darkstar
//! @date 2021/08/02
//! @details none
//! 
#ifndef GAME_GAME_APPLICATION_H
#define GAME_GAME_APPLICATION_H


namespace game {
class GameApplication {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameApplication();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameApplication();
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(void);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Update(float delta_time);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !GAME_GAME_APPLICATION_H