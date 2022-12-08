#pragma once

#include "includes.hpp"

class BackupLayer : public CCLayer {
protected:
    virtual bool init();
    virtual void keyBackClicked();
    void backButtonCallback(CCObject*);
public:
    static BackupLayer* create();
    void switchToBackupLayer(CCObject*);
};