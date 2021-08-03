//! 
//! @file Application.h
//! @brief �A�v���P�[�V�������N���X
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_APPLICATION_APPLICATION_H
#define LIBRARY_APPLICATION_APPLICATION_H


namespace library::application {
class Applicaion {
    /// <summary>
    /// �ݒ�
    /// </summary>
    /// <param name="name"></param>
    //bool SetCurrentPath(const char* name = "Resource");
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Applicaion() = default;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    virtual ~Applicaion() = default;
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Initialize(void) = 0;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) = 0;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Render(void) = 0;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) = 0;
};
}
#endif // !LIBRARY_APPLICATION_APPLICATION_H