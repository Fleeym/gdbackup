#include "BackupLayer.hpp"

bool BackupLayer::init() {
    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto backgroundSize = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / backgroundSize.width);
    backgroundSprite->setScaleY(winSize.height / backgroundSize.height);
    backgroundSprite->setAnchorPoint({0, 0});
    backgroundSprite->setColor({0, 102, 255});
    backgroundSprite->setZOrder(-1);
    this->addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(BackupLayer::backButton)
    );

    button->setPosition({25, winSize.height - 25});

    auto backupButton = gd::CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("accountBtn_myLevels_001.png"),
        this,
        menu_selector(BackupLayer::backup)
    );

    backupButton->setPosition({winSize.width - 30, 30});

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->addChild(backupButton);
    menu->setPosition({0, 0});
    menu->setAnchorPoint({0, 0});
    this->addChild(menu);

    this->setKeypadEnabled(true);

    return true;
}

void BackupLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void BackupLayer::backButton(CCObject* object) {
    keyBackClicked();
}

void BackupLayer::switchToBackupLayer(CCObject* object) {
    auto layer = BackupLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}

void BackupLayer::backup(CCObject* object) {
    gd::FLAlertLayer::create(
        this, "Backup", "Cancel", "Yes", "Do you want to save a <cy>local backup</c> of your save data?"
    )->show();
}

void BackupLayer::FLAlert_Clicked(gd::FLAlertLayer* layer, bool btn2) {
    if (btn2) {
        gd::FLAlertLayer::create(
            nullptr, "Success", "Cool", nullptr, "You saved the game!"
        )->show();
    }
}

BackupLayer* BackupLayer::create() {
    auto ret = new BackupLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}