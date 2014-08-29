FakeCall
========

Cocos2d-x 3.2 プロジェクト


# 使い方（Android）
* 前提
    - libcocos2dxプロジェクトがあること
* 手順
    * Eclipseへのインポート
        - Eclipseを起動
        - [インポート] - [Android]->[Existing Android Code Into Workspace] を選択
        - 『FakeCall/proj.android』を指定してインポート
    * libcocos2dxの参照設定
        - Eclipseの『FakeCall』プロジェクトを右クリックして『プロパティ』を選択
        - [リソース] - [リンクされたリソース] の『リンクされたリソース』タブにある[絶対パスロケーション]-[libcocos2dx]のパスに以下を設定
            - ${COCOS2DX}\cocos\platform\android\java\src
        - [リソース] - [Android] のライブラリーに『libcocos2dx』プロジェクトを追加
