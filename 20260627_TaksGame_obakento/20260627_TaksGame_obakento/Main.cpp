#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);
    // 画像を読み込む
    int images[3];

    images[0] = LoadGraph(_T("Image/HGD10-45-ザマス-1-320×464@2x.jpg"));
    images[1] = LoadGraph(_T("Image/dbsd-sdv11-084.webp.jpg"));
    images[2] = LoadGraph(_T("Image/Fqwm2GRaYAEzpEl.jpg"));

    // ゲームスタート
    int scene = 0;
    //初期化
    int oldSpace = 0;

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();
        // 現在のSPACEキー状態
        int space = CheckHitKey(KEY_INPUT_SPACE);
        // SPACEキーが押されると変わる
        if (space == 1 && oldSpace == 0)
        {
            scene++;
            if (scene > 4)
            {
                scene = 4;
            }
        }
        // キー状態をキープ
        oldSpace = space;
        // 画像を表示
        DrawGraph(0, 0, images[scene], TRUE);
        // ゲーム終了
        if (scene == 4 &&
            CheckHitKey(KEY_INPUT_ESCAPE) == 1)
        {
            break;
        }

        ScreenFlip();
    }
    DxLib_End();
    return 0;
}
