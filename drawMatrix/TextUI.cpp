#include "TextUI.h"

TextUI::TextUI()
{

    std::string cmd;
    
    picture = new DrawMatrix;
    
    while(true){
        std::cout << ">>> ";
        std::cin >> cmd;
        if (cmd=="quit" || cmd == "quit") break;
        else runCommand(cmd);
    }
    
}

TextUI::~TextUI()
{

}

void TextUI::printText(std::string text)
{
    std::cout << text;
}

void TextUI::runCommand(std::string cmd)
{
    if (cmd=="help") helpCmd();
    else if (cmd=="run" || cmd=="RUN" || cmd=="start") startCmd();
    else if (cmd=="geometry" || cmd=="set") setGeometryCmd();
    else if (cmd=="clear") clearCmd();
    else if (cmd=="assign") assignCmd();
    else if (cmd=="draw") drawCmd();
    else if (cmd=="line") drawLineCmd();
    else if (cmd=="fill") fillCmd();
    else if (cmd=="move") moveCmd();
    else if (cmd=="rmove") rmoveCmd();
    else if (cmd=="display") displayCmd();
    else if (cmd=="displayRaw") displayRawCmd();
    else if (cmd=="refresh") refreshCmd();
    else if (cmd=="dimensions") dimensionsCmd();
    else if (cmd=="position") positionCmd();
    else if (cmd=="stop") stopCmd();
    else if (cmd=="fence") drawFenceCmd();
    else wrongCmd();
}

void TextUI::helpCmd()
{
    std::string text="";
    printText(text);
}

void TextUI::wrongCmd()
{
    printText("Wrong command\n");
}

void TextUI::clearCmd()
{
    picture->clearPicture();
}

void TextUI::startCmd()
{


}

void TextUI::stopCmd()
{

}

void TextUI::setGeometryCmd()
{
    int width, height;
    std::cin >> width >> height;
    
    if (picture->isError()){
         printText("Dimensions out of range");
    }
    
    else picture->setGeometry(width, height);
    
}

void TextUI::displayRawCmd()
{
    printText(picture->getPictureRawString());
}

void TextUI::displayCmd()
{
    printText(picture->getPictureString());
}

void TextUI::dimensionsCmd()
{
    std::string dimensionsMsg="";
    dimensionsMsg+="Picture dimensions\n";
    dimensionsMsg+="Width: " + std::to_string(picture->getWidth()) + "\n";
    dimensionsMsg+="Height: " + std::to_string(picture->getHeight()) + "\n\n";
    printText(dimensionsMsg);
}

void TextUI::positionCmd()
{
    std::string dimensionsMsg="";
    dimensionsMsg+="Cursor position\n";
    dimensionsMsg+="X: " + std::to_string(picture->getCursorXPos()) + "\n";
    dimensionsMsg+="Y: " + std::to_string(picture->getCursorYPos()) + "\n\n";
    printText(dimensionsMsg);
}

void TextUI::moveCmd()
{
    int xpos, ypos;
    std::cin >> xpos >> ypos;
    
    picture->moveCursor(xpos, ypos);
}

void TextUI::rmoveCmd()
{
    int xpos, ypos;
    std::cin >> xpos >> ypos;
    
    picture->rmoveCursor(xpos, ypos);
}

void TextUI::fillCmd()
{
    int nr;
    std::cin >> nr;
    picture->fill(nr);
}

void TextUI::assignCmd()
{
    int nr;
    std::string symbol;
    std::cin >> nr >> symbol;
    picture->assignSymbol(nr, symbol);
}

void TextUI::drawCmd()
{
    int x, y, nr;
    std::cin >> x >> y >> nr;
    picture->draw(x, y, nr);
    
}

void TextUI::drawLineCmd()
{
    int x, y, nr;
    std::cin >> x >> y >> nr;
    picture->drawLine(x, y, nr);
    
}

void TextUI::refreshCmd()
{
    
    picture->refreshPicture();
}

void TextUI::drawFenceCmd()
{
    int width, height;
    this->fence = new FencePicture(picture);
    std::cin >> width >> height;
    fence->setFenceDimensions(width, height);
    fence->setASCII();
    fence->drawAll();
    
    
}
