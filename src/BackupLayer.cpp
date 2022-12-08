#include "BackupLayer.hpp"

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

bool BackupLayer::init() {
    auto label = CCLabelBMFont::create("Hello world!", "bigFont.fnt");
    label->setPosition({200, 100});
    label->setRotation(45);
    this->addChild(label);

    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto backgroundSize = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / backgroundSize.width);
    backgroundSprite->setScaleY(winSize.height / backgroundSize.height);
    backgroundSprite->setAnchorPoint({0, 0});
    backgroundSprite->setColor({100, 100, 100});
    backgroundSprite->setZOrder(-1);
    this->addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(BackupLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition({25, winSize.height - 25});
    this->addChild(menu);

    this->setKeypadEnabled(true);

    return true;
}

void BackupLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void BackupLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void BackupLayer::switchToBackupLayer(CCObject* object) {
    auto layer = BackupLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}
