#include <ui/SwitcherPopup.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

namespace switcher {

    struct HookPauseLayer : Modify<HookPauseLayer, PauseLayer> {
        void customSetup() {
    PauseLayer::customSetup();

    auto button = CCMenuItemExt::createSpriteExtraWithFrameName("GJ_editModeBtn_001.png", 0.675f, [=](CCObject*) {
        switcher::SwitcherPopup::create()->show();
    });
    button->setID("gamemode-editor-button"_spr);

    auto rightMenu = typeinfo_cast<CCMenu*>(this->getChildByID("right-button-menu"));
    if (rightMenu) {
        rightMenu->addChild(button);
        rightMenu->updateLayout();
        return;
    }

    // fallback: menu sendiri kalau node ID tidak ada
    auto winSize = CCDirector::get()->getWinSize();
    auto menu = CCMenu::create();
    menu->setID("gamemode-editor-menu"_spr);
    menu->setPosition({0.f, 0.f});
    button->setPosition({winSize.width - 35.f, 40.f});
    menu->addChild(button);
    this->addChild(menu);
        }
    };
}
