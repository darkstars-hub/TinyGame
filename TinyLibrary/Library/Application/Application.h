//! 
//! @file Application.h
//! @brief アプリケーション基底クラス
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_APPLICATION_APPLICATION_H
#define LIBRARY_APPLICATION_APPLICATION_H


namespace library::application {
class Applicaion {
    /// <summary>
    /// 設定
    /// </summary>
    /// <param name="name"></param>
    //bool SetCurrentPath(const char* name = "Resource");
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Applicaion() = default;
    /// <summary>
    /// コンストラクタ
    /// </summary>
    virtual ~Applicaion() = default;
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Initialize(void) = 0;
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) = 0;
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Render(void) = 0;
    /// <summary>
    /// 解放
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) = 0;
};
}
#endif // !LIBRARY_APPLICATION_APPLICATION_H