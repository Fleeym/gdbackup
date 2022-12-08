#include "MenuLayer.hpp"
#include "BackupLayer.hpp"

bool __fastcall MenuLayer::init_hook(CCLayer* self) {
    if (!MenuLayer::init(self)) return false;

    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_myServerBtn_001.png");
    auto button = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        self,
        menu_selector(BackupLayer::switchToBackupLayer)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition({45, 180});

    self->addChild(menu);

    return true;
}