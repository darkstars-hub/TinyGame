//! 
//! @file GameApplication.h
//! @brief �A�v���P�[�V����
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_TEST_GAME_APPLICATION_H
#define LIBRARY_TEST_GAME_APPLICATION_H


#include "TinyLibrary.h"


namespace test {
class GameApplicaion : public library::application::Applicaion {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameApplicaion();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    virtual ~GameApplicaion();
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Initialize(void) override;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) override;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Render(void) override;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) override;
};
}
#endif // !LIBRARY_TEST_GAME_APPLICATION_H