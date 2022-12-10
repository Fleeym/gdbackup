#pragma once

#include "includes.hpp"

class BackupLayer : public CCLayer, gd::FLAlertLayerProtocol {
protected:
    virtual bool init();
    virtual void keyBackClicked();
    void backButton(CCObject*);
    void backup(CCObject*);

    virtual void FLAlert_Clicked(gd::FLAlertLayer*, bool btn2);
public:
    static BackupLayer* create();
    void switchToBackupLayer(CCObject*);
};