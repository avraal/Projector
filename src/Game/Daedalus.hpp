//
// Created by andrew on 22.01.19.
//

#ifndef PROJECTOR_DAEDALUS_HPP
#define PROJECTOR_DAEDALUS_HPP

#include "../Engine/Level/Level.hpp"
#include <math.h>
class Daedalus : public Level
{
private:
    sf::Vector2f cellSize;
    bool setPositionByGrid;
    bool canCreateOrEdit;

    enum class EditorMode : int
    {
        ADD,
        SELECT
    };

    inline friend std::ostream &operator<<(std::ostream &os, EditorMode mode)
    {
        switch (mode)
        {
            case EditorMode::ADD:
            {
                os << "ADD";
                break;
            }
            case EditorMode::SELECT:
            {
                os << "SELECT";
                break;
            }
        }
        return os;
    }

    EditorMode currentEditorMode;

    //------------------------------UI------------------------------
        //-------------------------Info-----------------------------
            tgui::Panel::Ptr infoPanel;
            tgui::Label::Ptr infoFPSLabel;
            tgui::Label::Ptr infoObjCountLabel;

            sf::Color infoTextColor;
            us_int infoTextSize;
            float infoTextMargin;
        //-------------------------Info-----------------------------
    //------------------------------UI------------------------------

    void initGui();
public:
    Daedalus(const std::string &name);
    virtual ~Daedalus() override;
    virtual void update(sf::RenderWindow &window) override;
    virtual void prepare() override;
    virtual void exitProcess() override;
    virtual void mouseCallbacks(sf::RenderWindow &window, sf::Event &event) override;
    virtual void keyboardCallbacks(sf::RenderWindow &window, sf::Event &event) override;
    virtual void guiCallbacks(sf::Event &event) override;
    virtual void readSettings(const std::string &fileName);
};

#endif //PROJECTOR_DAEDALUS_HPP
